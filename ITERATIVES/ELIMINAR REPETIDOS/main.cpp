// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    COSTE:

    La primera instruccion tiene coste constante O(1).

    El bucle for() se ejecuta v.size() - 1 veces:

        La instruccion condicional:

            La cabecera es tiene coste constante O(1) -> comparacion
            + maximo instrucciones condicionales O(1)

    Como todas las vueltas tienen el mismo coste O(1), multiplicamos. O(1)*(n-1)

    Por tanto, el coste es O(n), siendo n el numero de elementos del vector.
*/

// función que resuelve el problema
void resolver(vector<int>& v)
{
    int j = 0;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[j] != v[i])
        {
            j++;
            v[j] = v[i];
        }
    }

    v.resize(j+1);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (!std::cin)
        return false;

    vector<int> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    sort(elementos.begin(), elementos.end());

    resolver(elementos);

    // escribir sol
    for (int i = 0; i < elementos.size(); i++)
    {
        cout << elementos[i] << " ";
    }

    cout << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}