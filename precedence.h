//
// Created by leopo on 03/12/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_PRECEDENCE_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_PRECEDENCE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud* suivant;
} Noeud;

typedef struct Graphe {
    int nombreNoeuds;
    Noeud** listeAdjacence;
} Graphe;
Graphe* creerGraphe(int nombreNoeuds);

Graphe* initialiserGraphe(int nombreNoeuds);

void afficherOrdreDesOperations(Graphe* graphe, int* rang);


void libererGraphe(Graphe* graphe);

void ajouterArete(Graphe* graphe, int source, int destination);
int trouverNombreNoeuds(FILE* fichier);


void triTopologiqueRecursif(Graphe* graphe, int sommet, int* visite, int* pile, int* indexPile);

void triTopologique(Graphe* graphe, int* rang);

void afficherGraphe(Graphe* graphe,int *rang);

/*
int main() {
    FILE *fichier = fopen("precedences.txt", "r");

    if (fichier == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier.\n");
        return 1;
    }

    int nombreTotalNoeuds = trouverNombreNoeuds(fichier);

    // Réinitialiser le curseur du fichier pour lire à partir du début
    fseek(fichier, 0, SEEK_SET);

    Graphe* graphe = initialiserGraphe(nombreTotalNoeuds);

    int source, destination;
    while (fscanf(fichier, "%d %d", &source, &destination) == 2) {
        ajouterArete(graphe, source, destination);
    }

    fclose(fichier);

    int* rang = (int*)malloc(nombreTotalNoeuds * sizeof(int));
    triTopologique(graphe, rang);

    // Afficher le rang de chaque opération
    afficherGraphe(graphe,rang);

    free(rang);
    libererGraphe(graphe);

    return 0;
}
*/
#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_PRECEDENCE_H
