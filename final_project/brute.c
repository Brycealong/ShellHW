#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brute.h"
#define MAX_NUM 400 //the maximum number of DNA sequences
#define MAX_LEN 1000 //the maximum length of DNA sequences

//tell user the usage of this program
void usage(){
    printf( "USAGE:./brute FILENAME [-om overlap_minimum]\n" );
    return;
}

//calculate the maximum overlap length between the prefix of s2 and the suffix of s1
int overlen(char s2[], char s1[]);

//find the shortest between the length of s1 and the length of s2
int find_min(char s1[], char s2[]);

int main(int argc, char* argv[]){
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
    char tmp1,tmp2='\n';
    int i=-1,j=0,flag=0,om=10;

    if(argc == 4){
    	if(strcmp(argv[2],"-om")==0) om=atoi(argv[3]);
	    else{
	        usage();
	        return -1;
	    }
    }
    
    while((tmp1=fgetc(fp))!=EOF)
    {
        if(tmp1=='>' && tmp2=='\n')
        {
            DNA[i][j]='\0';
            i++;j=0;
            flag=1;
        }
        if(flag==1)
        {
            if(tmp1=='\n')
            {
                flag=0;
            }
        }
        if(flag==0)
        {
            if((tmp1=='A')|(tmp1=='G')|(tmp1=='C')|(tmp1=='T')|(tmp1=='N'))
            {
                DNA[i][j]=tmp1;
                j++;
            }
        }
	tmp2=tmp1;
    }
    fclose(fp);

    int num=i+1;
    int Ov[num][num];
    for(i=0;i<num;i++){
        for(j=0;j<num;j++){
            if(i==j) Ov[i][j]=0;
	    else Ov[i][j]=overlen(DNA[i],DNA[j]);
            if(Ov[i][j]>om)
            printf("%d,%d,%d\n",i,j,Ov[i][j]);
        }
    }

    return 0;
}
