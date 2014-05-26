#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Hara randoms priero sin cambiar la semilla, luego, cambiandola.

int main (void)
{
	int i,j;

	printf("Sin modificar la seed:\n");

	for(i=0;i<10;++i)		//generara 10 randoms primero sin cambiar la seed
	{
		j=rand()%51;		//lo quiero entre 0 y 50
		printf("%d\n",j);
	}

	printf("Ahora modificare la seed:\n");


	srand(time(NULL));


	for (i=0;i<10;++i)		//ahora le modifico la seed
	{
		j=rand()%51;
		printf("%d\n",j);
	}



return 0;
}
