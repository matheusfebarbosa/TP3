#include "solutions.h"

int verifyConflict(Edge a, Edge b){
	if((a.va < b.va && a.vb > b.vb) || (b.va < a.va && b.vb > a.vb)){
		return 1;
	}
	return 0;
}

void readInput(Edge *flagLines, int n){
	int a,b,i;


	for(i=0; i<n; i++){
		scanf("%d%d",&a,&b);
		if(a%2==0){
			flagLines[i].va = a;
			flagLines[i].vb = b;
		}else{
			flagLines[i].va = b;
			flagLines[i].vb = a;
		}
		flagLines[i].conflicts = 0;
	}
}

int dinamico(){
	int *rua1, *rua2;
	int *maiorSequencia;
	int n,a,b,i,j,max=0;

	scanf("%d",&n);

	rua1 = calloc(n,sizeof(int));
	rua2 = calloc(n,sizeof(int));
	maiorSequencia = calloc(n,sizeof(int));

	for(i=0; i<n; i++){
		scanf("%d%d",&a,&b);
		if(a%2==0){
			rua1[i] = a;
			rua2[i] = b;
		}else{
			rua1[i] = b;
			rua2[i] = a;
		}
		maiorSequencia[i]=1;
	}	

	heapSort(rua1, rua2, n);

	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(rua2[i]>rua2[j] && maiorSequencia[i]<maiorSequencia[j]+1)
				maiorSequencia[i] = maiorSequencia[j] + 1;

	for(i=0;i<n;i++)
		if(max<maiorSequencia[i])
			max = maiorSequencia[i];

	free(maiorSequencia);
	free(rua1);
	free(rua2);

	return max;
}

int guloso(Edge *flagLines, int n){
	int i,j,ibig;

	for(i=0;i<n; i++){
		for(j=i+1;j<n;j++){
			if(verifyConflict(flagLines[i],flagLines[j])){
				flagLines[i].conflicts++;
				flagLines[j].conflicts++;
				//printf("Conflito: par %d e par %d\n", i,j);
			}
		}
	}

	//printf("\n");
	while(n){
		ibig = 0;
		for(i=1; i<n; i++){
			if(flagLines[ibig].conflicts < flagLines[i].conflicts){
				ibig = i;
			}
		}

		if(flagLines[ibig].conflicts==0){
			break;
		}
		
		//printf("Par com mais conflitos: (%d,%d)\n",flagLines[ibig].va,flagLines[ibig].vb);

		for(i=0; i<n; i++){
			if(i!=ibig && verifyConflict(flagLines[ibig],flagLines[i])){
				flagLines[i].conflicts--;
			}
		}

		flagLines[ibig] = flagLines[n-1];
		n--;
	}

	free(flagLines);
	return n;
}


int forca_bruta(Edge *flagLines, int n){
	
	return 0;
}