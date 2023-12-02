//
// Created by leopo on 01/12/2023.
//

#include "Stations.h"

t_station *creer_station(){
    t_station* nouvelle_station;
    nouvelle_station = (t_station*)malloc(sizeof(t_station));
    nouvelle_station->operations = NULL;
    nouvelle_station->nmb_operations = 0;
    nouvelle_station->temps_station = 0;
    return nouvelle_station;
}

/*
t_station** assigner_stations(t_operation** tab_operations, int *nmb_operations){
    t_station **tab_stations;
    tab_stations = (t_station**) malloc(sizeof(t_station*)**nmb_operations);
    int ope_traitees=0;
    int i =0;
    int t=0;
    while(ope_traitees< *nmb_operations){
        tab_stations[i] = creer_station();
        while(tab_stations[i]->temps_station<10){
            for(int j=0; j<tab_stations[i]->nmb_operations;j++){
                if(tab_operations[t]->rang){
                }
            }
        }
    }
    return (t_station**)tab_stations;
}
*/