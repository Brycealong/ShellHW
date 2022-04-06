#include <stdio.h>
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

    for(i=0;i<=3;i++) base[A][C][i]='T';

    base[A][T][A]='I';base[A][T][G]='M';
    base[A][T][C]='I';base[A][T][T]='I';

    base[G][A][A]='E';base[G][A][G]='E';
    base[G][A][C]='N';base[G][A][T]='N';

    for(i=0;i<=3;i++) base[G][G][i]='G';

    for(i=0;i<=3;i++) base[G][C][i]='A';

    for(i=0;i<=3;i++) base[G][T][i]='V';

    base[C][A][A]='Q';base[C][A][G]='Q';
    base[C][A][C]='H';base[C][A][T]='H';

    for(i=0;i<=3;i++) base[C][G][i]='R';

    for(i=0;i<=3;i++) base[C][C][i]='P';

    for(i=0;i<=3;i++) base[C][T][i]='L';

    base[T][A][A]='*';base[T][A][G]='*';
    base[T][A][C]='Y';base[T][A][T]='Y';

    base[T][G][A]='*';base[T][G][G]='W';
    base[T][G][C]='C';base[T][G][T]='C';

    for(i=0;i<=3;i++) base[T][C][i]='S';

    base[T][T][A]='L';base[T][T][G]='L';
    base[T][T][C]='F';base[T][T][T]='F';

    return base[base1][base2][base3];
}
