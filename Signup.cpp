#include "Signup.h"
#include <QSizePolicy>
#include <QMessageBox>
SignUpForm::SignUpForm(QWidget* parent):SignUpPage(parent){
    Form();
}
SignUpPage::SignUpPage(QWidget* parent) :QWidget(parent) {
    LayoutWidget = new QVBoxLayout(this);


    Box = new QGroupBox(this);
    Box->setMinimumSize(400, 500);
    Box->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    Box->setStyleSheet(
        "QGroupBox {"
        "    border: none;"              
        "    background: transparent;"
        "    margin-top: 0px;"
        "}"
    );
    LayoutWidget->addWidget(Box, 0, Qt::AlignCenter);

    LayoutWidget->setAlignment(Qt::AlignVCenter);
   
    
	Gradient.setStart(0,0);
	Gradient.setFinalStop(width(), 0);
	Gradient.setColorAt(0.0, QColor(48, 25, 52));
    Gradient.setColorAt(1, QColor(135, 31, 120));
    
	
}

void SignUpPage::paintEvent(QPaintEvent*E) {
    
	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);

	painter.fillRect(rect(), Gradient);
	painter.setRenderHint(QPainter::Antialiasing);


	QPen pen;
	pen.setColor(QColor(42, 1, 52));
	pen.setWidth(2);
	painter.setPen(pen);

	QPainterPath path;

    path.moveTo(-100, height() * 0.75);
    path.cubicTo(
        width() * 0.20, height() * 0.10,
        width() * 0.45, height() * 1.00,
        width() * 0.90, height() * 0.45);
    painter.drawPath(path);

    path.moveTo(-50, height() * 0.85);
    path.cubicTo(
        width() * 0.25, height() * 0.20,
        width() * 0.55, height() * 1.10,
        width() * 1.10, height() * 0.60);
    painter.drawPath(path);

    path.moveTo(width() * 0.05, height());
    path.cubicTo(
        width() * 0.35, height() * 0.40,
        width() * 0.65, height() * 1.20,
        width(), height() * 0.70);
    painter.drawPath(path);


    path.moveTo(width() * 0.05, height());
    path.cubicTo(
        width() * 0.40, height() * 0.50,
        width() * 0.75, height() * 1.10,
        width(), height() * 0.85);
	painter.drawPath(path);
}


void SignUpForm::addToFile() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Signup.db");

    if (!db.open()) {
        DataBaseError = new QLabel("Unable to load Database", Box);
        DataBaseError->setStyleSheet(
            "QLabel {"
            "    background-color: rgba(255, 0, 0, 50);"
            "    border: 2px solid rgba(255, 0, 0, 100);"
            "    border-radius: 15px;"
            "    padding: 10px;"
            "    color: #FF0000;"
            "    font-weight: bold;"
            "}"
        );
        GridLayout->addWidget(DataBaseError, 6, 0);
        return;  
    }

    QSqlQuery createQuery;
    createQuery.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "    id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "    username TEXT UNIQUE NOT NULL,"
        "    password TEXT NOT NULL,"
        "    pharmacyname TEXT"  
        ");"
    );
    if (usernameS.isEmpty() || PasswordS.isEmpty()) {
        QMessageBox::information(this,"Error","Empty Fiids");
        return;
    }
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM users WHERE username = ?");
    checkQuery.addBindValue(usernameS);

    if (checkQuery.exec() && checkQuery.next()) {
        int count = checkQuery.value(0).toInt();

        if (count > 0) {
            QMessageBox::warning(this, "Signup Failed",
                "an Account with the usernamee '" + usernameS + "' Already exists\n\n"
                "please choose a different usernaame.");
            db.close();
            return;
        }
    }
    QSqlQuery insertQuery; 
    insertQuery.prepare("INSERT INTO users (username, password, pharmacyname) VALUES (?, ?, ?)");
    insertQuery.addBindValue(usernameS);
    insertQuery.addBindValue(PasswordS);
    insertQuery.addBindValue(PharmacynameS);
    if (insertQuery.exec()) {
        emit SignUpstatus();
    }

 }




void SignUpForm::Form(){    
    LayoutBox = new QVBoxLayout(Box);
    GridLayout = new QGridLayout();
    LayoutBox->addLayout(GridLayout);



    InvalidCredintials = new QLabel("Invalid credintials",Box);
    InvalidCredintials->setStyleSheet(
        "QLabel {"
        "    background-color: rgba(255, 255, 255, 0);"
        "    border: 2px solid rgba(255, 0, 0, 100);"
        "    border-radius: 15px;"
        "    color: #FF0000;"
        "    font-weight: bold;"
        "}"
    );
    InvalidCredintials->setVisible(false);
    LayoutBox->addWidget(InvalidCredintials);
    GridLayout->addWidget(InvalidCredintials, 6, 0);






    GridLayout->setVerticalSpacing(15);
    GridLayout->setAlignment(Qt::AlignCenter);
    GridLayout->setHorizontalSpacing(20);
    GridLayout->setColumnStretch(0, 1);

    QFont font("Ariel");

    QLabel* Title = new QLabel("S I G N   U P",Box);
    Title->setFont(font);
    Title->setStyleSheet(
        "QLabel {"
        "   font-size: 40px;"
        "   font-weight: bold;"
        "   color: #D7A0C0;"
        "   padding: 10px;"
        "}"
    );
    Title->setAlignment(Qt::AlignCenter);

    GridLayout->addWidget(Title, 0, 0, 1, 2);




  


    SetUsername = new QLineEdit(Box);
    SetUsername->setStyleSheet(
        "QLineEdit {"
        "    background: rgba(255, 255, 255, 25);"
        "    border: 1px solid rgba(255, 255, 255, 80);"
        "    border-radius: 15px;"
        "    padding: 12px;"
        "    color: #2c3e50;"        
        "    font-size: 15px;"      
        "    font-weight: Bold;"
        "}"
        "QLineEdit::placeholder {"
        "    color: rgba(44, 62, 80, 100);"  
        "}"
        "QLineEdit:focus {"
        "    border: 2px solid rgb(0,0, 230);"
        "}"
    );
    SetUsername->setPlaceholderText("Username");
    SetUsername->setAlignment(Qt::AlignHCenter);
    
    GridLayout->addWidget(SetUsername,1,0);

    SetPassword = new QLineEdit(Box);
    SetPassword->setPlaceholderText("Password");
    SetPassword->setEchoMode(QLineEdit::Password);
    SetPassword->setAlignment(Qt::AlignCenter);
    SetPassword->setStyleSheet(
        "QLineEdit {"
        "    background: rgba(255, 255, 255, 25);"
        "    border: 1px solid rgba(255, 255, 255, 80);"
        "    border-radius: 15px;"
        "    padding: 12px;"
        "    color: #2c3e50;"
        "    font-size: 15px;"
        "    font-weight: Bold;"
        "}"
        "QLineEdit::placeholder {"
        "    color: rgba(44, 62, 80, 100);"
        "}"
        "QLineEdit:focus {"
        "    border: 2px solid rgb(0,0, 230);"
        "}"
    );




    ConfirmPassword = new QLineEdit(Box);
    ConfirmPassword->setStyleSheet(
        "QLineEdit {"
        "    background: rgba(255, 255, 255, 25);"
        "    border: 1px solid rgba(255, 255, 255, 80);"
        "    border-radius: 15px;"
        "    padding: 12px;"
        "    color: #2c3e50;"
        "    font-size: 15px;"
        "    font-weight: Bold;"
        "}"
        "QLineEdit::placeholder {"
        "    color: rgba(44, 62, 80, 100);"
        "}"
        "QLineEdit:focus {"
        "    border: 2px solid rgb(0,0, 230);"
        "}"

    );
    ConfirmPassword->setPlaceholderText("Confirm Password");
    ConfirmPassword->setAlignment(Qt::AlignCenter);
    ConfirmPassword->setEchoMode(QLineEdit::Password);


    


    GridLayout->addWidget(SetPassword,2,0);
    GridLayout->addWidget(ConfirmPassword,3,0);
    

    Pharmacyname = new QLineEdit(Box);
    Pharmacyname->setPlaceholderText("Pharmace name");
    Pharmacyname->setStyleSheet(
        "QLineEdit {"
        "    background: rgba(255, 255, 255, 25);"
        "    border: 1px solid rgba(255, 255, 255, 80);"
        "    border-radius: 15px;"
        "    padding: 12px;"
        "    color: #2c3e50;"
        "    font-size: 15px;"
        "    font-weight: Bold;"
        "}"
        "QLineEdit::placeholder {"
        "    color: rgba(255, 255, 255, 140);"
        "}"
        "QLineEdit:focus {" 
        "    border: 2px solid rgb(0,0, 230);"
        "}"

    );
    Pharmacyname->setAlignment(Qt::AlignCenter);
    GridLayout->addWidget(Pharmacyname, 4, 0);

    SignUp = new QPushButton("Sign up", Box);
    SignUp->setStyleSheet(
        "QPushButton {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "        stop:0 #8b1a7a,"
        "        stop:1 #6b1a5a);"
        "    color: #D7A0C0;"
        "    border-radius: 15px;"
        "    padding: 15px;"
        "    font-size: 18px;"
        "    font-weight: bold;"
        "    font-family: Segoe UI;"
        "}"
        "QPushButton:hover {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "        stop:0 #a0208a,"
        "        stop:1 #7b206a);"
        "}"
        "QPushButton:pressed {"
        "    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,"
        "        stop:0 #6b1a5a,"
        "        stop:1 #4a1040);"
        "}"
    );
    GridLayout->addWidget(SignUp,5,0);
   
  

    QObject::connect(SignUp, &QPushButton::clicked,this,[this](){

        usernameS = SetUsername->text();
        PasswordS = SetPassword->text();
        ConfirmPasswordS = ConfirmPassword->text();
        PharmacynameS = Pharmacyname->text();
        if (ConfirmPasswordS != PasswordS) {
            InvalidCredintials->setVisible(true);
        }
        else if (ConfirmPasswordS == PasswordS) {
           LayoutBox->removeWidget(InvalidCredintials);
           InvalidCredintials->setVisible(false);
            addToFile();
        }
        
        });

    



  

    
}
SignUpPage::~SignUpPage() {

}
SignUpForm::~SignUpForm() {

}