// Nicolae Gabriel Caliman

/*
{true}
proc equilibrio ( vector <int > v ) dev int p
{−1 ≤ p < v.size() ∧ numUnos(v, p + 1) = numCeros(v, p + 1)
∧∀k : p < k < v.size() : numUnos(v, k + 1) 6= numCeros(v, k + 1)}
donde numUnos(v, j) = #i : 0 ≤ i < j : v[i] = 1 y numCeros(v, j) = #i : 0 ≤ i < j : v[i] = 0

funcion de cota: v.size()-i

Complejidad:
Las 1as instrucciones tienen coste constante c O(1)
El bucle for se ejecuta v.size() veces.

Las instrucciones condicionales tienen coste constante c O(1) (comparaciones, asignaciones, acceso a vector, operaciones aritmeticas...)

La insturccion return tiene coste constante c O(1)

En definitiva, el algoritmo tiene coste lineal c O(n) siendo n = nº elementos del vector
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;


// función que resuelve el problema
int resolver(const vector<int>& v)
{
    int p = -1;
    int ceros = 0;
    int unos = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
            ceros++;
        else if (v[i] == 1)
            unos++;
        if (unos == ceros)
            p = i;
    }

    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    vector<int> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    int sol = resolver(elementos);

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