#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

char ** parse_args( char * line ) {
	char *s1 = line;
  char ** ret;
	while (s1) {
		strcat(line, strsep(line, " "));
	}
	return ret;
}

int main() {
	char line[100] = "woah-this-is-cool";
	char *s1 = line;
	printf("[%d]\n", strsep(&s1, "-"));
	printf("line = [%s]\n", line);
	printf("s1 = [%s]\n", s1);
  
	strcpy(line, "ls -a -l");
	char ** args = parse_args(line);
	execvp(args[0], args);

  return 0;
}
