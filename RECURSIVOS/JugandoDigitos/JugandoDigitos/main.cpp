// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int modificarDigitos(int numero)
{
    if (numero < 10)
    {
        if (numero % 2 == 0)
        {
            ++numero;
        }

        else
        {
            --numero;
        }

        return numero;
    }

    else
    {
        int n = (numero % 10);

        if (n % 2 == 0)
        {
            n++;
        }

        else
        {
            n--;
        }

        return n + modificarDigitos(numero/10)*10;  //recursion no final
    }

}

int modificarDigitos(int numero, int acumulador)
{
    if (numero < 10)
    {
        if (numero % 2 == 0)
        {
            ++numero;
        }

        else
        {
            --numero;
        }

        return numero;
    }

    else
    {
        int n = (numero % acumulador);

        if (n % 2 == 0)
        {
            n++;
        }

        else
        {
            n--;
        }

        return modificarDigitos(numero / 10*10+n, acumulador*10);  //recursion no final
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero;

    cin >> numero;

    cout << modificarDigitos(81,10) << "\n";
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