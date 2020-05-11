#include <stdio.h>
#include <string.h>
#include<iostream>
#include<vector>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;



vector<string> ordenarString() {
    //VECTORES
    string stringIngresado = " "; //Aqui se almacenara la cadena de texto del usuario.
   // vector<string> separado; //Aqui se guardaran los objetos comprados por el usuario de manera separada
    vector<string> listado; //Aqui se guardaran todas las compras realizadas
    //VARIABLES
    int indice = 0;
    int contador = 0;
    int contador2 = 0;
    //TOMA DE VALORES, SE INGRESAN EN UN VECTOR
    while (stringIngresado.length() != 0) { //Mientras los datos ingresados no esten vacios, se pedira el listado de articulos que compro el usuario
        cout << "Ingrese el listado de articulos: ";
        getline(cin, stringIngresado);
        listado.push_back(string(stringIngresado));//Se ingresa en el vector el listado completo 
        contador2++; //Aqui se mira cuantas compras se realizaron, nos servira para el siguiente ciclo
    }
    //SEPARAR STRING SEGUN SUS COMAS 
    vector<vector<string>> separado2;
    while (contador < contador2) {
        vector<string> separado;

        for (int i = 0; i < listado[contador].size(); i++) {
            if (listado[contador][i] == ',') {
                separado.push_back(string(listado[contador], indice, i - indice));//Se indica de donde donde se tomaran los caracteres para el vector
                indice = i + 1;
                indice = i + 1;
            }

        }
        separado.push_back(string(listado[contador], indice, listado[contador].length() - indice));
        contador++;
        indice = 0;
        separado2.push_back(separado);
    }
    //OBTENER TODAS LAS PAREJAS QUE SE CREAN CON LOS SUCESORES DE CADA NUMERO
    vector<vector<string>> uno;
    for (int i = 0; i < separado2.size(); i++) {
        for (int a = 0; a < separado2[i].size()-1; a++) {
            for (int b = 1; b < separado2[i].size(); b++) {
                vector<string> pareja;
                //SI LOS ELEMENTOS DE LA PAREJA SON IGUALES, NO SE AGREGAN A EL VECTOR DE LAS PAREJAS
                if(separado2[i][a]==separado2[i][b]){
                }else{
                pareja.push_back(separado2[i][a]);
                pareja.push_back(separado2[i][b]);
                uno.push_back(pareja);
                }
            }
        }
    }
    
    
    //CONVERTIR A UN SOLO VECTOR
  vector<string> convertidos;
   for(int i = 0; i<uno.size();i++){
                convertidos.push_back(uno[i][0]+","+uno[i][1]);
   }
   
  
   vector<string> repetidos;
   for(int i = 0; i<convertidos.size();i++){
       for(int a = 0; a<convertidos.size();a++){
           if(convertidos[i]==convertidos[a]){
               repetidos.push_back(convertidos[i]);
               break;
           }
       }
   }
  
  sort(repetidos.begin(), repetidos.end());
   return repetidos;
   
 
}

struct Productos{
    std::string productos;
    int adquisiciones = 0;
    vector<int> contador;
};

//FUNCION PARA ORDENAR LOS OBJETOS 
vector<Productos> contarAdquisiciones(vector<string> productos){
    
    vector<Productos> vectorProductos;
    Productos structProductos;
    structProductos.productos = productos[0];
    string productosAnteriores = productos[0];
    vectorProductos.push_back(structProductos);

    //CICLO QUE LLENA vectorProductos CON LOS PRODUCTOS SIN REPETIR
    for (int i = 1; i < productos.size(); i++){
        if (productos[i] != productosAnteriores){
            Productos structProductosTemporal;
            structProductosTemporal.productos = productos[i];
            vectorProductos.push_back(structProductosTemporal);

            productosAnteriores = productos[i];
        }
    }
    //CICLOS QUE DETERMINAN EL NUMERO DE COMPRAS A CADA PRODUCTO
    for (int i = 0; i < productos.size(); i++){
        for (int j = 0; j < vectorProductos.size(); j++){
            if (vectorProductos[j].productos == productos[i]){
                vectorProductos[j].adquisiciones++;
            }
        }
    }
    
    // CICLO QUE ORDENA LOS PORDUCTOS SEGUN CUANTAS VECES SE COMPRARON
    for (int i = 0; i < vectorProductos.size(); i++){
        for (int j = i + 1; j < vectorProductos.size(); j++){
            if (vectorProductos[j].adquisiciones > vectorProductos[i].adquisiciones){
                Productos structProductosTemporal;
                structProductosTemporal.productos = vectorProductos[j].productos;
                structProductosTemporal.adquisiciones = vectorProductos[j].adquisiciones;
                
                vectorProductos[j] = vectorProductos[i];
                vectorProductos[i] = structProductosTemporal;
            }
        }
    }
    return vectorProductos;
}

int main()
{
    vector<string> litastaRep = ordenarString();
    vector<Productos> reps= contarAdquisiciones(litastaRep);
    for(int i = 0;i<reps.size();i++){
            if(reps[i].adquisiciones == 1){
                
            }else{
                cout<<"Los productos "<<reps[i].productos<<" se compraron: "<<reps[i].adquisiciones<<endl;
            }
    }
}




