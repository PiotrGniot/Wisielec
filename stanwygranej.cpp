#include "stanwygranej.h"
#include "menedzergry.h"
#include "stanrozgrywki.h"
#include <iostream>
#include <QTextStream>

void StanWygranej::wejscie(MenedzerGry* menedzer) {
    // Wyświetlamy końcowy stan wisielca i hasło
    menedzer->wisielec.wyswietl(menedzer->rozgrywka->getLiczbaBledow());
    std::cout << "\nHaslo: " << menedzer->rozgrywka->getZamaskowaneHaslo().toStdString() << "\n";
    std::cout << "\n********************************\n";
    std::cout << "*** GRATULACJE! ODGADLES HASLO! ***\n";
    std::cout << "********************************\n";
}

void StanWygranej::aktualizuj(MenedzerGry* menedzer) {
    std::cout << "Czy chcesz zagrac jeszcze raz? (t/n): ";
    QTextStream qin(stdin);
    QString odp = qin.readLine().toLower();

    if (odp == "t") {
        // Zmieniamy stan na nową rozgrywkę.
        menedzer->zmienStan(std::make_unique<StanRozgrywki>());
    } else if (odp == "n") {
        // Kończymy grę.
        menedzer->zakonczGre();
    }
}
