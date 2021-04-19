#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "katz_score.h"

/** FONCTION POUR LE SCORE DE KATZ */

Liste *listInitialisation() {
    Liste *liste = malloc(sizeof(*liste));
    NodeList *nodeList = malloc(sizeof(*nodeList));
    if (liste == NULL || nodeList == NULL) {
        exit(EXIT_FAILURE);
    }
    nodeList->node = 0;
    nodeList->suivant = NULL;
    liste->premier = nodeList;
}

/* --------------------------- new function ------------------------------------*/

void insertion(Liste *liste, int nvNode) {
    /* Création du nouvel élément */
    NodeList *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL) {
        exit(EXIT_FAILURE);
    }
    nouveau->node = nvNode;

    /* Insertion de l'élément au début de la liste */
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

/* --------------------------- new function ------------------------------------*/

void suppression(Liste *liste) {
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }
    if (liste->premier != NULL) {
        NodeList *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

/* --------------------------- new function ------------------------------------*/

void afficherListe(Liste *liste) {
    if (liste == NULL) {
        exit(EXIT_FAILURE);
    }
    NodeList *actuel = liste->premier;
    while (actuel != NULL) {
        printf("%d -> ", actuel->node);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

/* --------------------------- new function ------------------------------------*/

int* generate_node_list(Graph graph)
{
    int i;
    int *nodeList = malloc(sizeof(graph->nber_vetices));
    for (i = 0; i <= graph->nber_vetices; i++)
    {
        nodeList[i] = i;
    }
}

/* --------------------------- new function ------------------------------------*/

void neighbors(int x, Graph graph){

}

/* --------------------------- new function ------------------------------------*/

void computeKatzNode(int x, Graph graph, float beta, int L){
    
}

/* --------------------------- new function ------------------------------------*/

int atomic_dequeue()
{

}

/* --------------------------- new function ------------------------------------*/



/* --------------------------- new function ------------------------------------*/

