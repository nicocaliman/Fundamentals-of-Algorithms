// Nicolae Gabriel Caliman
// FAL-A73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:

    La primera instruccion tiene coste constante O(1): acceso a vector + asignacion

    En el bucle for():
        
        se ejecuta v.size() veces.

    Del if(), tenemos la condicion (coste (2) constante O(1)) + maximo entre las intrucciones condicionales (coste (2) constante O(1)), por tanto, coste O(1) total.(el if se ejecuta v.size()-1 veces)

    En consecuencia, cada vuelta tiene coste constante O(1).

    En resumen, como el coste de cada vuelta es constante, lo mulitplicamos por el numero de vueltas que da el bucle(n) -> O(n) 
*/

// función que resuelve el problema
string resolver(const vector<string> &v)
{
    string p = v[0];

    //recorrer desde el 2o elemento
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < p)   //si el elemento es menor alfabeticamente que el que suponemos como mas pequeño 
        {
            p = v[i];   //modificar
        }
    }

    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    // leer los datos de la entrada
    int numPalabras;

    cin >> numPalabras; //numero 

    vector<string> palabras(numPalabras);   //declaracion de vector 

    for (int i = 0; i < palabras.size(); i++)
    {
        cin >> palabras[i]; //cargar palabras
    }

    string sol = resolver(palabras);    //primera palabra en orden alfabetico
    // escribir sol

    cout << sol << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
