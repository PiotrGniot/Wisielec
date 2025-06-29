#include "stanprzegranej.h"
#include "menedzergry.h"
#include "stanrozgrywki.h"
#include <iostream>
#include <QTextStream>

// Ta metoda jest uruchamiana raz, od razu po przegranej.
void StanPrzegranej::wejscie(MenedzerGry* menedzer)
{
    // 1. Rysujemy ostateczny, pełny wygląd wisielca.
    menedzer->wisielec.wyswietl(menedzer->rozgrywka->getLiczbaBledow());

    // 2. Wyświetlamy komunikat o przegranej.
    std::cout << "\n********************************\n";
    std::cout << "*** PRZEGRANA!         ***\n";
    std::cout << "********************************\n";

    // 3. Pokazujemy graczowi, jakie było poprawne hasło.
    std::cout << "Poprawne haslo to: " << menedzer->rozgrywka->getPelneHaslo().toStdString() << std::endl;
}

// Ta metoda działa w pętli PO wyświetleniu komunikatu o przegranej.
void StanPrzegranej::aktualizuj(MenedzerGry* menedzer)
{
    // Pytamy gracza, czy chce zagrać jeszcze raz.
    std::cout << "Czy chcesz sprobowac jeszcze raz? (t/n): ";
    QTextStream qin(stdin);
    QString odp = qin.readLine().toLower();

    if (odp == "t") {
        // Zmieniamy stan z powrotem na nową rozgrywkę.
        menedzer->zmienStan(std::make_unique<StanRozgrywki>());
    } else if (odp == "n") {
        // Kończymy grę.
        menedzer->zakonczGre();
    }
}
