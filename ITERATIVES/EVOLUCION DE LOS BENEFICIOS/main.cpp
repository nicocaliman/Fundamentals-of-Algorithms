// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:

    Las instrucciones iniciales tienen coste constante O(1): asignaciones + acceso a vector

    El bucle for se ejecuta v.size()-1 veces:

        La instruccion if tiene coste constante O(1) pues son comparaciones + maximo instrucciones condicionales (tmbn coste constante O(1))

    Por tanto. como todas las vueltas tienen el mismo coste, multiplicamos el coste de cada vuelta por el numero de vueltas: v.size()-1 vueltas = n-1 * O(1)

    El coste del algoritmo es lineal O(n).
*/

// función que resuelve el problema
vector<int> resolver(const vector<int> &v, int y1) 
{
    vector<int> beneficios; //declarar vector donde van a ir los años en los que se obtuvo beneficio
    int profit = v[0];   
    int aux = y1+1; //no consideramos el primer año, lo pone el enunciado

    //recorrer desde 0 hasta n-1, penultimo elemento del vector
    for (int i = 0; i < v.size()-1; i++)
    {
        if (profit < v[i+1])    //si el beneficio del siguiente año es mayor que 
        {
            aux += i;   
            beneficios.push_back(aux);  //meter año de beneficio en el vector
            aux = y1 + 1;   //resetear al primer año
            profit = v[i + 1];  //actualizar beneficio
        }
    }

    return beneficios;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    int y1, y2;

    cin >> y1 >> y2;    //leer primer y ultimo año

    vector<int> ventas((y2-y1)+1);

    for (int i = 0; i < ventas.size(); i++)
    {
        cin >> ventas[i];
    }

    vector<int> beneficios = resolver(ventas, y1);
   
    // escribir sol
    for (int i = 0; i < beneficios.size(); i++)
    {
        cout << beneficios[i] << " ";
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