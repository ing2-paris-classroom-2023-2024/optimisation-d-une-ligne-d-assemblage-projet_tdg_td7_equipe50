//
// Created by leopo on 22/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphe.h"
#include "lecture_contraintes.h"
#include "file.h"

int main(){
    char nomFichier[50];
    char precedence[50];
    int sommet_init;
    Graphe *g;
    printf("Entrez le nom du fichier: ");
    fgets(nomFichier, sizeof(nomFichier), stdin);
    nomFichier[strcspn(nomFichier, "\n")] = 0;
    int nmb_lignes = 0;
    t_operation **operations = lire_operations(nomFichier, &nmb_lignes);
    for(int i = 0; i<nmb_lignes; i++){
        operations[i]->rang = i;
    }
    for(int i = 0; i<nmb_lignes; i++){
        printf("%d %f\n", operations[i]->num, operations[i]->temps);
    }

    printf("Entrez le nom du fichier: ");
    fgets(precedence, sizeof(precedence), stdin);
    precedence[strcspn(precedence, "\n")] = 0;
    //FILE * nouveau_fichier = creer_fichier_graphe(precedence, operations, &nmb_lignes);

    g = lire_graphe("nouveau_fichier.txt", nmb_lignes, 34);
    printf("numero du sommet initial : \n");
    scanf("%d", &sommet_init);
    afficher_pred(g, sommet_init, operations);
    /*
    for(int i=0; i<nmb_lignes; i++){
        printf("operations %d : rang %d", operations[i]->num, operations[i]->rang);
    }
    */
    for(int i = 0; i<nmb_lignes; i++){
        printf("operation %d : rang %d\n", operations[i]->num, operations[i]->rang);
    }
    for (int i = 0; i < nmb_lignes; i++) {
        free(operations[i]);
    }
    free(operations);
    return 0;
}