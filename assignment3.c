#include <stdio.h>
#include <pthtread.h>

float totalShirts = 1000;
float temp;
void *takeShirtsA();
void *takeShirtsB();
void *takeShirtsC();

int main (int argc, char *argv[])
{
	pthread_t tid1, tid2, tid3;	//thread identifier
	pthread_attr_t attr;	//thread attributes

	pthread_create(&tid1, NULL, (void *(*)(void*))takeShirtsA, NULL);
	pthread_create(&tid2, NULL, (void *(*)(void*))takeShirtsB, NULL);
	pthread_create(&tid3, NULL, (void *(*)(void*))takeShirtsC, NULL)

	pthread_exit(0);
}

void *takeShirtsA(){
	while (totalShirts > 0){
		temp = 0;
		 temp = ( totalShirts / 3.0 );
		 if (temp != (int)temp){
		 	totalShirts -= (totalShirts (3 - 1) / 3) + 1;
		 }
		 printf("A takes away %d T-shirts", temp);
	}
} 
void *takeShirtsB(){
	while (totalShirts > 0){
		temp = 0;
		 temp -= ( totalShirts / 4.0 );
		 if (temp != (int)temp){
		 	totalShirts -= (totalShirts (4 - 1) / 4);
		 }
		 printf("B takes away %d T-shirts", temp);
	}
} 
void *takeShirtsC(){
	while (totalShirts > 0){
		temp = 0;
		 temp -= ( totalShirts / 5.0 );
		 if (temp != (int)temp){
		 	totalShirts -= (totalShirts (4 - 1) / 4);
		 }
		 printf("C takes away %d T-shirts", temp);
	}
} 