// Nicolae Gabriel Caliman  
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

const int CENTINELA = 0;

/*
    P = {numPuntuaciones > 0 ^ pt i: 0 <= i < v.size(): v[i] != 0}
        fun resolver(vector<integer> v, integer &numApariciones) dev integer maximo
    Q = {maximo = max k: 0 <= k < v.size(): v[k] ^ numApariciones = # k: 0 <= k < v.size(): v[k] == maximo(v)}

    siendo maximo(v) = max i: 0 <= i < v.size() : v[i]

    funcion de coste: t = v.size() - i 

    Invariante: I = {maximo = max K: 0 <= k < i: v[k]}

    Complejidad:

        La primera instruccion tiene coste constante O(1)
        El bucle se ejcuta v.size()-1 veces.
        El coste de la instruccion condicional es 2 + max(1,2) = 4 c O(1)
        
        Por tanto, el coste del bucle for() es 4*v.size() c O(v.size())

        La instruccion return tiene coste constante c O(1).

        Definitivamente, el algoritmo pertenece al orden de n, siendo n el tamanio del vector: O(n)
*/

// función que resuelve el problema
int resolver(const vector<int>& v, int& numApariciones) 
{
    int maximo = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > maximo)
        {
            maximo = v[i];
            numApariciones = 1;
        }

        else if (v[i] == maximo)
        {
            ++numApariciones;
        }
    }
    
    return maximo;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int puntuacion;

    cin >> puntuacion;  //leer puntuacion 
        
    vector<int> puntuaciones;

    while (puntuacion != CENTINELA) //mientras no se llegue al final del caso (0)
    {
        puntuaciones.push_back(puntuacion);
        cin >> puntuacion;
    }

    int numApariciones = 1;

    int maximo = resolver(puntuaciones, numApariciones);

    cout << maximo << " " << numApariciones << "\n";
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