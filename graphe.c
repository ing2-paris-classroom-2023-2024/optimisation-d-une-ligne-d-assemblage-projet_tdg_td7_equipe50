//
// Created by leopo on 25/11/2023.
//

#include "graphe.h"
#include "file.h"
#include "lecture_contraintes.h"

/* affichage des successeurs du sommet num*/
void afficher_successeurs(pSommet * sommet, int num)
{

    printf(" sommet %d :\n",num);

    pArc arc=sommet[num]->arc;

    while(arc!=NULL)
    {
        printf("%d ",arc->sommet);
        arc=arc->arc_suivant;
    }

}

// Ajouter l'arête entre les sommets s1 et s2 du graphe
pSommet* CreerArete(pSommet* sommet,int s1,int s2)
{
    if(sommet[s1]->arc==NULL)
    {
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;
        sommet[s1]->arc=Newarc;
        return sommet;
    }

    else
    {
        pArc temp=sommet[s1]->arc;
        while( !(temp->arc_suivant==NULL))
        {
            temp=temp->arc_suivant;
        }
        pArc Newarc=(pArc)malloc(sizeof(struct Arc));
        Newarc->sommet=s2;
        Newarc->arc_suivant=NULL;

        if(temp->sommet>s2)
        {
            Newarc->arc_suivant=temp->arc_suivant;
            Newarc->sommet=temp->sommet;
            temp->sommet=s2;
            temp->arc_suivant=Newarc;
            return sommet;
        }

        temp->arc_suivant=Newarc;
        return sommet;
    }
}

// créer le graphe
Graphe* CreerGraphe(int ordre)
{
    Graphe * Newgraphe=(Graphe*)malloc(sizeof(Graphe));
    Newgraphe->pSommet = (pSommet*)malloc(ordre*sizeof(pSommet));

    for(int i=0; i<ordre; i++)
    {
        Newgraphe->pSommet[i]=(pSommet)malloc(sizeof(struct Sommet));
        Newgraphe->pSommet[i]->couleur = 0;
        Newgraphe->pSommet[i]->valeur=i;
        Newgraphe->pSommet[i]->arc=NULL;
    }

    return Newgraphe;
}


/* La construction du réseau peut se faire à partir d'un fichier dont le nom est passé en paramètre
Le fichier contient : ordre, taille,orientation (0 ou 1)et liste des arcs */
Graphe * lire_graphe(char * nomFichier, int nmb_operations, int taille)
{
    Graphe* graphe;
    FILE * ifs = fopen(nomFichier,"r");
    int orientation, s1, s2;

    if (!ifs)
    {
        printf("Erreur de lecture fichier\n");
        exit(-1);
    }


    graphe=CreerGraphe(nmb_operations); // créer le graphe d'ordre sommets


    graphe->orientation=1;
    graphe->ordre=nmb_operations;

    // créer les arêtes du graphe
    for (int i=0; i<taille; ++i)
    {
        fscanf(ifs,"%d%d",&s1,&s2);
        graphe->pSommet=CreerArete(graphe->pSommet, s1, s2);

        if(!orientation) {
            graphe->pSommet = CreerArete(graphe->pSommet, s2, s1);
        }

    }
    return graphe;
}

/*affichage du graphe avec les successeurs de chaque sommet */
void graphe_afficher(Graphe* graphe)
{
    printf("graphe\n");

    if(graphe->orientation)
        printf("oriente\n");
    else
        printf("non oriente\n");

    printf("ordre = %d\n",graphe->ordre);

    printf("listes d'adjacence :\n");

    for (int i=0; i<graphe->ordre; i++)
    {
        afficher_successeurs(graphe->pSommet, i);
        printf("\n");
    }

}

int *bfs(Graphe *g, int sdep, t_operation ** operations){
    //création de la file et initialisation des couleurs et predecesseurs de chaques sommets
    t_file *file = creer_file();
    int* niveau = malloc(sizeof(int) * g->ordre);

    // Initialisation des niveaux à -1 (inconnu)
    for (int i = 0; i < g->ordre; i++) {
        niveau[i] = -1;
    }
    //initialisation de la couleur des sommets à 0 (non necessaire car j'ai ajouté une ligne dans le programme de la creation du graphe)
    for(int i=0; i<g->ordre; i++){
        g->pSommet[i]->couleur = 0;
    }
    //initialisation d'un tableau pour stocker le predecesseur de chaque sommet. -1 = pas de predecesseurs
    int*pred;
    pred = malloc(sizeof(int)*g->ordre);
    for(int i=0; i<g->ordre; i++){
        pred[i]=-1;
    }
    enfiler(file, sdep);//on enfile le sommet de depart pour pouvoir lancer la boucle
    niveau[sdep] = 0;
    g->pSommet[sdep]->couleur = 1;//une fois qu'on l'a vu on le marque
    while(file->longueur != 0){//tant que la file n'est pas vide

        //recuperation des sommets reliés à un autre inspiré du sous programme "afficher_successeurs"
        int i = defiler(file);//on prend le prochain sommet de la file afin de le marquer et voir si il a des voisins non marqués
        pArc arc = g->pSommet[i]->arc;
        while(arc!=NULL){//tant que le sommet qu'on regarde à des voisins, on va les mettre dans la file si ils ne sont pas deja marqués
            if (g->pSommet[arc->sommet]->couleur == 0) {
                enfiler(file, arc->sommet);
                g->pSommet[arc->sommet]->couleur = 1;
                pred[arc->sommet] = i;
                niveau[arc->sommet] = niveau[i] + 1; // Définir le niveau ici
                operations[arc->sommet]->rang = niveau[arc->sommet]; // Assigner le rang
            }
            //operations[g->pSommet[i]->valeur]->rang = rang;
            arc = arc->arc_suivant;
        }
    }
    //on retourne le tableau des predecesseur
    return pred;

}

void afficher_pred(Graphe* g, int sdep, t_operation** operations){
    //affichage des predecesseurs si il y en a
    int *pred;
    //recuperation des donnees avec le bfs
    pred = bfs(g, sdep, operations);
    for(int i =0; i<g->ordre; i++){
        if(pred[i] == -1){
            printf("predecesseur du sommet %d : pas de predecesseur\n", operations[i]->num);
        }else {
            printf("predecesseur du sommet %d : %d \n", operations[i]->num, pred[i]);
        }
    }
}