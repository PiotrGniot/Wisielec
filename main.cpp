#include <QCoreApplication>
#include <QTextStream>
#include <iostream>

#include "menedzergry.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream cout(stdout);

    // W systemie Windows, ta komenda zmienia kodowanie konsoli na UTF-8.
#ifdef Q_OS_WIN
    system("chcp 65001");
#endif



    cout << "============================" << Qt::endl;
    cout << "   Uruchamiam gre Wisielec" << Qt::endl;
    cout << "============================" << Qt::endl;

    MenedzerGry menedzer;
    menedzer.start();

    cout << "============================" << Qt::endl;
    cout << "    Dziekuje za gre! " << Qt::endl;
    cout << "============================" << Qt::endl;

    return 0;
}
