//
// Created by leopo on 01/12/2023.
//
#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_STATIONS_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_STATIONS_H

#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include "lecture_contraintes.h"

typedef struct Station{
    int nmb_operations;
    float temps_station;
    t_operation **operations;
}t_station;

t_station *creer_station();

void trier_operations_par_rang(t_operation** operations, int nmb_operations);

void assigner_stations(t_operation** tab_operations, int nmb_operations, FILE * fichier_exclusion, FILE * fichier_temps);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_STATIONS_H
