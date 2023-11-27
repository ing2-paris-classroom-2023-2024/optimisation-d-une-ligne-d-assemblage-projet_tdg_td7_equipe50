//
// Created by leopo on 22/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graphe.h"
#include "lecture_contraintes.h"

int main(){
    char nomFichier[50];
    printf("Entrez le nom du fichier: ");
    fgets(nomFichier, sizeof(nomFichier), stdin);
    nomFichier[strcspn(nomFichier, "\n")] = 0;
    int nmb_lignes;
    t_operation **operations = lire_operations(nomFichier, &nmb_lignes);
    for(int i = 0; i<nmb_lignes; i++){
        printf("%d %f\n", operations[i]->num, operations[i]->temps);
    }
    for (int i = 0; i < nmb_lignes; i++) {
        free(operations[i]);
    }
    free(operations);

    return 0;
}