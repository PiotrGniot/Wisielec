#pragma once
#include "stangry.h"

// Zarządza logiką, gdy gra aktywnie trwa.
class StanRozgrywki : public StanGry {
public:
    // Metoda uruchamiana raz, gdy zaczynamy rozgrywkę.
    void wejscie(MenedzerGry* menedzer) override;
    // Metoda wywoływana w pętli: pyta gracza o literę i sprawdza ją.
    void aktualizuj(MenedzerGry* menedzer) override;

};
