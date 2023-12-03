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

t_file_ope *creer_file_ope(){
    t_file_ope *file = malloc(sizeof(t_file_ope));
    file->tete = file->queue = NULL;
    return file;
}

void enfiler_ope(t_file_ope * file, t_operation * operation) {
    if (file->queue == NULL) {
        file->tete = file->queue = operation;
    } else {
        file->queue->suivant = operation;
        file->queue = operation;
    }
    operation->suivant = NULL;
}

t_operation * defiler_ope(t_file_ope * file) {
    if (file->tete == NULL) return NULL;
    t_operation * operation = file->tete;
    file->tete = file->tete->suivant;
    if (file->tete == NULL) {
        file->queue = NULL;
    }
    operation->suivant = NULL; // Détacher l'opération de la file
    return operation;
}

void libererFile(t_file_ope * file) {
    while (file->tete != NULL) {
        t_operation* temp = defiler_ope(file);
        free(temp);
    }
    free(file);
}

void afficherFile(t_file_ope * file) {
    t_operation * ope = file->tete;
    while (ope != NULL) {
        printf("Operation %d de rang %d\n", ope->num, ope->rang);
        ope = ope->suivant;
    }
}
