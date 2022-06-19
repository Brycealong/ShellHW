#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tell user the usage of this program
void usage(){
    printf( "USAGE:./utol FILENAME\n");
    return;
}

//transform a fasta file into several .txt files that contain only one DNA sequence in lowercase each, so that they can be read by AGESA
int main(int argc, char* argv[]){
    if(argc != 2)
    {
        printf("Wrong Input!\n");
        usage();
        return -1;
    }

    char* FILE_NAME=argv[1];
    FILE *fp1, *fp2;
    char filename[10]={0};
    fp1=fopen(FILE_NAME,"r");
    if(fp1==NULL)
    {
        perror("Fail to open!\n");
        return -1;
    }

    int i=0,flag=0;
    char tmp1,tmp2='\n';
    while((tmp1=fgetc(fp1))!=EOF)
    {
        if(tmp1=='>' && tmp2=='\n')
        {
	          i++;
            sprintf(filename,"%d.txt",i);
            fp2=fopen(filename,"w");
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
                tmp1=tmp1+32;
                fprintf(fp2,"%c",tmp1);
            }
        }
	      tmp2=tmp1;
    }
    fclose(fp2);
    fclose(fp1);
    return 0;
}
