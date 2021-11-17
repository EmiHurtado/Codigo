/*
NOMBRE DE PROGRAMA: Ordenamiento shell
DESCRIPCIÓN: Ordenamiento de números con el algoritmo por Shell
que mejora el ordenamiento por inserción al crear subarreglos

FECHA: septiembre 2021
VERSIÓN: 1.2
AUTOR(ES): 
    Gómez Molina Ulises
    González Pérez Vanessa Berenice
    Hurtado Morales Emiliano
    Islas Osorio Enrique
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



void Shell(int*,int); 

/*Descripcion de la función:
Funcion main, se ingresan valores de n, arreglo
y despliega resultados
Input: arreglo numeros, tamaño n
Output: arreglo en orden ascendente
Observaciones: el valor del arreglo emplea malloc 
*/
int main(void) {
	
	int n,*A,valor;
	int i;
	
	scanf("%d",&n);
	A=malloc(sizeof(int)*n);
	
	if(A==NULL)
	{
		exit(1);
	}
	
	for(i=0;i<n;i++)
	scanf("%d",&A[i]);
	
	Shell(A,n);
	
	return 0;
}

/*Descripcion de la función:
Funcion para ordenar numeros con el 
algoritmo de ordenamiento por Shell
Recibe el arreglo dinamico y el numero de elementos
No devuelve ningun valor
*/
void Shell(int*A,int n)
{
	int k,b,i,temp=0;
	k=trunc(n/2);
	
	while(k>=1)
	{
		b=1;
		while(b!=0)
		{
			b=0;
			for(i=k;i<=n-1;i++)
			{
				if(A[i-k]>A[i])
				{
					temp=A[i];
					A[i]=A[i-k];
					A[i-k]=temp;
						b=b+1;
				}
			}
		}
		k=trunc(k/2);
	}
}
