#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 210
#define MAX_COLUMN 81

int main(){
    FILE *fp;
    char file[MAX_LINE][MAX_COLUMN]={0};
    char info[MAX_LINE][20][15]={0};
    int i = -1, j = 0;
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
    return 0;
}
