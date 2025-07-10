#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "contactList.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Ui::MainWindow *ui;
    contactList List;
    string mode;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateList();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_searchButton_clicked();
    void on_okButton_clicked();
    void on_showallButton_clicked();

};
#endif // MAINWINDOW_H
