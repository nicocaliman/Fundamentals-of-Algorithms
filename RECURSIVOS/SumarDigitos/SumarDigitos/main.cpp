// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//el problema pide tanto la recursion final como no final

/*
// función que resuelve el problema
int sumaDigitos(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        return n % 10 + sumaDigitos(n/10);  //recursion no final (se hace algo con el resultado de la funcion)
    }
}
*/

// función que resuelve el problema
int sumaDigitos(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        int num = n/10;
        int d = n % 10;
        int sum = num + d;

        return sumaDigitos(sum);  //recursion final 
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int N;
    int numero;
    int n;

    cin >> N >> numero;

    for (int i = 0; i < N; i++)
    {
        cin >> n;

        if (sumaDigitos(numero) == sumaDigitos(n))
        {
            cout << n << " ";
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