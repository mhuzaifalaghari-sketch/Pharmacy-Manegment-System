#ifndef SIGNUP_H
#define SIGNUP_H
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QHBoxLayout>
#include <QSqlDatabase> 
#include <QSqlQuery>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLinearGradient>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>


class SignUpPage : public QWidget {


public:
	QVBoxLayout* LayoutBox;
	QGridLayout* GridLayout;
	QVBoxLayout* LayoutWidget;
	QGroupBox* Box;
	QLinearGradient Gradient ;
	QPen pen;
	SignUpPage(QWidget* parent = nullptr);
	void paintEvent(QPaintEvent* event)override;
	~SignUpPage();


};


class SignUpForm : public SignUpPage {
	Q_OBJECT
signals:
	void SignUpstatus();
public:
	SignUpForm(QWidget* parent = nullptr);
	~SignUpForm();
	
	QLineEdit* SetUsername;
	QLineEdit* SetPassword;
	QLineEdit* ConfirmPassword;
	QLineEdit* Pharmacyname;

	QString usernameS;
	QString PasswordS;
	QString ConfirmPasswordS;
	QString PharmacynameS;

	QPushButton* SignUp;


	QLabel* InvalidCredintials;
	QLabel* DataBaseError;



	void Form();
	void addToFile();
	
};


#endif 

