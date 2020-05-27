//
// Created by Slowikus on 22.05.2020.
//
#include "plansza.h"



Plansza::Plansza(int rozm)
        : rozmiar{rozm}
        , pole{new char[rozmiar*rozmiar]}
    {
        for(int i = 0; i < rozmiar*rozmiar; i++){
        pole[i] = i * i * 2;
        }
    }

void Plansza::ustawieniePoczatkowe() {
    for (int i = 0; i < rozmiar*rozmiar ; ++i) {
        pole[i] ='_';
    }
}

void Plansza::rysuj() {


    std::cout << "   ";
    for (int k = 0; k < rozmiar ; ++k) {
        std::cout << k+1 << "  ";
    }
    std::cout << std::endl;

    for (int i = 0; i < rozmiar; ++i) {
        std::cout << i+1 << "  ";
        for (int j = 0; j < rozmiar; ++j) {
            std::cout << pole[rozmiar*i+j] << "  ";
        }
        std::cout << std::endl;
    }
}

bool Plansza::wstaw(char gracz,int x, int y) {
    if (pole[rozmiar*y+x] != '_') return false;
    pole[rozmiar*y+x] = gracz; return true;
}

bool Plansza::czyWygrana(char gracz) {
    //wektory pomocnicze
    std::vector<char> znakWpisany;
    for (int i = 0; i < rozmiar ; ++i) {
        znakWpisany.push_back(gracz);
    }
    std::vector<char> pom;
    // poziom
    for (int j = 0; j < rozmiar; ++j) {
        for (int i = 0; i < rozmiar ; ++i) {
            pom.push_back(pole[rozmiar*j+i]);
        }
        if (pom == znakWpisany) return true;
        pom.clear();
    }
    // pion
    for (int j = 0; j < rozmiar; ++j) {
        for (int i = 0; i < rozmiar ; ++i) {
            pom.push_back(pole[rozmiar*i+j]);
        }
        if (pom == znakWpisany) return true;
        pom.clear();
    }
    //skos
    for (int k = 0; k < rozmiar; ++k) {
        pom.push_back(pole[(rozmiar-1)*(k+1)]);
    }
    if (pom == znakWpisany) return true;
    pom.clear();

    for (int k = 0; k < rozmiar; ++k) {
        pom.push_back(pole[(rozmiar+1)*k]);
    }
    if (pom == znakWpisany) return true;
    //pom.clear();
    return false;
}

bool Plansza::czyWolne() {
    for (int i = 0; i <rozmiar*rozmiar ; ++i) {
        if (pole[i] == '_') return true;
    }
    return false;
}







