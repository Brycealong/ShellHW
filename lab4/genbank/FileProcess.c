#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 210
#define MAX_COLUMN 81

int main(int argc, char *argv[]){
    FILE *fp;
    char file[MAX_LINE][MAX_COLUMN]={0};
    char info[MAX_LINE][20][15]={0};
    int i = -1, j = 0, k;
    if((fp = fopen("./NM000207.gb","r"))==NULL){  //open file
        perror("Fail to open!\n");
        return -1;
    }
    while((fgets(file[++i],MAX_COLUMN+1,fp))!=NULL){  //save one line to an array named file
        char *subfile = strtok(file[i]," ");
        while(subfile!=NULL){
            strcpy(info[i][j], subfile);  //save a word to an array named info
            subfile = strtok(NULL," ");  //read the next word
            j++;
        }
    }
    fclose(fp);  //close file
    //now the file is saved in two arrays
    
    if(argv[1] == 'L')printf("Locus: %s",info[0][1]);//print locus

    if(argv[1] == 'l')printf("Length: %s %s",info[0][2],info[0][3]);// print length

    if(argv[1] == 'D'){  //print definition
        printf("Definition:");
        for(i=1;i<=15;i++){
            printf(" %s",info[1][i]);
            if(info[1][i][0]==NULL)break;
        }
    }

    if(argv[1] == 'S'){  //print DNA sequence
        for(i=0;i<=MAX_LINE;i++){
            if(strcmp("ORIGIN",info[i][0])==0){
                printf("The DNA sequence is:\n");
                for(j=i+1;j<=209;j++){
                    for(k=1;k<=9;k++)printf("%s",info[j][k]);
                }
            }
        }
    }


    if(argv[1] == 'F'){  //print fasta file
        for(i=0;i<=MAX_LINE;i++){
            if(strcmp("ORIGIN",info[i][0])==0){
                printf(">NM_000207\n");
                for(j=i+1;j<=209;j++){
                    for(k=1;k<=9;k++)printf("%s",info[j][k]);
                }
            }
        }
    }
    
    return 0;
}
