// Nicolae Gabriel Caliman

/*
    P = {0 < p <= u <= 100 000 ^ 0 <= n < 2^30 ^ 0 < m <= 100 000}
        fun resolver(vector<int> v) dev vector<int> acumulados
    Q = {acumulados = pt i: 0<= i<v.size(): w[i] == sumaAcumulados(v,w,i)}

    siendo sumaAcumulados(v,i) = (w[i] = sumatorio k: k<=i<v.size():v[k])

    funcion de cota: t = acumulados.size()-i

    Complejidad:

    La primera instruccion tiene coste constante c O(1)

    El bucle se ejecuta v.size()-1 veces

    Cada vuelta tiene un coste constante c O(1) (acceso a vector, operacion aritmetica, asignacion...)

    La instruccion return tiene un coste constante c O(1).

    En conclusion el coste asintotico del algoritmo es lineal c O(n) siendo n = nº elementos del vector
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;

// función que resuelve el problema
vector<lli> resolver(const vector<int>& v) 
{
    vector<lli> acumulados(v.size() + 1, 0);

    for (int i = 1; i < acumulados.size(); i++)
    {
        acumulados[i] = acumulados[i - 1] + v[i - 1];
    }

    return acumulados;    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int p;
    int u;
    int n;

    cin >> p >> u;

    if (p == 0 && u == 0)
        return false;

    n = u - p + 1;

    vector<int> nacimientos(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nacimientos[i];
    }

    vector<lli> sol = resolver(nacimientos);

    int m;
    int a;
    int b;

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        cout << sol[b-p+1] - sol[a-p] << "\n";
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