#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H
int min(int array[], int n);
int max(int array[], int n);
float average(int array[], int n);
float estDev(int array[], int n);
float median(int array[], int n);
int mode(int array[], int n);
void copyArray(int source[], int destiny[],int tam);
//Funciones iniciakes
int* setArray(int array[], int tam);
void printArray(int array[], int tam);
void bubbleSort(int array[], int n);
void swap(int *p_a, int *p_b);
void graph(int array[], int n);
int validarDato(int valor);
void menu();

#endif
