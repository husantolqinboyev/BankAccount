#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , account(0)               // nullptr o'rniga 0
    , account1(0)
    , account2(0)
{
    ui->setupUi(this);
    setWindowTitle("Cyber Bank - Zamonaviy Bank Tizimi");

    ui->grpAmallar->setEnabled(false);
    ui->lblHolat->setText("Yangi hisob ochish uchun ma'lumot kiriting.");
    ui->lblBalans->setText("Balans: -- so'm");
    ui->lblEgasi->setText("Egasi: --");
    
    // Ism maydoni bo'sh bo'lganda tugmani o'chirib qo'yish
    ui->btnOchish->setEnabled(false);
    
    // Ism maydoni o'zgarganda tekshirish
    connect(ui->leIsm, &QLineEdit::textChanged, this, [this](const QString &text) {
        ui->btnOchish->setEnabled(!text.trimmed().isEmpty());
    });
}

MainWindow::~MainWindow() {
    delete ui;
    delete account;
    delete account1;
    delete account2;
}

void MainWindow::on_btnOchish_clicked() {
    QString ism = ui->leIsm->text().trimmed();
    int boshlangichBalans = ui->spnBalans->value();

    if (ism.isEmpty()) {
        xabarKorsatish("Iltimos, hisob egasining ismini kiriting!", false);
        return;
    }

    delete account;
    delete account1;
    delete account2;
    
    account = new Account(ism.toStdString(), boshlangichBalans);
    account1 = new Account(ism.toStdString() + " (Hisob 1)", boshlangichBalans / 2);
    account2 = new Account(ism.toStdString() + " (Hisob 2)", boshlangichBalans / 2);

    ui->grpAmallar->setEnabled(true);
    yangilaKorinish();

    xabarKorsatish(
        QString("Hisoblar muvaffaqiyatli ochildi!\nAsosiy hisob: %1 (%2 so'm)\nHisob 1: %3 (%4 so'm)\nHisob 2: %5 (%6 so'm)")
            .arg(ism).arg(account->getBalance())
            .arg(QString::fromStdString(account1->getName())).arg(account1->getBalance())
            .arg(QString::fromStdString(account2->getName())).arg(account2->getBalance()),
        true
    );
}

void MainWindow::on_btnDepozit_clicked() {
    if (!account) return;

    int summa = ui->spnSumma->value();
    
    // Progress ko'rsatish
    showProgress("Depozit amalga oshirilmoqda...");
    
    // Simulyatsiya uchun vaqtinchalik kechikish
    QTimer::singleShot(1000, [this, summa]() {
        bool ok = account->deposit(summa);
        
        if (ok) {
            ui->progressBar->setValue(100);
            xabarKorsatish(QString("✅ Depozit muvaffaqiyatli amalga oshirildi! +%1 so'm").arg(summa), true);
        } else {
            xabarKorsatish("❌ Depozit rad etildi! Manfiy yoki nol summa qabul qilinmaydi.", false);
        }
        
        yangilaKorinish();
        hideProgress();
    });
}

void MainWindow::on_btnYechish_clicked() {
    if (!account) return;

    int summa = ui->spnSumma->value();
    
    // Progress ko'rsatish
    showProgress("Pul yechib olinmoqda...");
    
    // Simulyatsiya uchun vaqtinchalik kechikish
    QTimer::singleShot(1200, [this, summa]() {
        bool ok = account->withdraw(summa);
        
        if (ok) {
            ui->progressBar->setValue(100);
            xabarKorsatish(QString("✅ Mablag' muvaffaqiyatli yechib olindi! -%1 so'm").arg(summa), true);
        } else {
            xabarKorsatish(
                QString("❌ Yetarli mablag' yo'q!\nBalans: %1 so'm | So'ralgan: %2 so'm")
                    .arg(account->getBalance()).arg(summa),
                false
            );
        }
        
        yangilaKorinish();
        hideProgress();
    });
}

void MainWindow::on_btnReset_clicked() {
    if (!account) return;

    QMessageBox::StandardButton javob = QMessageBox::question(
        this, "Tasdiqlash",
        "Hisobni nolga qaytarmoqchimisiz?",
        QMessageBox::Yes | QMessageBox::No
    );

    if (javob == QMessageBox::Yes) {
        account->reset();
        yangilaKorinish();
        xabarKorsatish("Hisob nolga qaytarildi.", true);
    }
}

void MainWindow::on_btnOtkazma_clicked() {
    if (!account1 || !account2) {
        xabarKorsatish("Avval hisoblarni oching!", false);
        return;
    }

    int summa = ui->spnSumma->value();
    
    if (summa <= 0) {
        xabarKorsatish("❌ Manfiy yoki nol summa kiritilgani uchun o'tkazma rad etildi!", false);
        return;
    }

    if (account1->getBalance() < summa) {
        xabarKorsatish(
            QString("❌ Hisob 1 da yetarli mablag' yo'q!\nHisob 1 balansi: %1 so'm | So'ralgan: %2 so'm")
                .arg(account1->getBalance()).arg(summa),
            false
        );
        return;
    }

    // Progress ko'rsatish
    showProgress("Hisobdan hisobga o'tkazma amalga oshirilmoqda...");
    
    // Simulyatsiya uchun vaqtinchalik kechikish
    QTimer::singleShot(1500, [this, summa]() {
        // O'tkazma amalga oshirish
        bool yechildi = account1->withdraw(summa);
        bool qoshildi = account2->deposit(summa);

        if (yechildi && qoshildi) {
            ui->progressBar->setValue(100);
            xabarKorsatish(
                QString("✅ O'tkazma muvaffaqiyatli amalga oshirildi!\n%1 → %2 ga %3 so'm o'tkazildi\n\nHisob 1 balansi: %4 so'm\nHisob 2 balansi: %5 so'm")
                    .arg(QString::fromStdString(account1->getName()))
                    .arg(QString::fromStdString(account2->getName()))
                    .arg(summa)
                    .arg(account1->getBalance())
                    .arg(account2->getBalance()),
                true
            );
        } else {
            xabarKorsatish("❌ O'tkazma amalga oshmadi! Iltimos, qayta urinib ko'ring.", false);
        }

        yangilaKorinish();
        hideProgress();
    });
}

void MainWindow::showProgress(const QString &xabar) {
    ui->progressBar->setVisible(true);
    ui->progressBar->setValue(0);
    xabarKorsatish(xabar, false);
    
    // Tugmalarni vaqtincha o'chirib qo'yish
    ui->btnDepozit->setEnabled(false);
    ui->btnYechish->setEnabled(false);
    ui->btnOtkazma->setEnabled(false);
    ui->btnReset->setEnabled(false);
}

void MainWindow::hideProgress() {
    ui->progressBar->setVisible(false);
    
    // Tugmalarni qayta yoqish
    if (account) {
        ui->btnDepozit->setEnabled(true);
        ui->btnYechish->setEnabled(true);
        ui->btnOtkazma->setEnabled(true);
        ui->btnReset->setEnabled(true);
    }
}

void MainWindow::yangilaKorinish() {
    if (!account) return;

    ui->lblEgasi->setText(
        QString("Egasi: %1").arg(QString::fromStdString(account->getName()))
    );
    ui->lblBalans->setText(
        QString("Balans: %1 so'm | Tranzaksiyalar: %2").arg(account->getBalance()).arg(account->getTransactionCount())
    );

    if (account->getBalance() == 0)
        ui->lblBalans->setStyleSheet("color: #ff0055; font-size: 16px; font-weight: bold;"); // Neon Red
    else if (account->getBalance() < 10000)
        ui->lblBalans->setStyleSheet("color: #ffaa00; font-size: 16px; font-weight: bold;"); // Neon Orange
    else
        ui->lblBalans->setStyleSheet("color: #00ff00; font-size: 16px; font-weight: bold;"); // Neon Green

    ui->txtTarikh->setPlainText(QString::fromStdString(account->getHistory()));

    QTextCursor cursor = ui->txtTarikh->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->txtTarikh->setTextCursor(cursor);

    ui->lblHolat->setText("Hisob faol. Amallar panelidagi tugmalardan foydalaning.");
}

void MainWindow::xabarKorsatish(const QString &xabar, bool muvaffaqiyat) {
    if (muvaffaqiyat)
        ui->lblXabar->setStyleSheet(
            "background-color: #062010; color: #00ff00;"
            "border: 1px solid #00ff00; border-radius: 4px; padding: 8px; font-size: 13px;"
        );
    else
        ui->lblXabar->setStyleSheet(
            "background-color: #200606; color: #ff0055;"
            "border: 1px solid #ff0055; border-radius: 4px; padding: 8px; font-size: 13px;"
        );

    ui->lblXabar->setText(xabar);
}
