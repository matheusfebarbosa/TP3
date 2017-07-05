#include "internal_sorting.h"

void maxHeapify(int *va, int *vb, int n, int father){
	int son;
	int auxa,auxb;
	
	son= 2*father +1;
	auxa = va[father];
	auxb = vb[father];

	while(son<n){
		if(son+1<n && (va[son]<va[son+1] || (va[son]==va[son+1] && vb[son]<vb[son+1]))){
			son++;
		}

		if(auxa<va[son] || (auxa==va[son] && auxb<vb[son])){
			va[father] = va[son];
			vb[father] = vb[son];
			father = son;
			son = 2*father +1;
		}else{
			break;
		}
		va[father] = auxa;
		vb[father] = auxb;
	}
}

void buildHeap(int *va, int *vb, int n){
	int i;
	for(i=n/2; i>=0; i--){
		maxHeapify(va,vb,n,i);
	}	
}

void heapSort(int *va, int *vb, int n){
	int auxa,auxb;
	buildHeap(va,vb, n);
	while(n>1){
		auxa = va[n-1];
		auxb = vb[n-1];
		va[n-1] = va[0];
		vb[n-1] = vb[0];
		va[0] = auxa;
		vb[0] = auxb;
		n--;
		maxHeapify(va,vb, n, 0);
	}
}
