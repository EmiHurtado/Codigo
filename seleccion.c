/*
NOMBRE DE PROGRAMA: Selecci�n
DESCRIPCIÓN: Consiste en encontrar el menor de todos los elementos del arreglo 
 e intercambiarlo con el que est� en la primera posici�n. Luego el segundo mas 
 peque�o, y as� sucesivamente hasta ordenarlo todo.
OBSERVACIONES: el algoritmo realiza recorrido (e intercambio) 
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
/*Descripción de función:
Funcion main, se ingresan valores de n, arreglo
y despliega resultados.
Para ordenar el arreglo por seleccion se utilizan dos ciclos,
uno para recorrer todo el arreglo e irlo ordenando  y otro para seleccionar 
el numero mas peque�o del resto del arreglo, se usa una variable temp para
intercambiar los numeros del arreglo
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
Observaciones: se emplea malloc con enteros en el arreglo
*/
int main(void)
{
	int n,k,i,temp,*A,p;// declaracion de variables
	scanf("%d",&n);
	
	A =  (int *) calloc(n, sizeof(int));
	if(A==NULL)
	{
		exit(-1);// si hay error al reservar memoria
	}
	//llenado de arreglo
	for(i=0;i<n;i++)
	{
		scanf("%d",&A[i]);

		printf("Arreglo sin ordenar: A[%d]: %d\n",i,A[i]);
	}
	//ordenamiento por seleccion
	for(k=0;k<=n-2;k++)
	{
		p=k;
		for(i=k+1;i<=n-1;i++)
		{
			if(A[i]<A[p])
			p=i;
			
		}
		temp= A[p];
		A[p]=A[k];
		A[k]=temp;
	}
	/*//para probar que ordena
	for(i=0;i<n;i++)
	{
		printf("Arreglo ordenado: A[%d]: %d\n",i,A[i]);
	}
	*/
}
