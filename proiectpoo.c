#include <stdio.h>
#include <string.h>
#include "proiectpoo.h"

// Inițializăm flota și numărul de vehicule
Transport flota[MAX_FLOTA];
int numar_vehicule = 0;

// Funcție pentru a adăuga un vehicul în flotă
void adauga_transport() {
    if (numar_vehicule >= MAX_FLOTA) {
        printf("Flota est\e plina!\n");
        return;
    }

    Transport t;
    printf("Introduceti numarul vehiculului: ");
    scanf("%d", &t.numar);
    printf("Introduceti tipul vehiculului (autobuz/tren/avion): ");
    scanf("%s", t.tip);
    printf("Introduceti destinatia: ");
    scanf("%s", t.destinatie);
    printf("Introduceti distanta până la destinatie (în km): ");
    scanf("%d", &t.distanta);
    t.defect = false; // Implicit, vehiculul nu este defect
    t.activ = true;  // Implicit, vehiculul este în circulație

    flota[numar_vehicule++] = t;
    printf("Vehicul adaugat cu succes!\n");
}

// Funcție pentru a retrage un vehicul
void retrage_transport() {
    int numar;
    printf("Introduceti numarul vehiculului care va fi retras: ");
    scanf("%d", &numar);

    for (int i = 0; i < numar_vehicule; i++) {
        if (flota[i].numar == numar) {
            if (!flota[i].activ) {
                printf("Vehiculul este deja retras din circulație.\n");
                return;
            }
            flota[i].activ = false;
            flota[i].defect = true; // Presupunem că retragerea este cauzată de defecte
            printf("Vehiculul %d a fost retras din circulatie.\n", numar);
            return;
        }
    }

    printf("Vehiculul cu numarul %d nu a fost gasit.\n", numar);
}

// Funcție pentru a reintroduce un vehicul în circulație
void reintrodu_transport() {
    int numar;
    printf("Introduceti numarul vehiculului care va fi reintrodus: ");
    scanf("%d", &numar);

    for (int i = 0; i < numar_vehicule; i++) {
        if (flota[i].numar == numar) {
            if (flota[i].activ) {
                printf("Vehiculul este deja in circulatie.\n");
                return;
            }
            flota[i].activ = true;
            flota[i].defect = false;
            printf("Vehiculul %d a fost reintrodus în circulatie.\n", numar);
            return;
        }
    }

    printf("Vehiculul cu numarul %d nu a fost gasit.\n", numar);
}

// Funcție pentru a afișa toate vehiculele
void afiseaza_transport() {
    printf("\n=== Detalii flota ===\n");
    for (int i = 0; i < numar_vehicule; i++) {
        printf("Numar: %d, Tip: %s, Destinatie: %s, Distanta: %d km, Status: %s, Defect: %s\n",
               flota[i].numar, flota[i].tip, flota[i].destinatie, flota[i].distanta,
               flota[i].activ ? "Activ" : "Retras",
               flota[i].defect ? "Da" : "Nu");
    }
}

// Funcție pentru a calcula vehiculele retrase
void calculeaza_retrase() {
    int autobuze = 0, trenuri = 0, avioane = 0;

    for (int i = 0; i < numar_vehicule; i++) {
        if (!flota[i].activ) {
            if (strcmp(flota[i].tip, "autobuz") == 0) autobuze++;
            else if (strcmp(flota[i].tip, "tren") == 0) trenuri++;
            else if (strcmp(flota[i].tip, "avion") == 0) avioane++;
        }
    }

    printf("\n=== Vehicule retrase ===\n");
    printf("Autobuze retrase: %d\n", autobuze);
    printf("Trenuri retrase: %d\n", trenuri);
    printf("Avioane retrase: %d\n", avioane);
}
