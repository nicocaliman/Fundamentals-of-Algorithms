// Nicolae Gabriel Caliman

/*

    Complejidad:
    Las 1as instrucciones tienen coste constante c O(1) (declaracion+asignacioes)

    El bucle for() se ejecuta v.size() veces.
    Las instrucciones condicionales tienen coste constante c O(1) (acceso a vector, comparacion, operacion aritmetica)

    resize() tiene coste constante si el nuevo tamanio es menor que el que tenia.

    En conclusion, el algoritmo tiene coste lineal c O(n) siendo n = nº de elementos del vector

    funcion de cota: t = v.size()-i
    
    P = {true}
        fun resolver(vector<long long integer>& v, integer de) dev void
    Q = {pt i: 0<=i<v.size(): v[i] != de}

*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;

// función que resuelve el problema
void resolver(vector<lli>& v, int de)
{
    int numErroneos = 0;
    int noErroneos = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == de)
        {
            numErroneos++;
        }

        else
        {
            noErroneos++;
            v[i - numErroneos] = v[i];
        }
    }

    v.resize(noErroneos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int erroneo;

    cin >> n >> erroneo;

    vector<lli> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    resolver(elementos, erroneo);

    cout << elementos.size() << "\n";

    for (int i = 0; i < elementos.size(); i++)
    {
        cout << elementos[i] << " ";
    }
    cout << "\n";
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