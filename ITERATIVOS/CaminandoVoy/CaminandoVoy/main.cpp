// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

/*
    P = {0 <= D <= 1000000 ^ 1 <= N <= 200000}
        fun resolver(vector<integer> v, integer D) dev bool apta
    Q = {apta = 7ex i,j: 0 <= i < j < v.size(): v[j] - v[i] > D}

    funcion de cota: t = v.size()-i

    Complejidad:

    Las 4 primeras instrucciones tienen coste constante c O(1)

    El bucle da v.size()-1 vueltas.

    La primera instruccion condicional es 3+max(2, 2), por tanto, coste constante c O(1)
    La 2a instruccion condicional es tiene coste constane c O(1) tambien (acceso a vector+operacion aritmetica+comparacion)
    
    La instruccion i++; se ejecuta v.size()-1 veces tiene coste constante O(1)

    La instruccion return tiene coste constante c O(1).

    En definitiva, el añgoritmo tiene coste lineal O(n), siendo n el tamanio del vector
*/


// función que resuelve el problema
bool resolver(const vector<int>& v, int D)
{
    int ini = v[0];
    int fin = v[v.size()-1];
    bool apta = true;
    int i = 1;

    while (i < v.size() && apta)
    {
        if (v[i] > v[i-1])
        {
            fin = v[i];
        }

        else
        {            
            ini = v[i];
        }

        if (v[i] - ini > D)
        {
            apta = false;
        }
        i++;
    }

    return apta;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int D;
    int N;

    cin >> D >> N;
    if (!std::cin)
        return false;

    vector<int> cotas(N);

    for (int i = 0; i < N; i++)
    {
        cin >> cotas[i];
    }

    bool sol = resolver(cotas, D);

    sol == true ? cout << "APTA\n" : cout << "NO APTA\n";

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