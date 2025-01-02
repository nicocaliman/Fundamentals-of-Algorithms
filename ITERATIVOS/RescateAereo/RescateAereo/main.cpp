// Nicolae Gabriel Caliman

/*

P = {v.size()>0 ^ menorQueT(v,t)}
    fun resolver(vector<integer> v, integer t) dev pair<int,int> sol
Q = {sol = max i,j:0<= i<=j<v.size() ^ mayoresQueT(v,i,j): j-i+1}

siendo menorQueT(v,t): ex i:0<=i<v.size(): v[i] < t
siendo mayoresQueT(v,i,j): pt k: i<=k<=j: v[k] > t

funcion de cota: t = v.size()-i

Complejidad:

Las 1as instrucciones tienen coste constante c O(1) (declaracion+asignacion)
El bucle for se ejecuta v.size() veces.

Las instrucciones condicionales tienen coste constante c O(1) 

La instruccion ini tiene un coste constante c O(1) (operaciones aritmeticas + asignacion)

La instruccion return tiene coste constante c O(1) tambien.

Por tanto, el algoritmo tiene un coste lineal c O(n) siendo n = nº de elementos del vector
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
pair<int,int> resolver(const vector<int>& v, int t)
{
    int longActual = 0;
    int longMaxima = 0;

    int ini = 0;
    int fin = 0;

    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] > t)
        {
            longActual++;

            if (longActual > longMaxima)
            {
                longMaxima = longActual;
                fin = i;
            }
        }

        else
        {
            longActual = 0;
        }
    }

    ini = fin - longMaxima + 1;

    return {ini, fin};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int t;

    cin >> n >> t;

    vector<int> elementos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> elementos[i];
    }

    pair<int,int> sol = resolver(elementos, t);

    cout << sol.first << " " << sol.second << "\n";
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