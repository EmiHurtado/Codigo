/*
NOMBRE DE PROGRAMA: Inserción
DESCRIPCIÓN: Ordenamiento de números con el algoritmo de inserción
 que mediante un tamaño del arreglo y números aleatorios, 
 realiza comparaciones e inserta el número donde observa que es mayor,
 de esto regresa regresa un array ordenado ascendentemente
OBSERVACIONES: el algoritmo realiza recorrido (e inserciones) 
en el tamaño total de su arreglo, se aplica uso de malloc para la creación del array.
FECHA: septiembre 2021
VERSIÓN: 1.2
AUTOR(ES): 
    Gómez Molina Ulises
    González Pérez Vanessa Berenice
    Hurtado Morales Emiliano
    Islas Osorio Enrique
*/

//LIBRERIAS

#include <stdio.h>
#include <stdlib.h>

/*Descripción de función:
Funcion para ordenar números con algoritmo de inserción
Input: arreglo de números, tamaño n
Output: arreglo en orden ascendente
Observaciones: el metodo de inserción es un poco más eficiente que
los métodos de burbuja, pero sigue teniendo un comportamiento
exponencial. Es un método parecido al ordenamiento humano.
Se emplean variables auxiliares para evitar errores de sintaxis.
*/

void Insercion(int*, int);

/*Descripción de función:
Funcion main, se ingresan valores de n, arreglo
y despliega resultados
Input: puntero a arreglo de números, tamaño n
Output: arreglo en orden ascendente
Observaciones: se emplea malloc con enteros en el arreglo.
Si se ingresan valores no enteros, no se logrará el
ordenamiento.
*/

int main(void) {
	
	int *A,n,i;//Variables del algoritmo y loops
	
	scanf("%d",&n);
	A=malloc(sizeof(int)*n);
	
	if(A == NULL)
		exit(1);
	
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	
	Insercion(A,n);
	
	for(i=0;i<n;i++)
		printf("\nArreglo ordenado[%d] %d",i,A[i]);	
		
	return 0;
}

/*Descripción de función:
Funcion para ordenar números con algoritmo por inserción
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
*/

void Insercion(int* A, int n){
	int i, j, temp;
	for(i=0 ; i<n ; i++){
		j=i;
		temp = A[i];
		//Ciclo while para el ordenamiento
		while(j>0 && temp<A[j-1]){
			A[j] = A[j-1];
			j--;
		}
		A[j] = temp;
	}
}
