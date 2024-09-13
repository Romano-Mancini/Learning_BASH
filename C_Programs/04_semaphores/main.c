#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "semaphore.h"

sem_t s1,s2,s3,s4,s5,s6;

void *A(void *p) {
	sem_wait(&s1);
	fprintf(stdout, "A\n");
	sem_post(&s2);
	sem_post(&s2);
	sem_post(&s2);
	pthread_exit(NULL);
}

void *B(void *p) {
	sem_wait(&s2);
	fprintf(stdout, "B\n");
	sem_post(&s3);
	pthread_exit(NULL);
}

void *C(void *p) {
	sem_wait(&s2);
	fprintf(stdout, "C\n");
	sem_post(&s4);
	sem_post(&s4);
	pthread_exit(NULL);
}

void *D(void *p) {
	sem_wait(&s2);
	fprintf(stdout, "D\n");
	sem_post(&s5);
	pthread_exit(NULL);
}

void *E(void *p) {
	sem_wait(&s4);
	fprintf(stdout, "E\n");
	sem_post(&s6);
	pthread_exit(NULL);
}

void *F(void *p) {
	sem_wait(&s4);
	fprintf(stdout, "F\n");
	sem_post(&s6);
	pthread_exit(NULL);
}

void *G(void *p) {
	sem_wait(&s6);
	sem_wait(&s6);
	fprintf(stdout, "G\n");
	sem_post(&s3);
	pthread_exit(NULL);
}

void *H(void *p) {
	sem_wait(&s5);
	fprintf(stdout, "H\n");
	sem_post(&s3);
	pthread_exit(NULL);
}

void *I(void *p) {
	sem_wait(&s3);
	sem_wait(&s3);
	sem_wait(&s3);
	fprintf(stdout, "I\n");
	sem_post(&s1);
	pthread_exit(NULL);
}

int main(void) {
	sem_init(&s1, 0, 1);
	sem_init(&s2, 0, 0);
	sem_init(&s3, 0, 0);
	sem_init(&s4, 0, 0);
	sem_init(&s5, 0, 0);
	sem_init(&s6, 0, 0);
	
	pthread_t a,b,c,d,e,f,g,h,i;
	
	while (1) {
		pthread_create(&a, NULL, A, NULL);
		pthread_create(&b, NULL, B, NULL);
		pthread_create(&c, NULL, C, NULL);
		pthread_create(&d, NULL, D, NULL);
		pthread_create(&e, NULL, E, NULL);
		pthread_create(&f, NULL, F, NULL);
		pthread_create(&g, NULL, G, NULL);
		pthread_create(&h, NULL, H, NULL);
		pthread_create(&i, NULL, I, NULL);
		
		pthread_join(a, NULL);
		pthread_join(b, NULL);
		pthread_join(c, NULL);
		pthread_join(d, NULL);
		pthread_join(e, NULL);
		pthread_join(f, NULL);
		pthread_join(g, NULL);
		pthread_join(h, NULL);
		pthread_join(i, NULL);
		
		sleep(1);
		fprintf(stdout, "----\n");
	}
	
	sem_destroy(&s1);
	sem_destroy(&s2);
	sem_destroy(&s3);
	sem_destroy(&s4);
	sem_destroy(&s5);
	sem_destroy(&s6);
	
	return 0;
}

Given the following precedence graph:

       A  <--------
    /  |  \       ^
   /   |   \      |
  B    C    D     |
  |   / \   |     |
  |  /   \  |     |
  | E    F  |     |
  |  \   /  |     |
  |   \ /   |     |
  |    G    H     |
   \   |   /      |
    \  |  /       |
       I  ---------
       
in which each vertex corresponds to an independent task (a process or a thread).
Each task corresponds to a thread.
Each thread is (re-)created and destroyed at each iteration of the principal cycle.
Semaphores are implemented by means of the POSIX library, and types/functions sem_*.

