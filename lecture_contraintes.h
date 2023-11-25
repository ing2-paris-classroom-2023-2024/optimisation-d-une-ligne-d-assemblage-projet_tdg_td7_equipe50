//
// Created by leopo on 25/11/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_LECTURE_CONTRAINTES_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_LECTURE_CONTRAINTES_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Operation{
    int num;
    int temps;
    int rang;
}t_operation;

typedef struct Station{
    int nmb_operations;
    t_operation *operations;
}t_station;



#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_LECTURE_CONTRAINTES_H
