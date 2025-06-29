#pragma once
#include "stangry.h"

// Zarządza stanem gry po przegranej.
class StanPrzegranej : public StanGry {
public:
    void wejscie(MenedzerGry* menedzer) override;
    void aktualizuj(MenedzerGry* menedzer) override;
};
