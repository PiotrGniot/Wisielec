#pragma once
#include <QString>
#include <QVector>

// Odpowiada za rysowanie postaci wisielca w konsoli.
class Wisielec {
public:
    // Konstruktor: przygotowuje wszystkie etapy rysunku.
    Wisielec();

    // Metoda wyświetla w konsoli wisielca w stanie odpowiadającym liczbie błędów.
    void wyswietl(int liczbaBledow);

private:
    // Wektor przechowujący kolejne etapy rysunku jako ciągi znaków.
    QVector<QString> m_stanyWisielca;
};
