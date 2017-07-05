#include "solutions.h"

int dinamico(){
	int *rua1, *rua2;
	int *lis;
	int n,a,b,i,j,max=0;

	scanf("%d",&n);

	rua1 = calloc(n,sizeof(int));
	rua2 = calloc(n,sizeof(int));
	lis = calloc(n,sizeof(int));
	for(i=0; i<n; i++){
		scanf("%d%d",&a,&b);
		if(a%2==0){
			rua1[i] = a;
			rua2[i] = b;
		}else{
			rua1[i] = b;
			rua2[i] = a;
		}
		lis[i]=1;
	}	

	heapSort(rua1, rua2, n);

	for(i=1;i<n;i++)
		for(j=0;j<i;j++)
			if(rua2[i]>rua2[j] && lis[i]<lis[j]+1)
				lis[i] = lis[j] + 1;

	for(i=0;i<n;i++)
		if(max<lis[i])
			max = lis[i];

	free(lis);
	free(rua1);
	free(rua2);

	return max;
}

int guloso(){

	return 0;
}

int forca_bruta(){

	return 0;
}