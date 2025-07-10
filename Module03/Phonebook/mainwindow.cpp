#include "mainwindow.h"
#include "contact.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked() {
    mode = "Add";
    ui->label->setText("Add Contact");

    ui->nameInput->clear();
    ui->numInput->clear();
    ui->emailInput->clear();

    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow:: on_removeButton_clicked() {
    mode = "Remove";
    ui->label->setText("Remove Contact");

    ui->nameInput->clear();
    ui->numInput->clear();
    ui->emailInput->clear();

    ui->stackedWidget->setCurrentIndex(3);
}
void MainWindow::on_searchButton_clicked() {
    mode = "Search";
    ui->label->setText("Search Contact");

    ui->nameInput->clear();
    ui->numInput->clear();
    ui->emailInput->clear();

    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_okButton_clicked() {
    QString qstr_name = ui->nameInput->text();
    QString qstr_number = ui->numInput->text();
    QString qstr_email = ui->emailInput->text();

    string name = qstr_name.toStdString();
    string number = qstr_number.toStdString();
    string email = qstr_email.toStdString();
    //다시 C++언어에 맞게 문법변경

    //input validity check(관문)
    Contact validator(name, number, email);
    if (!validator.setName(name)) {
        ui->contactList->clear();
        string nameError = "Invalid name input";
        QString itemText = QString::fromStdString(nameError);

        ui->contactList->addItem(itemText);
        ui->stackedWidget->setCurrentIndex(2);
        return;
    }
    if (!validator.setPhoneNumber(number)) {
        ui->contactList->clear();
        string numError = "Invalid number input";
        QString itemText = QString::fromStdString(numError);

        ui->contactList->addItem(itemText);
        ui->stackedWidget->setCurrentIndex(2);
        return;
    }
    if (!validator.setEmailAddress(email)) {
        ui->contactList->clear();
        string emailError = "Invalid email input";
        QString itemText = QString::fromStdString(emailError);

        ui->contactList->addItem(itemText);
        ui->stackedWidget->setCurrentIndex(2);
        return;
    }

    //데이터처리
    if (mode == "Add") {
        //validity check
        if (qstr_name.isEmpty() || qstr_number.isEmpty()) {  //name and number is mandatory
            return;
        }
        //prevention of phone number duplication
        Contact* c = List.search("No need", number, "No need");
        if (c) {
            ui->contactList->clear();
            string addError = "There's already same number";
            QString itemText = QString::fromStdString(addError);

            ui->contactList->addItem(itemText);
        }
        //new number add
        else {
            Contact newContact(name, number, email); //Contact constructor operate

            List.add(newContact);
            //to show added contact with update
            updateList();
        }

    }
    else if (mode == "Search") {
        //validity check
        if (qstr_name.isEmpty() && qstr_number.isEmpty() && qstr_email.isEmpty()) {  //at least one input is mandatory
            return;
        }
        Contact* c = List.search(name, number, email);
        ui->contactList->clear();
        if (c) {
            string contactInfo = c->getName() + "  |  " + c->getPhoneNum() + "  |  " + c->getEmail();
            //convert C++string into Qt qstring
            QString itemText = QString::fromStdString(contactInfo);

            ui->contactList->addItem(itemText);
        }
        else {
            string error = "There's no Contact with that name";
            QString itemText = QString::fromStdString(error);

            ui->contactList->addItem(itemText);
        }
    }
    else if (mode == "Remove") {
        //validity check
        if (qstr_name.isEmpty() && qstr_number.isEmpty()) { //name is mandatory
            return;
        }

        List.remove(name, number);
        updateList();
    }

    ui->stackedWidget->setCurrentIndex(2);
}
void MainWindow::on_showallButton_clicked() {
    updateList();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::updateList() {
    ui->contactList->clear();

    for(const Contact& c : List.getContacts()) {
        string contactInfo = c.getName() + "  |  " + c.getPhoneNum() + "  |  " + c.getEmail();
        //convert C++string into Qt qstring
        QString  itemText = QString::fromStdString(contactInfo);

        //add converted QString on the window
        ui->contactList->addItem(itemText);
    }
}
