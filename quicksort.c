/*
NOMBRE DE PROGRAMA: QuickSort (Ordenamiento r�pido)
DESCRIPCI�N: Ordenamiento de n�meros con el algoritmo Quicksort
el cual ordena los n�meros a partir de un pivote que usa como referencia. 
Utiliza recursividad

FECHA: septiembre 2021
VERSI�N: 1.2
AUTOR(ES): 
    G�mez Molina Ulises
    Gonz�lez P�rez Vanessa Berenice
    Hurtado Morales Emiliano
    Islas Osorio Enrique
*/
#include <stdio.h>
#include <stdlib.h>


void Quicksort(int*,int,int);


void intercambiar(int*,int,int);


int Pivot(int*,int,int);

/*Descripcion de la funci�n:
Funcion main que recibe el tama�o
del arreglo dinamico
Se crea un arreglo dinamico con la funci�n malloc 
para reservar memoria y se llena con valores dados del archivo de 1000 millones de numeros.
Manda a llamar a la funci�n Quicksort
*/
int main(int argc, char *argv[]) {
	
	int p,r,*A,n,i;
	
		scanf("%d",&n);
		//memoria dinamica del arreglo
	A=malloc(sizeof(int)*n);
	
	if(A==NULL)
	{
		exit(1);
	}
	
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	
	p=0;
	r=(n-1);
	Quicksort(A,p,r);
	return 0;
}


/*Descripcion de la funci�n:
Funcion recursiva que recibe el arreglo, el 
valor del primer y ultimo indice del arreglo
No devuelve ning�n valor
No tiene exepciones
*/
void Quicksort(int* A,int p,int r)
{
	int j;
	if(p<r)
	{
		j=Pivot(A,p,r);
		Quicksort(A,p,j-1);
		Quicksort(A,j+1,r);
	}
}


/*Descripcion de la funci�n:
Funcion para determinar el pivote del arreglo
dado y a partir de ah� encontrar los valores 
que sean mayores o menores que este. 
Recibe el arreglo, el primer y ultimo indice de
posiciones.
Devuelve el indice del pivote.
*/
int Pivot(int* A,int p,int r)
{
	int piv,i,j,temp;
	piv=A[p];
	i=p+1;
	j=r;
	while(1)
	{
		while (A[i]<piv && i<r)
	    {
		i++;
	    }
	    while(A[j]>piv)
	    {
	    	j--;
		}
		if(i<j)
		{
			intercambiar(A,i,j);
		}
		else
		{
			intercambiar(A,p,j);
			return j;
		}
	
	}
}


/*Descripcion de la funci�n:
Funcion que intercambia los valores 
de dos posiciones del arreglo.
Recibe el arreglo y el valor de los
dos indices de las posiciones que se van a 
intercambiar.
No devuelve valores
*/
void intercambiar(int *A,int i,int j)
{
	int temp=A[j];
	A[j]=A[i];
	A[i]=temp;
}
