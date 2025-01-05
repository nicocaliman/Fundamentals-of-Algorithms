// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int complementario(int numero)
{
    if (numero < 10)
    {
        return 9 - numero;
    }
    else
        return 9 - numero % 10 + complementario(numero / 10) * 10;
}

int inverso(int numero, int digitoAinvertir, int acumulador)
{
    if (numero < 10)
    {
        return digitoAinvertir * 10 + 9-numero;
    }
    else
    {
        digitoAinvertir = digitoAinvertir * acumulador + 9-(numero % 10);

        return inverso(numero / 10, digitoAinvertir, 10);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numero;

    cin >> numero;

    cout << complementario(numero) << " " << inverso(numero,0,1) << "\n";
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