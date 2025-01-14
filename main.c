#include <stdio.h>
#include "proiectpoo.h"

void meniu() {
    int optiune;

    do {
        printf("\n=== Meniu ===\n");
        printf("1. Adauga vehicul\n");
        printf("2. Retrage vehicul\n");
        printf("3. Reintrodu vehicul\n");
        printf("4. Afiseaza flota\n");
        printf("5. Calculeaza vehicule retrase\n");
        printf("0. Iesire\n");
        printf("Introduceti optiunea: ");
        scanf("%d", &optiune);

        switch (optiune) {
            case 1:
                adauga_transport();
                break;
            case 2:
                retrage_transport();
                break;
            case 3:
                reintrodu_transport();
                break;
            case 4:
                afiseaza_transport();
                break;
            case 5:
                calculeaza_retrase();
                break;
            case 0:
                printf("Iesire din program. La revedere!\n");
                break;
            default:
                printf("Optiune invalida. Incercati din nou.\n");
        }
    } while (optiune != 0);
}

int main() {
    meniu();
    return 0;
}
