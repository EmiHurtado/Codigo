/*
NOMBRE DE PROGRAMA: Burbuja simple
DESCRIPCIÓN: Ordenamiento de números con el algoritmo de burbuja
 que mediante un tamaño del arreglo y números aleatorios, 
 realiza comparaciones e intercambios de posicion por todo el 
 tamaño del arreglo y regresa un array ordenado ascendentemente
OBSERVACIONES: el algoritmo realiza recorrido (e intercambios) 
en el tamaño total de su arreglo, se aplica uso de mallo en el tamaño del arreglo
COMPILACIÓN: gcc -o burbujaSimple.c burbujaSimple.exe (en Windows)
          
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
Funcion para ordenar números con algoritmo de burbuja
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
Observaciones: el metodo burbuja se emplea en su forma original, es decir
se realiza una comparacion por todo el tamaño del arreglo, 
se emplean variables auxiliares para evitar errores de sintaxis
*/
void burbujaSimple(int* A, int n);

/*Descripción de función:
Funcion main, se ingresan valores de n, arreglo
y despliega resultados
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
Observaciones: se emplea malloc con enteros en el arreglo
*/
int main(void){
    int n, *A, i; 
    printf("total numeros: ");
    scanf("%d",&n);
    //memoria dinamica del arreglo 
    A = malloc(sizeof(int)*n);
    //ingresan los numeros del arreglo
    for ( i = 0; i < n; i++){
        printf("numero: ");
        scanf("%d", &A[i]);
    }
    burbujaSimple(A,n);
    //devuelve arreglo ordenado
    printf("\n Arreglo ordenado: \n");
    for ( i = 0; i < n; i++){
        printf(" %d", A[i]);
    }
    return 0;
}


void burbujaSimple(int* A, int n) {
	int i, j, k, aux;
    //dos ciclos iterativos uno menor a otro para realizar 
    //recorridos e intercambio de posiciones 
    for (i= 0; i < n-2; i++) {
        for ( j = 0; j < n-2; j++) {
            int k = j + 1;
            if (A[j] > A[k]) {
                aux = A[j];
                A[j] = A[k];
                A[k] = aux;
            }
        }
    }
}