// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;   //numero de etapas de las que consta el viaje

    if (n == -1)
        return false;

    vector<int> kilometros(n);

    for (int i = 0; i < n; i++)
    {
        cin >> kilometros[i];
    }

    vector<lli> acumulados(n + 1);
    acumulados[0] = 0;
     
    for (int i = 1; i < acumulados.size(); i++)
    {
        acumulados[i] = acumulados[i - 1] + kilometros[i - 1];
    }

    int numPreguntas;
    int dia;

    cin >> numPreguntas;

    for (int i = 0; i < numPreguntas; i++)
    {
        cin >> dia;

        cout << acumulados[acumulados.size()-1] - acumulados[dia-1] << "\n";
    }

    cout << "---\n";

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