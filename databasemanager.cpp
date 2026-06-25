#include "databasemanager.h"

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager manager;
    return manager;
}

bool DatabaseManager::initialize() {
    db = QSqlDatabase::addDatabase("QSQLITE", "pharmacy_connection");
    db.setDatabaseName("pharmacy.db");

    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database opened successfully!";
    return createTables();
}

void DatabaseManager::close() {
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::createTables() {
    QSqlQuery query(db);

    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS medicines ("
        "    id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    name TEXT NOT NULL,"
        "    formula TEXT,"
        "    batch_number TEXT UNIQUE NOT NULL,"
        "    quantity INTEGER DEFAULT 0,"
        "    price REAL DEFAULT 0.00,"
        "    expiry_date DATE,"
        "    supplier TEXT"
        ");"
    );

    if (!success) {
        qDebug() << "Error creating medicines table:" << query.lastError().text();
        return false;
    }
    qDebug() << "Medicines table ready.";

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS sales ("
        "    id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    medicine_id INTEGER NOT NULL,"
        "    quantity INTEGER NOT NULL,"
        "    unit_price REAL NOT NULL,"
        "    total_price REAL NOT NULL,"
        "    customer_name TEXT,"
        "    customer_phone TEXT,"
        "    sale_date DATETIME DEFAULT CURRENT_TIMESTAMP,"
        "    payment_method TEXT,"
        "    FOREIGN KEY (medicine_id) REFERENCES medicines(id) ON DELETE CASCADE"
        ");"
    );

    if (!success) {
        qDebug() << "Error creating sales table:" << query.lastError().text();
        return false;
    }
    qDebug() << "Sales table ready.";

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS stock_movements ("
        "    id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    medicine_id INTEGER NOT NULL,"
        "    quantity_change INTEGER NOT NULL,"
        "    movement_type TEXT,"
        "    previous_quantity INTEGER,"
        "    new_quantity INTEGER,"
        "    notes TEXT,"
        "    movement_date DATETIME DEFAULT CURRENT_TIMESTAMP,"
        "    FOREIGN KEY (medicine_id) REFERENCES medicines(id) ON DELETE CASCADE"
        ");"
    );

    if (!success) {
        qDebug() << "Error creating stock_movements table:" << query.lastError().text();
        return false;
    }
    qDebug() << "Stock movements table ready.";

    success = query.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "    id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    username TEXT UNIQUE NOT NULL,"
        "    password TEXT NOT NULL,"
        "    role TEXT DEFAULT 'Staff',"
        "    pharmacy_name TEXT"
        ");"
    );

    if (!success) {
        qDebug() << "Error creating users table:" << query.lastError().text();
        return false;
    }
    qDebug() << "Users table ready.";

    qDebug() << "All tables ready!";
    return true;
}


QList<Sale> DatabaseManager::getSalesForToday() {
    QList<Sale> sales;
    QSqlQuery query(db);
    query.exec(
        "SELECT s.*, m.name as medicine_name FROM sales s "
        "JOIN medicines m ON s.medicine_id = m.id "
        "WHERE DATE(s.sale_date) = DATE('now') "
        "ORDER BY s.sale_date DESC"
    );

    while (query.next()) {
        Sale sale = recordToSale(query.record());
        sale.medicineName = query.value("medicine_name").toString();
        sales.append(sale);
    }

    return sales;
}

QList<Sale> DatabaseManager::getSalesForLastDays(int days) {
    QList<Sale> sales;
    QSqlQuery query(db);
    query.prepare(
        "SELECT s.*, m.name as medicine_name FROM sales s "
        "JOIN medicines m ON s.medicine_id = m.id "
        "WHERE DATE(s.sale_date) >= DATE('now', ?) "
        "ORDER BY s.sale_date DESC"
    );
    query.addBindValue("-" + QString::number(days) + " days");
    query.exec();

    while (query.next()) {
        Sale sale = recordToSale(query.record());
        sale.medicineName = query.value("medicine_name").toString();
        sales.append(sale);
    }

    return sales;
}

double DatabaseManager::getTotalSalesForToday() {
    QSqlQuery query(db);
    query.exec("SELECT COALESCE(SUM(total_price), 0) as total FROM sales WHERE DATE(sale_date) = DATE('now')");

    if (query.next()) {
        return query.value("total").toDouble();
    }
    return 0.0;
}

int DatabaseManager::getSalesCountForToday() {
    QSqlQuery query(db);
    query.exec("SELECT COUNT(*) as count FROM sales WHERE DATE(sale_date) = DATE('now')");

    if (query.next()) {
        return query.value("count").toInt();
    }
    return 0;
}





bool DatabaseManager::addMedicine(const Medicine& medicine) {
    
    QSqlQuery checkQuery(db);
    checkQuery.prepare("SELECT id, quantity FROM medicines WHERE name = ?");
    checkQuery.addBindValue(medicine.name);

    if (checkQuery.exec() && checkQuery.next()) {
       
        int existingId = checkQuery.value("id").toInt();
        int currentQty = checkQuery.value("quantity").toInt();
        int newQty = currentQty + medicine.quantity;

        QSqlQuery updateQuery(db);
        updateQuery.prepare("UPDATE medicines SET quantity = ? WHERE id = ?");
        updateQuery.addBindValue(newQty);
        updateQuery.addBindValue(existingId);

        if (updateQuery.exec()) {
            qDebug() << "Stock updated! Medicine:" << medicine.name
                << "New quantity:" << newQty;
            return true;
        }
        else {
            qDebug() << "Error updating stock:" << updateQuery.lastError().text();
            return false;
        }
    }
    else {
      
        QSqlQuery insertQuery(db);
        insertQuery.prepare(
            "INSERT INTO medicines (name, formula, batch_number, quantity, price, expiry_date, supplier) "
            "VALUES (?, ?, ?, ?, ?, ?, ?)"
        );
        insertQuery.addBindValue(medicine.name);
        insertQuery.addBindValue(medicine.formula);
        insertQuery.addBindValue(medicine.batchNumber);
        insertQuery.addBindValue(medicine.quantity);
        insertQuery.addBindValue(medicine.price);
        insertQuery.addBindValue(medicine.expiryDate.toString("yyyy-MM-dd"));
        insertQuery.addBindValue(medicine.supplier);

        if (insertQuery.exec()) {
            qDebug() << "New medicine added:" << medicine.name;
            return true;
        }
        else {
            qDebug() << "Error adding medicine:" << insertQuery.lastError().text();
            return false;
        }
    }
}

bool DatabaseManager::updateMedicine(const Medicine& medicine) {
    QSqlQuery query(db);
    query.prepare(
        "UPDATE medicines SET "
        "    name = ?, formula = ?, batch_number = ?, quantity = ?, price = ?, "
        "    expiry_date = ?, supplier = ? "
        "WHERE id = ?"
    );
    query.addBindValue(medicine.name);
    query.addBindValue(medicine.formula);
    query.addBindValue(medicine.batchNumber);
    query.addBindValue(medicine.quantity);
    query.addBindValue(medicine.price);
    query.addBindValue(medicine.expiryDate.toString("yyyy-MM-dd"));
    query.addBindValue(medicine.supplier);
    query.addBindValue(medicine.id);

    if (!query.exec()) {
        qDebug() << "Error updating medicine:" << query.lastError().text();
        return false;
    }

    qDebug() << "Medicine updated:" << medicine.name;
    return true;
}

bool DatabaseManager::deleteMedicine(int id) {
    QSqlQuery query(db);
    query.prepare("DELETE FROM medicines WHERE id = ?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error deleting medicine:" << query.lastError().text();
        return false;
    }

    qDebug() << "Medicine deleted. ID:" << id;
    return true;
}

QList<Medicine> DatabaseManager::getAllMedicines() {
    QList<Medicine> medicines;
    QSqlQuery query(db);
    query.exec("SELECT * FROM medicines ORDER BY name");

    while (query.next()) {
        medicines.append(recordToMedicine(query.record()));
    }

    return medicines;
}

QList<Medicine> DatabaseManager::searchMedicines(const QString& searchText) {
    QList<Medicine> medicines;
    QSqlQuery query(db);
    query.prepare(
        "SELECT * FROM medicines WHERE "
        "name LIKE ? OR "
        "formula LIKE ? OR "
        "batch_number LIKE ? OR "
        "supplier LIKE ?"
    );
    QString searchPattern = "%" + searchText + "%";
    query.addBindValue(searchPattern);
    query.addBindValue(searchPattern);
    query.addBindValue(searchPattern);
    query.addBindValue(searchPattern);
    query.exec();

    while (query.next()) {
        medicines.append(recordToMedicine(query.record()));
    }

    return medicines;
}

QList<Medicine> DatabaseManager::searchByFormula(const QString& formula) {
    QList<Medicine> medicines;
    QSqlQuery query(db);
    query.prepare(
        "SELECT * FROM medicines WHERE formula LIKE ? ORDER BY name"
    );
    query.addBindValue("%" + formula + "%");
    query.exec();

    while (query.next()) {
        medicines.append(recordToMedicine(query.record()));
    }

    return medicines;
}

QList<Medicine> DatabaseManager::getLowStockMedicines(int threshold) {
    QList<Medicine> medicines;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM medicines WHERE quantity <= ? ORDER BY quantity ASC");
    query.addBindValue(threshold);
    query.exec();

    while (query.next()) {
        medicines.append(recordToMedicine(query.record()));
    }

    return medicines;
}

QList<Medicine> DatabaseManager::getExpiringMedicines(int days) {
    QList<Medicine> medicines;
    QSqlQuery query(db);
    query.prepare(
        "SELECT * FROM medicines WHERE expiry_date <= date('now', ?) "
        "ORDER BY expiry_date ASC"
    );
    query.addBindValue("+" + QString::number(days) + " days");
    query.exec();

    while (query.next()) {
        medicines.append(recordToMedicine(query.record()));
    }

    return medicines;
}

Medicine DatabaseManager::getMedicineById(int id) {
    Medicine medicine;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM medicines WHERE id = ?");
    query.addBindValue(id);

    if (query.exec() && query.next()) {
        medicine = recordToMedicine(query.record());
    }

    return medicine;
}

bool DatabaseManager::updateStock(int id, int newQuantity) {
    int oldQuantity = 0;

    QSqlQuery getQuery(db);
    getQuery.prepare("SELECT quantity FROM medicines WHERE id = ?");
    getQuery.addBindValue(id);
    if (getQuery.exec() && getQuery.next()) {
        oldQuantity = getQuery.value(0).toInt();
    }

    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE medicines SET quantity = ? WHERE id = ?");
    updateQuery.addBindValue(newQuantity);
    updateQuery.addBindValue(id);

    if (!updateQuery.exec()) {
        qDebug() << "Error updating stock:" << updateQuery.lastError().text();
        return false;
    }
    int change = newQuantity - oldQuantity;
    addStockMovement(id, change, "ADJUSTMENT", "Stock updated from " + QString::number(oldQuantity) + " to " + QString::number(newQuantity));

    qDebug() << "Stock updated. ID:" << id << "New quantity:" << newQuantity;
    return true;
}

Medicine DatabaseManager::recordToMedicine(const QSqlRecord& record) {
    Medicine medicine;
    medicine.id = record.value("id").toInt();
    medicine.name = record.value("name").toString();
    medicine.formula = record.value("formula").toString();
    medicine.batchNumber = record.value("batch_number").toString();
    medicine.quantity = record.value("quantity").toInt();
    medicine.price = record.value("price").toDouble();
    medicine.expiryDate = record.value("expiry_date").toDate();
    medicine.supplier = record.value("supplier").toString();
    return medicine;
}


bool DatabaseManager::addSale(const Sale& sale) {
    QSqlQuery query(db);
    db.transaction();
    query.prepare(
        "INSERT INTO sales (medicine_id, quantity, unit_price, total_price, customer_name, customer_phone, payment_method) "
        "VALUES (?, ?, ?, ?, ?, ?, ?)"
    );
    query.addBindValue(sale.medicineId);
    query.addBindValue(sale.quantity);
    query.addBindValue(sale.unitPrice);
    query.addBindValue(sale.totalPrice);
    query.addBindValue(sale.customerName);
    query.addBindValue(sale.customerPhone);
    query.addBindValue(sale.paymentMethod);

    if (!query.exec()) {
        db.rollback();
        qDebug() << "Error adding sale:" << query.lastError().text();
        return false;
    }

    // Update stock quantity
    QSqlQuery updateQuery(db);
    updateQuery.prepare("UPDATE medicines SET quantity = quantity - ? WHERE id = ?");
    updateQuery.addBindValue(sale.quantity);
    updateQuery.addBindValue(sale.medicineId);

    if (!updateQuery.exec()) {
        db.rollback();
        qDebug() << "Error updating stock:" << updateQuery.lastError().text();
        return false;
    }

    addStockMovement(sale.medicineId, -sale.quantity, "SALE", "Sold " + QString::number(sale.quantity) + " units");

    db.commit();
    qDebug() << "Sale added successfully!";
    return true;
}

QList<Sale> DatabaseManager::getAllSales() {
    QList<Sale> sales;
    QSqlQuery query(db);
    query.exec(
        "SELECT s.*, m.name as medicine_name FROM sales s "
        "JOIN medicines m ON s.medicine_id = m.id "
        "ORDER BY s.sale_date DESC"
    );

    while (query.next()) {
        Sale sale = recordToSale(query.record());
        sale.medicineName = query.value("medicine_name").toString();
        sales.append(sale);
    }

    return sales;
}

QList<Sale> DatabaseManager::getSalesByDate(const QString& date) {
    QList<Sale> sales;
    QSqlQuery query(db);
    query.prepare(
        "SELECT s.*, m.name as medicine_name FROM sales s "
        "JOIN medicines m ON s.medicine_id = m.id "
        "WHERE DATE(s.sale_date) = ? "
        "ORDER BY s.sale_date DESC"
    );
    query.addBindValue(date);
    query.exec();

    while (query.next()) {
        Sale sale = recordToSale(query.record());
        sale.medicineName = query.value("medicine_name").toString();
        sales.append(sale);
    }

    return sales;
}

QList<Sale> DatabaseManager::getRecentSales(int limit) {
    QList<Sale> sales;
    QSqlQuery query(db);
    query.prepare(
        "SELECT s.*, m.name as medicine_name FROM sales s "
        "JOIN medicines m ON s.medicine_id = m.id "
        "ORDER BY s.sale_date DESC "
        "LIMIT ?"
    );
    query.addBindValue(limit);
    query.exec();

    while (query.next()) {
        Sale sale = recordToSale(query.record());
        sale.medicineName = query.value("medicine_name").toString();
        sales.append(sale);
    }

    return sales;
}

double DatabaseManager::getTotalSales() {
    QSqlQuery query(db);
    query.exec("SELECT COALESCE(SUM(total_price), 0) as total FROM sales");

    if (query.next()) {
        return query.value("total").toDouble();
    }
    return 0.0;
}


Medicine DatabaseManager::getMedicineByName(const QString& name) {
    Medicine medicine;
    QSqlQuery query(db);
    query.prepare("SELECT * FROM medicines WHERE name = ?");
    query.addBindValue(name);

    if (query.exec() && query.next()) {
        medicine = recordToMedicine(query.record());
    }

    return medicine;
}



int DatabaseManager::getTotalSalesCount() {
    QSqlQuery query(db);
    query.exec("SELECT COUNT(*) as count FROM sales");

    if (query.next()) {
        return query.value("count").toInt();
    }
    return 0;
}

Sale DatabaseManager::recordToSale(const QSqlRecord& record) {
    Sale sale;
    sale.id = record.value("id").toInt();
    sale.medicineId = record.value("medicine_id").toInt();
    sale.quantity = record.value("quantity").toInt();
    sale.unitPrice = record.value("unit_price").toDouble();
    sale.totalPrice = record.value("total_price").toDouble();
    sale.customerName = record.value("customer_name").toString();
    sale.customerPhone = record.value("customer_phone").toString();
    sale.saleDate = record.value("sale_date").toString();
    sale.paymentMethod = record.value("payment_method").toString();
    return sale;
}
bool DatabaseManager::addStockMovement(int medicineId, int quantityChange, const QString& movementType, const QString& notes) {
    int previousQuantity = 0;
    int newQuantity = 0;

    QSqlQuery getQuery(db);
    getQuery.prepare("SELECT quantity FROM medicines WHERE id = ?");
    getQuery.addBindValue(medicineId);
    if (getQuery.exec() && getQuery.next()) {
        previousQuantity = getQuery.value(0).toInt();
        newQuantity = previousQuantity + quantityChange;
    }

    QSqlQuery query(db);
    query.prepare(
        "INSERT INTO stock_movements (medicine_id, quantity_change, movement_type, previous_quantity, new_quantity, notes) "
        "VALUES (?, ?, ?, ?, ?, ?)"
    );
    query.addBindValue(medicineId);
    query.addBindValue(quantityChange);
    query.addBindValue(movementType);
    query.addBindValue(previousQuantity);
    query.addBindValue(newQuantity);
    query.addBindValue(notes);

    if (!query.exec()) {
        qDebug() << "Error adding stock movement:" << query.lastError().text();
        return false;
    }

    return true;
}

DatabaseManager::~DatabaseManager() {
    close();
}