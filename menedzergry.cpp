#include "menedzergry.h"
#include "stanrozgrywki.h"
#include <iostream>

MenedzerGry::MenedzerGry()
    : bazaHasel(":/hasla/hasla.txt"),
    m_czyDziala(false)
{
}

void MenedzerGry::start()
{
    m_czyDziala = true;
    zmienStan(std::make_unique<StanRozgrywki>());

    while (m_czyDziala)
    {
        if (m_aktualnyStan)
        {
            m_aktualnyStan->aktualizuj(this);
        }
    }
}

void MenedzerGry::zmienStan(std::unique_ptr<StanGry> nowyStan)
{
    m_aktualnyStan = std::move(nowyStan);

    if (m_aktualnyStan) {
        m_aktualnyStan->wejscie(this);
    }
}

void MenedzerGry::zakonczGre()
{
    m_czyDziala = false;
    std::cout << "Menedzer gry otrzymal sygnal do zakonczenia..." << std::endl;
}
