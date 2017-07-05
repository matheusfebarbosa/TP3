#include <stdio.h>
//#include "graph.h"
#include "solutions.h"

int main(){
	char algType;
	scanf("%c",&algType);

	switch(algType){
		case 'd':
			printf("%d\n",dinamico());
			break;
		case 'g':
			printf("%d\n",guloso());
			break;
		case 'f':
			printf("%d\n",forca_bruta());
			break;
		default:
			printf("Opção inválida\n");
			break;
	}

	return 0;
}