#include <stdio.h>
#include <stdlib.h>

char *tras_amino(char DNA[]){
    int *DNAnum;
	DNAnum=(int *)malloc(2000);
	DNAnum=translation(DNA);
    int i,t;
    int k=0;
    char *amino;
    amino=(char *)malloc(500);
    for(t=0;DNAnum[t+3]!=-1;++t){
        if(DNAnum[t]!=2&&DNAnum[t+1]==3&&DNAnum[t+2]==2){
            for(i=t;DNAnum[i+3]!=-1;i+=3){
                amino[k]=codon(DNAnum[i],DNAnum[i+1],DNAnum[i+2]);
                if(amino[k]=='*') break;
                else k++;
        }
    }
    else continue;
    if(amino[k]=='*') break;
}
  return amino;
}

