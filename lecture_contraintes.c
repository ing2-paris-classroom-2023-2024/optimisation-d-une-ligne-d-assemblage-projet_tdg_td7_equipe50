//
// Created by leopo on 25/11/2023.
//
#include "lecture_contraintes.h"

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