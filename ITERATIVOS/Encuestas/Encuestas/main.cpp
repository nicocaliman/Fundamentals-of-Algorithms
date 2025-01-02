// Nicolae Gabriel Caliman
// FAL-A73

/*

    P = {0 < N < 1000}
     fun resolver(vector<integer> v, int numElems) dev long long integer suma
    Q = {suma = sumatorio k: 0<=k<v.size() ^ 7minimo(v, v[k]):v[k] ^ numElems = (#w:0<=w<v.size():7minimo(v,v[k]))}

        siendo minimo(v, x) = x = min i: 0<=i<v.size():v[j]

    funcion de cota: v.size()-i

    Complejidad:

    Las instrucciones del principio tienen coste constante c O(1)

    El bucle se ejecuta v.size() veces.

    El coste de las instrucciones condicionales es: 2(acceso a vector+comparacion) + max(8, 4) = 10 c O(1)

    La instruccion i++ se ejecuta v.size() veces y tiene coste constante c O(1)

    La instruccion return tiene coste constante c O(1)

    En conclusion, el orden de complejidad del algoritmo es O(n) siendo n el numero de elementos que tiene el vector
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
using lli = long long int;

// función que resuelve el problema
lli resolver(const vector<int>& v, int& numElems)
{
    int minimo = v[0];
    lli suma = 0;
    int contMin = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < minimo)
        {
            suma += (contMin * minimo);
            minimo = v[i];    //actualizar valor minimo
            numElems += contMin;
            contMin = 1;
        }

        else if (v[i] == minimo)
        {
            contMin++;
        }

        else
        {
            suma += v[i];
            numElems++;
        }
    }

    return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;

    cin >> N;

    vector<int> elementos(N);

    for (int i = 0; i < N; i++)
    {
        cin >> elementos[i];
    }

    int numValores = 0;

    lli sol = resolver(elementos, numValores);

    cout << sol << " " << numValores << "\n";
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