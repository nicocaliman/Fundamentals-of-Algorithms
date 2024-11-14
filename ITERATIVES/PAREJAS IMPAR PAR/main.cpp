//Nicolae Gabriel Caliman
//FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:

    Las instrucciones iniciales tienen coste constante O(1).

    El bucle for() se ejecuta v.size() veces:

        Las instrucciones condicionales:
            sus cabeceras tienen coste constante O(1)
            + maximo(instrucciones condicionales) = O(1)

    Como todas las vueltas tienen coste constante O(1) y el for da v.size() vueltas, multiplicamos.

    Por tanto, el coste del algoritmo es O(n), siendo n el numero de elementos del vector.
*/

// función que resuelve el problema
int resolver(const vector<int>& v) 
{
    int par = 0;
    int numParejas = 0;

    for (int i = v.size()-1; i >= 0; --i)
    {
        if (v[i] % 2 == 0)
        {
            par++;
        }

        else
        {
            numParejas += par;
        }
    }

    return numParejas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int n;

    cin >> n;

    vector<int> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    int sol = resolver(elementos);

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