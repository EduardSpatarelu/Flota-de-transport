#ifndef FLOTA_H
#define FLOTA_H

#include <stdbool.h> // Pentru utilizarea tipului `bool`

// Structura pentru un mijloc de transport
typedef struct {
    int numar;              // Numărul unic al vehiculului
    char tip[20];           // Tipul: "autobuz", "tren" sau "avion"
    char destinatie[50];    // Destinația
    int distanta;           // Distanța până la destinație
    bool defect;            // Dacă vehiculul este defect
    bool activ;             // Dacă vehiculul este în circulație
} Transport;

// Dimensiunea maximă a flotei
#define MAX_FLOTA 100

// Variabile globale pentru flotă
extern Transport flota[MAX_FLOTA];
extern int numar_vehicule;

// Declarațiile funcțiilor
void adauga_transport();
void retrage_transport();
void reintrodu_transport();
void afiseaza_transport();
void calculeaza_retrase();

#endif // FLOTA_H
