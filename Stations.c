//
// Created by leopo on 01/12/2023.
//

#include "Stations.h"

t_station *creer_station(){
    t_station* nouvelle_station;
    nouvelle_station = (t_station*)malloc(sizeof(t_station));
    nouvelle_station->operations = NULL;
    nouvelle_station->operations = (t_operation **)malloc(sizeof(t_operation));
    nouvelle_station->nmb_operations = 0;
    nouvelle_station->temps_station = 0;
    return nouvelle_station;
}

void trier_operations_par_rang(t_operation** operations, int nmb_operations) {
    for (int i = 1; i < nmb_operations; i++) {
        t_operation* key = operations[i];
        int j = i - 1;
        while (j >= 0 && operations[j]->rang > key->rang) {
            operations[j + 1] = operations[j];
            j = j - 1;
        }
        operations[j + 1] = key;
    }
}

void assigner_stations(t_operation** operations, int nmb_operations, FILE* fichier_exclusion, FILE* fichier_temps) {
    trier_operations_par_rang(operations, nmb_operations);
    t_station **tab_stations = malloc(sizeof(t_station *) * nmb_operations);

    int ope_traitees = 0;
    int temps_total = lecture_temps(fichier_temps);
    int i = 0;

    for (int h = 0; h < nmb_operations; h++) {
        operations[h]->couleur = 0;
    }

    while (ope_traitees < nmb_operations) {
        tab_stations[i] = creer_station();
        int exclusion_trouvee;
        do {
            exclusion_trouvee = 0;
            for (int k = 0; k < nmb_operations; k++) {
                if (operations[k]->couleur == 0) {
                    for (int g = 0; g < tab_stations[i]->nmb_operations; g++) {
                        if (exclusion(operations[k]->num, tab_stations[i]->operations[g]->num, fichier_exclusion)) {
                            exclusion_trouvee = 1;
                            break;
                        }
                    }
                    if (!exclusion_trouvee && tab_stations[i]->temps_station + operations[k]->temps <= temps_total) {
                        tab_stations[i]->operations[tab_stations[i]->nmb_operations++] = operations[k];
                        operations[k]->couleur = 1;
                        tab_stations[i]->temps_station += operations[k]->temps;
                        ope_traitees++;
                    }
                }
            }
            if (exclusion_trouvee) {
                i++;
                if (i >= nmb_operations) {
                    printf("Erreur: Plus de stations nécessaires que d'opérations disponibles.\n");
                    exit(EXIT_FAILURE);
                }
                tab_stations[i] = creer_station();
            }
        } while (exclusion_trouvee);
    }
    for (int nmb_stations = 0; nmb_stations <= i; nmb_stations++) {
        printf("\nStation %d :\n", nmb_stations + 1);
        for (int o = 0; o < tab_stations[nmb_stations]->nmb_operations; o++) {
            printf("Operation %d\n", tab_stations[nmb_stations]->operations[o]->num);
        }
        printf("Temps station : %f\n\n", tab_stations[nmb_stations]->temps_station);
    }
    for (int j = 0; j <= i; j++) {
        free(tab_stations[j]->operations);
        free(tab_stations[j]);
    }
    free(tab_stations);
}

