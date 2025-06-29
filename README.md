# Wisielec
Prosta, konsolowa implementacja klasycznej gry słownej "Wisielec", napisana w języku C++ z wykorzystaniem biblioteki Qt 6. Projekt został stworzony z naciskiem na demonstrację zasad programowania obiektowego.

## Funkcjonalności
- Baza Haseł z Zasobów: Gra wczytuje hasła i ich kategorie z pliku hasla.txt, który jest wkompilowany w aplikację za pomocą systemu zasobów Qt, dzięki czemu program jest w pełni przenośny.

- System Kategorii: Przed każdą rundą gracz otrzymuje podpowiedź w postaci kategorii, do której należy hasło.

- Pełne Wsparcie dla Polskich Znaków: Aplikacja poprawnie obsługuje polskie znaki diakrytyczne zarówno w hasłach, jak i w danych wprowadzanych przez użytkownika.

- Interaktywna Rozgrywka: Prosty interfejs tekstowy pozwala na odgadywanie liter, a program na bieżąco informuje o postępach.

- Wizualizacja Wisielca: Każdy błąd skutkuje dorysowaniem kolejnego elementu klasycznego wisielca w formie grafiki ASCII.

- Opcja Ponownej Gry: Po zakończeniu każdej partii (wygranej lub przegranej) użytkownik ma możliwość zagrania jeszcze raz.

## Architektura i Technologie
Technologie
- Język: C++ (w standardzie C++17)

- Biblioteki: Qt 6 (moduł Qt Core dla QString, QFile, QVector etc.)

- Środowisko: Qt Creator

- System budowania: qmake

## Architektura
Aplikacja została zaprojektowana w oparciu o elementy programowania obiektowego. Logika gry została podzielona na odrębne stany (`StanRozgrywki`, `StanWygranej`, `StanPrzegranej`), a klasa `MenedzerGry` pełni rolę kontekstu, który zarządza przejściami między nimi. Takie podejście zapewnia dużą elastyczność i czytelność kodu, unikając skomplikowanych instrukcji warunkowych.

## Struktura Projektu
Projekt wykorzystuje płaską strukturę plików w celu uproszczenia zarządzania:
```
Wisielec/
├── Wisielec.pro            # Plik konfiguracyjny projektu Qt
├── zasoby.qrc              # Plik zasobów (linkuje hasla.txt do aplikacji)
├── hasla.txt               # Plik tekstowy z hasłami i kategoriami
│
├── main.cpp                # Główny punkt wejścia aplikacji
│
├── stangry.h               # Abstrakcyjna klasa bazowa dla wszystkich stanów gry
│
├── menedzergry.h           # Deklaracja klasy zarządzającej grą
├── menedzergry.cpp         # Implementacja Menedżera Gry
│
├── rozgrywka.h             # Deklaracja klasy przechowującej dane partii
├── rozgrywka.cpp           # Implementacja klasy Rozgrywka
│
├── bazahasel.h             # Deklaracja klasy wczytującej hasła
├── bazasel.cpp           # Implementacja Bazy Haseł
│
├── wisielec.h              # Deklaracja klasy rysującej wisielca
├── wisielec.cpp            # Implementacja klasy Wisielec
│
├── stanrozgrywki.h         # Deklaracja stanu aktywnej gry
├── stanrozgrywki.cpp       # Implementacja stanu aktywnej gry
│
├── stanwygranej.h          # Deklaracja stanu po wygranej
├── stanwygranej.cpp        # Implementacja stanu po wygranej
│
└── stanprzegranej.h        # Deklaracja stanu po przegranej
└── stanprzegranej.cpp        # Implementacja stanu po przegranej
```

## Instalacja i Uruchomienie
Wymagania
- Kompilator C++ obsługujący standard C++17

- Zainstalowana biblioteka Qt w wersji 6.x

## Kompilacja i Uruchomienie

Uwaga dla użytkowników Windows:
Aplikacja w pliku main.cpp wykonuje komendę `system("chcp 65001");`, aby ustawić w konsoli stronę kodową na UTF-8. Jest to konieczne do poprawnego wyświetlania polskich znaków.

Plik z Hasłami (hasla.txt)
Możesz dowolnie modyfikować bazę haseł, edytując plik hasla.txt. Pamiętaj, aby zachować format:

[HASŁO MOŻE BYĆ WIELOWYRAZOWE] (kategoria)

Każdy wpis musi znajdować się w nowej linii. Po edycji pliku należy ponownie skompilować projekt, aby zmiany zostały uwzględnione w zasobach aplikacji.

Autor: Piotr
