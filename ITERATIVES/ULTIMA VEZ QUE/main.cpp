// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    COSTE:
    Las 3 primeras instrucciones tienen coste constante O(1).

    Las 2 comparaciones de la cabecera son de coste constante O(1).

        Las instrucciones condicionales:

            if(nacionalidad == v[i]) -> acceso + comparacion (coste constante O(1))
                ultima = true;       -> asignacion (coste constante O(1))

            else
                ultimaVez++;         -> operacion aritmetica (coste constante O(1))

            Las instrucciones condicionales tienen coste constante O(1).
            
        --i;    -> operacion aritmetica (coste constante O(1))

    El bucle tiene coste constante O(1).
    Se dan n vueltas, por tanto, el coste es O(n), siendo n el tamaño del vector
*/

// función que resuelve el problema
int resolver(const vector<string> &v, const string &nacionalidad)
{
    int ultimaVez = 1;  //suponemos que la ultima carrera se realizop hace 1 anno

    int i = v.size() - 1;
    bool ultima = false;

    //recorrer vector desde el final
    while (i >= 0 && !ultima)
    {
        if (nacionalidad == v[i])   //si es la nacionalidad que estamos buscando 
            ultima = true;  //hemos dejado de buscar 
        
        else        //sino
            ultimaVez++;    //los annos aumentan        

        --i;
    } 

    if (!ultima)    //si no ha ganado en los ultimos annos 
    {
        ultimaVez = 0;  //flag 
    }

    return ultimaVez;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    int numAnnos;
    string nacionalidad;

    cin >> numAnnos >> nacionalidad;    //leer el numero de annos y la nacionalidad que estamos buscando

    if (numAnnos == 0)
        return false;

    vector<string> ganadores(numAnnos); //vector que almacena los ganadores en los ultimos <numAnnos> annos

    for (int i = 0; i < ganadores.size(); i++)
    {
        cin >> ganadores[i];    //cargar vector con ganadores
    }

    int sol = resolver(ganadores, nacionalidad);    //devuelve el ultimo anno en el que gano la carrera


    // escribir sol
    if (sol == 0)
        cout << "NUNCA" << "\n";

    else
        cout << sol << "\n";

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
