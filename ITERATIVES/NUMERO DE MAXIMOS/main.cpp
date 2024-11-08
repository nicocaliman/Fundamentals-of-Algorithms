// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE(resolver):

    La primera instruccion tiene coste 2(acceso a v[] + asignacion) = coste constante O(1)

    Las instrucciones de la cabecera del bucle:

        - int i = 1 : asignacion (coste constante O(1))
        - i < v.size(): comparacion (coste constante O(1)) -> se ejecuta v.size()-1 veces
        - i++: operacion aritmetica (coste constante O(1))  -> se ejecuta v.size()-1 veces

    Las instrucciones condicionales:

        if(v[i] > maximo)  = acceso + comparacion (coste constante O(1))
            maximo = v[i];  = acceso + asignacion (coste constante O(1))

        else if(v[i] == maximo) = acceso + comparacion (coste constante O(1))
            ++nr;               = operacion aritmetica (coste constante O(1))

    Como el coste de una vuelta es constante O(1), el coste del bucle for es O(1)*O(n) = O(n)

    siendo n = numero de puntuaciones que tiene el vector
*/

// función que devuelve la maxima puntuacion
int resolver(const vector<int> &v, int &nr)
{
    int maximo = v[0];  //cogemos el primer valor del vector como maximo

    //recorrer puntuaciones desde el 2o elemento del vector
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > maximo)  //si hemos encontrado un valor mayor que el que teniamos como maximo  
            maximo = v[i];         //actualizar maximo

        else if (v[i] == maximo)    //si hemos encontrado un valor identico al maximo
            ++nr;                  //actualizar contador de repetidos
    }

    return maximo;  //devolver maximo
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int puntuacion;
    
    cin >> puntuacion;

    vector<int> v;  //vector sin tamaño

    //mientras no sea el fin de caso(0)
    while (puntuacion != 0)
    {
        v.push_back(puntuacion);    //agregar al vector la puntuacion
        cin >> puntuacion;
    }

    int numRepetido = 1;    //como en resolver consideramos maximo al primer elemento, consideramos que hemos visto ese elemento 1 vez

    int sol = resolver(v, numRepetido); //almacenar en sol la puntuacion maxima
        
    // escribir sol
    cout << sol << " " << numRepetido << "\n";  // <puntuacion maxima> <numero de veces repetido>
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