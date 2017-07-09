#include "internal_sorting.h"

void maxHeapify(Edge *edges, int n, int father){
	int son;
	Edge aux;
	
	son= 2*father +1;
	aux = edges[father];

	while(son<n){
		if(son+1<n && (edges[son].va<edges[son+1].va 
			|| (edges[son].va==edges[son+1].va && edges[son].vb<edges[son+1].vb))){
			son++;
		}

		if(aux.va < edges[son].va || (aux.va==edges[son].va && aux.vb<edges[son].vb)){
			edges[father] = edges[son];
			father = son;
			son = 2*father +1;
		}else{
			break;
		}
		edges[father] = aux;
	}
}

void buildHeap(Edge *edges, int n){
	int i;
	for(i=n/2; i>=0; i--){
		maxHeapify(edges,n,i);
	}	
}

void heapSort(Edge *edges, int n){
	Edge aux;
	buildHeap(edges, n);
	while(n>1){
		aux = edges[n-1];
		edges[n-1] = edges[0];
		edges[0] = aux;
		n--;
		maxHeapify(edges, n, 0);
	}
}
