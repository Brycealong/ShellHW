#include <stdio.h>
#include <stdlib.h>

int *translation(char DNA[]){
    int i;
    int *num;
    num=(int *)malloc(1000);
    for(i=0;*(DNA+i)!='\0';++i){
         *(num+i)=transla(*(DNA+i));
    }
    *(num+i) = -1;
    return num;

}
