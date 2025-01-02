// Nicolae Gabriel Caliman

/*

    P = {0<=v.size()<150000}
        fun resolver(vector<integer> v) dev void
    Q = {v = pt i,j: 0<=i<j<v.size():v[i] != v[j]}

    funcion de cota: t = v.size()-i

    Complejidad:

    Las 1as instrucciones tienen coste constante c O(1)

    El bucle for() se ejecuta v.size()-1 veces.
    Las instrucciones condicionales tienen coste constante c O(1).

    La instruccion resize tiene coste constante c O(1) pues el nuevo tamanio es menor que el original.

    Por tanto, el algoritmo tiene coste lineal O(n);
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// función que resuelve el problema
void resolver(vector<int>& v)
{
    int numRepetido = v[0];
    int numEliminados = 0;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == numRepetido)
        {
            numEliminados++;
        }

        else
        {
            v[i - numEliminados] = v[i];
            numRepetido = v[i];
        }
    }
    v.resize(v.size()-numEliminados);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
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
    
    sort(elementos.begin(), elementos.end());   //ordena de menor a mayor

    resolver(elementos);

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