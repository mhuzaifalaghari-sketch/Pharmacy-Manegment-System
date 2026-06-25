#ifndef LOGIN_H
#define LOGIN_H
#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDialog>
#include <QLinearGradient>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>



class LoginForm : public QDialog{
	Q_OBJECT
signals:
	void noAccount();
	void checkLoginsuccesful();

public:
	QLineEdit* username;
	QLineEdit* password;

	QPushButton* login;
	QPushButton* signup;

	QLabel* NOAccoutn;
	QLabel* loginNotsuccesful;

	QVBoxLayout* LayoutForm;

//	bool login = false;

	LoginForm(QWidget* parent = nullptr);
	~LoginForm();

	void checkCredientials();

	


	QString Getusername;
	QString GetPassword;




};

class LoginPage :public QWidget {
	Q_OBJECT
public:
	LoginPage(QWidget* parent = nullptr);
	~LoginPage();

	QLinearGradient Gradient;
	QPen pen;
	QLabel* statustlabel;
	QVBoxLayout* Layout;
	void setSignupsuccesful();
	void paintEvent(QPaintEvent* event)override;


};


#endif

