#pragma once
#include <memory>

#include "stangry.h"
#include "bazahasel.h"
#include "wisielec.h"
#include "rozgrywka.h"

class StanGry;

class MenedzerGry
{
public:
    MenedzerGry();
    void start();
    void zmienStan(std::unique_ptr<StanGry> nowyStan);
    void zakonczGre();

    BazaHasel bazaHasel;
    Wisielec wisielec;
    std::unique_ptr<Rozgrywka> rozgrywka;

private:
    std::unique_ptr<StanGry> m_aktualnyStan;
    bool m_czyDziala;
};
