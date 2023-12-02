//
// Created by leopo on 25/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_LECTURE_CONTRAINTES_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_LECTURE_CONTRAINTES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Operation{
    int num;//numero de l'operation(son indice)
    float temps;//temps d'execution de l'operation
    int rang;//le rang défini apres quelles operations on peut effectuer l'operation
}t_operation;

int compter_nombre_operations(FILE * fichier);

t_operation *creer_operation(int num, float temps);

t_operation **lire_operations(char *NomFichier, int *nmb_lignes);

int lecture_temps(char* fichier);


#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_LECTURE_CONTRAINTES_H
