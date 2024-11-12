// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:

    Las instrucciones iniciales tienen coste constante O(1): asignaciones + acceso a vector

    El bucle while se ejecuta v.size() veces:

        La instruccion if tiene coste constante O(1) pues son comparaciones + maximo instrucciones condicionales (tmbn coste constante O(1))
        
        Luego, vienen operaciones aritmeticas que tambien tienen coste constante O(1).

    Por tanto. como todas las vueltas tienen el mismo coste, multiplicamos el coste de cada vuelta por el numero de vueltas: v.size() vueltas = n * O(1)

    El coste del algoritmo es lineal O(n).
*/

// función que resuelve el problema
bool resolver(const vector<int> &v, int& p) 
{
    int sum = 0;
    bool encontrado = false;
    int i = v.size()-1;

    while (i >= 0 && !encontrado)
    {
        if (v[i] == sum)
        {
            p = i;  //indice pastoso
            encontrado = true;  //primer pastoso encontrado
        }

        sum += v[i];    //sumar valores posteriores al indice pastoso

        --i;
    }

    return encontrado;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int size;

    cin >> size;    //leer tamaño del vector

    vector<int> valores(size);

    for (int i = 0; i < valores.size(); i++)
    {
        cin >> valores[i];
    }

    int p = -1;

    bool sol = resolver(valores, p);
   
    // escribir sol
    if (sol)
    {
        cout << "Si" << " " << p << "\n";
    }

    else
    {
        cout << "No" << "\n";
    }
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