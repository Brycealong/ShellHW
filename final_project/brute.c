#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brute.h"
#define MAX_NUM 400 //the maximum number of DNA sequences
#define MAX_LEN 800 //the maximum length of DNA sequences

//tell user the usage of this program
void usage(){
    printf( "USAGE:./apsp FILENAME\n [-om overlap_minimum]" );
    return;
}

//calculate the maximum overlap length between the prefix of s2 and the suffix of s1
int overlen(char s2[], char s1[]);

//find the shortest between the length of s1 and the length of s2
int find_min(char s1[], char s2[]);

int main(int argc, char** argv[]){
    if(argc != 2 && argc != 4){
        printf("Wrong Input!\n");
        usage();
        return -1;
    }

    char* FILE_NAME=argv[1];
    FILE *fp;
    fp=fopen(FILE_NAME,"r");
    if(fp==NULL)
    {
        perror("Fail to open!\n");
        return -1;
    }

    char DNA[MAX_NUM][MAX_LEN]={'\0'};
    char tmp;
    int i=-1,j=0,flag=0,om=10;

    if (strcmp(argv[2],"-om")) om=atoi(argv[3]);

    while((tmp=fgetc(fp))!=EOF)
    {
        if(tmp=='>')
        {
            DNA[i][j]='\0';
            i++;j=0;
            flag=1;
        }
        if(flag==1)
        {
            if(tmp=='\n')
            {
                flag=0;
            }
        }
        if(flag==0)
        {
            if((tmp=='A')|(tmp=='G')|(tmp=='C')|(tmp=='T'))
            {
                DNA[i][j]=tmp;
                j++;
            }
        }

    }
    fclose(fp);

    int num=i+1;
    int Ov[num][num];
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            Ov[i][j]=overlen(DNA[i],DNA[j]);
            if(Ov[i][j]>om)
            printf("%d,%d,%d\n",i,j,Ov[i][j]);
        }
    }

    return 0;
}
