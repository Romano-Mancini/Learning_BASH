#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include "semaphore.h"

sem_t sa,sb,sc,sd,se,sf,sg,sh,si;

void *a(void *arg) {
	while (1) {
		sem_wait(&sa);
		fprintf(stdout, "A\n");
		sem_post(&sb);
		sem_post(&sc);
		sem_post(&sd);
	}
	
	pthread_exit(NULL);	
}

void *b(void *arg) {
	while (1) {
		sem_wait(&sb);
		fprintf(stdout, "B\n");
		sem_post(&si);
	}
	
	pthread_exit(NULL);	
}

void *c(void *arg) {
	while (1) {
		sem_wait(&sc);
		fprintf(stdout, "C\n");
		sem_post(&se);
		sem_post(&sf);
	}
	
	pthread_exit(NULL);	
}

void *d(void *arg) {
	while (1) {
		sem_wait(&sd);
		fprintf(stdout, "D\n");
		sem_post(&sh);
	}
	
	pthread_exit(NULL);	
}

void *e(void *arg) {
	while (1) {
		sem_wait(&se);
		fprintf(stdout, "E\n");
		sem_post(&sg);
	}
	
	pthread_exit(NULL);	
}

void *f(void *arg) {
	while (1) {
		sem_wait(&sf);
		fprintf(stdout, "F\n");
		sem_post(&sg);
	}
	
	pthread_exit(NULL);	
}

void *g(void *arg) {
	while (1) {
		sem_wait(&sg);
		sem_wait(&sg);
		fprintf(stdout, "G\n");
		sem_post(&si);
	}
	
	pthread_exit(NULL);	
}

void *h(void *arg) {
	while (1) {
		sem_wait(&sh);
		fprintf(stdout, "H\n");
		sem_post(&si);
	}
	
	pthread_exit(NULL);	
} 

void *i(void *arg) {
	while (1) {
		sem_wait(&si);
		sem_wait(&si);
		sem_wait(&si);
		fprintf(stdout, "I\n");
		sem_post(&sa);
		fprintf(stdout, "---\n");
		sleep(1);
	}
	
	pthread_exit(NULL);	
}


int main(void) {
	pthread_t ta,tb,tc,td,te,tf,tg,th,ti;
	
	sem_init(&sa, 0, 1);
	sem_init(&sb, 0, 0);
	sem_init(&sc, 0, 0);
	sem_init(&sd, 0, 0);
	sem_init(&se, 0, 0);
	sem_init(&sf, 0, 0);
	sem_init(&sg, 0, 0);
	sem_init(&sh, 0, 0);
	sem_init(&si, 0, 0);				
	
	pthread_create(&ta, NULL, a, NULL);
	pthread_create(&tb, NULL, b, NULL);
	pthread_create(&tc, NULL, c, NULL);
	pthread_create(&td, NULL, d, NULL);
	pthread_create(&te, NULL, e, NULL);
	pthread_create(&tf, NULL, f, NULL);
	pthread_create(&tg, NULL, g, NULL);
	pthread_create(&th, NULL, h, NULL);
	pthread_create(&ti, NULL, i, NULL);
	
	pthread_join(ta, NULL);
	pthread_join(tb, NULL);
	pthread_join(tc, NULL);
	pthread_join(td, NULL);
	pthread_join(te, NULL);
	pthread_join(tf, NULL);
	pthread_join(tg, NULL);
	pthread_join(th, NULL);
	pthread_join(ti, NULL);
	
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
Threads are all cyclic and they are created and destroyed only one time in the principal cycle.
Semaphores are implemented by means of the POSIX library, and types/functions sem_*. 
