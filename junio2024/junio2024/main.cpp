// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    1. noMasDeDos(v,p,q) = 7ex i: p <= i <= q - 3: v[i] < v[i+1] < v[i+2]

    2.
        P = { 3 <= k <= v.size() }
        fun resolver(vector<integer> v, integer k) dev integer segs
        Q = {segs = #w: w <= k <= v.size() : noMasDeDos(v,w-k,w)}

    3. funcion de cota: v.size()-w+1

*/

// función que resuelve el problema
int resolver(const vector<int>& v, int k)
{
    int r = -1;

    for (int i = 0; i < k-2; i++)
    {
        if (v[i] < v[i+1] && v[i+1] < v[i+2])
        {
            r = i;
        }
    }

    int segs = 0;

    if (r == -1)
    {
        ++segs;
    }

    for (int w = k+1; w <= v.size(); w++)
    {
        if (v[w-3] < v[w-2] && v[w-2] < v[w-1])
        {
            r = w - 3;
        }

        if (r < w-k)
        {
            ++segs;
        }
    }

    return segs;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numValores;
    int k;

    cin >> numValores;

    if (numValores == 0)
        return false;

    cin >> k;

    vector<int> valores(numValores);

    for (int i = 0; i < numValores; i++)
    {
        cin >> valores[i];
    }

    int sol = resolver(valores, k);

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