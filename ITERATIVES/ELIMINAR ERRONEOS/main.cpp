// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
void resolver(vector<int> & v, int erroneo)
{
    int buenos = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (erroneo != v[i])
        {
            v[buenos] = v[i];
            ++buenos;
        }
    }

    v.resize(buenos);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int numMedidas, vErroneo;

    cin >> numMedidas >> vErroneo;  //leer numero de medidas tomadas y el valor erroneo

    vector<int> valores(numMedidas);

    for (int i = 0; i < numMedidas; i++)
    {
        cin >> valores[i];
    }

    resolver(valores, vErroneo);

    // escribir sol

    cout << valores.size() << "\n";

    for (int i = 0; i < valores.size(); i++)
    {
        cout << valores[i] << " ";
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