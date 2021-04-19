#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "graph.h"

void *do_work(){
    /*while(nodeList.suivant != NULL){
        x = atomic_dequeue(nodeList);
        Ksc[x] = computeKatzNode(x, graph, beta, L);
    }*/
    printf("toto\n");
}

int main(int argc, char const *argv[])
{
    /* DECLARATION DES VARIABLES */
    int t; 
    int n_threads = atoi(argv[1]);
    int rc;
    pthread_t threads[n_threads];
    void *status;

    Graph graph = new_graph(5, true);

    add_edge(graph, 1, 2);
    add_edge(graph, 2, 5);
    add_edge(graph, 3, 2);
    add_edge(graph, 1, 5);    
    add_edge(graph, 3, 4);
    add_edge(graph, 3, 1);
    add_edge(graph, 4, 5);

    print_graph(graph);
    display_graph(graph);
    erase_graph(graph);

    //Liste *maListe = listInitialisation();
    for (t=0; t<n_threads; t++){
        rc = pthread_create(&threads[t], NULL, do_work, NULL);
    }

    /* Free attribute and wait for the other threads */
    for(t=0; t<n_threads; t++) {
        rc = pthread_join(threads[t], &status);
        if (rc) {
            printf("ERROR; return code from pthread_join() is %d\n", rc);
            exit(-1);
        }
        printf("Main: completed join with thread %d having a status of %ld\n",t,(long)status);
    }
    
    puts("\n##########  FIN DU PROGRAMME  ##########\n");
    //pthread_exit(NULL);
    return 0;
}
