// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

/*
    P = {numPalabras > 0}
       fun resolver(vector<string> v) dev string primera
    Q = {primera = min i: 0 <= i < v.size(): v[i]}

    funcion de cota: t = v.size()-i

    Complejidad:

    La primera instruccion tiene coste constante c O(1).
    El bucle se ejecuta v.size()-1 veces

    La instruccion condicional tiene coste constante c O(1)

    Por tanto, el coste del bucle for() pertenece a O(n), siendo n = v.size() = nº elementos del vector

    La instruccion return tiene coste constante O(1).

    Definitivamente, el coste asintotico del algoritmo es del orden de n. O(n), siendo n = v.size() = nº elementos del vector
*/

// función que resuelve el problema
string resolver(const vector<string>& v)
{
    string primera = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < primera)
        {
            primera = v[i];
        }
    }

    return primera;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numPalabras;
    
    cin >> numPalabras;

    vector<string> palabras(numPalabras);

    for (int i = 0; i < numPalabras; i++)
    {
        cin >> palabras[i];
    }

    cout << resolver(palabras) << "\n";
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