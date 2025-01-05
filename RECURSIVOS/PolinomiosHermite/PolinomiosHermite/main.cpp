// Nicolae Gabriel Caliman

/*
ecuacion de recurrencia:
       
       |    co      si n == 0 || n == 1
T(n) = |
       |    2T(n-1) + c1     si n > 1


T(n) = 2T(n-1) + c1 = 
     = 2(2T(n-2) + c1) + c1 =
     = 4T(n-2) + 2c1 + c1 =
     = 4(2T(n-3) + c1) + 2c1 + c1 = 
     =8T(n-3) + 4c1 + 2c1 + c1 = ...=
     = 2^kT(n-k) + sum i: 0<=i<=k-1: 2^i*c1=
     = 2^kT(n-k) + c1sum i: 0<=i<=k-1: 2^i=
     = 2^nT(0) + c1*2^n c O(2^n)
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
using lli = long long int;

// función que resuelve el problema
lli H(int n, int y)
{
    if (n == 0) //caso base
    {
        return 1;
    }

    else if (n == 1)    //caso base
    {
        return 2 * y;
    }

    else
    {
        return 2 * y * H(n - 1, y) - 2 * (n - 1) * H(n - 2, y);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    int y;

    cin >> n;

    if (n == -1)
        return false;

    cin >> y;

    cout << H(n, y) << "\n";

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