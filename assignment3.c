#include <stdio.h>
#include <pthread.h>

struct Vars
{
	float totalShirts;
	float temp;
};

void *takeShirtsA();
void *takeShirtsB();
void *takeShirtsC();
struct Vars vars;


pthread_mutex_t mutex;

int main (int argc, char *argv[])
{
	vars.totalShirts = 1000.0;
	vars.temp = 0;
	pthread_t tid1, tid2, tid3;	//thread identifier
	pthread_attr_t attr;	//thread attributes


	printf("A takes away %d T-shirts \n", vars.totalShirts);
	printf("A takes away %d T-shirts \n", vars.temp);
	pthread_create(&tid1, NULL, (void *(*)(void*))takeShirtsA, NULL);
	pthread_create(&tid2, NULL, (void *(*)(void*))takeShirtsB, NULL);
	pthread_create(&tid3, NULL, (void *(*)(void*))takeShirtsC, NULL);

	pthread_exit(0);
}

void *takeShirtsA(){
	while (vars.totalShirts > 0){
		pthread_mutex_lock(&mutex);

		printf("A takes away %d T-shirts \n", vars.totalShirts);
		vars.temp = 0;
		vars.temp = ( vars.totalShirts / 3.0 );

		if (vars.temp != (int)vars.temp){
			vars.temp = ((vars.totalShirts + (3 - 1) / 3) + 1);
			vars.totalShirts = vars.totalShirts - vars.temp;
		}
		else {
			vars.totalShirts = vars.totalShirts - vars.temp;
		}
		printf("temp takes away %d T-shirts\n", vars.temp);
		pthread_mutex_unlock(&mutex);
	}
} 
void *takeShirtsB(){
	while (vars.totalShirts > 0){
		pthread_mutex_lock(&mutex);
		vars.temp = 0;
		vars.temp = ( vars.totalShirts / 4.0 );

		if (vars.temp != (int)vars.temp){
			vars.temp = ((vars.totalShirts + (4 - 1) / 4) + 1);
			vars.totalShirts = vars.totalShirts - vars.temp;
		}
		else {
			vars.totalShirts = vars.totalShirts - vars.temp;
		}
		printf("B takes away %d T-shirts\n", vars.temp);
		pthread_mutex_unlock(&mutex);
	}
} 
void *takeShirtsC(){
	while (vars.totalShirts > 0){
		pthread_mutex_lock(&mutex);
		vars.temp = 0;
		vars.temp = ( vars.totalShirts / 5.0 );

		if (vars.temp != (int)vars.temp){
			vars.temp = ((vars.totalShirts + (5 - 1) / 5) + 1);
			vars.totalShirts = vars.totalShirts - vars.temp;
		}
		else {
			vars.totalShirts = vars.totalShirts - vars.temp;
		}
		printf("C takes away %d T-shirts\n", vars.temp);
		pthread_mutex_unlock(&mutex);
	}
} 