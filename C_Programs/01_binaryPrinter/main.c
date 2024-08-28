#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

void binary(int *vet, int *pid, int n);

int main(int argc, char *argv[]) {
  int n, *vet, *pid;

  n = atoi(argv[1]);

  vet = malloc(n * sizeof(int));
  pid = malloc(n * sizeof(int));
  if (vet == NULL) {
    printf("Allocation Error.\n");
    exit(1);
  }

  printf("Binary Numbers:\n");
  binary(vet, pid, n);
  free(vet);
  free(pid);
  return 0;
}


void binary(int *vet, int *pid, int n) {
	int i = 0;

	while (i != n) {
		vet[i] = 0;
		pid[i] = fork();
		if (!pid[i])
			i++;
		else {
			waitpid(pid[i], (int *) 0, 0);
			vet[i] = 1;
			i++;
		}
	}
	
	for (i = 0; i < n; i++)
		fprintf(stdout, "%d", vet[i]);
	fprintf(stdout, "\n");
	
	exit(0);
}



