// Nicolae Gabriel Caliman

/*

    P:{v.size() >= 0}
        fun menorPico(vector<integer> v) dev {bool encontrado, integer pico}
    Q:{pico = min k: 0 < k < v.size()-1 ^ pico(v,v.size(),k): v[k] ^ encontrado = ex p: 0<p<v.size()-1: pico(v,v.size(),p)}

    siendo pico(v,n,i): ex i: 0<i<n-1: v[i-1]<v[i] && v[i] > v[i+1]

    Complejidad:

    Las 2 primeras instrucciones tienen coste constante O(1) (declaraciones + asignaciones)

    En cuanto al bucle for():

        int i = 1; se ejecuta 1 vez, por tanto, tiene coste constante O(1)
        i < v.size()-1; tiene coste 3 (1 comparacion+ 1 funcion v.size() + operacion aritmetica)
        que se ejecuta v.size()-2 veces 

        El if() interno tiene coste constante o(1) (operaciones aritmeticas + asignaciones)
        la cabecera del if() externo tiene coste constante(1) tambien (acceso a vector + comparaciones)

    Por tanto, todas las vueltas tiene coste constante O(1).

    El cuerpo se ejecuta v.size()-2 veces.

    En definitiva, el coste del bucle for() es O(v.size()) ~ O(n) siendo n = numero de elementos del vector

    La isntruccion return tiene coste constante tambien O(1).

    Por tanto, el coste del algoritmo es lineal O(n).

    funcion cota: t = v.size() - i - 1

    I:{pico = min k:0<k<=i ^ pico(v, v.size(), k): v[k]}
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<bool, int> menorPico(const vector<int>& v)
{
    bool encontrado = false;
    int menorPico = INT_MAX;

    for (int i = 1; i < v.size()-1; i++)
    {
        if (v[i-1] < v[i] && v[i] > v[i+1])
        {
            if (v[i] < menorPico)
            {
                menorPico = min(menorPico, v[i]);
                encontrado = true;
            }
        }
    }

    return {encontrado, menorPico};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector<int> v(n);

    for (int i = 0; i < v.size(); i++)
    {
        cin >> v[i];
    }

    pair<bool, int> sol = menorPico(v);

    if (sol.first)
    {
        cout << sol.second;
    }

    else
    {
        cout << "no hay";
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