/*
NOMBRE DE PROGRAMA: Burbuja optimizada 2
DESCRIPCIÓN: Ordenamiento de números con el algoritmo de
 burbuja optimizado que mediante una bandera notifica si se 
 requieren modificaciones y si no, el arreglo esta ordenado
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
Observaciones: se maneja bandera tipo boolean, 
donde: 1 es true, 0 es false, la posicion de i se va acumulando 
*/
void burbujaOpt2(int* A, int n);

/*Descripción de función:
Funcion main, se ingresan valores de n, arreglo
y despliega resultados
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
Observaciones: el valor de n emplea malloc al ser esta 
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
    burbujaOpt2(A,n);
    //devuelve arreglo ordenado
    printf("\n Arreglo ordenado: \n");
    for ( i = 0; i < n; i++){
        printf(" %d", A[i]);
    }
    return 0;
}

void burbujaOpt2(int* A, int n) {
	int i = 0, j, k, aux;
    int cambios = 1;
    //condicion donde se pide sea rango menor al arreglo y bandera en true 
    while ((i<=n-2)&&(cambios!=0))
    {
        cambios = 0;
        for ( j = 0; j < (n-2)-i; j++){
            int k = j + 1;
            if (A[j] > A[k]) {
               aux = A[j];
               A[j] = A[k];
               A[k] = aux;
               cambios = 1;
            }
            
            
        }
        i = i + 1; 
    }
}