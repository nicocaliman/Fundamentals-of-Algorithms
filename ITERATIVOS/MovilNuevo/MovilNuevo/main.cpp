// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(const vector<int>& v1, const vector<int>&v2)
{
    vector<int> mezclaOrdenada;
    int i = 0;
    int j = 0;

    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            mezclaOrdenada.push_back(v1[i]);
            ++i;
        }

        else if (v2[j] < v1[i])
        {
            mezclaOrdenada.push_back(v2[j]);
            ++j;
        }

        else
        {
            mezclaOrdenada.push_back(v1[i]);
            ++i;
            ++j;
        }
    }

    while (i < v1.size())
    {
        mezclaOrdenada.push_back(v1[i]);
        ++i;
    }

    while (j < v2.size())
    {
        mezclaOrdenada.push_back(v2[j]);
        ++j;
    }

    return mezclaOrdenada;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n1, n2;

    cin >> n1 >> n2;

    vector<int>catalogoA(n1);

    for (int i = 0; i < n1; i++)
    {
        cin >> catalogoA[i];
    }

    vector<int>catalogoB(n2);
    
    for (int i = 0; i < n2; i++)
    {
        cin >> catalogoB[i];
    }

    vector<int> sol = resolver(catalogoA, catalogoB);

    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }

    cout << "\n";
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