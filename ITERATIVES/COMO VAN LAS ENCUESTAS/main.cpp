// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;

/*
    COSTE:

    Las instrucciones iniciales tienen coste constante O(1): asignaciones + acceso a vector

    El bucle for se ejecuta v.size() veces:

        Las instrucciones if tienen coste constante O(1) pues son comparaciones + maximo instrucciones condicionales (tmbn coste constante O(1))

    Por tanto. como todas las vueltas tienen el mismo coste, multiplicamos el coste de cada vuelta por el numero de vueltas: v.size() vueltas = n * O(1)

    El coste del algoritmo es lineal O(n).
*/

// función que resuelve el problema
lli resolver(const vector<lli> &v, int &c) 
{
    lli sum = 0;
    lli min = v[0];
    int numMin = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < min)
        {
            sum += (numMin * min);
            min = v[i];
            c += numMin;
            numMin = 1;
        }

        else if (v[i] == min)
        {
            ++numMin;
        }

        else
        {
            sum += v[i];
            ++c;
        }
    }

    return sum;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int size;

    cin >> size;

    vector<lli> valores(size);

    for (int i = 0; i < valores.size(); i++)
    {
        cin >> valores[i];
    }

    int cont = 0;

    lli sum = resolver(valores, cont);
    // escribir sol

    cout << sum << " " << cont << "\n";
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