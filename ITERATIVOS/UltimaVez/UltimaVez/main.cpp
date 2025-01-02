// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
    P = {0 < numVeces < 100000}
        fun resolver(vector<string> v, string nacionalidad) dev integer uv
    Q = { (uv = 0 <==> pt k: 0 <= k < v.size(): v[k] != nacionalidad) ||  (uv > 0 <==> ex k: 0 <= k < v.size(): v[k] == nacionalidad))}

    funcion de cota: t = i

    Complejidad:

    Las 4 primeras instrucciones tienen coste constante c O(1).
    El bucle se ejecuta v.size() veces
    El coste de las instrucciones condicionales es: 3 comparaciones + max(1,1) = 4 c O(1)
    Por tanto, el coste del bucle es 4*v.size()
    La instruccion --i; se ejecuta v.size() veces tambien teniendo un coste constante c O(1)

    Al salir del bucle tenemos una instruccion condicional cuyo coste es constante c O(1).

    La instruccion return tiene coste constante O(1).

    Definitivamente, el algoritmo tiene coste O(n) siendo n = v.size() = nº elementos del vector
*/

// función que resuelve el problema
int resolver(const vector<string>& v, string nacionalidad)
{
    int ultimaVez = 0;
    int aux = 1;
    int i = v.size()-1;
    bool encontrado = false;

    while (i >= 0 && !encontrado)
    {
        if (v[i] == nacionalidad)
        {
            encontrado = true; 
        }

        else
        {
            aux++;
        }

       --i;
    }

    if (encontrado)
    {
        ultimaVez = aux;
    }

    return ultimaVez;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numVeces;
    string nacionalidad;

    cin >> numVeces;

    if (numVeces == 0)
        return false;

    cin >> nacionalidad;

    vector<string> nacionalidades(numVeces);

    for (int i = 0; i < numVeces; i++)
    {
        cin >> nacionalidades[i];
    }

    int sol = resolver(nacionalidades, nacionalidad);

    if (sol == 0)
    {
        cout << "NUNCA\n";
    }

    else
    {
        cout << sol << "\n";
    }

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