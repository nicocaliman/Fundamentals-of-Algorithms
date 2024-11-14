// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v)
{
    int p = -1;
    int numCeros = 0;
    int numUnos = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            numCeros++;
        }

        else if (v[i] == 1)
        {
            numUnos++;
        }

        if (numCeros == numUnos)
        {
            p = i;
        }
    }

    return p;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    // leer los datos de la entrada
    int size;

    cin >> size;

    vector<int> valores(size);

    for (int i = 0; i < size; i++)
    {
        cin >> valores[i];
    }

    int sol = resolver(valores);
    
    // escribir sol
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