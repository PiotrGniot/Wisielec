#include "wisielec.h"
#include <iostream>

// To jest konstruktor klasy Wisielec.
// Jego zadaniem jest przygotowanie wszystkich rysunków wisielca.
Wisielec::Wisielec()
{

    // Stan 0: 0 błędów
    m_stanyWisielca.push_back(R"(
     +---+
     |   |
         |
         |
         |
         |
    =========
    )");

    // Stan 1: 1 błąd
    m_stanyWisielca.push_back(R"(
     +---+
     |   |
     O   |
         |
         |
         |
    =========
    )");

    // Stan 2: 2 błędy
    m_stanyWisielca.push_back(R"(
     +---+
     |   |
     O   |
     |   |
         |
         |
    =========
    )");

    // Stan 3: 3 błędy
    m_stanyWisielca.push_back(R"(
     +---+
     |   |
     O   |
    /|   |
         |
         |
    =========
    )");

    // Stan 4: 4 błędy
    m_stanyWisielca.push_back(R"(
     +---+
     |   |
     O   |
    /|\  |
         |
         |
    =========
    )");

    // Stan 5: 5 błędów
    m_stanyWisielca.push_back(R"(
     +---+
     |   |
     O   |
    /|\  |
    /    |
         |
    =========
    )");

    // Stan 6: 6 błędów (koniec gry)
    m_stanyWisielca.push_back(R"(
     +---+
     |   |
     O   |
    /|\  |
    / \  |
         |
    =========
    )");
}

// Ta metoda wyświetla w konsoli konkretny rysunek wisielca.
void Wisielec::wyswietl(int liczbaBledow)
{
    // Sprawdzamy, czy podana liczba błędów jest poprawna, aby uniknąć błędu programu.
    if (liczbaBledow >= 0 && liczbaBledow < m_stanyWisielca.size())
    {
        // Wyświetlamy rysunek o indeksie równym liczbie błędów.
        std::cout << m_stanyWisielca[liczbaBledow].toStdString() << std::endl;
    }
}
