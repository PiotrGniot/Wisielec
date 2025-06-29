#include "rozgrywka.h"
#include <QChar>

Rozgrywka::Rozgrywka(const QString& haslo)
    : m_pelneHaslo(haslo), m_liczbaBledow(0)
{
    for (const QChar& znak : m_pelneHaslo) {
        if (znak.isSpace()) { m_hasloUzytkownika += ' '; }
        else { m_hasloUzytkownika += '_'; }
    }
}

QString Rozgrywka::getZamaskowaneHaslo() const {
    return m_hasloUzytkownika;
}

bool Rozgrywka::zgadnijLitere(QChar litera) {
    bool trafiony = false;
    for (int i = 0; i < m_pelneHaslo.length(); ++i) {
        if (m_pelneHaslo[i].toLower() == litera.toLower()) {
            m_hasloUzytkownika[i] = m_pelneHaslo[i];
            trafiony = true;
        }
    }
    // Jeśli nie trafiliśmy, zwiększamy licznik błędów.
    if (!trafiony) {
        zwiekszLiczbeBledow();
    }
    return trafiony;
}

bool Rozgrywka::czyOdgadniete() const {
    return !m_hasloUzytkownika.contains('_');
}

void Rozgrywka::zwiekszLiczbeBledow() {
    m_liczbaBledow++;
}

int Rozgrywka::getLiczbaBledow() const {
    return m_liczbaBledow;

}

QString Rozgrywka::getPelneHaslo() const {
    return m_pelneHaslo;
}
