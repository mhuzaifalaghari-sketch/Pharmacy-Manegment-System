#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QString>
#include <QDate>
#include <QList>
#include <QVariant>

struct Medicine {
    int id;
    QString name;
    QString formula;        
    QString batchNumber;
    int quantity;
    double price;
    QDate expiryDate;
    QString supplier;
};

struct Sale {
    int id;
    int medicineId;
    int quantity;
    double unitPrice;
    double totalPrice;
    QString customerName;
    QString customerPhone;
    QString saleDate;
    QString paymentMethod;
    QString medicineName;
};

class DatabaseManager {
public:
    static DatabaseManager& instance();
    bool initialize();
    void close();

    bool addMedicine(const Medicine& medicine);
    bool updateMedicine(const Medicine& medicine);
    bool deleteMedicine(int id);
    QList<Medicine> getAllMedicines();
    QList<Medicine> searchMedicines(const QString& searchText);
    QList<Medicine> searchByFormula(const QString& formula); 
    QList<Medicine> getLowStockMedicines(int threshold = 10);
    QList<Medicine> getExpiringMedicines(int days = 30);
    Medicine getMedicineById(int id);
    bool updateStock(int id, int newQuantity);

    bool addSale(const Sale& sale);
    QList<Sale> getAllSales();
    QList<Sale> getSalesByDate(const QString& date);
    double getTotalSales();
    QList<Sale> getSalesForToday();
    QList<Sale> getSalesForLastDays(int days);
    double getTotalSalesForToday();
    int getSalesCountForToday();
    int getTotalSalesCount();
    QList<Sale> getRecentSales(int limit = 10);

    
    bool addStockMovement(int medicineId, int quantityChange, const QString& movementType, const QString& notes);

private:
    DatabaseManager() = default;
    ~DatabaseManager();
    DatabaseManager(const DatabaseManager&) = delete;
    DatabaseManager& operator=(const DatabaseManager&) = delete;

    QSqlDatabase db;
    bool createTables();
    Medicine recordToMedicine(const QSqlRecord& record);
    Sale recordToSale(const QSqlRecord& record);
   
    Medicine getMedicineByName(const QString& name);

    
};

#endif 