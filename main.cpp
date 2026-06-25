
#include <iostream>
#include <QMainWindow>
#include <QWidget>
#include <QDockWidget>
#include <QApplication>
#include <QDebug>
#include <QIcon>
#include "Signup.h"
#include "Login.h"
#include "dashboard.h"
#include <QStackedWidget>
int main(int argc , char* argv[]) {


	QApplication app(argc, argv);


	QMainWindow* window = new QMainWindow;
	window->setMinimumSize(500,500);
	window->showMaximized();
	window->setWindowTitle("MedStock pro");
	window->setWindowIcon(QIcon("Icon9.png"));

	QStackedWidget *widget = new QStackedWidget(window);
	window->setCentralWidget(widget);



	LoginPage *login = new LoginPage;
	widget->addWidget(login);
	LoginForm *Form = new LoginForm(window);
	Form->setWindowFlags(Qt::FramelessWindowHint);
	Form->setAttribute(Qt::WA_TranslucentBackground);
	Form->setAutoFillBackground(false);
	Form->show();
	Form->setAutoFillBackground(false);
	SignUpForm* page = new SignUpForm;
	widget->addWidget(page);
	dashboard* board = new dashboard(window);
	widget->addWidget(board);
	widget->setCurrentIndex(0);


	
	QObject::connect(Form, &LoginForm::noAccount, widget, [widget, Form, page]() {
		widget->setCurrentIndex(1);
		Form->hide();
		});

	QObject::connect(page, &SignUpForm::SignUpstatus, widget, [widget,Form,login]() {
		login->setSignupsuccesful();
		widget->setCurrentIndex(0);
		Form->show();
		});


	QObject::connect(Form, &LoginForm::checkLoginsuccesful, widget, [widget, board,Form,window]() {
		board->addWidgetS();
		widget->setCurrentIndex(2);
		Form->hide();
		});


	window->show();



	return app.exec();
}