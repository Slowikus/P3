#include <iostream>
#include "Gra.h"

using namespace std;

int main() {

    bool koniec = false;
    char zmienna;
    int rozmiar;

    while(!koniec) {

        std::cout << "Podaj rozmiar planszy na ktorej chesz grac(np 2, 3, 4.....) : " << std::endl;
        std::cin >> rozmiar;
        Gra gra(rozmiar);
        gra.graj();
        std::cout << "Czy chcesz zagrac jescze raz? (T/N): " << std::endl;
        cin >> zmienna;
        if (zmienna == 'n' || zmienna == 'N') koniec = true;
    }

    return 0;
}
