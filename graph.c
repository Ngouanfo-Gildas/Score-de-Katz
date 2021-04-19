#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

Graph new_graph(int vertices, Bool is_oriented)
{
    int i;
    GraphElement *element;
    element = malloc(sizeof(*element));

    if (element == NULL)
    {
        fprintf(stderr, "Erreur: Problème de création du graph.\n");
        exit(EXIT_FAILURE);
    }
    
    element->is_oriented = is_oriented;
    element->nber_vetices = vertices;
    element->tab_neighbors = malloc(vertices * sizeof(AdjacencyListElement));

    if (element->tab_neighbors == NULL)
    {
        fprintf(stderr, "Erreur: Problème de création du graph.\n");
        exit(EXIT_FAILURE);
    }

    for (i=1; i<=element->nber_vetices; i++)
    {
        element->tab_neighbors[i-1].begin = NULL;
    }

    /* Pour une manipulation (affichage) avec graphviz */

    if (element->is_oriented)
        element->graph_file = fopen("digraph.out", "w");
    else
        element->graph_file = fopen("graph.out", "w");
    
    if (element->graph_file == NULL)
    {
        fprintf(stderr, "Erreur: Problème de création du fichier.\n");
        exit(EXIT_FAILURE);
    }

    if (element->is_oriented)
        fprintf(element->graph_file, "digraph my_graph\n{\n");
    else
        fprintf(element->graph_file, "graph my_graph\n{\n");
    //
    return element;
}

/* --------------------------- new function ------------------------------------*/

Bool is_empty_graph(Graph graph)
{
    if (graph == NULL)
        return true;
    return false;
}

/* --------------------------- new function ------------------------------------*/

NodeList add_node(int nwNode)
{
    NodeList node = malloc(sizeof(NodeListElement));

    if (node == NULL)
    {
        fprintf(stderr, "Erreur: Problème de création du noeud.\n");
        exit(EXIT_FAILURE);
    }
    
    node->value = nwNode;
    node->next = NULL;
    
    return node;
}

/* --------------------------- new function ------------------------------------*/

void add_edge(Graph graph, int scr, int dest)
{
    NodeList node = add_node(dest);
    node->next = graph->tab_neighbors[scr-1].begin;
    graph->tab_neighbors[scr-1].begin = node;

    if (!graph->is_oriented)
    {
        node = add_node(scr);
        node->next = graph->tab_neighbors[dest-1].begin;
        graph->tab_neighbors[dest-1].begin = node;
    }

    /* Ajout des liasons dans le fichier graphviz */
    if (graph->is_oriented)
        fprintf(graph->graph_file, "\t%d -> %d;\n",scr, dest);
    else
        fprintf(graph->graph_file, "\t%d -- %d;\n",scr, dest);
    return;
}

/* --------------------------- new function ------------------------------------*/

void erase_graph(Graph graph)
{
    if (is_empty_graph(graph))
    {
        printf ("Rien à supprimer\n");
        return;
    }

    // si sommets adjacents
    if (graph->tab_neighbors)
    {
        int i;
        for (i = 1; i <= graph->nber_vetices; i++)
        {
            NodeList node = graph->tab_neighbors[i-1].begin;
            while (node != NULL)
            {
                NodeList tmp = node;
                node = node->next;
                free(tmp);
            }
        }
        // libération de la liste d'adjacence
        free(graph->tab_neighbors);
    }

    //Fin et fermeture du fichier graphviz
    fprintf(graph->graph_file, "}\n");
    fclose(graph->graph_file);

    // libération du graphe
    free(graph);
}

/* --------------------------- new function ------------------------------------*/

void print_graph(Graph graph)
{
    int i;

    for (i = 1; i <= graph->nber_vetices; i++)
    {
        NodeList node = graph->tab_neighbors[i-1].begin;
        printf("[%d]: ",i);

        while (node != NULL)
        {
            printf("%d, ",node->value);
            node = node->next;
        }
        printf("NULL\n");    
    }    
}

/* --------------------------- new function ------------------------------------*/

void display_graph(Graph graph)
{
    if (graph->is_oriented)
        system("dotty digraph.out");
    else 
        system("dotty.lefty graph.out");
}

