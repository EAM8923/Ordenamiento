#include "ordenamiento.h"
#include <stdio.h>
#include <math.h>

int min(int array[], int n){
    int i, menor = array[0];
    for(i = 1; i < n; i++){
        if(array[i] < menor){
            menor = array[i];
        }
    }
    return menor;
}

int max(int array[], int n){
    int i, mayor = array[0];
    for(i = 1; i < n; i++){
        if(array[i] > mayor){
            mayor = array[i];
        }
    }
    return mayor;
}

float average(int array[], int n){
    int i, suma = 0;
    for(i = 0; i < n; i++){
        suma += array[i];
    }
    return (float)suma / n;
}

float estDev(int array[], int n){
    int i;
    float media = average(array, n);
    float suma = 0;

    for(i = 0; i < n; i++){
        suma += (array[i] - media) * (array[i] - media);
    }

    return sqrt(suma / n);
}

float median(int array[], int n){
    int copia[100];
    int i;

    // copiar arreglo
    for(i = 0; i < n; i++){
        copia[i] = array[i];
    }

    // ordenar copia
    bubbleSort(copia, n);

    if(n % 2 == 0){
        return (copia[n/2 - 1] + copia[n/2]) / 2.0;
    } else {
        return copia[n/2];
    }
}

int mode(int array[], int n){
    int i, j, cont, max_cont = 0;
    int moda = array[0];

    for(i = 0; i < n; i++){
        cont = 0;
        for(j = 0; j < n; j++){
            if(array[j] == array[i]){
                cont++;
            }
        }
        if(cont > max_cont){
            max_cont = cont;
            moda = array[i];
        }
    }

    return moda;
}

void copyArray(int source[], int destiny[],int tam){
    int t;
    for (t=0;t<tam;t++){
        destiny[t] = source[t];
    }
}

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

void graph(int array[], int n){
    int i, j;

    for(i = 0; i < n; i++){
        printf("%d: ", array[i]);
        for(j = 0; j < array[i]; j++){
            printf("*");
        }

        printf("\n");
    }
}

int validarSiHayArreglo(int n){
    if(n <= 0){
        return 0;
    }else{
        return 1;
    }
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
                if(validarSiHayArreglo(n)==0){
                    printf("No hay arreglo capturado, captura con opcion a)\n");
                    break;
                }else{
                    printf("Arreglo originalmente capturado:\n");
                    printArray(array, n);
                }
                break;
            case 'c':
                if(validarSiHayArreglo(n)==0){
                    printf("No hay arreglo capturado, captura con opcion a)\n");
                    break;
                }else{
                    copyArray(array, copia, n);
                    bubbleSort(copia, n);
                    printf("Arreglo ordenado:\n");
                    printArray(copia, n);
                }
                break;
            case 'd':
                if(validarSiHayArreglo(n)==0){
                    printf("No hay arreglo capturado, captura con opcion a)\n");
                    break;
                }else{
                    printf("Minimo: %d\n", min(array, n));
                    printf("Maximo: %d\n", max(array, n));
                    printf("Promedio: %.2f\n", average(array, n));
                    printf("Desviacion estandar: %.2f\n", estDev(array, n));
                    printf("Mediana: %.2f\n", median(array, n));
                    printf("Moda: %d\n", mode(array, n));
                }
                break;
            case 'e':
                if(validarSiHayArreglo(n)==0){
                    printf("No hay arreglo capturado, captura con opcion a)\n");
                    break;
                }else{
                    printf("Histograma:\n");
                    graph(array, n);
                }
                break;
            case 'f':
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
        }
    } while(opcion != 'f');
}