#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "matrix.h"


//ESTO VA A IR EN EL .H

float * makematrix (int rows, int column);  //creara una matriz con los elementos pedidos y en los primeros dos n° dara la cant de rows y columns 
void randomatrix (float * matrix,int minnum,int maxnum);	//se llamara si se quiere inicializar con numeros random y si no, flaco llenala vos






//HASTA ACA


float * makematrix (int rows,int columns)
{

	float * matrix;

	matrix=(float *) malloc(((rows*columns)*sizeof(float))+2);

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
			*(matrix+(i*columnas)+j)=minnum+(rand()%(maxnum-minnum+1));
		}
	}



}
