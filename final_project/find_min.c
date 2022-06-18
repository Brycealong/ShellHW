int find_min(char s1[], char s2[]){
  if (strlen(s1) >= strlen(s2)) return strlen(s2);
  else return strlen(s1);
}
