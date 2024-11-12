// Nicolae Gabriel Caliman
// FAL-A73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;

/*
    COSTE:

    La instruccion inicial tiene coste constante O(1).

    El coste del bucle for da va.size()-1 vueltas:
        las instrucciones de dentro tienen coste constante O(1) -> asignaciones + operaciones aritmeticas

    Por tanto, el coste del algoritmo es lineal O(n), siendo n el numero de elementos del vector

*/

// función que resuelve el problema
void resolver(const vector<int> &v, vector<lli>& va)
{
    va[0] = 0;

    for (int i = 1; i < va.size(); ++i)
    {
        va[i] = va[i - 1] + v[i - 1];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() 
{
    // leer los datos de la entrada
    int p, u, n;

    cin >> p >> u;

    if (p == 0 && u == 0)
        return false;

    n = u - p + 1;

    vector<int> nacimientos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nacimientos[i];
    }

    int m;
    int a;
    int b;

    vector<lli> acumulados(nacimientos.size() + 1);
    resolver(nacimientos, acumulados);

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        cout << acumulados[b-p+1] - acumulados[a-p] << "\n";
    }

    cout << "---\n";

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