//
// Created by leopo on 22/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphe.h"
#include "lecture_contraintes.h"
#include "file.h"
#include "Stations.h"

int main(){
    char nomFichier[50];
    char precedence[50];
    char temps[50];
    char exclusion[50];
    int sommet_init = 0;
    Graphe *g;
    printf("Entrez le nom du fichier d'operations: ");
    gets(nomFichier);
    int nmb_lignes = 0;
    t_operation **operations = lire_operations(nomFichier, &nmb_lignes);
    for(int i = 0; i<nmb_lignes; i++){
        operations[i]->rang = i;
    }
    for(int i = 0; i<nmb_lignes; i++){
        printf("%d %f\n", operations[i]->num, operations[i]->temps);
    }

    printf("Entrez le nom du fichier de precedences: ");
    gets(precedence);
    //FILE * nouveau_fichier = creer_fichier_graphe(precedence, operations, &nmb_lignes);

    g = lire_graphe("nouveau_fichier.txt", nmb_lignes, 34);

    bfs(g, sommet_init, operations);
    printf("Entrez le nom du fichier de temps: ");
    gets(temps);
    printf("Entrez le nom du fichier d'exclusions: ");
    gets(exclusion);
    assigner_stations(operations, nmb_lignes, exclusion, temps);
    for (int i = 0; i < nmb_lignes; i++) {
        free(operations[i]);
    }
    free(operations);
    return 0;
}