
#include <iostream>
using namespace std;

//Ejercicio 1
bool esPrimoRec(int x) {
    int contador = 2;
    if (x == 0) {
        cout << "No primo";
        return false;
        
    }
    else if (x == 1) {
        cout << "Primo";
        return true;
    }
    else if (x % contador != 0) {
        cout << "Primo";
        return true;
    }
    else {
        cout << "No primo";
        return false;
    }
}

//Ejercicio 2

bool esPrimoCiclica(int n) {
    int contador = 2;
        while (n % contador != 0) {
            cout << "Primo";
            return true;
    }
        while (n % contador == 0) {
            cout << "No primo";
            return false;
        }
        return 0;
}

//Ejercicio 3
int obtenerPrimoRec(int n, int contador1 = 0, int contador2 = 1) {
    if (contador1 <= n){
        if (contador2%2 !=0) {
            return obtenerPrimoRec(n, (contador1 + 1), (contador2 + 1));
        }else{
            return obtenerPrimoRec(n, contador1, (contador2 + 1));
        }
    }
  
}

//Ejercicio 4
int obtenerPrimoCiclico(int n, int contador1 = 0, int contador2 = 1) {
    
    while (contador1 <= n) {
        if (contador2 % 2 != 0) {
            return obtenerPrimoCiclico(n, contador1, (contador2 + 1));
        }
        else {
            return obtenerPrimoCiclico(n, contador1, (contador2 +1));
        }
    }
}

int main(){
    esPrimoCiclica(98);
  
}

