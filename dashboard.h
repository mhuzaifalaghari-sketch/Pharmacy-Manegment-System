#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <QLinearGradient>
#include <QPushButton>
#include "databasemanager.h"
#include <QMessageBox>
#include <QLineEdit>
#include <QDateEdit>
#include <QIcon>
#include <QDate>
#include <QTableWidget>
#include <QLabel>
#include <QStackedWidget>
#include <QMenuBar>
#include <QSqlDatabase>
#include <QMenu>
#include <QGridLayout>
#include <QSqlError>
#include <QSqlQuery>
#include <QComboBox>
#include <QHBoxLayout>
#include <QPainter>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>


class dashboard : public QWidget
{
public :
	dashboard(QWidget* parent = nullptr);
	~dashboard();

	QWidget* set;


	QLinearGradient Gradient;
	void paintEvent(QPaintEvent*)override;
	void addWidgetS();




	QVBoxLayout* MainLayout; 
	QVBoxLayout* ShowAllLayout;






};
class QuickActions : public QWidget {
public:
	QuickActions(QWidget* parent = nullptr);
	~QuickActions();
	void setUPUI();


	QWidget* NameWidget = nullptr;
	QWidget* FormulaWidget = nullptr;
	QLabel* TotalLabel;
	QWidget* SearchPage;
	QVBoxLayout* SearchPageLayout;
	QLabel* countLabel;
	QTableWidget* TableWidget;
	QHBoxLayout* Layout;
	QPushButton* GenerateButton;
	QLineEdit* Formula;
	QComboBox* Box;
	QLineEdit* MedName;
	QStackedWidget* SearchMedicineStack;




	void loadreport(const QString& filter );
	void GenerateReport(const QString& filter = "Today");
	void onDateChanged();

	void addMedicinePage();
	void SaleManeger();
	void SearchBYnamee();
	void SearchBYformula();
	void SalesReport();
	void DisPlayResults(const QList<Medicine>& Med);
	void searchMedicinePage();
	void SearchMedicinee(const QString& Searchby);
	void SearchFormula();
	void SearchName();
};

class MedicineMangement : public QWidget {
public:
	MedicineMangement(QWidget* parent);
	~MedicineMangement();

	QColor rowcolor;
	QTableWidget* ExpiryTable;
	QWidget* ExpiryAlertWidget = nullptr;
	QHBoxLayout* LayoutE;

	void ExpiryAlert();

	void LowStockAlert();

	void SetUIE();

};






#endif 


