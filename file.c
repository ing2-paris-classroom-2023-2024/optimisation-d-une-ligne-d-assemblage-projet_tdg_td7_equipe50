//
// Created by leopo on 22/09/2023.
//

#include "file.h"

//creation d'une file pour stocker les sommet à marquer

t_file *creer_file(){
    t_file *f;
    f = (t_file *)malloc(sizeof(t_file));
    if(f == NULL){
        printf("erreur creation file");
        exit(EXIT_FAILURE);
    }
    f->longueur = 0;
    f->tete = f->queue = NULL;
    return f;
}

//les maillons stockeront le numero du sommet dans la file

t_maillon *creer_maillon(int num){
    t_maillon *nouveau_maillon;
    nouveau_maillon = (t_maillon *)malloc(sizeof(t_maillon));
    nouveau_maillon->num = num;
    nouveau_maillon->suivant = NULL;
    return nouveau_maillon;
}

//sous programme pour enfiler un sommet à la fin de la file

void enfiler(t_file *f, int num){
    t_maillon *maillon = creer_maillon(num);
    if(!f){
        printf("la file n'existe pas");
        exit(EXIT_FAILURE);
    }
    if(f->longueur == 0){
        f->tete = f->queue = maillon;
        (f->longueur)++;
    }
    else{
        f->queue->suivant = maillon;
        f->queue = maillon;
        (f->longueur)++;
    }
}

//on defile depuis le debut de la file

int defiler(t_file *f){
    int num;
    if(!f || f->longueur == 0){
        printf("file nulle ou vide");
        exit(EXIT_FAILURE);
    }
    num = f->tete->num;
    t_maillon *maillon=f->tete;
    f->tete = f->tete->suivant;
    if(f->tete==NULL) f->queue=NULL;
    (f->longueur)--;
    free(maillon);
    return num;
}