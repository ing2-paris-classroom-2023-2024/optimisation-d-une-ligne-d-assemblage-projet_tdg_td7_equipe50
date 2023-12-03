//
// Created by leopo on 25/11/2023.
//
#include "lecture_contraintes.h"
#include "file.h"

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

void enfiler_operations(t_operation ** operations, int nmb_operation){
    t_file_ope **file_rang = calloc(8, sizeof(t_file_ope*));
    for(int i=0; i<=7; i++){
        file_rang[i] = creer_file_ope();
    }
    for(int i =0; i<nmb_operation; i++){
        enfiler_ope(file_rang[operations[i]->rang], operations[i]);
    }
    t_file_ope * file_finale = creer_file_ope();
    for (int i = 0; i <= 7; i++) {
        while (file_rang[i]->tete != NULL) {
            enfiler(file_finale, defiler(file_rang[i]));
        }
        libererFile(file_rang[i]);
    }
    free(file_rang);

    // Afficher la file finale
    afficherFile(file_finale);
    libererFile(file_finale);
}

int exclusion(int s1, int s2, char *Fichier){
    FILE * fichier = fopen(Fichier, "r");
    int nmb_lignes = compter_nombre_operations(fichier);
    int ope1 = -1, ope2 = -1;
    rewind(fichier);
    for(int i =0; i<nmb_lignes; i++){
        fscanf(fichier, "%d%d", &ope1, &ope2);
        if((s1 == ope1 && s2 == ope2) || (s1 == ope2 && s2 == ope1)){
            return 1;
        }
    }
    return 0;
}