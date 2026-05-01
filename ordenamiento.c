#include "ordenamiento.h"
#include <stdio.h>

//Esta funcion pide un arreglo
int* setArray(int array[], int tam){
    int i;
    for(i=0; i<tam; i++){
        printf("Ingresa el valor del elemento %d: ", i+1);
        scanf("%d", &array[i]);
    }
    return array;
}

void printArray(int array[], int tam){//Se pone el tamaño del arreglo si lo tiene
    int i;
    for(i=0; i<tam; i++){
        printf("%d, ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int array[], int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n-i-1; j++){
            if(array[j] > array[j+1]){
                swap(&(array[j]), &(array[j+1]));
            }
        }
    }
}

void swap(int *p_a, int *p_b){
    int temp;
    temp = *p_b;
    *p_b = *p_a;
    *p_a = temp;
}

int validarDato(int valor){
    //validar dato entre 0 y 100
    while(valor < 0 || valor > 100){
        printf("Valor fuera del rango, vuelve a escribirlo: ");
        scanf("%d", &valor);
    }
    return valor;
}

void menu() {
    int array[100];
    int n = 0;
    int i, dato;
    int copia[100];
    char opcion;

    do {
        printf("a. Capturar arreglo\n");
        printf("b. Mostrar arreglo\n");
        printf("c. Mostrar arreglo ordenado\n");
        printf("d. Estadisticas\n");
        printf("e. Histograma\n");
        printf("f. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%s", &opcion);

        switch(opcion) {
            case 'a':
                //int dato;
                printf("Ingresa el tamaño del arreglo: ");
                scanf("%d", &n);
                dato = validarDato(n);
                setArray(array, dato);
                break;
            case 'b':
                printf("Arreglo originalmente capturado:\n");
                printArray(array, n);
                break;
            case 'c':
                //int i;
                for(i=0; i<n; i++){
                    copia[i] = array[i];
                }
                bubbleSort(copia, n);
                printf("Arreglo ordenado:\n");
                printArray(copia, n);
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(opcion != 'f');
}