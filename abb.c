/*
NOMBRE DE PROGRAMA: Arbol Binario de Búsqueda
DESCRIPCIÓN: Ordenamiento de números con el algoritmo del árbol de búsqueda
binaria que mediante un tamaño del arreglo y números aleatorios, 
crea el ABB y realiza el recorrido inorden con el tamaño del arreglo 
y regresa un array ordenado ascendentemente
OBSERVACIONES: el algoritmo realiza el recorrido 
en el tamaño total de su arreglo, se aplica uso 
de malloc para la creación del array dinámico
FECHA: septiembre 2021
VERSIÓN: 1.2
AUTOR(ES): 
    Gómez Molina Ulises
    González Pérez Vanessa Berenice
    Hurtado Morales Emiliano
    Islas Osorio Enrique
*/

//Librerías

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
//#define MAX 100
 
/*Descripción de estructura:
Esctructura que tiene un entero y los punteros a NULL
Observaciones: La estructura es el nodo del árbol y permite la
creación del mismo, a partir de enlazarlo con nuevos nodos
creados dinámicamente.
*/
 
typedef struct snodoa{
    int valor;
    struct snodoa *izq, *der;
}tnodoa;
 
typedef tnodoa *tpunteroa;
 
/*Descripción de función:
Funcion para insertar los números aleatorios en el ABB
Input: puntero a la raíz del ABB, tamaño n
Output: ABB con todos los números insertados
Observaciones: La inserción es muy rápida y no conlleva
mucho tiempo de procesamiento.
*/

void insertarArbol (tpunteroa*, int );

/*Descripción de función:
Funcion para guardar el recorrido inorden en el arreglo A
Input: raiz del ABB, puntero al arreglo A, puntero a la variable auxiliar i
Output: arreglo en orden ascendente
Observaciones: El método de ordenamiento por ABB tiene un comportamiento
logarítmico, por lo que, se mejora en gran manera el tiempo de procesamiento.
Se emplean variables auxiliares para evitar errores de sintaxis.
*/

void guardaArbol (tpunteroa, int*, int*);

/*Descripción de función:
Funcion para borrar el ABB dinámico.
Input: puntero a la raíz del ABB
Output: Nada
Observaciones: Es importante liberar la memoria dinámica
empleada.
Se emplean variables auxiliares para evitar errores de sintaxis.
*/

void borrarArbol (tpunteroa*);
 
/*Descripción de función:
Funcion main, se ingresan valores de n, arreglo
y despliega resultados
Input: arreglo números, tamaño n
Output: arreglo en orden ascendente
Observaciones: se emplea malloc con enteros en el arreglo.
Si se ingresan valores no enteros, no se logrará el
ordenamiento.
*/
 
int main (){
 
    tpunteroa raiz;
    int dato, aux, n, i, *A;//Variables del algoritmo y loops
    raiz = NULL;
 
	scanf("%i", &n);
	
	A=malloc(sizeof(int)*n);
	
	if(A == NULL)
		exit(1); 
	 
    for(i=0 ; i<n ; i++){
    	scanf("%i", &dato);
		insertarArbol (&raiz, dato);
	}
 
    //Imprimimos el Arbol en orden
    i=0;
    guardaArbol (raiz, A, &i);
 
    //Borramos el Arbol
    borrarArbol (&raiz);

	system ("PAUSE");
	return 0;
}
 
 
//ARBOL-INSERTAR//
void insertarArbol (tpunteroa *raiz, int dato){
    if (*raiz == NULL){
    	*raiz = malloc(sizeof(tnodoa));
        (*raiz)->valor = dato;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;
    }else{
        if (dato <= (*raiz)->valor)
            insertarArbol (&(*raiz)->izq, dato);
        else
            insertarArbol (&(*raiz)->der, dato);
    }
}
 
//ARBOL-IMPRIMIR//
void guardaArbol (tpunteroa raiz, int* A, int* i){
    if (raiz != NULL){
        guardaArbol (raiz->izq, A, i);
        A[*i] = raiz->valor;
        *i = (*i) + 1;
        guardaArbol (raiz->der, A, i);
    }
}
 
//ARBOL-BORRAR//
void borrarArbol (tpunteroa *raiz){
    if (*raiz != NULL){
        borrarArbol (&(*raiz)->izq);
        borrarArbol (&(*raiz)->der);
        free (*raiz);
        *raiz = NULL;
    }
}