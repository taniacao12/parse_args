#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char ** parse_args( char * line ) {
  char *s1 = calloc(strlen(line), 1);
  char ** ret = calloc(6, sizeof(char *));
  strcpy(s1, line);
  for (int i = 0; s1; i++)
    ret[i] = strsep(&s1, " ");
  return ret;
}

int main() {
  char line[100] = "woah-this-is-cool";
  char *s1 = line;
  printf("[%s]\n", strsep(&s1, "-"));
  printf("line = [%s]\n", line);
  printf("s1 = [%s]\n", s1);
  
  char ** args = parse_args("ls -a -l");
  execvp(args[0], args);

  return 0;
}
