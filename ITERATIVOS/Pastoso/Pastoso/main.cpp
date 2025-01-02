// Nicolae Gabriel Caliman

/*
    P = {0≤n≤100.000}
        fun resolver(vector<integer> v, integer p) dev {bool pastoso, integer p}
    Q = {p = max k: 0<=k<v.size(): sumaSiguientes(v, k) == v[p] ^ pastoso = ex i: 0<=i<v.size(): v[i] == sumaSiguientes(v,i)}

    siendo sumaSiguientes(v,i) = sumatorio k: i+1<=k<v.size():v[k]

    funcion de cota: t = i

    Complejidad:

    Las 1as instrucciones tiene coste constante c O(1).
    El bucle while() se ejecuta v.size() veces

    La instruccion condicional tiene coste constante (acceso a vector, comparacion, asignacion...) c O(1)

    La instruccion --i se ejecuta v.size() veces tambien.

    La instruccion return tiene coste constante c O(1).

    En conclusion, el algoritmo tiene coste lineal c O(n) siendo n = nº elementos del vector
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& v, int& pastoso)
{
    bool primerPastoso = false;
    int i = v.size()-1;
    int sumaTotal = 0;

    while (i >= 0 && !primerPastoso)
    {
        if (v[i] == sumaTotal)
        {
            primerPastoso = true;
            pastoso = i;
        }

        else
        {
            sumaTotal += v[i];
        }

        --i;
    }

    return primerPastoso;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElems;

    cin >> numElems;

    vector<int>valores(numElems);

    for (int i = 0; i < numElems; i++)
    {
        cin >> valores[i];
    }

    int p = valores.size() - 1;

    bool sol = resolver(valores, p);
    
    if (sol)
    {
        cout << "Si " << p << "\n";
    }
    else
    {
        cout << "No\n";
    }


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