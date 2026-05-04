#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QString stil =
        "QMainWindow { background-color: #050508; color: #00f2ff; }"
        "QGroupBox {"
        "    font-size: 14px; font-weight: bold; color: #00f2ff;"
        "    border: 1px solid #00f2ff; border-radius: 4px;"
        "    margin-top: 15px; padding-top: 15px; background-color: #0d1117;"
        "}"
        "QGroupBox::title { subcontrol-origin: margin; left: 10px; padding: 0 5px; color: #ff00ff; }"
        "QPushButton {"
        "    background-color: #161b22; color: #00f2ff; border: 1px solid #00f2ff;"
        "    border-radius: 2px; padding: 8px; font-weight: bold; text-transform: uppercase;"
        "}"
        "QPushButton:hover { background-color: #00f2ff; color: #050508; }"
        "QPushButton:disabled { border-color: #30363d; color: #30363d; }"
        "QPushButton#btnOtkazma { border-color: #ff00ff; color: #ff00ff; }"
        "QPushButton#btnOtkazma:hover { background-color: #ff00ff; color: #050508; }"
        "QLineEdit, QSpinBox {"
        "    background-color: #0d1117; color: #00f2ff; border: 1px solid #30363d;"
        "    padding: 8px; border-radius: 2px;"
        "}"
        "QLineEdit:focus, QSpinBox:focus { border: 1px solid #00f2ff; }"
        "QPlainTextEdit {"
        "    background-color: #010409; color: #00f2ff; border: 1px solid #30363d;"
        "    font-family: 'Consolas'; font-size: 11px; padding: 10px;"
        "}"
        "QProgressBar {"
        "    border: 1px solid #30363d; background-color: #0d1117; text-align: center;"
        "}"
        "QProgressBar::chunk { background-color: #00f2ff; }"
        "QLabel { color: #00f2ff; }"
        "QLabel#lblSarlavha { color: #ff00ff; font-weight: bold; }"
        "QLabel#lblBalans { font-size: 16px; font-weight: bold; color: #00ff00; }"
        "QLabel#lblEgasi  { font-size: 14px; font-weight: 600; }"
        "QLabel#lblHolat  { color: #8b949e; font-size: 12px; font-style: italic; }";

    a.setStyleSheet(stil);

    MainWindow w;
    w.show();
    return a.exec();
}
