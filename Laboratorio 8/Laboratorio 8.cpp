#include <iostream>
#include <stdio.h>
#include <string>
#include<vector>


using namespace std; 


vector<string> separarString(const string& stringIngresado){
    vector<string> separado;
    int indice = 0;

    for (int i = 0; i < stringIngresado.size(); i++){
        if (stringIngresado[i] == ','){
            separado.push_back(string(stringIngresado, indice, i - indice));
            indice = i + 1;
        }
    }
    separado.push_back(string(stringIngresado, indice, stringIngresado.length() - indice));
    return separado;
}

//Ejercicio 1
float parseFloat(string valor){
    return stof(valor);   
}

//Ejercicio 2
class Vector3dim {
public:
    Vector3dim (string coordenadas) {
        vector<string> coord = separarString(coordenadas);
        x = coordenadas[0];
        y = coordenadas[1];
        z = coordenadas[2];

        cout << coordenadas[0] << endl << coordenadas[1];
    }
//Ejercicio 3
    float distancia(Vector3dim coordenadas2) {
        return sqrt(pow(x - coordenadas2.x, 2) + pow(y - coordenadas2.y, 2) + pow(z - coordenadas2.z, 2));
    }
private:
    float x, y, z;
}
;



//Ejercicio 4

int main(){
	//Ejercicio #4

	vector<Vector3dim> vectores;//Arreglo con todos los vectores que se ingresarán
	string numeros;//parametro del Vector3d
	float distanciaTotal = 0;
	int contador = 0;

	cout << "Ingrese los vectores de 3 dimensiones (x,y,z) que desee:\n";

	while (numeros != "\n") {
		getline(cin, numeros);

		if (!numeros.empty()) {
			vectores.push_back(Vector3dim(numeros));
			contador++;
		}
		else {
			break;
		}
	}
	if (vectores.empty()) {
		distanciaTotal = 0;
	}
	else {
		for (int i = 0; i < contador - 1; i++) {

			distanciaTotal = distanciaTotal + vectores[i].distancia(vectores[i + 1]);
		}
	}

	cout << "La distancia total entre los vectores es: " << distanciaTotal;


	char x;
	std::cin >> x;
}

