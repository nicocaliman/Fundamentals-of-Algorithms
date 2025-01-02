﻿// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v, int L)
{
    int sumaParcial = 0;
    int sumaMaxima = 0;
    int ini = 0;

    for (int i = 0; i < L; i++)
    {
        sumaParcial += v[i];
    }

    sumaMaxima = sumaParcial;

    for (int i = 0; i < v.size()-L; i++)
    {
        sumaParcial += v[i+L];
        sumaParcial -= v[i];

        if (sumaParcial >= sumaMaxima)
        {
            sumaMaxima = sumaParcial;
            ini = i+1;
        }
    }

    return ini;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int L;

    cin >> n >> L;

    if (n == 0 && L == 0)
        return false;

    vector<int> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    int sol = resolver(elementos, L);

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