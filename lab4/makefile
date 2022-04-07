OBJS = translate.o transla.o tras_amino.o translation.o codons.o
CC = gcc

FileProcess: FileProcess.c
	$(CC) $^ -lcodon -o $@ -I include -L lib -static

translatemain: translatemain.c
	$(CC) $^ -lcodon -o $@ -I include -L lib -static

lib/libcodon.a: $(OBJS)
	ar cr $@  $(OBJS)

%.o: %.c
	$(CC) -std = c99 -c $^ -o $@
clean:
	$(RM) *.o FileProcess translatemain -r
