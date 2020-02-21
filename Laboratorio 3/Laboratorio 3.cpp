#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;
//Ejercicio 1
void imprimirBinario(int i) {
    string binario = "";
    while (i >= 1) {
        if (i % 2 == 0) {
            binario = binario + "0";
            i = i / 2;
        }
        else {
            binario = binario + "1";
            i = i / 2;
        }
    }
    cout << binario;
}
//Ejercicio 2
bool existe(char valor, long numero) {
    if (valor & numero) {
        return true;
    }
    else {
        return false;
    }
   
}

//Ejericio 3
short conteo(long numero) {
    string binario = "";
    while (numero >= 1) {
        if (numero % 2 != 0) {
            binario = binario + "1";
            numero = numero / 2;
        }
        else {
            numero = numero / 2;
        }
    }
    return binario.length();
}

//Ejercicio 
//MIRAR AL FINAL DEL PROGRAMA

//Ejercicio 5
int codificar(char c1, char c2, char c3, char c4) {
    int char1 = (c1 << 8) | c2;
    int char2 = (char1 << 8) | c3;
    int char3 = (char2 << 8) | c4;
    cout << char3;
    return 0;
}

 

int main()
{
    andOr(10,20);
}

/*
SINCERAMENTE NO SE ME OCURRIO COMO HACERLO, ASI QUE HICE ESTO
//Ejercicio 4
int andOr(int valor1, int valor2) {
    char binario1[255] = "";
    char binario2[255] = "";

    while (valor1 >= 1) {
        for (int i = 0; i <=7; i++) {
            if (valor1 % 2 == 0) {
                binario1[i] = '0';
                valor1 = valor1 / 2;
            }
            else {
                binario1[i] = '1';
                valor1 = valor1 / 2;
            }
        }

    }
    while (valor2 >= 1) {
        for (int i = 0; i <= 7; i++) {
            if (valor2 % 2 == 0) {
                binario2[i] = '0';
                valor2 = valor2 / 2;
            }
            else {
                binario2[i] = '1';
                valor2 = valor2 / 2;
            }
        }
    }
    cout << endl << binario1 << endl << binario2<<endl;

    for (int i = 0; i <= 7; i++) {
        if (i%2 != 0) {
            if (binario1[i] == '1' && binario2[i] == '1') {
                cout << "True" << endl;
            }
            else if (binario1[i] == '0' && binario2[i] == '0') {
                cout << "True" << endl;
            }
            else {
                cout << "False" << endl;
            }
        }
        else {
            if (binario1[i] == '1' && binario2[i] == '0'|| binario1[i] == '0' && binario2[i] == '1') {
                cout << "True"<<endl;
            }
            else {
                cout << "False"<<endl;
            }
        }

    }
    return 0;
}
*/