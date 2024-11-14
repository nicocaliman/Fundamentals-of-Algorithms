// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
bool resolver(const vector<int>& v, int maximo)
{
    bool divertidoYcreciente = true;
    int i = 1;
    int cont = 1;

    while (i < v.size() && divertidoYcreciente)
    {
        if (v[i] == v[i-1])
        {
            cont++;
        }

        else
        {
            cont = 1;
        }

        if (v[i] < v[i-1] || v[i] - v[i-1] > 1 || cont > maximo)
        {
            divertidoYcreciente = false;
        }

        ++i;
    }

    return divertidoYcreciente;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    // leer los datos de la entrada
    int max;
    int n;

    cin >> max >> n;

    vector<int> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    bool sol = resolver(elementos, max);

    // escribir sol
    if (sol)
        cout << "SI\n";

    else
        cout << "NO\n";
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