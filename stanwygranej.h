#pragma once
#include "stangry.h"

// Zarządza stanem gry po wygranej.
class StanWygranej : public StanGry {
public:
    void wejscie(MenedzerGry* menedzer) override;
    void aktualizuj(MenedzerGry* menedzer) override;
};
