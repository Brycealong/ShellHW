/* lab4/include/codon.h */
#ifndef __CODON__
#define __CODON__
char condon(int base1, int base2, int base3);
int transla(char DNA);
#endif

/* lab4/src/codon.c */
#include <stdio.h>
#include <stdlib.h>
#define A 0
#define T 3
#define G 1
#define C 2

char condon(int base1, int base2, int base3)
{
  char base[4][4][4];
  int i;

  base[A][A][A]='K';base[A][A][G]='K';
  base[A][A][C]='N';base[A][A][T]='N';

  base[A][G][A]='R';base[A][G][G]='R';
  base[A][G][C]='S';base[A][G][T]='S';

  for(i=0;i<3;i++) base[A][C][i]='T';

  base[A][T][A]='I';base[A][T][G]='M';

  base[G][A][A]='E';base[G][A][G]='E';
  base[G][A][C]='N';base[G][A][T]='N';

  for(i=0;i<3;i++) base[G][G][i]='G';

  for(i=0;i<3;i++) base[G][C][i]='A';

  for(i=0;i<3;i++) base[G][T][i]='V';

  base[C][A][A]='Q';base[C][A][G]='Q';
  base[C][A][C]='H';base[C][A][T]='H';

  for(i=0;i<3;i++) base[C][G][i]='R';

  for(i=0;i<3;i++) base[C][C][i]='P';

  for(i=0;i<3;i++) base[C][T][i]='L';

  base[T][A][A]='*';base[T][A][G]='*';
  base[T][A][C]='Y';base[T][A][T]='Y';

  base[T][G][A]='*';base[T][G][G]='W';
  base[T][G][C]='C';base[T][G][T]='C';

  for(i=0;i<3;i++) base[T][C][i]='S';

  base[T][T][A]='L';base[T][T][G]='L';
  base[T][T][C]='F';base[T][T][T]='F';

  return base[base1][base2][base3];
}

int transla(char DNA)
{
  if(DNA=='A') return 0;
  else if(DNA=='T') return 3;
  else if(DNA=='C') return 2;
  else if(DNA=='G') return 1;
  else return -1;
}

/* lab4/src/main.c */
#include "codon.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i;
  char dna[3];
  int base[3];
  char amino;

  fflush(stdin);

  printf("please input:");

  dna[0]=getchar();
  dna[1]=getchar();
  dna[2]=getchar();

  while(dna[0] == 'G' || dna[1] != 'T' || dna[2] != 'G' ){

    dna[0]=dna[1];
    dna[1]=dna[2];
    dna[2]=getchar();

  }

  while(1){
    for(i=0;i<=2;++i) base[i]=transla(dna[i]);

    amino = condon(base[0],base[1],base[2]);
    printf("%c",amino);
    if (amino == '*') break;
    dna[0]=getchar();
    dna[1]=getchar();
    dna[2]=getchar();
  }
  printf("\n");

  return 0;
}
