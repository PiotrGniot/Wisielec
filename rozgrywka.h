#pragma once
#include <QString>

class Rozgrywka {
public:
    Rozgrywka(const QString& haslo);
    QString getZamaskowaneHaslo() const;
    bool zgadnijLitere(QChar litera);
    bool czyOdgadniete() const;
    void zwiekszLiczbeBledow();
    int getLiczbaBledow() const;

    QString getPelneHaslo() const;

private:
    QString m_pelneHaslo;
    QString m_hasloUzytkownika;
    int m_liczbaBledow;
};
