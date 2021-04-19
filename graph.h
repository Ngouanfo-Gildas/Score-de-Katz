#include <stdio.h>
#include <stdlib.h>

/* Définition d'un booléen*/
typedef enum
{
    false,
    true
}Bool;

/* Définition d'un noeud du graphe */
typedef struct NodeListElement
{
    int value;
    struct NodeListElement *next;
    
}NodeListElement, *NodeList;

/* Définition d'une liste d'adjacence */
typedef struct AdjacencyListElement
{
    NodeListElement *begin;
}AdjacencyListElement, *AdjacencyList;

/* Définition du graphe */
typedef struct GraphElement 
{
    Bool is_oriented;
    int nber_vetices;
    AdjacencyList tab_neighbors;
    FILE *graph_file;  // pour une manip avec graphviz
}GraphElement, *Graph;

Graph new_graph(int vertices, Bool is_oriented);

Bool is_empty_graph(Graph graph);

NodeList add_node(int node);

void add_edge(Graph graph, int scr, int dest);

void print_graph(Graph graph);

void erase_graph(Graph graph);

void display_graph(Graph graph);