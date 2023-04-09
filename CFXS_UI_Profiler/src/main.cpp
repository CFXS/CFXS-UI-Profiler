// [CFXS] //
#include <Log/Log.hpp>
#include <QApplication>
#include <QMainWindow>
#include <QPalette>
#include <QStyleFactory>

QMainWindow* MakeWindow() {
    auto win = new QMainWindow;
    win->setStyleSheet("background: #111;");
    win->setFixedSize({1280, 720});
    return win;
}

int main(int argc, char** argv) {
    Log::Initialize();

    QApplication::setAttribute(Qt::AA_UseDesktopOpenGL);
    auto app = new QApplication(argc, argv);
    app->setOrganizationName(QSL("CFXS"));
    app->setApplicationName(QString::fromStdString(CFXS_PROGRAM_NAME " // " CFXS_VERSION_STRING));

    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(55, 55, 55));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::WindowText, QColor(127, 127, 127));
    darkPalette.setColor(QPalette::Base, QColor(33, 33, 33));
    darkPalette.setColor(QPalette::AlternateBase, QColor(66, 66, 66));
    darkPalette.setColor(QPalette::Mid, QColor(66, 66, 66));
    darkPalette.setColor(QPalette::Midlight, QColor(105, 105, 105));
    darkPalette.setColor(QPalette::Light, QColor(164, 164, 164));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));
    darkPalette.setColor(QPalette::Dark, QColor(44, 44, 44));
    darkPalette.setColor(QPalette::Shadow, QColor(20, 20, 20));
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor(127, 127, 127));
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(0, 105, 220));
    darkPalette.setColor(QPalette::Disabled, QPalette::Highlight, QColor(80, 80, 80));
    darkPalette.setColor(QPalette::HighlightedText, Qt::white);
    darkPalette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor(127, 127, 127));

    QApplication::setPalette(darkPalette);
    QApplication::setStyle(QStyleFactory::create(QSL("fusion")));

    auto win = MakeWindow();

    win->show();
    app->exec();
    delete win;
    delete app;

    return 0;
}