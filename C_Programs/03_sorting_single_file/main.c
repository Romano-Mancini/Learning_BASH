#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define DIM_FILE 5

typedef struct {
	FILE *fpin;
	int *mat;
} Arguments;

void *sortFiles(void *args);
void mergeSort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);

int main(int argc, char *argv[]) {
	FILE *fpout;
	int i, j, n, size = 0, **mat;
	char *input_name;
	pthread_t *tid;
	Arguments *arguments;
	
	n = atoi(argv[1]);
	tid = malloc(n*sizeof(pthread_t));
	input_name = malloc((strlen(argv[2])+strlen(argv[1])+5)*sizeof(char));
	arguments = malloc(n*sizeof(Arguments));
	mat = malloc(n*sizeof(int *));
	
	
	for (i = 0; i < n; i++) {
		mat[i] = malloc(DIM_FILE*sizeof(int));
		sprintf(input_name, "%s%d.txt", argv[2], i+1);
		arguments[i].fpin = fopen(input_name, "r");
		arguments[i].mat = mat[i];
		pthread_create(&(tid[i]), NULL, sortFiles, (void *) &(arguments[i]));
	}
	
	for (i = 0; i < n; i++) {
		pthread_join(tid[i], NULL);
		fclose(arguments[i].fpin);
		if (i != 0) {
 			for (j = 0; j < DIM_FILE; j++)
				mat[0][(i)*DIM_FILE+j] = mat[i][j];
			mergeSort(mat[0], 0, ((i+1)*DIM_FILE)-1);
			free(mat[i]);
		}
		size = size + DIM_FILE;
	}


	fpout = fopen(argv[3], "w");
	for (i = 0; i < n*DIM_FILE; i++)
		fprintf(fpout, "%d\n", mat[0][i]);
	fclose(fpout);

	free(tid);
	free(arguments);
	free(input_name);
	free(mat[0]);
	free(mat);
	return 0;
}

void *sortFiles(void *args) {
	int i, *vect;
	Arguments *argumen;
	
	argumen = (Arguments *) args;
	
	for (i = 0; i < DIM_FILE; i++) {
		fscanf(argumen->fpin, "%d", &(argumen->mat[i]));
	}	
	mergeSort(argumen->mat, 0, DIM_FILE - 1);

	return NULL;
}

void mergeSort(int *arr, int l, int r) {
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


