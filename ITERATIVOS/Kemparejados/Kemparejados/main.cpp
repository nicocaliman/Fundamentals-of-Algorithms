﻿// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, int n, int k)
{
    int numParejas = 0;
    int i = 0;
    int j = 0;

    while (i < n && j < n)
    {
        if (abs(v[j] - v[i]) == k)
        {
            numParejas++;
            ++i;
            ++j;
        }

        else if (abs(v[j] - v[i]) < k)
        {
            j++;
        }

        else
        {
            i++;
        }
    }

    return numParejas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, k;

    cin >> n;

    if (n == -1)
        return false;

    cin >> k;

    vector<int> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    int sol = resolver(elementos, n, k);

    cout << sol << "\n";

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