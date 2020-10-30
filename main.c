#include <stdio.h>
#include <string.h>
#include "identifier.h"

int main(int argc, char *argv[]){
  char vetor[20];
  int outa = -1;
  memset(vetor,0xaa,sizeof vetor);
  strcpy(vetor,argv[1]);

  printf("\tIdentificador: %s\n", vetor);
  outa = identifier(vetor);
  if(outa ==0)
    printf("Valido");
  else
    printf("Invalido");
  
  return 0;
}