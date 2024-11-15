// Nicolae Gabriel Caliman
// FAL-A73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int numEtapas;

    cin >> numEtapas;   //leer numero de etapas de las que consta el viaje

    if (numEtapas == -1)
        return false;

    vector<int> kilometros(numEtapas);   //declarar vector que contiene los kilometros que se recorren en cada etapa

    //recorrer vector
    for (int i = 0; i < kilometros.size(); i++)
    {
        cin >> kilometros[i];    //cargar elementos en el vector
    }

    int numPreguntas;

    cin >> numPreguntas;    //leer numero de dias en que Picaporte se pregunta cuantos kilometros quedaran para llegar a casa

    vector<long long int> dias(numPreguntas); //vector que guarda los dias en los que Picaporte se pregunta cuantos kilometros quedaran para llegar a casa

    for (int i = 0; i < numPreguntas; i++)
    {
        cin >> dias[i]; //cargar elementos en el vector
    }

    vector<long long int> aux(numEtapas + 1);

    aux[0] = 0;

    for (int i = 0; i < kilometros.size(); i++)
    {
        aux[i + 1] = aux[i] + kilometros[i];    //vector que contiene los kilometros acumulados de etapas previas
    }

    for (int i = 0; i < dias.size(); i++)
    {
        if (dias[i] != aux.size())  //si no esta al final del vector
        {
            dias[i] = aux[aux.size() - 1] - aux[dias[i] - 1];
        }

        else    //si esta al final del vector
        {
            dias[i] = 0;
        }
    }

    // escribir sol
    for (int i = 0; i < dias.size(); i++)
    {
        std::cout << dias[i] << '\n';
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
