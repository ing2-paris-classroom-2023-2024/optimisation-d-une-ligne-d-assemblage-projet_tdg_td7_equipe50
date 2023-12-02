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
t_station** assigner_stations(t_operation** tab_operations, int* nmb_operations);

#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_STATIONS_H
