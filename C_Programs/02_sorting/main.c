#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_DIM 50

typedef struct {
	char *input_name;
	char *output_name;
} Arguments;

void *sortFiles(void *args);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

int main(int argc, char *argv[]) {
	int i, n;
	char temp[MAX_DIM];
	pthread_t *tid;
	Arguments *args;
	
	n = atoi(argv[1]);
	tid = malloc(n*sizeof(pthread_t));
	args = malloc(n*sizeof(Arguments));
	
	for (i = 0; i < n; i++) {
		args[i].input_name = malloc((strlen(argv[2])+strlen(argv[1])+5)*sizeof(char));
		args[i].output_name = malloc((strlen(argv[3])+strlen(argv[1])+5)*sizeof(char));
		sprintf(args[i].input_name, "%s%d.txt", argv[2], i+1);
		sprintf(args[i].output_name, "%s%d.txt", argv[3], i+1);
		pthread_create(&(tid[i]), NULL, sortFiles, (void *) &(args[i]));
	}
	
	for (i = 0; i < n; i++)
		pthread_join(tid[i], NULL);
	
	free(tid);
	free(args);
	
	return 0;
}

void *sortFiles(void *args) {
	FILE *fpin, *fpout;
	int i, n, *vect;
	Arguments *filenames;
	
	filenames = (Arguments *) args;
	fpin = fopen(filenames->input_name, "r");
	fpout = fopen(filenames->output_name, "w");
	
	fscanf(fpin, "%d", &n);
	vect = malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
		fscanf(fpin, "%d", &(vect[i]));
	
	mergeSort(vect, 0, n);
	
	fprintf(fpout, "%d\n", n);
	for (i = 0; i < n; i++)
		fprintf(fpout, "%d\n", vect[i]);
	
	fclose(fpin);
	fclose(fpout);
	free(vect);
	
	return NULL;
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L, *R;

	L = malloc(n1*sizeof(int));
	R = malloc(n2*sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = (arr)[l + i];
    for (j = 0; j < n2; j++)
        R[j] = (arr)[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            (arr)[k] = L[i];
            i++;
        }
        else {
            (arr)[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        (arr)[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        (arr)[k] = R[j];
        j++;
        k++;
    }

	free(L); free(R);
}


