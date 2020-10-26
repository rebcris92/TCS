#include "sort.h"

void sort(int* vet, int tam){
	int i, j, min, x;
    for (i=0; i<=tam-1; i++){
        min = i;
		for (j=i+1; j<tam; j++){
				if (vet[j] < vet[min])
				min = j;
		}
    x = vet[min];
    vet[min] = vet[i];
    vet[i] = x;
    }
}