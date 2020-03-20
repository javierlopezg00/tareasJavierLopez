#include <iostream>
#include <math.h>

using namespace std;



struct Lista
{
    int valor;
    Lista* resto;
};

/*
Problema 1 (10%)
*/

Lista* crear(const int* valores, const int cantidad)
{
    Lista* lista = (Lista*)malloc(sizeof(Lista) * cantidad);
    if (cantidad == 0) {
        return nullptr;
    }
    else {
        for (int i = 0; i < cantidad; i++) {
            lista[i].valor = valores[i];
        }
    }
    return lista;
}


/*
Problema 2

*/

void eliminar(Lista* valores) {

    while (valores != nullptr) {
        delete& valores->valor;//Elimina el puntero
        valores = valores->resto;
    }
}


/*
Promblema 3
*/

void unir(Lista* primera, Lista* segunda) {

    Lista* p;
    if (primera == nullptr) {
        primera = segunda;
    }
    else {
        if (segunda != nullptr) {
            p = primera;
            while (p->resto != nullptr) {
                p = p->resto;
            }
            p->resto = segunda;
        }
    }
}
/*
Problema 4 (10%)
*/

int longitud(const Lista* valores) {
    int contador = 1;
    if (valores->resto == nullptr) {
        return 0;
    }

    else {

        while (valores->resto != nullptr) {
            contador++;
            valores = valores->resto;
        }

        return contador;
    }
}
/*
Problema 5 (20%)
*/
bool lookup(const Lista* valores, int indice, int& resultado) {
    int contador = longitud(valores);


    if (indice >= contador) {
        return false;
    }
    else {
        while (0 < indice) {
            indice--;
            valores = valores->resto;
        }
        resultado = valores->valor;
        return true;
    }
}

    /*
    Problema 6 (20%)
    */

    struct Triangulo {
        int p1[2];
        int p2[2];
        int p3[2];
    };

    struct ListaTriangulos {
        Triangulo primero;
        ListaTriangulos* resto;
    };

    /*
    Problema 7 (10%)
    */

    float lado1(Triangulo triangulo) {//Longitud lado 1

        float x2 = pow((triangulo.p1[0] - triangulo.p2[0]), 2);
        float y2 = pow((triangulo.p1[1] - triangulo.p2[1]), 2);

        float resultado = sqrt(x2 + y2);

        return resultado;
    }

    float lado2(Triangulo triangulo) {//Longitud lado 2

        float x2 = pow((triangulo.p1[0] - triangulo.p3[0]), 2);
        float y2 = pow((triangulo.p1[1] - triangulo.p3[1]), 2);

        float resultado = sqrt(x2 + y2);

        return resultado;
    }

    float lado3(Triangulo triangulo) {//Longitud lado 3

        float x2 = pow((triangulo.p2[0] - triangulo.p3[0]), 2);
        float y2 = pow((triangulo.p2[1] - triangulo.p3[1]), 2);

        float resultado = sqrt(x2 + y2);

        return resultado;
    }


    float area(const Triangulo & triangulo) {
        //Utilizando fórmula de Herón (área de un triangulo con la longitud de los lados)

        float s = (lado1(triangulo) + lado2(triangulo) + lado3(triangulo)) / 2;

        float areat = sqrt(s * (s - lado1(triangulo)) * (s - lado2(triangulo)) * (s - lado3(triangulo)));

        return areat;
    }

    /*
    Problema 8 (10%)
    */
    int contarTriangulos(const ListaTriangulos* valores) {
        int contador = 1;
        if (valores->resto == nullptr) {
            return 0;
        }
        else {

            while (valores->resto != nullptr) {
                contador++;
                valores = valores->resto;
            }

            return contador;
        }
    }

    float areaPromedio(const ListaTriangulos* triangulos) {
        int cantidad = contarTriangulos(triangulos);

        int sumas = 0;

        for (int i = 0; i < cantidad; i++) {
            sumas = sumas + area(triangulos->primero);
            triangulos = triangulos->resto;
        }

        int promedio = sumas / cantidad;
        return promedio;
    }


    int main()
    {

        Lista lista;
        lista.valor = 1;
        lista.resto = (Lista*)malloc(sizeof(Lista));

        lista.resto->valor = 2;
        lista.resto->resto = nullptr;

        cout << "Hello World: " << lista.valor << " y " << lista.resto->valor;

        return 0;
    }