//
// Created by leopo on 03/12/2023.
//

#ifndef OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_FILE_H
#define OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_FILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct maillon{
    int num;
    struct maillon *suivant;
}t_maillon;

typedef struct file{
    int longueur;
    t_maillon *tete;
    t_maillon *queue;
}t_file;

t_file *creer_file();

t_maillon * creer_maillon(int num);

void enfiler(t_file *f, int num);

int defiler(t_file *f);


#endif //OPTIMISATION_D_UNE_LIGNE_D_ASSEMBLAGE_PROJET_TDG_TD7_EQUIPE50_FILE_H
