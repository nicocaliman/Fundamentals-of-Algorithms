// Nicolae Gabriel Caliman

/*
    P:{pt i, j: 0 <= i < j < v.size(): v[i] != v[j]}
        fun resolver(vector<integer> v) dev numParejas
    Q:{numParejas = #k,l: 0<=k<l<v.size(): v[k] == impar(v,k) ^ v[l] == par(v,k)}

    siendo impar(v,k) = v[k] % 2 == 1    
    siendo par(v,l) = v[l] % 2 == 0
*/  

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& v)
{
    int numParejas = 0;
    int numPares = 0;

    for (int i = v.size() - 1; i > 0; --i)
    {
        if (v[i] % 2 == 0)
        {
            numPares++;
        }

        if(v[i-1] % 2 != 0)
        {
            numParejas += numPares;
        }
    }

    return numParejas;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    vector<int> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    int sol = resolver(elementos);

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
