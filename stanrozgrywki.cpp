#include "stanrozgrywki.h"
#include "menedzergry.h"
#include "stanwygranej.h"
#include "stanprzegranej.h"
#include <iostream>
#include <QTextStream>

void StanRozgrywki::wejscie(MenedzerGry* menedzer) {
    std::cout << "\n--- NOWA GRA ---\n";

    QPair<QString, QString> paraHaslo = menedzer->bazaHasel.losujHaslo();

    std::cout << "Kategoria: " << paraHaslo.second.toStdString() << std::endl;

    menedzer->rozgrywka = std::make_unique<Rozgrywka>(paraHaslo.first);
}

void StanRozgrywki::aktualizuj(MenedzerGry* menedzer) {
    int bledy = menedzer->rozgrywka->getLiczbaBledow();
    menedzer->wisielec.wyswietl(bledy);

    std::cout << "\nHaslo: " << menedzer->rozgrywka->getZamaskowaneHaslo().toStdString() << "\n";
    std::cout << "Podaj litere: ";
    QTextStream qin(stdin);
    QString line = qin.readLine();

    if (line.isEmpty()) { return; }
    QChar litera = line[0];

    if (menedzer->rozgrywka->zgadnijLitere(litera)) {
        std::cout << "Dobry strzal!" << std::endl;
        if (menedzer->rozgrywka->czyOdgadniete()) {
            menedzer->zmienStan(std::make_unique<StanWygranej>());
        }
    } else {
        std::cout << "Pudlo!" << std::endl;
        if (menedzer->rozgrywka->getLiczbaBledow() >= 6) {
            menedzer->zmienStan(std::make_unique<StanPrzegranej>());
        }
    }
}

