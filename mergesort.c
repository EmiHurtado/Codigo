/*
NOMBRE DE PROGRAMA: Ordenamiento por mezcla
DESCRIPCIÓN: Ordenamiento de números con el algoritmo de mezcla
 su premisa es divide y venceras,como su nombre lo dice el arreglo 
 ser� dividido en dos sub-arreglos, luego estos sub-arreglos ser�n nuevamente divididos
  y as� sucesivamente, hasta que llega a un arreglo de dos elementos que puede ser f�cilmente ordenado. 
  Luego de llegar a estos sub-arreglos peque�os de 1 o 2 elementos, se comienzan a mezclar 
  los sub-arreglos formando nuevos arreglos ordenados.
OBSERVACIONES: Es un arreglo que utiliza recursividad 
en el tamaño total de su arreglo, se aplica uso de malloc en el tamaño del arreglo
FECHA: septiembre 2021
VERSIÓN: 1.2
AUTOR(ES): 
    Gómez Molina Ulises
    González Pérez Vanessa Berenice
    Hurtado Morales Emiliano
    Islas Osorio Enrique
*/

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
//declaracion de funciones
void MergeSort(int*,int,int);
void Merge(int *A,int,int,int);
/*Descripción de función:
Funcion main, se ingresan valores de n, arreglo
y despliega resultados
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
Observaciones: se emplea malloc con enteros en el arreglo
*/
int main()
{
	int n,i,*A;
	
	scanf("%d",&n);
	A =  (int *) malloc(n* sizeof(int));
	if(A==NULL)
	{
		return 0;
	}
	//llenado arreglo principal
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
	//	printf("\nArreglo principal[%d] %d",i,A[i]);	
	}
	MergeSort(A,0,n-1);
	/* //para probar que ordena
	for(i=0;i<n;i++)
	{
		printf("\nArreglo ordenado[%d] %d",i,A[i]);	
	}
	*/
}
//definicion de funciones

/*
Funcion para dividir el arreglo en sub-arreglos
Input: arreglo de numeros, primer indice de arreglo, ultimo indice de arreglo
Output: sub-arreglos
Observaciones: se usa recursividad para hacer los sub-arreglos
*/


void MergeSort(int *A,int p,int r)
{
	int q;
	if(p<r)
	{
		q= (p+r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
	
}
/*
Funcion para "mezclar" los sub-arreglos
Input: arreglo de numeros, primer indice de arreglo, indice de la mitad del arreglo, ultimo indice de arreglo
Output: arreglo ordenado
Observaciones: se usa recursividad para ordenar los sub-arreglos
*/
void Merge(int *A,int p,int q,int r)
{
	int l=r-p+1,i=p,j=q+1,k,*C;
	C=(int *) malloc((l+1)* sizeof(int));
	
	for(k=0;k<=l;k++)
	{
		if(i<=q && j<=r)
		{
			if(A[i]<A[j])
			{
				C[k]=A[i];
				i++;
			}
			else
			{
				C[k]=A[j];
				j++;
			}
		}
		else
		{
			if(i<=q)
			{
				C[k]=A[i];
				i++;
			}
			else
			{
				C[k]=A[j];
				j++;
			}
		}
	}
	for(k=p,i=0;k<=r;k++,i++)
	{
		A[k]=C[i];
	}
	
}
