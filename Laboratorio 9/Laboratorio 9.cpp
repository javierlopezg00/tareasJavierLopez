
#include <iostream>
#include <vector>

using namespace std;

class LinkedList{
private:

    vector<int> cadena;

public:
    //EJERCICIO 1
    void push(int valor) {
        cadena.push_back(valor);
    }
    
    //EJERCICIO 2
    vector<int> toVector() {
        vector<int> cadenaRetorno = cadena;
        return cadenaRetorno;
    }
    //EJERCICIO 3

    int& operator[](const int indice)
    {

    }
    //EJERICIO 4
    ~LinkedList() {
        cadena.clear();
    }
    //EJERCICIO 5
};
int main()
{
    std::cout << "Hello World!\n";
}

