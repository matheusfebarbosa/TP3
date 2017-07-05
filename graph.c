#include "graph.h"

void insertEdge(Graph *g, int i, int y){

}

void makeEmptyGraph(Graph **g){
	*g = (Graph*) calloc(1,sizeof(Graph));
	*g->first = (EdgeCell*) calloc(1,sizeof(EdgeCell));
	*g->last = g->first;
}