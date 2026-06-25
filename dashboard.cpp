#include "dashboard.h"




QuickActions::QuickActions(QWidget* parent):QWidget(parent) {
	setWindowFlags(Qt::FramelessWindowHint);
	setUPUI();
}
MedicineMangement::MedicineMangement(QWidget* parent):QWidget(parent) {
	setWindowFlags(Qt::FramelessWindowHint);
	SetUIE();
}


void QuickActions::addMedicinePage() {
	QWidget* Addme = new QWidget();
	Addme->setAttribute(Qt::WA_DeleteOnClose);
	Addme->setWindowTitle("Add Medicine");
	Addme->setMinimumSize(500, 350);
	QVBoxLayout* Layout = new QVBoxLayout(Addme);
	Layout->addSpacing(0);
	Addme->setStyleSheet(
		"QWidget {"
		"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
		"                                stop: 0 rgba(0, 102, 255, 0.1), stop: 1 rgba(0, 102, 255, 0.02));"
		"    border: 1px solid rgba(0, 102, 255, 0.15);"
		"    border-radius: 8px;"
		"}"
	);
	QLineEdit* NameMedi = new QLineEdit;
	NameMedi->setPlaceholderText("Add Medicine namae");
	NameMedi->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid rgba(0, 102, 255, 0.15);"
		"    border-radius: 8px;"
		"    padding: 8px 12px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border: 2px solid rgba(0, 102, 255, 0.4);"
		"    background-color: white;"
		"}"
		"QLineEdit:hover {"
		"    border: 1px solid rgba(0, 102, 255, 0.25);"
		"    background-color: #FAFAFA;"
		"}"
		"QLineEdit::placeholder {"
		"    color: #ADB5BD;"
		"}"
	);
	Layout->addWidget(NameMedi);

	QLineEdit* Formula = new QLineEdit();
	Formula->setPlaceholderText("Formula of Medicine");
	Formula->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid rgba(0, 102, 255, 0.15);"
		"    border-radius: 8px;"
		"    padding: 8px 12px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border: 2px solid rgba(0, 102, 255, 0.4);"
		"    background-color: white;"
		"}"
		"QLineEdit:hover {"
		"    border: 1px solid rgba(0, 102, 255, 0.25);"
		"    background-color: #FAFAFA;"
		"}"
		"QLineEdit::placeholder {"
		"    color: #ADB5BD;"
		"}");
	Layout->addWidget(Formula);


	QLineEdit* Batchno = new QLineEdit;
	Batchno->setPlaceholderText("Add Medicine Batch No");
	Batchno->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"
	);
	Layout->addWidget(Batchno);


	QLineEdit* Quantity = new QLineEdit;
	Quantity->setPlaceholderText("Add Medicine Quatity");
	Quantity->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"
	);
	Layout->addWidget(Quantity);

	QLineEdit* price = new QLineEdit;
	price->setPlaceholderText("Add Medicine price");
	price->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"
	);
	Layout->addWidget(price);

	QLineEdit* expiryDate = new QLineEdit;
	expiryDate->setPlaceholderText("Add Medicine expiryDate");
	expiryDate->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"
	);
	Layout->addWidget(expiryDate);


	QLineEdit* supplier = new QLineEdit;
	supplier->setPlaceholderText("Add Medicine supplier");
	supplier->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"
	);
	Layout->addWidget(supplier);
	
	QPushButton* Add = new QPushButton("Add Medicine");
	Add->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background: rgb(188, 226, 238);"
		"    border: 2px solid rgba(255, 180, 255, 180);"
		"    border-radius: 10px;"
		"    color: Black;"
		"    padding: 10px;"
		"}"
		"QPushButton:hover {"
		"    background: rgba(255, 180, 255, 50);"
		"    border: 2px solid rgba(255, 180, 255, 255);"
		"    color: #2c3e50;"
		"}"
		"QPushButton:pressed {"
		"    background: rgba(255, 180, 255, 100);"
		"    border: 2px solid rgba(200, 130, 200, 255);"
		"}"
	);
	QObject::connect(Add, &QPushButton::clicked, this, [this, supplier, NameMedi, expiryDate, price, Quantity, Batchno,Formula]() {

		Medicine med;

		med.name = NameMedi->text();
		med.supplier = supplier->text();
		med.expiryDate = QDate::fromString(expiryDate->text(), "yyyy-MM-dd");
		med.price = price->text().toFloat();
		med.quantity = Quantity->text().toInt();
		med.batchNumber = Batchno->text();
		med.formula = Formula->text();

		DatabaseManager& db = DatabaseManager::instance();
		db.initialize();
		db.addMedicine(med);

		supplier->clear();
		NameMedi->clear();
		expiryDate->clear();
		price->clear();
		Quantity->clear();
		Batchno->clear();
		Formula->clear();

		db.close();

		});
	Layout->addWidget(Add);
	Addme->setWindowIcon(QIcon("Icon9.png"));
	Layout->addStretch();
	Addme->show();


}
void QuickActions:: DisPlayResults(const QList<Medicine>& results) {
	QWidget* Display = new QWidget(); 
	Display->setAttribute(Qt::WA_DeleteOnClose);
	Display->setMinimumSize(350,350);
	Display->setStyleSheet(
		"QWidget {"
		"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
		"                                stop: 0 rgba(0, 102, 255, 0.1), stop: 1 rgba(0, 102, 255, 0.02));"
		"    border: 1px solid rgba(0, 102, 255, 0.15);"
		"    border-radius: 8px;"
		"}"
	);
	Display->setWindowTitle("Formula");
	QVBoxLayout* DisplayLayout = new QVBoxLayout(Display);
	
	
	QStringList displaylists;
	for (const Medicine& med : results) {
		displaylists << med.name + "(Stock: " + QString::number(med.quantity) + ")\n";
	}

	QLabel* FomulaLabel = new QLabel(displaylists.join("\n"), Display);
	FomulaLabel->setAlignment(Qt::AlignTop|Qt::AlignLeft);
	DisplayLayout->addWidget(FomulaLabel);

	Display->show();
}





void QuickActions::SearchFormula() {
	QString FormulaS = Formula->text();
	if (FormulaS.isEmpty()) {
		QMessageBox::information(this,"Search", "Enter A formula First ");
		return;
	}
	DatabaseManager& db = DatabaseManager::instance();
	db.initialize();
	QList<Medicine> results;
	results = db.searchByFormula(FormulaS);
	if (!results.isEmpty()) {
		DisPlayResults(results);
	}
	else {
		QMessageBox::information(this,"Not found","Medicine with this Composition Not found \nCheck typo and try again");
	}


}
void QuickActions::SearchBYformula() {
	FormulaWidget = new QWidget(this);
	FormulaWidget->setMinimumSize(350,350);
	QVBoxLayout* FormulaLayout = new QVBoxLayout(FormulaWidget);
	Formula = new QLineEdit(FormulaWidget);
	Formula->setPlaceholderText("Enter Formula");
	Formula->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"
	);
	FormulaLayout->addWidget(Formula);

	QPushButton* SearchButton = new QPushButton;
	SearchButton->setText("Search");
	SearchButton->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background: rgb(188, 226, 238);"
		"    border: 2px solid rgba(255, 180, 255, 180);"
		"    border-radius: 10px;"
		"    color: Black;"
		"    padding: 10px;"
		"}"
		"QPushButton:hover {"
		"    background: rgba(255, 180, 255, 50);"
		"    border: 2px solid rgba(255, 180, 255, 255);"
		"    color: #2c3e50;"
		"}"
		"QPushButton:pressed {"
		"    background: rgba(255, 180, 255, 100);"
		"    border: 2px solid rgba(200, 130, 200, 255);"
		"}"
	);
	FormulaLayout->addWidget(SearchButton);
	SearchPageLayout->addWidget(FormulaWidget);
	FormulaWidget->setVisible(false);
	QObject::connect(SearchButton, &QPushButton::clicked, this, [this]() {SearchFormula();});

}
void QuickActions::SearchName() {
	QString Name = MedName->text();
	if (!Name.isEmpty()) {
		DatabaseManager& db = DatabaseManager::instance();
		db.initialize();
		QList<Medicine> results;
		results = db.searchMedicines(Name);
		DisPlayResults(results);
	}
	else {
		QMessageBox::information(this,"Not found","Medicine Not found");
	}
}
void QuickActions::SearchBYnamee() {

	NameWidget= new QWidget(this);
	NameWidget->setMinimumSize(350,350);
	QVBoxLayout* NameLayout = new QVBoxLayout(NameWidget);
	MedName = new QLineEdit(NameWidget);
	MedName->setPlaceholderText("Medicine name");
	MedName->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"

	);

	NameLayout->addWidget(MedName);


	QPushButton* SearchButton = new QPushButton;
	SearchButton->setText("Search");
	SearchButton->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background: rgb(188, 226, 238);"
		"    border: 2px solid rgba(255, 180, 255, 180);"
		"    border-radius: 10px;"
		"    color: Black;"
		"    padding: 10px;"
		"}"
		"QPushButton:hover {"
		"    background: rgba(255, 180, 255, 50);"
		"    border: 2px solid rgba(255, 180, 255, 255);"
		"    color: #2c3e50;"
		"}"
		"QPushButton:pressed {"
		"    background: rgba(255, 180, 255, 100);"
		"    border: 2px solid rgba(200, 130, 200, 255);"
		"}"
	);
	NameLayout->addWidget(SearchButton);
	SearchPageLayout->addWidget(NameWidget);
	NameWidget->setVisible(false);
	QObject::connect(SearchButton, &QPushButton::clicked, this, [this]() {SearchName();});
	

}
void QuickActions::SearchMedicinee(const QString& Searchby = "Search By Name") {
	if (Searchby == "Search By Formula") {
		SearchBYformula();
		if (NameWidget != nullptr) {
			NameWidget->setVisible(false);
		}
		FormulaWidget->setVisible(true);
	}
	else if (Searchby == "Search By Name") {
		SearchBYnamee();
		if (FormulaWidget != nullptr) {
			FormulaWidget->setVisible(false);
		}
		NameWidget->setVisible(true);
	}
}
void QuickActions::GenerateReport(const QString& Date) {
	loadreport(Date);
}

void QuickActions::searchMedicinePage() {
	SearchPage = new QWidget();
	SearchPage->setWindowTitle("Search Medicine");
	SearchPage->setWindowIcon(QIcon("Icon9.png"));
	SearchPage->setMinimumSize(400,400);
	SearchPage->setStyleSheet(
		"QWidget {"
		"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
		"                                stop: 0 rgba(0, 102, 255, 0.1), stop: 1 rgba(0, 102, 255, 0.02));"
		"    border: 1px solid rgba(0, 102, 255, 0.15);"
		"    border-radius: 8px;"
		"}"
	);
	QComboBox* Choice = new QComboBox(SearchPage);
	Choice->addItem("Search By : ");
	Choice->addItem("Search By Formula");
	Choice->addItem("Search By Name");
	
	QObject::connect(Choice, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this,Choice]() {
		QString Searchby = Choice->currentText();
		SearchMedicinee(Searchby);
		});

	SearchPageLayout = new QVBoxLayout(SearchPage);
	SearchPageLayout->addWidget(Choice);



	SearchPage->show();
}

void QuickActions::SalesReport() {
	QWidget* ReportPage = new QWidget();
	ReportPage->setAttribute(Qt::WA_DeleteOnClose);
	ReportPage->setStyleSheet(
		"QWidget {"
		"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
		"                                stop: 0 rgba(0, 102, 255, 0.1), stop: 1 rgba(0, 102, 255, 0.02));"
		"    border: 1px solid rgba(0, 102, 255, 0.15);"
		"    border-radius: 8px;"
		"}"
	);
	ReportPage->setWindowTitle("Report");
	ReportPage->setWindowIcon(QIcon("Icon9.png"));
	ReportPage->setMinimumSize(700,700);
	QVBoxLayout* Layout = new QVBoxLayout(ReportPage);

	QLabel* Titile = new QLabel("Sales Report", ReportPage);
	Titile->setAlignment(Qt::AlignCenter);
	Titile->setStyleSheet("font-size: 24px; font-weight: bold; color:#FFF8E7;");
	Layout->addWidget(Titile);

	QHBoxLayout* DateLayout = new QHBoxLayout(ReportPage);
	DateLayout->addWidget(new QLabel("Date",ReportPage));

	Box = new QComboBox(ReportPage);
	Box->addItems({"Today","yestarday","Last 7 days","Last 30 days"});

	QObject::connect(Box, QOverload<int>::of(&QComboBox::currentIndexChanged), this,&QuickActions::onDateChanged);
	DateLayout->addWidget(Box);


	GenerateButton = new QPushButton(ReportPage);
	GenerateButton->setText("Generate report");
	GenerateButton->setVisible(true);
	QString CurentText = Box->currentText();
	QObject::connect(GenerateButton, &QPushButton::clicked, this, [this,CurentText]() {GenerateReport(CurentText);});
	
	DateLayout->addWidget(GenerateButton);
	DateLayout->addStretch();

	Layout->addLayout(DateLayout);


	QHBoxLayout* SummaryLayout = new QHBoxLayout();
	SummaryLayout->setSpacing(20);
	
	TotalLabel= new QLabel("TOTAL : ", ReportPage);
	TotalLabel->setStyleSheet("font-size: 16px; font-weight: bold; padding: 1px;  margin: 0px; color: #FFF8E7;");
	SummaryLayout->addWidget(TotalLabel);

	countLabel = new QLabel("transactions: 0",ReportPage);
	countLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: ##FFF8E7;");
	SummaryLayout->addWidget(countLabel);

	SummaryLayout->addStretch();

	Layout->addLayout(SummaryLayout);


	TableWidget = new QTableWidget(ReportPage);
	TableWidget->setColumnCount(6);
	TableWidget->setHorizontalHeaderLabels({"ID","Medicine","QTY","Total","Customer","Date"});
	TableWidget->horizontalHeader();
	TableWidget->setEditTriggers(QTableWidget::NoEditTriggers);
	TableWidget->setSelectionBehavior(QTableWidget::SelectRows);
	TableWidget->setAlternatingRowColors(true);
	TableWidget->setFixedHeight(600);
	Layout->addWidget(TableWidget);
	ReportPage->show();

}

void QuickActions::loadreport(const QString& filter ) {
	DatabaseManager& db = DatabaseManager::instance();
	db.initialize();

	QList<Sale> sales;
	QString title = "";

	if (filter == "Today") {
		sales = db.getSalesForToday();
		title = "Today";
	}
	else if (filter == "yestarday") {
		sales = db.getSalesForLastDays(1);
		title = "Yesterday";
	}
	else if (filter == "Last 7 Days") {
		sales = db.getSalesForLastDays(7);
		title = "Last 7 Days";
	}
	else if (filter == "Last 30 Days") {
		sales = db.getSalesForLastDays(30);
		title = "Last 30 Days";
	}



	TableWidget->setRowCount(sales.count());
	double total = 0.0;

	for (int i = 0; i < sales.count(); i++) {
		const Sale& sale = sales[i];
		TableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(sale.id)));
		TableWidget->setItem(i, 1, new QTableWidgetItem(sale.medicineName));
		TableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(sale.quantity)));
		TableWidget->setItem(i, 3, new QTableWidgetItem("Rupies " + QString::number(sale.totalPrice, 'f', 2)));
		TableWidget->setItem(i, 4, new QTableWidgetItem(sale.customerName.isEmpty() ? "-" : sale.customerName));
		TableWidget->setItem(i, 5, new QTableWidgetItem(sale.saleDate));

		total += sale.totalPrice;
	}


	TotalLabel->setText("Total: rupies " + QString::number(total, 'f', 2));
	countLabel->setText("Transactions: " + QString::number(sales.count()));

	

}
void QuickActions::onDateChanged() {
	QString filter = Box->currentText();
		GenerateButton->setVisible(true);
		loadreport(filter);
}


void QuickActions::SaleManeger() {
	QWidget* Sales = new QWidget();
	Sales->setAttribute(Qt::WA_DeleteOnClose);
	Sales->setMinimumSize(500, 350);
	Sales->setWindowTitle("Sale");
	Sales->setWindowIcon(QIcon("Icon9.png"));
	Sales->setStyleSheet(
		"QWidget {"
		"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
		"                                stop: 0 rgba(0, 102, 255, 0.1), stop: 1 rgba(0, 102, 255, 0.02));"
		"    border: 1px solid rgba(0, 102, 255, 0.15);"
		"    border-radius: 8px;"
		"}"
	);
	QVBoxLayout* Layout = new QVBoxLayout(Sales);

	QLineEdit* Medicinename = new QLineEdit();
	Medicinename->setPlaceholderText("Medicine Name");
	Medicinename->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"
	
	);
	Layout->addWidget(Medicinename);

	QLineEdit* Quantity = new QLineEdit;
	Quantity->setPlaceholderText("Quantity");
	Quantity->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"
	
	);
	Layout->addWidget(Quantity);

	QLineEdit* Custommer = new QLineEdit;
	Custommer->setPlaceholderText("Custommer Name");
	Custommer->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"

	);
	Layout->addWidget(Custommer);
	


	QLineEdit* Payment = new QLineEdit;
	Payment->setPlaceholderText("Cash/card");
	Payment->setStyleSheet(
		"QLineEdit {"
		"    background-color: white;"
		"    border: 1px solid #DEE2E6;"
		"    border-radius: 4px;"
		"    padding: 6px 10px;"
		"    color: #212529;"
		"    font: 10pt 'Segoe UI';"
		"}"
		"QLineEdit:focus {"
		"    border-color: #0066FF;"
		"    outline: none;"
		"}"

	);
	Layout->addWidget(Payment);

	QPushButton* Salee = new QPushButton("Sale");
	Layout->addWidget(Salee);
	QObject::connect(Salee, &QPushButton::clicked, this, [Payment, Quantity, Medicinename, Custommer, Sales,this]() {
		QString Customername = Custommer->text();
		QString PaymentS = Payment->text();
		int quantity = Quantity->text().toInt();
		QString MedicinenameS = Medicinename->text();

		DatabaseManager& db = DatabaseManager::instance();
		db.initialize();
		QList<Medicine> results= db.searchMedicines(MedicinenameS);
	

		if (results.isEmpty()) {
			QMessageBox::warning(Sales, "Error", "Medicine not found Please check the name.");
			return;
		}
		Medicine med = results[0];


		if (med.quantity < quantity) {
			QMessageBox::warning(Sales, "Error",
				"Not enough stock \nAvailable: " + QString::number(med.quantity));
			return;
		}
		Sale sale;
		sale.medicineId = med.id;
		sale.quantity = quantity;
		sale.unitPrice = med.price;
		sale.totalPrice = quantity * med.price;
		sale.customerName = Customername;
		sale.paymentMethod = PaymentS;
		if (db.addSale(sale))
		{
			Payment->clear();
			Custommer->clear();
			Quantity->clear();
			Medicinename->clear();
			db.close();
			
		}
		}
		
	);


	Sales->show();


}


void QuickActions::setUPUI() {
	Layout = new QHBoxLayout(this);
	Layout->setContentsMargins(0, 0, 0, 0);


	QPushButton* SearchMedicine = new QPushButton("Search Medicine",this);
	SearchMedicine->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background-color: #725A7A;"
		"    color: #F8F4FA;"
		"    border: 1px solid #725A7A;"
		"    border-radius: 8px;"
		"    padding: 8px 16px;"
		"    font-weight: 600;"
		"}"
		"QPushButton:hover {"
		"    background-color: #92729B;"
		"    border: 1px solid #C5A7CD;"
		"    color: white;"
		"}"
		"QPushButton:pressed {"
		"    background-color: #5A4761;"
		"    border: 1px solid #4D3C52;"
		"}"
	);
	SearchMedicine->setFixedHeight(200);
	Layout->addWidget(SearchMedicine);
	QObject::connect(SearchMedicine, &QPushButton::clicked, this, [this]() {searchMedicinePage();});


	QPushButton* addmedicine = new QPushButton(" Add Medicine", this);
	addmedicine->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background-color: #725A7A;"
		"    color: #F8F4FA;"
		"    border: 1px solid #725A7A;"
		"    border-radius: 8px;"
		"    padding: 8px 16px;"
		"    font-weight: 600;"
		"}"
		"QPushButton:hover {"
		"    background-color: #92729B;"
		"    border: 1px solid #C5A7CD;"
		"    color: white;"
		"}"
		"QPushButton:pressed {"
		"    background-color: #5A4761;"
		"    border: 1px solid #4D3C52;"
		"}"
	
	);
	addmedicine->setFixedHeight(200);
	Layout->addWidget(addmedicine);

	QObject::connect(addmedicine, &QPushButton::clicked, this, [this]() {
		addMedicinePage();
		});


	QPushButton* saleTrack = new QPushButton("Sale Maneger", this);
	saleTrack->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background-color: #725A7A;"
		"    color: #F8F4FA;"
		"    border: 1px solid #725A7A;"
		"    border-radius: 8px;"
		"    padding: 8px 16px;"
		"    font-weight: 600;"
		"}"
		"QPushButton:hover {"
		"    background-color: #92729B;"
		"    border: 1px solid #C5A7CD;"
		"    color: white;"
		"}"
		"QPushButton:pressed {"
		"    background-color: #5A4761;"
		"    border: 1px solid #4D3C52;"
		"}"
	);
	saleTrack->setFixedHeight(200);
	Layout->addWidget(saleTrack);


	QObject::connect(saleTrack, &QPushButton::clicked, this, [this]() {
		SaleManeger();
		});


	QPushButton* Salesreport = new QPushButton("View Sales report", this);
	Salesreport->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background-color: #725A7A;"
		"    color: #F8F4FA;"
		"    border: 1px solid #725A7A;"
		"    border-radius: 8px;"
		"    padding: 8px 16px;"
		"    font-weight: 600;"
		"}"
		"QPushButton:hover {"
		"    background-color: #92729B;"
		"    border: 1px solid #C5A7CD;"
		"    color: white;"
		"}"
		"QPushButton:pressed {"
		"    background-color: #5A4761;"
		"    border: 1px solid #4D3C52;"
		"}"
	
	);
	Salesreport->setFixedHeight(200);
	QObject::connect(Salesreport, &QPushButton::clicked, this, [this]() {
		SalesReport();
		});
	Layout->addWidget(Salesreport);


}

void  MedicineMangement::ExpiryAlert() {
	QWidget* ExpiryWidg = new QWidget();
	ExpiryWidg->setAttribute(Qt::WA_DeleteOnClose);
	ExpiryWidg->setWindowTitle("Expiry");
	QVBoxLayout* ExpiryLayout = new QVBoxLayout(ExpiryWidg);

	ExpiryTable = new QTableWidget(ExpiryWidg);

	DatabaseManager& db = DatabaseManager::instance();
	db.initialize();

	QList<Medicine> resultsc;
	resultsc = db.getExpiringMedicines();
	db.close();
	ExpiryTable->setColumnCount(2);
	ExpiryTable->setHorizontalHeaderLabels({ "Medicine name","Expiry Date" });
	ExpiryTable->setRowCount(resultsc.count());

	QDate today = QDate::currentDate();
	bool expiringsoon = false;
	int count = 0;
	if (resultsc.isEmpty()) {
		QMessageBox::information(this, "Expiry", "No medicine FOund Expiring in 30 days");
	}
	else {
		for (int i = 0; i < resultsc.count();i++) {
			Medicine& med = resultsc[i];

			int daysleft = today.daysTo(med.expiryDate);

			if (daysleft >= 0 && daysleft <= 30) {
				expiringsoon = true;
				count++;
			}
			ExpiryTable->setItem(i, 0, new QTableWidgetItem(med.name));
			ExpiryTable->setItem(i, 1, new QTableWidgetItem(med.expiryDate.toString()));
			if (daysleft < 0) {
				rowcolor = QColor(220, 38, 38);
			}
			for (int col = 0; col < 2; col++) {
				if (ExpiryTable->item(i, col)) {
					ExpiryTable->item(i, col)->setBackground(rowcolor);
				}
			}
		}
	}
	ExpiryLayout->addWidget(ExpiryTable);
	ExpiryWidg->show();

}

void  MedicineMangement::SetUIE() { 
	LayoutE = new QHBoxLayout(this);
	QPushButton* Expiry = new QPushButton(this);
	Expiry->setText("Near to Expiry");
	Expiry->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background-color: #725A7A;"
		"    color: #F8F4FA;"
		"    border: 1px solid #725A7A;"
		"    border-radius: 8px;"
		"    padding: 8px 16px;"
		"    font-weight: 600;"
		"}"
		"QPushButton:hover {"
		"    background-color: #92729B;"
		"    border: 1px solid #C5A7CD;"
		"    color: white;"
		"}"
		"QPushButton:pressed {"
		"    background-color: #5A4761;"
		"    border: 1px solid #4D3C52;"
		"}"
	);
	LayoutE->addWidget(Expiry);
	Expiry->setFixedHeight(200);
	QObject::connect(Expiry, &QPushButton::clicked, this, [this]() {ExpiryAlert();});

	QPushButton* LowStock = new QPushButton(this);
	LowStock->setText("Low Stock Medicines");
	LowStock->setStyleSheet(
		"QPushButton {"
		"    font-size: 15px;"
		"    background-color: #725A7A;"
		"    color: #F8F4FA;"
		"    border: 1px solid #725A7A;"
		"    border-radius: 8px;"
		"    padding: 8px 16px;"
		"    font-weight: 600;"
		"}"
		"QPushButton:hover {"
		"    background-color: #92729B;"
		"    border: 1px solid #C5A7CD;"
		"    color: white;"
		"}"
		"QPushButton:pressed {"
		"    background-color: #5A4761;"
		"    border: 1px solid #4D3C52;"
		"}"
	);
	LowStock->setFixedHeight(200);
	LayoutE->addWidget(LowStock);
	QObject::connect(LowStock, &QPushButton::clicked, this, [this]() {LowStockAlert();});


}

void  MedicineMangement::LowStockAlert() {
	QWidget* Lowstock = new QWidget();
	Lowstock->setAttribute(Qt::WA_DeleteOnClose);
	Lowstock->setWindowIcon(QIcon("Icon9.png"));
	Lowstock->setWindowTitle("Low stock ");
	QLabel* Title = new QLabel(Lowstock);
	QVBoxLayout* LowstockLayout = new QVBoxLayout(Lowstock);


	Lowstock->setWindowTitle("Low stock");
	Lowstock->setWindowIcon(QIcon("Icon9.png"));
	LowstockLayout->setSpacing(0);
	LowstockLayout->setContentsMargins(10,10,10,10);
	Title->setText("Medicines Less then 10");
	Title->setStyleSheet("font-size: 24px; font-weight: bold; color:#FFF8E7;");
	Title->setAlignment(Qt::AlignCenter);
	LowstockLayout->addWidget(Title);
	Lowstock->setStyleSheet(
		"QWidget {"
		"    background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
		"                                stop: 0 rgba(0, 102, 255, 0.1), stop: 1 rgba(0, 102, 255, 0.02));"
		"    border: 1px solid rgba(0, 102, 255, 0.15);"
		"    border-radius: 8px;"
		"}"
	);
	Lowstock->setMinimumSize(500,500);


	QTableWidget* LowstockTable = new QTableWidget(Lowstock);
	LowstockTable->setColumnCount(1);

	DatabaseManager& db = DatabaseManager::instance();
	db.initialize();

	QList<Medicine> Lowstockmed = db.getLowStockMedicines();
	LowstockTable->setRowCount(Lowstockmed.count());
	if (Lowstockmed.isEmpty()) {
		QLabel* label = new QLabel("No Lowstock Medicine",Lowstock);
		label->setStyleSheet("font-size: 16px; color: #10b981;");
		LowstockLayout->addWidget(label);
	}
	else {
		for (int i = 0; i < Lowstockmed.count();i++) {
			LowstockTable->setItem(i , 0 , new QTableWidgetItem(Lowstockmed[i].name));
		}
	}

	LowstockLayout->addWidget(LowstockTable);
	Lowstock->show();

}

dashboard::dashboard(QWidget* parent):QWidget(parent) {
	Gradient.setStart(0, 0);
	Gradient.setColorAt(0.0, QColor(26, 15, 42));
	Gradient.setColorAt(0.5, QColor(20, 25, 45));
	//Gradient.setColorAt(1.0, QColor(15, 12, 22));


}




void dashboard::addWidgetS() {
	QuickActions* Actions = new QuickActions(this);
	MedicineMangement* medManegment = new  MedicineMangement(this);

	
	MainLayout = new QVBoxLayout(this);
	MainLayout->addWidget(Actions);
	MainLayout->addWidget(medManegment);

	MainLayout->addStretch();


}






void dashboard::paintEvent(QPaintEvent* Event) {
	QPainter painter(this);
	Gradient.setFinalStop(width(), 0);

	painter.setRenderHint(QPainter::Antialiasing);
	painter.fillRect(rect(),Gradient);

}

QuickActions::~QuickActions() {
	delete SearchPage;
	delete FormulaWidget;
	delete NameWidget;
}
dashboard::~dashboard() {



}
MedicineMangement::~MedicineMangement() {}