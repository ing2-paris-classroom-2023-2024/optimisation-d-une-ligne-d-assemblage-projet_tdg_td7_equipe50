//
// Created by leopo on 25/11/2023.
//
#include "lecture_contraintes.h"

int lecture_temps(char* fichier){
    FILE * ifs = fopen(fichier, "r");
    if(!ifs){
        printf("erreur ouverture fichier temps");
        exit(EXIT_FAILURE);
    }
    int temps_total = 0;
    fscanf(ifs, "%d", &temps_total);
    return temps_total;
}

t_operation *creer_operation(int num, float temps){
    t_operation *nouvelle_operation;
    nouvelle_operation = (t_operation *)malloc(sizeof(t_operation));
    nouvelle_operation->num = num;
    nouvelle_operation->temps = temps;
    nouvelle_operation->rang = 0;
    //j'initialise le rang de la nouvelle operation à 0 parce que j'ai besoin de lire le graphe de precedences pour pouvoir determiner le rang
    return nouvelle_operation;
}

t_operation **lire_operations(char * NomFichier, int *nmb_lignes){
    FILE * ifs = fopen(NomFichier, "r");

    if(!ifs){
        printf("erreur ouverture ifs\n");
        exit(-1);
    }
    *nmb_lignes = compter_nombre_operations(ifs);
    rewind(ifs);
    int num = 1;
    float temps = 0;
    t_operation **operation;
    operation = (t_operation **)malloc(sizeof(t_operation*) ** nmb_lignes);

    for(int i = 0; i< *nmb_lignes; i++){
        fscanf(ifs, "%d%f", &num, &temps);
        operation[i] = creer_operation(num, temps);
        operation[i]->compteur = i;
    }

    fclose(ifs);
    return (t_operation **) operation;
}

int compter_nombre_operations(FILE * fichier){
    int c;
    int nLignes = 0;
    while((c=fgetc(fichier)) != EOF)
    {
        if(c=='\n')
            nLignes++;
    }
    rewind(fichier);
    return nLignes;
}

FILE * creer_fichier_graphe(char* nomFichier, t_operation **operations, int *nmb_operations){
    FILE * fichier = fopen(nomFichier, "r");
    FILE * nouveau_fichier = fopen("nouveau_fichier.txt", "w+");
    if(!fichier){
        printf("erreur ouverture fichier");
        exit(EXIT_FAILURE);
    }
    int s1, s2;
    int nmb_lignes = compter_nombre_operations(fichier);
    for(int i=0; i<nmb_lignes; i++){
        fscanf(fichier, "%d%d",&s1,&s2);
        for(int j=0; j<*nmb_operations; j++){
            if(s1 == operations[j]->num){
                fprintf(nouveau_fichier, "%d", operations[j]->compteur);
            }
        }
        for(int k=0; k<*nmb_operations; k++){
            if(s2 == operations[k]->num){
                fprintf(nouveau_fichier, " %d\n", operations[k]->compteur);
            }
        }
    }
    return nouveau_fichier;
}