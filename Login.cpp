#include "Login.h"
#include <QPainter>
#include <QVBoxLayout>
#include <QMessageBox>
LoginPage::LoginPage(QWidget* parent) : QWidget(parent) {
    Gradient.setStart(0,0);
    Gradient.setFinalStop(width(), 0);
    Gradient.setColorAt(0.0, QColor(180, 90, 255));
    Gradient.setColorAt(1.0, QColor(100, 70, 180));
    Gradient.setColorAt(2.0, QColor(15, 20, 80));
    pen.setColor(QColor(255, 180, 255, 180));
    pen.setWidth(2);
    Layout = new QVBoxLayout(this);
    statustlabel = new QLabel(this);
    statustlabel->setStyleSheet(
        "QLabel {"
        "    color: rgba(255, 180, 255, 180);"
        "    font-size: 18px;"
        "    font-weight: bold;"
        "    background: transparent;"
        "}"
    );
    statustlabel->setAlignment(Qt::AlignCenter);
    statustlabel->setVisible(false);
    Layout->addWidget(statustlabel);

    setWindowTitle("Login Page");
}




void LoginPage::paintEvent(QPaintEvent* event){ 
	QPainter painter(this); 
    QPainterPath Paint;
    painter.setRenderHint(QPainter::Antialiasing); 
    Paint.moveTo(0, 0);
	painter.fillRect(rect(),Gradient);
    painter.setPen(pen);


    Paint.moveTo(-100, height() * 0.75);
    Paint.cubicTo(
        width() * 0.20, height() * 0.10,
        width() * 0.45, height() * 1.00,
        width() * 0.90, height() * 0.45);
    painter.drawPath(Paint);

    Paint.moveTo(-50, height() * 0.85);
    Paint.cubicTo(
        width() * 0.25, height() * 0.20,
        width() * 0.55, height() * 1.10,
        width() * 1.10, height() * 0.60);
    painter.drawPath(Paint);

    Paint.moveTo(width() * 0.05, height());
    Paint.cubicTo(
        width() * 0.35, height() * 0.40,
        width() * 0.65, height() * 1.20,
        width(), height() * 0.70);
    painter.drawPath(Paint);


    Paint.moveTo(width() * 0.05, height());
    Paint.cubicTo(
        width() * 0.40, height() * 0.50,
        width() * 0.75, height() * 1.10,
        width(), height() * 0.85);
    painter.drawPath(Paint);
    
    QFont font("Arial", 40, QFont::Bold);
    painter.setFont(font);
    painter.drawText(width()*1/20, height()*1/3, "MedStock Pro");


    QFont subFont("Arial", 10);
    painter.setFont(subFont);
    painter.drawText(width() * 1 / 20, (height() * 1 / 3) + 50, "A Pharmacy maneger");
}

void LoginForm::checkCredientials() {
    Getusername = username->text();
    GetPassword = password->text();

    if (loginNotsuccesful) {
        LayoutForm->removeWidget(loginNotsuccesful);
        delete loginNotsuccesful;
        loginNotsuccesful = nullptr;
    }
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Signup.db");
    if (!db.open()) {
     
        return;
    }


    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(Getusername);
    query.addBindValue(GetPassword);

    if (query.exec() && query.next()) {
        
        QString foundUsername = query.value("username").toString();
        QString foundPassword = query.value("password").toString();
        QString pharmacy = query.value("pharmacyname").toString();

        emit checkLoginsuccesful();

        db.close();
    
    }
    else {
        loginNotsuccesful = new QLabel("Account not found", this);
        LayoutForm->addWidget(loginNotsuccesful);
    }



}



LoginForm::LoginForm(QWidget* parent) : QDialog(parent) {
    loginNotsuccesful = nullptr;
    setAutoFillBackground(false);
    setMinimumSize(300, 450);
    setStyleSheet(
        "QWidget {"
        "   background: rgba(40, 20, 80, 0.6);" 
        "   border-radius: 20px;"
        "   border: 1px solid rgba(255, 255, 255, 0.3);"
        "}"
      
        "QLabel { background: transparent; }"
        "QLineEdit { background: rgba(255, 255, 255, 0.15); }" 
    );

    setMaximumSize(900, 900);







    LayoutForm = new QVBoxLayout(this);
    LayoutForm->setSpacing(0);
    LayoutForm->setContentsMargins(10, 10, 10, 10);

    

    QLabel* TitleLabel = new QLabel("LOGIN");
    QFont TitleFont("monospace");
    TitleFont.setBold(true);
    TitleFont.setItalic(true);
  
    TitleLabel->setStyleSheet(
        "QLabel {"
        "   font-size: 40px;"
        "background: transparent;"
        "   border: none;"
        "   color: #2c3e50;"
        "   padding: 10px;"
        "}"
    );
    TitleLabel->setAlignment(Qt::AlignCenter);
    LayoutForm->addWidget(TitleLabel);
    
    QLabel* passwordl = new QLabel("Enter Password");
    passwordl->setStyleSheet(
        "QLabel {"
        "   font-size: 20px;"
        "   font-weight: bold;"
        "background: transparent;"
        "   border: none;"
        "   color: #2c3e50;"
        "   padding: 10px;"
        "}"
    );
    passwordl->setAlignment(Qt::AlignLeft);
    LayoutForm->addWidget(passwordl);

    password = new QLineEdit;
    password->setPlaceholderText("Password");
    password->setEchoMode(QLineEdit::Password);
    password->setStyleSheet(
        "QLineEdit {"
        "    background: rgba(255, 255, 255, 25);"
        "    border: 1px solid rgba(255, 255, 255, 80);"
        "    border-radius: 15px;"
        "    padding: 12px;"
        "    color: white;"
        "    font-size: 15px;"
        "}"
        "QLineEdit::placeholder {"
        "    color: rgba(255, 255, 255, 140);"
        "}"
        "QLineEdit:focus {"
        "    border: 2px solid rgb(220, 120, 255);"
        "}"
    );
    LayoutForm->addWidget(password);
    QLabel* usernameL = new QLabel("Username ");
    usernameL->setStyleSheet(
        "QLabel {"
        "   font-size: 20px;"
        "   font-weight: bold;"
        "   color: #2c3e50;"
        "background: transparent;"
        "   border: none;"
        "   padding: 10px;"
        "}"
    );
    usernameL->setAlignment(Qt::AlignLeft);
    LayoutForm->addWidget(usernameL);
    

    username = new QLineEdit;
    username->setPlaceholderText("username");
    username->setStyleSheet(
        "QLineEdit {"
        "    background: rgba(255, 255, 255, 25);"
        "    border: 1px solid rgba(255, 255, 255, 80);"
        "    border-radius: 15px;"
        "    padding: 12px;"
        "    color: white;"
        "    font-size: 15px;"
        "}"
        "QLineEdit::placeholder {"
        "    color: rgba(255, 255, 255, 140);"
        "}"
        "QLineEdit:focus {"
        "    border: 2px solid rgb(220, 120, 255);"
        "}"
    );
    move(width()*2.5 , height()*0.2);
    LayoutForm->addWidget(username);
    QPushButton* Login = new QPushButton;
    Login->setText("Login");
    Login->setStyleSheet(
        "QPushButton {"
        "    font-size: 15px;"
        "    background: transparent;"
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
    LayoutForm->addWidget(Login);

    QObject::connect(Login, &QPushButton::clicked, this, [this]() {
        checkCredientials();
        });


    Getusername = username->text();
    GetPassword = password->text();


    NOAccoutn = new QLabel("Dont have an account ?");
    NOAccoutn->setStyleSheet(
        "QLabel {"
        "   font-size: 15px;"
        "background: transparent;"
        "   border: none;"
        "   color: #2c3e50;"
        "   padding: 10px;"
        "}"
    
    );
    LayoutForm->addWidget(NOAccoutn);
    signup = new QPushButton;
    signup->setText("Sign up");
    signup->setStyleSheet(
        "QPushButton {"
        "    font-size: 15px;"
        "    background: transparent;"
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
    QObject::connect(signup, &QPushButton::clicked, this, [this]() {
        emit noAccount();
        });
    LayoutForm->addWidget(signup);




}

void LoginPage::setSignupsuccesful() {
    statustlabel->setText("Sign Up succesfull\n Login to continue");
    statustlabel->setVisible(true);
    statustlabel->setStyleSheet(
        "QLabel {"
        "    color: rgba(255, 180, 255, 180);"
        "    font-size: 18px;"
        "    font-weight: bold;"
        "    background: transparent;"
        "}"
    );
   statustlabel->setAlignment(Qt::AlignHCenter);
   Layout->addWidget(statustlabel);
}
LoginPage::~LoginPage() {

}
LoginForm:: ~LoginForm() {

}