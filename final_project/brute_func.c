#include <string.h>

int find_min(char s1[], char s2[]){
  if (strlen(s1) >= strlen(s2)) return strlen(s2);
  else return strlen(s1);
}

int overlen(char s1[], char s2[]){
    int min = find_min(s1, s2);
    int i, j;
    int overlen = 0;
    for (i = 1; i <= min; i++){
        int ct = 0;
        for (j = 0; j < i; j++){
            if (s1[strlen(s1)-i+j] == s2[j]) ct++;
        }
        if (ct == i) overlen = i;
    }
    return overlen;
}
