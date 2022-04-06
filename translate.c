void translate()
{
    int i;
    char dna[3];
    int base[3];
    char amino;

    fflush(stdin);

    printf("please input a whole sequence:");

    dna[0]=getchar();
    dna[1]=getchar();
    dna[2]=getchar();


    for(i=0;i<=2;++i){
            if (transla(dna[i])==-1) {
                printf("\n");
                printf("error\n");
                exit (1);
    }
  }

    while(1){
            while((dna[0] == 'G' || dna[0] == 'g') || (dna[1] != 'T' && dna[1] != 't')|| (dna[2] != 'G' && dna[2] != 'g')){
                dna[0]=dna[1];
                dna[1]=dna[2];
                dna[2]=getchar();
                if (dna[2]=='\n') exit (0);
                if (transla(dna[2])==-1) {
                printf("\n");
                printf("error\n");
                exit (1);
                }
            }

            while(1){
                for(i=0;i<=2;++i) {
                    if (transla(dna[i])!=-1) base[i]=transla(dna[i]);
                    else {
                        printf("\n");
                        printf("error\n");
                        exit (1);
                    }
                }

            amino = codon(base[0],base[1],base[2]);
            printf("%c",amino);
            if (amino == '*') break;
            dna[0]=getchar();
            if(dna[0]=='\n') {printf(" It's the end of the sequence."); exit(0);}
            dna[1]=getchar();
            if(dna[1]=='\n') {printf(" It's the end of the sequence."); exit(0);}
            dna[2]=getchar();
            if(dna[2]=='\n') {printf(" It's the end of the sequence."); exit(0);}
        }

            dna[0]=getchar();
            if(dna[0]=='\n') {printf("\n"); exit(0);}
            if (transla(dna[2])==-1) {
                printf("\n");
                printf("error\n");
                exit (1);
                }
            dna[1]=getchar();
            if(dna[1]=='\n') {printf("\n"); exit(0);}
            if (transla(dna[2])==-1) {
                printf("\n");
                printf("error\n");
                exit (1);
                }
            dna[2]=getchar();
            if(dna[2]=='\n') {printf("\n"); exit(0);}
            if (transla(dna[2])==-1) {
                printf("\n");
                printf("error\n");
                exit (1);
                }

        printf("\n");
    }
    exit (0);
}
