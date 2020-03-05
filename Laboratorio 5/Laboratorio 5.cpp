// Laboratorio 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;

//TAREA 1


int* copiar(int* valores, int cantidad) {
    int* arreglo = (int*)malloc(cantidad*sizeof(int));
    for (int i = 0; i < cantidad;i++) {
        arreglo[i] = valores[i];
    }
    return arreglo;
}

//TAREA 2
int* primos(const int maximo) {
    int* numeros = (int*)malloc(maximo * sizeof(int));
    int contador = 0;
    int contador2 = 0;
    for (int i = 2; i < maximo; i++) {
        int divisor = 1;
        int divisores = 0;
        do {
            if (i % divisor == 0) {
                divisores++;
            }
            divisor++;
        } while (divisor <= i);

        if (divisores == 2) {
            numeros[contador2] = i;
            contador2++;
            contador++;
        }
    }
    int* arrayRetorno = (int*)malloc(sizeof(int) * contador);
    arrayRetorno = numeros;
    delete numeros; 
    //free(numeros);
    return arrayRetorno;
}
//TAREA 3


int** vectoresCercanos(int** vectores, const int cantidad, const int distancia) {
    int* resultadVectoresX = (int*)malloc(sizeof(int) * cantidad);
    int* resultadVectoresY = (int*)malloc(sizeof(int) * cantidad);
    int* distanciaEucli = (int*)malloc(sizeof(int) * cantidad);

    for (int i = 0; i < cantidad; i++) {
        for (int a = 0; a < 2; a++) {
            if (a % 2 == 0) {
                resultadVectoresX[i] = pow(vectores[i][a], 2);
            }
            else
            {
                resultadVectoresY[i] = pow(vectores[i][a], 2);
            }
        }
    }
    
    for (int i = 0; i < cantidad; i++) {
        distanciaEucli[i] = sqrt(resultadVectoresX[i] + resultadVectoresY[i]);
    }
    for (int i = 0; i < cantidad; i++) {
        if (distanciaEucli[i] < distancia) {
            
        }
    }
    
    
    return 0;
}


int main()
{
    //Tarea 1
    int valores[] = {1,2,3,4,5};
    copiar(valores,5);
    
    //TAREA 2
    primos(30);

    //TAREA 3
    int contador = 0;
    int cantidad = 2;
    int** vectores2 = (int**)malloc(sizeof(int) * cantidad);

    for (int i = 0; i < cantidad; i++) {
        vectores2[i] = (int*)malloc(sizeof(int)*2);
    }

    //AQUI SE INGRESAN LAS COORDENADAS
    vectores2[0][0] = 2;
    vectores2[0][1] = 3;
    vectores2[1][0] = 4;
    vectores2[1][1] = 2;

    vectoresCercanos(vectores2, cantidad,5);
    
}

