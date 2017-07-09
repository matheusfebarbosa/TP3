#include "graph.h"

int verifyConflict(Edge a, Edge b){
	if((a.va < b.va && a.vb > b.vb) || (b.va < a.va && b.vb > a.vb)){
		return 1;
	}
	return 0;
}

void readGraph(Edge *edges, int n){
	int a,b,i;

	for(i=0; i<n; i++){
		scanf("%d%d",&a,&b);
		if(a%2==0){
			edges[i].va = a;
			edges[i].vb = b;
		}else{
			edges[i].va = b;
			edges[i].vb = a;
		}
		edges[i].conflicts = 0;
	}
}
