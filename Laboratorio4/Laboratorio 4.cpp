// Laboratorio 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

//TAREA 1
bool divisionSegura(int numerador, int denominador, int* respuesta) {
    if (denominador != 0) {
        int division = numerador / denominador;
        respuesta = &division;
        return true;
    }
    else {
        return false;
    }
}
//TAREA 2

int numeroMayor(int valores[], int cantidad) {
    int mayor = valores[0];
    for (int i = 0; i < cantidad; i++) {
        if (mayor<valores[i]) {
            mayor = valores[i];
        }
    }
    return mayor;
}
int numeroMayor2(int valores[], int cantidad) {
    int mayor2 = valores[0];
    for (int i = 0; i < cantidad; i++) {
        if (mayor2 < valores[i] && (valores[i] !=(numeroMayor(valores, cantidad)))){
            mayor2 = valores[i];
        }
    }
    return mayor2;
}

bool sumaMayor(int valores[], int cantidad,int **puntero) {
    int valor1 = numeroMayor(valores, cantidad);
    int valor2 = numeroMayor2(valores, cantidad);

    puntero[0] = &valor1;
    puntero[1] = &valor2;

    return true;
}




//TAREA 3  (n - 1) + (n - 2);

void fibonacci(int n, int *valores) {

    long int fib[100];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 1; i < n; i++) {
        fib[i + 1] = fib[i - 1] + fib[i];
        cout << fib[i]<<endl;
    }
    for (int i = 0; i < n; i++) {
        valores[i] = fib[i];
    }
}



//TAREA 4


int main()
{   
    //Tarea 1
    int* respuestas = (int*)malloc(sizeof(int));
    divisionSegura(10, 2, respuestas);

    //Tarea 2
    int** punteros = (int**)malloc(2*(sizeof(int)));
    int valores[] = { 1,2,7,4,9 };
    sumaMayor(valores,5,punteros);

    //Tarea 3 
    int* valoress = (int*)malloc(100 * (sizeof(int)));
    fibonacci(10, valoress);

}