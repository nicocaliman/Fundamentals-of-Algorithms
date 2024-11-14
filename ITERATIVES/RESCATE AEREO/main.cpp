// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:

    Las instrucciones iniciales tienen coste constante O(1).

    El bucle for() se ejecuta v.size() veces:

        Las instrucciones condicionales tienen:

           Coste constante O(1) de la cabecera
           + maximo instrucciones condicionales:

                otro if con coste constante O(1) en su cabecera
                + maximo instrucciones condicionales: coste constante O(1)

        Por tanto las instrucciones condicionales tienen coste constante(1).

    La ultima instruccion tiene coste constante O(1).

    Por tanto, todas las vueltas tienen el mismo coste, multiplicamos por el numero de vueltas.

    El coste del algoritmo es lineal O(n), siendo n el numero de elementos del vector
*/

// función que resuelve el problema
void resolver(const vector<int>& v, int t, int& ini, int& fin)
{
    int ivaloMAX = 0;
    int ivaloACT = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > t)
        {
            ivaloACT++;

            if (ivaloACT > ivaloMAX)
            {
                ivaloMAX = ivaloACT;
                fin = i;
            }
        }

        else
        {
            ivaloACT = 0;
        }
    }

    ini = fin - ivaloMAX + 1;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    // leer los datos de la entrada
    int n, t;

    cin >> n >> t;

    vector<int> alturas(n);

    for (int i = 0; i < n; i++)
    {
        cin >> alturas[i];
    }

    int ini = 0;
    int fin = 0;

    resolver(alturas, t, ini, fin);
    
    // escribir sol
    cout << ini << " " << fin << "\n";
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