#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrix.h"

//ESTO VA A IR EN EL .H

float * makematrix (int rows, int column);  //creara una matriz con los elementos pedidos y en los primeros dos n° dara la cant de rows y columns 
void randomatrix (float * matrix,int minnum,int maxnum);	//se llamara si se quiere inicializar con numeros random y si no, flaco llenala vos
float * sumatrix (float * matrix1, float * matrix2);     //suma dos matrices, devuelve puntero a null si no se pueden sumar porque no son del mismo tamaño o no hay memoria suficiente para dar respuesta
float * restamatrix (float * matrix1, float * matrix2); //lo mismo que la de suma, pero con resta
float getvalmax (float * matrix);
float getminval (float * matrix);



#define ERROR 1





//HASTA ACA


void main ()
{
	printf("nada\n");
}

float getvalmax (float * matrix)
{

	int cantfilas,cantcolumnas;

	cantfilas=*(matrix-2);
	cantcolumnas=*(matrix-1);

	int i,j;
	float k=(float)0;
	for(i=0;i<cantfilas;++i)
	{
		for(j=0;j<cantcolumnas;++j)
		{
			if(k<(*(matrix+(i*cantcolumnas)+j)))
			{
				k=*(matrix+(i*cantcolumnas)+j);
			}
		}
	}

return k;
}


float getminval (float * matrix)
{

        int cantfilas,cantcolumnas;

        cantfilas=*(matrix-2);
        cantcolumnas=*(matrix-1);

        int i,j;
        float k=(float)0;
        for(i=0;i<cantfilas;++i)
        {
                for(j=0;j<cantcolumnas;++j)
                {
                        if(k>(*(matrix+(i*cantcolumnas)+j)))
                        {
                                k=*(matrix+(i*cantcolumnas)+j);
                        }
                }
        }

return k;
}









float * makematrix (int rows,int columns)
{

	float * matrix;

	matrix=(float *) malloc(((rows*columns)*(sizeof(float)))+2);
	if(matrix==NULL)
	{

	printf("Falta de memoria\n");

	return NULL;	//devolvera puntero a null si no hay suficiente memoria
	}


	*matrix=(float) rows;	//el primer numero es rows y el segundo las coumns

	*(matrix+1)=(float) columns;


return (matrix+2);
}

void randomatrix(float * matrix ,int minnum, int maxnum)
{

	srand(time(NULL));	//Para randomizar dependiendo tambien del numero maximo
	int i,j;

	int rows=(int)*(matrix-2);

	int columns=(int)*(matrix-1);


	for(i=0;i<rows;++i)
	{
		for(j=0;j<columns;++j)
		{
			*(matrix+(i*columns)+j)=minnum+(rand()%(maxnum-minnum+1));
		}
	}



}


float * sumatrix (float * matrix1, float * matrix2)	//suma dos matrices, devuelve puntero a null si no se pueden sumar porque no son del mismo tamaño o no hay memoria suficiente para dar respuesta
{
	//como primera instancia chequeo que las filas y columnas de las matrices 1 y dos sean iguales

	float rowsmat1, colsmat1;
	float rowsmat2, colsmat2;	//Creo 2 variables que sirven para ver cuales son los  tamaños de las matrices que recibo (deben ser iguales)


	rowsmat1=*(matrix1-2);

	colsmat1=*(matrix1-1);


	rowsmat2=*(matrix2-2);			//Recordando que el formato de matrices vienen dos lugares antes donde indican su tamaño

	colsmat2=*(matrix2-1);

	int estadotemp=0;


	if(colsmat2!=colsmat1)
	{
		estadotemp=ERROR;
		printf("Las matrices no tienen el mismo numero de columnas\n");
	}

	if(rowsmat1!=rowsmat2)
	{						//Modifico la variable estado temporal SI son de distinto tamaño
		estadotemp=ERROR;
		printf("Las MAtrices no tienen el mismo numero de filas\n");
	}


	if(estadotemp==0)
	{
	 	float * matresult;	//creo puntero a donde devolvere el resultado

		matresult=(float *)malloc(((rowsmat1*colsmat1)*(sizeof(float)))+2);
		if(matresult==NULL)
		{

			printf("No hay memoria para el resultado\n");
			return NULL;					//Devuelve no si no hay memoria para el resultado

		}

		*matresult=rowsmat1;
		*(matresult+1)=colsmat1;	//aplico el formato

		matresult=matresult+2;		//avanzo al inicio de la matriz en si

		int i,j;

		for(i=0;i<rowsmat1;++i)
		{

			for(j=0;i<colsmat1;++j)
			{

				*(matresult+(i*((int)colsmat1))+j)=(*(matrix1+(i*((int)colsmat1))+j))+(*(matrix2+(i*((int)colsmat1))+j));

			}

		}

		return matresult;

	}

	return NULL; //por si las dudas agrego este ultimo
}



float * restamatrix (float * matrix1, float * matrix2)
{
	//como primera instancia chequeo que las filas y columnas de las matrices 1 y dos sean iguales

	float rowsmat1, colsmat1;
	float rowsmat2, colsmat2;	//Creo 2 variables que sirven para ver cuales son los  tamaños de las matrices que recibo (deben ser iguales)


	rowsmat1=*(matrix1-2);

	colsmat1=*(matrix1-1);


	rowsmat2=*(matrix2-2);			//Recordando que el formato de matrices vienen dos lugares antes donde indican su tamaño

	colsmat2=*(matrix2-1);

	int estadotemp=0;


	if(colsmat2!=colsmat1)
	{
		estadotemp=ERROR;
		printf("Las matrices no tienen el mismo numero de columnas\n");
	}

	if(rowsmat1!=rowsmat2)
	{						//Modifico la variable estado temporal SI son de distinto tamaño
		estadotemp=ERROR;
		printf("Las MAtrices no tienen el mismo numero de filas\n");
	}


	if(estadotemp==0)
	{
	 	float * matresult;	//creo puntero a donde devolvere el resultado

		matresult=(float *)malloc(((rowsmat1*colsmat1)*(sizeof(float)))+2);
		if(matresult==NULL)
		{

			printf("No hay memoria para el resultado\n");
			return NULL;					//Devuelve no si no hay memoria para el resultado

		}

		*matresult=rowsmat1;
		*(matresult+1)=colsmat1;	//aplico el formato

		matresult=matresult+2;		//avanzo al inicio de la matriz en si

		int i,j;

		for(i=0;i<rowsmat1;++i)
		{

			for(j=0;i<colsmat1;++j)
			{

				*(matresult+(i*((int)colsmat1))+j)=(*(matrix1+(i*((int)colsmat1))+j))-(*(matrix2+(i*((int)colsmat1))+j));	//en vez de sumar, resto

			}

		}

		return matresult;

	}

	return NULL; //por si las dudas agrego este ultimo
}
