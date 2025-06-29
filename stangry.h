#pragma once

class MenedzerGry;

// Definiuje ogólny "szablon" dla wszystkich stanów gry.
class StanGry {
public:
    // Wirtualny destruktor - ważny przy dziedziczeniu klas.
    virtual ~StanGry() {}

    // Metoda uruchamiana JEDEN RAZ, gdy dany stan staje się aktywny.
    virtual void wejscie(MenedzerGry* menedzer) = 0;

    // Metoda wywoływana w PĘTLI, dopóki stan jest aktywny. Tu dzieje się cała logika.
    virtual void aktualizuj(MenedzerGry* menedzer) = 0;
};
