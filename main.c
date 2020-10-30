#include <stdio.h>
#include <string.h>
#include "identifier.h"

int main(){
  char vetor[20];
  memset(vetor,0xaa,sizeof vetor);
  int outa = -1;
  printf("Identificador: ");
  scanf("%s"  ,vetor);
  outa = identifier(vetor);
  return outa;
}