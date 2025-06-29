#pragma once
#include <QVector>
#include <QString>
#include <QPair>

class BazaHasel {
public:
    BazaHasel(const QString& nazwaPliku);
    QPair<QString, QString> losujHaslo();

private:
    void wczytajHasla();
    QVector<QPair<QString, QString>> m_hasla;
    QString m_nazwaPliku;
};
