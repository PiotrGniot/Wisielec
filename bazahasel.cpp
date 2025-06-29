#include "bazahasel.h"
#include <iostream>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>
#include <QRegularExpression>

BazaHasel::BazaHasel(const QString& nazwaPliku) : m_nazwaPliku(nazwaPliku) {
    wczytajHasla();
}

void BazaHasel::wczytajHasla() {
    QFile plik(m_nazwaPliku);
    if (!plik.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "BLAD: Nie mozna otworzyc pliku z haslami: " << m_nazwaPliku.toStdString() << std::endl;
        return;
    }
    std::cout << "INFO: Wczytuje hasla z pliku..." << std::endl;
    QTextStream in(&plik);


    QRegularExpression re(R"(\[(.+)\]\s*\((.+)\))");

    while (!in.atEnd()) {
        QString linia = in.readLine();
        QRegularExpressionMatch match = re.match(linia);

        if (match.hasMatch()) {
            QString tresc = match.captured(1).trimmed();
            QString kategoria = match.captured(2).trimmed();
            m_hasla.push_back(qMakePair(tresc, kategoria));
        }
    }
    plik.close();
    std::cout << "INFO: Wczytano " << m_hasla.size() << " hasel." << std::endl;
}

QPair<QString, QString> BazaHasel::losujHaslo() {
    if (m_hasla.isEmpty()) {
        std::cerr << "BLAD: Lista hasel jest pusta!" << std::endl;
        return qMakePair("AWARYJNE", "brak");
    }
    int losowyIndeks = QRandomGenerator::global()->bounded(m_hasla.size());
    return m_hasla[losowyIndeks];
}
