#include<iostream>
using namespace std;
struct Mapa {
    bool** posiciones;
    int ancho;
    int largo;
};

struct Vector {
    int x;
    int y;
};

class Vehiculo {
public:
    //Problema 1
    Vehiculo(Mapa _mapa, Vector _posicionI) {
        mapa2 = _mapa;
        posicion2 = _posicionI;
        velocidad2 = Vector{ 0,0 };
    }
    //Problema 2

    void estadoActual() {
        cout <<"Posicion en X: "<<posicion2.x<<endl<<"Posicion Y: "<<posicion2.y;
        cout << "Velocidad en X: " << velocidad2.x << endl << "Velocidad Y: " << velocidad2.y;
    }
    //Problema 3
    void acelerar(Vector velo) {
        velocidad2.x += velo.x;
        velocidad2.y += velo.y;
    }
    //Problema 4
    bool validarAvance() {
        Vector suma;
        suma.x = posicion2.x + velocidad2.x;
        suma.y = posicion2.y + velocidad2.y;

        if (suma.x <= mapa2.ancho && suma.y <= mapa2.largo) {
            return true;
        }
         
    }
    //Problema 5
    void avanzar(int tiempo) {
        for (int i = 0; i < tiempo; i++) {
            posicion2.x = posicion2.x + velocidad2.x;
            posicion2.y = posicion2.y + velocidad2.y;

            if (posicion2.x > mapa2.ancho) {
                posicion2.x = mapa2.ancho;
            }
            else if (posicion2.y > mapa2.largo) {
                posicion2.y = mapa2.largo;
            }
        }


    }
private:
    Mapa mapa2;
    Vector posicion2;
    Vector velocidad2;
};

int main() {

}