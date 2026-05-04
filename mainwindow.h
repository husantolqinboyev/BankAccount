#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "account.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);   // nullptr o'rniga 0
    ~MainWindow();

private slots:
    void on_btnOchish_clicked();
    void on_btnDepozit_clicked();
    void on_btnYechish_clicked();
    void on_btnReset_clicked();
    void on_btnOtkazma_clicked();

private:
    Ui::MainWindow *ui;
    Account *account;                  // = nullptr o'rniga konstruktorda 0 beriladi
    Account *account1;                 // Birinchi hisob
    Account *account2;                 // Ikkinchi hisob

    void yangilaKorinish();
    void xabarKorsatish(const QString &xabar, bool muvaffaqiyat);
    void showProgress(const QString &xabar);
    void hideProgress();
};

#endif // MAINWINDOW_H
