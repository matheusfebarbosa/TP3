#include "solutions.h"

int dinamico(Edge *flagLines, int n){
	int *maiorSequencia;
	int i,j,start,end,middle;

	maiorSequencia = calloc(n,sizeof(int));

	for(i=0; i<n; i++){
		maiorSequencia[i]=1;
	}	

	heapSort(flagLines, n);

    j=1;
    maiorSequencia[0] = flagLines[0].vb;
    for (i = 1; i < n; i++) {
        if (flagLines[i].vb < maiorSequencia[0]){
            maiorSequencia[0] = flagLines[i].vb;
        }else if (flagLines[i].vb  > maiorSequencia[j-1]){
            maiorSequencia[j++] = flagLines[i].vb;
        }else{
        	start=-1;
        	end=j-1;
        	while(end-start>1){
        		middle = start + (end-start)/2;
        		if(maiorSequencia[middle] < flagLines[i].vb){
        			start = middle; 
        		}else{
        			end = middle;
        		}
        	}
        	maiorSequencia[end] = flagLines[i].vb;
        }
    }

	free(maiorSequencia);

	return j;
}

int guloso(Edge *flagLines, int n){
	int i,j,ibig;

	for(i=0;i<n; i++){
		for(j=i+1;j<n;j++){
			if(verifyConflict(flagLines[i],flagLines[j])){
				flagLines[i].conflicts++;
				flagLines[j].conflicts++;
			}
		}
	}

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
		

		for(i=0; i<n; i++){
			if(i!=ibig && verifyConflict(flagLines[ibig],flagLines[i])){
				flagLines[i].conflicts--;
			}
		}

		flagLines[ibig] = flagLines[n-1];
		n--;
	}

	return n;
}

int try_options(Edge *flagLines, int *solution, int i, int n){
	if(i==n){
		int j,k,sum=0;
		
		for(k=0; k<n; k++)
			if(solution[k] == 1)
				for(j=k+1;j<n;j++)
					if(solution[j] ==1 && verifyConflict(flagLines[k],flagLines[j]))
						return 0;
		
		for(k=0; k<n; k++)
			sum += solution[k];

		return sum;
	}

	int opA,opB;

	solution[i] = 0;
	opA = try_options(flagLines,solution,i+1,n);

	solution[i] = 1;
	opB = try_options(flagLines,solution,i+1,n);

	if(opA > opB)
		return opA;
	else
		return opB;
}


int forca_bruta(Edge *flagLines, int n){
	int *solution;
	int ret;
	solution = calloc(n,sizeof(int));

	ret = try_options(flagLines,solution,0,n);

	free(solution);

	return ret;
}