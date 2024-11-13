// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:
    
    Las instrucciones iniciales tienen coste constante O(1)

    El bucle for se ejecuta v.size() veces:

        La primera instruccion condicional tiene el siguiente coste:
                La cabecera tiene coste constante O(1) + maximo instrucciones condicionales tambien tiene coste constante O(1)

        La segunda instruccion condicional tiene el mismo coste O(1).

    Por tanto, como todas las vueltas tienen el mismo coste, multiplicamos el coste x el numero de vueltas: O(n) siendo n el tamaño del vector
*/

typedef struct tEdificio
{
    string id;
    int altura;
    int hPiso;
};

// función que resuelve el problema
vector<string> resolver(const vector<tEdificio>& v)
{
    int hMax = 0;  //inicializamos la altura a la del mar
    vector<string> ids;

    //recorrer desde la costa hacia dentro
    for (int i = v.size()-1; i >= 0; --i)
    {
        if (v[i].hPiso != -1 && v[i].hPiso > hMax)
        {
            ids.push_back(v[i].id);
        }

        if (v[i].altura > hMax)
        {
            hMax = v[i].altura;
        }
    }

    return ids;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() 
{
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector<tEdificio> edificios(n);

    for (int i = 0; i < edificios.size(); i++)
    {
        cin >> edificios[i].id >> edificios[i].altura >> edificios[i].hPiso;
    }

    vector<string> identificadores = resolver(edificios);

    // escribir sol
    if (identificadores.empty())
    {
        cout << "Ninguno";
    }

    else
    {
        cout << identificadores.size() << "\n";

        for (int i = 0; i < identificadores.size(); i++)
        {
            cout << identificadores[i] << " ";
        }
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