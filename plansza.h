//
// Created by Slowikus on 22.05.2020.
//

#ifndef P33_PLANSZA_H
#define P33_PLANSZA_H
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

//Klasa tworząca pole do gry i dajaca
//możliwość wykonywania wszytkich
//potrzenych modyfikacji na polu gry
class Plansza
{
public:
    //rozmiar planszy
    int rozmiar;
    //wartosci odpowiednich pol
    std::unique_ptr<char[]> pole;

    //tworze plansze o danym rozmiarze
    Plansza(int rozm);
    //wstawiam we wszytkie pola '_'
    void ustawieniePoczatkowe();
    //rysuje planszę
    void rysuj();
    //wstawiam znak w wybrane pole
    bool wstaw(char gracz,int x, int y);
    //sprawdza czy dany gracz wygrał grę
    bool czyWygrana(char gracz);
    //sprawdza czy są jeszcze wolne miesjca na planszy
    bool czyWolne();
};

#endif //P33_PLANSZA_H
