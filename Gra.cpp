//
// Created by Slowikus on 23.05.2020.
//


#include "Gra.h"

int Gra::podajX() {
    int x;
    bool blad = true;
    while (blad == true) {
        std::cout << "Podaj wspolrzedna X: "<< std::endl;
        std::cin >> x;
        x = x - 1;
        if (x > (rozmiar-1) || x < 0 ) {
            std::cout << "Bledna wartosc X" << std::endl;
        } else blad = false;
    }
    return x;
}

int Gra::podajY() {
    int y;
    bool blad = true;
    while (blad == true) {
        std::cout << "Podaj wspolrzedna Y: "<< std::endl;
        std::cin >> y;
        y = y - 1;
        if (y > (rozmiar-1) || y < 0 ) {
            std::cout << "Bledna wartosc Y" << std::endl;
        } else blad = false;
    }
    return y;
}

void Gra::graj() {
    koniecGry = false;
    char mojaTura;
    ustawieniePoczatkowe();

    std::cout << "Kto zaczyna 'x'(czlowiek) czy 'o'(komputer)" << std::endl;
    std::cin >> mojaTura;

    std::cout << "****************" << std::endl;
    rysuj();
    std::cout << "****************" << std::endl;

    while (!koniecGry) {


        if (mojaTura == graczX) {
            ruchGracza();
        }

        if (mojaTura == kompO) {
            ruchKomputera();
        }
        std::cout << "****************" << std::endl;
        rysuj();
        std::cout << "****************" << std::endl;
        //sprawdzam czy obecny gracz wygrał
        if (czyWygrana(mojaTura)) {
            rysuj();
            std::cout << "////////////////////////////" << std::endl;
            std::cout << "Koniec gry, wygrywa gracz " << mojaTura << std::endl;
            std::cout << "////////////////////////////" << std::endl;
            koniecGry = true;
        }
        //sprawdzam czy sa jescze wolne miejsca
        else if (!czyWolne()) {
            std::cout << "/////////////////////" << std::endl;
            std::cout << "/////// Remis ///////" << std::endl;
            std::cout << "/////////////////////" << std::endl;
            koniecGry = true;
        }
        //rysuj();
        //zmieniam gracza
        if (mojaTura == kompO) {
            mojaTura = graczX;
        } else mojaTura = kompO;
    }

}

Gra::Gra(int rozm) : Plansza(rozm) {
}

void Gra::ruchGracza() {
    int x;
    int y;

    x=podajX();
    y=podajY();
    while (!wstaw(graczX, x, y)) {
        std::cout << "To miejsce jest juz zajete" << std::endl;
        x=podajX();
        y=podajY();
    }
}

void Gra::ruchKomputera() {
    najlepszyRuch();
    wstaw(kompO,komX,komY);

}
//funkcja która zwraca +10 gdy komputer wygra, -10 gdzy przgra i 0 gdy jest remis
int Gra::ocen() {
    if(czyWygrana(kompO)) {
        return +10;
    } else if(czyWygrana(graczX)) {
        return -10;
    } else {
        return 0;
    }
}
//algorytm minimax dla KiK z odcieciami alfa-beta
int Gra::minimax(int glebokosc,int alpha,int beta, bool maximizingPlayer) {

    int wartosc = ocen(); //oceniam aktulany stan gry
    if (glebokosc == 0) return wartosc; // zwracam ocene gdy głebokość osiagnie 0
    if (wartosc == 10) return wartosc; // gdy ktoras ze stron wygra lub bedzie remis
    if (wartosc == -10) return wartosc;// zwracam odpowiendie dla nich wart
    if (!czyWolne()) return 0;

    if (maximizingPlayer) {
        int maksimum = -9999;
        for (int i = 0; i < rozmiar*rozmiar; i++) { //dla każdego wolnego pola
                if (pole[i] == '_') {
                    pole[i] = kompO; //wstawiam o
                    // co wykoanie funkcji zmieniam gracza - !maximazingpalyer
                    int szac =  minimax(glebokosc - 1, alpha, beta, !maximizingPlayer); //symuluje dalsze gałęzie
                    maksimum = std::max(maksimum, szac); // zwraca wieksza z liczb
                    alpha = std::max(alpha, szac);
                    pole[i] = '_'; // wracam do stanu wejsciowego
                    if (beta <= alpha) break;
                }
        }
        return maksimum;

    } else { //maximazing
        int minimum = 9999;
        for (int j = 0; j < rozmiar*rozmiar; ++j) { //przechodze po wszxytkich polach
                if (pole[j] == '_') {
                    pole[j] = graczX; //wsatwiam x
                    int szac =  minimax(glebokosc - 1, alpha, beta, !maximizingPlayer);
                    minimum = std::min(minimum, szac);
                    beta = std::min(beta, szac);
                    pole[j] = '_';
                    if (beta <= alpha) break;
                }
        }
        return minimum;
    }

}
// znajdz najlepszy ruch i zapisz jego wspolrzedne
void Gra::najlepszyRuch() {
    int najkorzystniejsza = -9999;
    //mniejsze od 0
    komY = -10;
    komX = -10;

    for (int j = 0; j < rozmiar ; ++j) { //dla każdego psuetgo pola w aktualnym stanie
        for (int k = 0; k <rozmiar ; ++k) {
            if (pole[rozmiar*j+k] == '_' ) {
                pole[rozmiar*j+k] = kompO; //wstawiam o
                //okreslam głebokosc przeszukiwania, przekazuje false bo teraz pora na ruch człowieka
                int nowa = minimax(6, -10000, 10000, false);
                pole[rozmiar*j+k] = '_'; // przywracam stan poczatkowy
                if (nowa > najkorzystniejsza) {
                    // zaspiuje najkorzystniejsze wspolrzedne
                    komY = j;
                    komX= k;
                    najkorzystniejsza = nowa;
                }
            }

        }

    }

}


