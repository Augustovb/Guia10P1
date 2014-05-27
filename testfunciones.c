#include <stdio.h>
#include <stdlib.h>


int main (void)
{

	float * mimatriz;

	mimatriz=makematrix(3,2);

	printmatrix(mimatriz);	// a ver que sale

	printf("Cree mi matriz de manera correcta, como se pidio.\n Ahora, voy a probar la de llenarla con numeros random, porque soy vago y no la quiero llenar yo.\n");

	randomatrix(mimatriz,1,25);	//Con numeros entre 0 y 10

	float * otramatriz;



	printf("Creo otra matriz\n");
	otramatriz=makematrix(3,4);

	randomatrix(otramatriz,1,5);
	printmatrix(mimatriz);



	int i,j;	//testeo de dos funciones
	printf("Testeo obtencion de filas\n");
	i=getfilas(mimatriz);

	printf("De columnas..\n");

	j=getcolumnas(mimatriz);

	printf("Mi matriz ( la 1, tiene) %d filas y %d columnas\n",i,j);


	printf("busco valor maximo\n");
	float k,l;
	k=getvalmax(mimatriz);

	printf("el minimo\n");

	l=getminval(mimatriz);

	printf("El valor maximo es %g, el minimo %g\n",k,l);



	float * resultado;

	resultado=sumatrix(mimatriz,otramatriz);


	resultado=sumatrix(mimatriz,mimatriz);

	printmatrix(resultado);

	printmatrix(mimatriz);

	resultado=restamatrix(mimatriz,mimatriz);

	printmatrix(resultado);




	printf("para finalizar, hago dos matrices para multiplicar");

	float * matA;
	float * matB;

	matA=makematrix(2,2);
	matB=makematrix(2,2);

	randomatrix(matA,0,4);
	randomatrix(matB,0,5);

	printmatrix(matA);

	printmatrix(matB);

	printf("el producto da...\n");

	resultado=productomatrix(matA,matB);

	printmatrix(resultado);



return 0;
}
