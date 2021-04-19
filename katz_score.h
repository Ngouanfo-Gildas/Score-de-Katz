#include <stdio.h>
#include <stdlib.h>

typedef struct NodeList NodeList;
struct NodeList {
    int node;
    NodeList *suivant;
};

typedef struct Liste Liste;
struct Liste {
    NodeList *premier;
};

