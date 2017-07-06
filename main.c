#include <stdio.h>
#include "solutions.h"

int main(){
	char algType;
	Edge *flagLines;
	int n;

	scanf("%c",&algType);
	scanf("%d",&n);

	flagLines = calloc(n,sizeof(Edge));

	readInput(flagLines,n);
	
	switch(algType){
		case 'd':
			printf("%d\n",dinamico());
			break;
		case 'g':
			printf("%d\n",guloso(flagLines,n));
			break;
		case 'f':
			printf("%d\n",forca_bruta(flagLines,n));
			break;
		default:
			printf("Opção inválida\n");
			break;
	}

	return 0;
}