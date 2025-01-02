// Nicolae Gabriel Caliman
// FAL-A73

/*
    P = { 1700 <= p < q <= 100000 ^ v.size() > 0 }
        fun resolver(vector<integer> v, integer primero) dev vector<integer> beneficios
    Q = { beneficios = pt w: 0<= w < beneficios.size():beneficios[w] == beneficio(v)}

    donde beneficio(v) = pt i,j: 0 <= i < j < v.size(): v[j] > minimo(v,i,j) -> primero+j)
    siendo minimo(v,i,j) = min k: i<= k <= j: v[k]

    funcion de cota: t = v.size()-1

    Complejidad:
    Las 1as instrucciones tienen coste constante.
    El bucle se recorre v.size()-1 veces.
    La instruccion condicional tiene coste constante c O(1) (acceso a vector+comparacion+asignacion...)
    Por tanto, el coste total del bucle for() c O(v.size())

    El coste de la instruccion return es constante c O(1).

    En conclusion, el coste del algoritmo es lineal c O(n) siendo n = numero de elementos del vector
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
vector<int> resolver(const vector<int>& v, int p)
{
    vector<int> beneficios;
    int minimo = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > minimo)
        {
            beneficios.push_back(p+i);
            minimo = v[i];
        }
    }

    return beneficios;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int p;
    int u;

    cin >> p >> u;

    int numElementos = u - p + 1;

    vector<int> ventas(numElementos);

    for (int i = 0; i < numElementos; i++)
    {
        cin >> ventas[i];
    }

    vector<int> sol = resolver(ventas, p);

    if (!sol.empty())
    {
        for (int i = 0; i < sol.size(); i++)
        {
            cout << sol[i] << " ";
        }
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