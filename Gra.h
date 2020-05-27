//
// Created by Slowikus on 23.05.2020.
//

#ifndef P33_GRA_H
#define P33_GRA_H

#include "plansza.h"

#include <algorithm>

// wykonuje pokolei wszytkie operacje związane z grą w KiK
//oraz zawiera zaimplementowny algorym minimax pozwalający na
//na grę człwoieka z "komputerem".
class Gra : public Plansza{
private:
    // najleosze wsp ruchu dla komputera
    int komY;
    int komX;
    // znacznik gracza i komputera
    char graczX = 'x';
    char kompO = 'o';
    //oznacza czy gra sie skonczyla czy nie
    bool koniecGry = false;
public:
    Gra(int rozm);
    //pobireanie wspolrzednyc z wejscia
    int podajX();
    int podajY();
    //gra
    void graj();
    //wykonuje ruch okreslony przez gracza
    void ruchGracza();
    //wykonuje ruch okreslony przez komputer
    void ruchKomputera();
    //punktuje wykonywane ruchy
    int ocen();
    //algorytm minimax
    int minimax(int glebokosc,int alpha, int beta, bool maximizingPlayer);
    //znajduje najlpeszy ruch z aktualnego stanu
    void najlepszyRuch();
};


#endif //P33_GRA_H
