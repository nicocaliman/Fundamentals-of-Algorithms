// Nicolae Gabriel Caliman  
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:
    
    Las instrucciones del principio tiene coste constante O(1): asignaciones, comparaciones, acceso a vector

    Las instrucciones condicionales de dentro del bucle:

        Son comparaciones; coste constante O(1) + maximo instrucciones condicionales que tienen un coste constante O(1)

    En el caso peor el bucle se ejecuta n-1 veces, siendo n el numero de elementos del vector.

    Por tanto, el coste pertenece a O(n).
*/

// función que resuelve el problema
bool resolver(const vector<int>& v, int D) 
{
    int i = 1;
    int ini = v[0];
    int fin = v[v.size()-1];
    bool apto = true;

    while (i < v.size() && apto)
    {
        //cuesta arriba (estrictamente creciente)
        if (v[i] > v[i-1])
        {
            fin = v[i];
        }

        //cuesta abajo
        else
        {
            ini = v[i];
        }

        if (v[i] - ini > D)
        {
            apto = false;
        }
        
        ++i;
    }

    return apto;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() 
{
    // leer los datos de la entrada
    int D, N;

    cin >> D >> N;  //leer el desnivel maximo permitido y el numero de cotas de altura 

    if (!std::cin)
        return false;

    vector<int> cotas(N);

    for (int i = 0; i < N; i++)
    {
        cin >> cotas[i];    //leer las N cotas
    }

    bool sol = resolver(cotas, D);

    // escribir sol
    if (sol)
        cout << "APTA" << "\n";

    else
        cout << "NO APTA" << "\n";

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