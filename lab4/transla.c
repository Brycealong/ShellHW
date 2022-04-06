#include <stdio.h>
#include <stdlib.h>

int transla(char DNA){
  if (DNA=='A'||DNA=='a') return 0;
  else if(DNA=='T'||DNA=='t') return 3;
  else if(DNA=='C'||DNA=='c') return 1;
  else if(DNA=='G'||DNA=='g') return 2;
  else return -1;
}
