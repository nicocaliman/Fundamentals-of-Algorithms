// Nicolae Gabriel Caliman
// FAL-A73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:

    Las instrucciones del inicio tienen coste constante O(1):
        acceso a vector + asignacion
        asignacion

    El if del principio O(1):
        comparacion tiene coste constante
        +
        maximo(instrucciones condicionales) tambien tiene coste constante O(1)

    El for da v.size() vueltas:

        Las instrucciones condicionales:

            la condicion tiene coste constante O(1)
            +
            maximo instrucciones condicionales: son otro if que tienen el mismo coste que este O(1)

    Por tanto, el bucle for tiene coste constante en todas sus vueltas, da igual que condicion pase, si el if o el else

    Como da v.size() vueltas siendo v.size() = n, el coste total es O(n)
*/

// función que resuelve el problema
bool resolver(const vector<int>& v, int p)
{
    int maximoI = v[0];
    int minimoD = INT_MAX;

    if (p == v.size() - 1)
        return true;

    //recorrer vector
    for (int i = 0; i < v.size(); i++)
    {
        //zona (x1) en la que se supone que son todos estrictamente menores que en la zona x2
        if (i <= p)
        {
            if (v[i] > maximoI)
            {
                maximoI = v[i];
            }
        }

        //zona (x2)
        else
        {
            if (v[i] < minimoD) 
            {
                minimoD = v[i];
            }
        }
    }

    return maximoI < minimoD;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElems, posicion;

    cin >> numElems >> posicion;   //leer numero de elementos del vector y la posicion que deberia separar los valores menores de los mayores

    vector<int> valores(numElems);

    for (int i = 0; i < valores.size(); i++)
    {
        cin >> valores[i];
    }

    bool sol = resolver(valores, posicion);
    
    // escribir sol
    if (sol)
        cout << "SI" << "\n";

    else
        cout << "NO" << "\n";

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