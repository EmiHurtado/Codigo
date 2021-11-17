/*
NOMBRE DE PROGRAMA: Burbuja optimizada 1
DESCRIPCIÓN: Ordenamiento de números con el algoritmo de
 burbuja optimizado que mediante el intervalo del arreglo se 
 reducen los recorridos e intercambios entre valores 
 para ordenar números en un arreglo

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

//DECLARACIÓN DE FUNCIONES 

/*Descripción de función:
Funcion para ordenar números con algoritmo de burbuja mejorada
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
Observaciones: se emplea una reducción en el rango del arreglo 
y variables para reducir la sintaxis
*/
void burbujaOpt1(int* A, int n);

/*Descripción de función:
Funcion main, se ingresan valores de n, arreglo
y despliega resultados
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
Observaciones: el valor del arreglo emplea malloc al ser esta A
de tamaño variable 
*/
int main(void){
    int n, *A, i;
    printf("total numeros: ");
    scanf("%i",&n);
    //memoria dinamica del arreglo
    A = malloc(sizeof(int)*n); 
    //ingresan numeros del arreglo
    for ( i = 0; i < n; i++){
        printf("numero: ");
        scanf("%d", &A[i]);
    }
    burbujaOpt1(A,n);
    //devuelve arreglo ordenado
    printf("\n Arreglo ordenado: \n");
    for ( i = 0; i < n; i++){
        printf(" %d", A[i]);
    }
    return 0;
}


void burbujaOpt1(int* A, int n) {
	int i, j, k, aux;
    //mediante dos ciclos, se van haciendo comparacione e intercambios
    for (i= 0; i < n-2; i++) {
        for ( j = 0; j < (n-2)-i; j++) { //rango externo - posicion
            int k = j + 1;
            if (A[j] > A[k]) {
                aux = A[j];
                A[j] = A[k];
                A[k] = aux;
            }
        }
    }
}