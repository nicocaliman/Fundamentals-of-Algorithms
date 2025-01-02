// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(const vector<int>& v, int maximo)
{
    // Cuenta el numero de apariciones
    vector <int > apariciones(maximo);

    for (int i = 0; i < v.size(); i++)
    {
        apariciones[v[i] - 1]++;    //guardar en el vector el numero de veces que aparece el indice i
    }

    // Calcula el maximo del vector apariciones
    int aparicionesMax = apariciones[0];

    for (int i = 0; i < apariciones.size();++i)
        aparicionesMax = max(aparicionesMax, apariciones[i]);

    // Anade a sol los valores que aparecen aparicionesMax veces
    vector <int > sol;

    for (int i = apariciones.size(); i > 0; --i)
    {
        // se suma 1 porque los valores de v comenzaban en 1.
        if (apariciones[i - 1] == aparicionesMax)
            sol.push_back(i);
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int valorMaximo;

    cin >> n;

    if (n == -1)
        return false;

    cin >> valorMaximo;

    vector<int> valores(n);

    for (int i = 0; i < n; i++)
    {
        cin >> valores[i];
    }

    vector<int> sol = resolver(valores, valorMaximo);
   
    // escribir sol
    for (int i = 0; i < sol.size(); i++)
    {
        cout << sol[i] << " ";
    }

    cout << "\n";


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