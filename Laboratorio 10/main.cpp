#include <iostream>
#include <cmath>
using namespace std;
/*
Universidad del Istmo
Facultad de Ingenieria
Informatica II
Prof. Ernesto Rodriguez <erodriguez@unis.edu>
Laboratorio #10
*/

/*
Instrucciones: En esta taria usted tendra que utilizar herencia para definir clases
que modelan el comportamiento de 3 aviones: Concorde, A320 y EMB-120. Todos los
modelos de avion deben heredar de una clase general llamada avion.
*/

/*
Tarea #1 (50%): Defina la clase avion que debe tener lo siguietne:
* Un metodo llamado "acelerar" el cual acepta un numero y aumeta
  o reduce la velocidad por dicho numero si es possible. Retorna
  true si la velocidad fue cambiada y false de lo contrario.
* Una variable protegida llamada "eficiencia", esta variable cambia
  cuando el avion cambia su altura segun los detalles especificos
  de cada modelo.
* Un metodo llamado "ascender" que debe aceptar una altitud en pies
  y retornar true si el ascenco es possible o false de lo contrario.
* Un metodo llamado "getConsumoActual" el cual debe retornar el consumo
  de gasolina del avion. Este consumo es la "eficiencia" multiplicado
  por la velocidad del avion.
*/
class Avion
{
protected:
  float eficiencia;

  int acel = 20;
public:
  float consumoActual = 20;
  int hactual = 100;
  float eficiencia_ = eficiencia;
  int acel_ = acel;

    Avion (int, int, float);	//CONSTRUCTOR

  bool acelerar (int acel_, int VelMax)
  {
    if (acel_ > VelMax)
      {
	return false;
      }
    else
      {
	return true;
      }

  }

  bool ascender (int hactual, int hmax)
  {
    int hinicio;
    hactual = hinicio + hactual;
    if (hactual > hmax)
      {
	return false;
      }
    else
      {
	return true;
      }

  }

  float getconsumoActual (float eficiencia_, float hactual)
  {
    consumoActual = eficiencia_ * hactual;
    return consumoActual;
  }

};

class Concorde:public Avion
{
private:
  int alturaMaxima = 60000;
  int velocidadMaxima = 2350;
public:

    Concorde (int, int, float, int, int);	//Constructor Concorde
};

//Constructor Concorde
Concorde::Concorde (int _hactual, int _acel_, float _eficiencia_,int _alturaMaxima, int _velocidadMaxima):Avion (_hactual, _acel_, _eficiencia_)
{
  alturaMaxima = _alturaMaxima;
  velocidadMaxima = _velocidadMaxima;
}


//A
class A:public Avion
{
private:
  int alturaMaxima = 40000;
  int velocidadMaxima = 950;
public:

    A (int, int, float, int, int);	//Constructor A
};

//Constructor A320
A::A (int _hactual, int _acel_, float _eficiencia_,int _alturaMaxima, int _velocidadMaxima):Avion (_hactual, _acel_, _eficiencia_)
{
  alturaMaxima = _alturaMaxima;
  velocidadMaxima = _velocidadMaxima;
}


//EMB
class EMB:public Avion
{
private:
  int alturaMaxima = 30000;
  int velocidadMaxima = 500;
public:

    EMB (int, int, float, int, int);	//Constructor EMB
};

//Constructor A320
EMB::EMB (int _hactual, int _acel_, float _eficiencia_,int _alturaMaxima, int _velocidadMaxima):Avion (_hactual, _acel_, _eficiencia_)
{
  alturaMaxima = _alturaMaxima;
  velocidadMaxima = _velocidadMaxima;
}

//Constructor avion
Avion::Avion (int _hactual, int _acel_, float _eficiencia_)
{
  hactual = _hactual;
  acel_ = _acel_;
  eficiencia_ = _eficiencia_;
}





/*
Tarea #2 (50%): Defina clases especificas para cada uno de los 3 modelos
de avion. A continuacion se muestra una tabla con los detalles
tecnicos de los aviones:
Concorde
    Altura maxima: 60,000 pies
    Velocidad maxima: 2350 km/h
    Eficiencia:
        50,000 - 60,000: 1.0
        40,000 - 49,999: 1.5
        30,000 - 39,999: 2
        0      - 29,999: 4
A320
    Altura maxima: 40,000 pies
    Velocidad maxima: 950 km/h
    Eficiencia:
        30,000 - 40,000: 1.0
        20,000 - 29,999: 1.3
        0      - 19,999: 2
EMB-130:
    Altura maxima: 30,000 pies
    Velocidad maxima: 500 km/h
    Eficiencia:
        15,000 - 30,000: 1.0
        5,000  - 14,999: 1.2
        0      -  4,999: 1.7
*/
int
main ()
{
  return 0;
}
