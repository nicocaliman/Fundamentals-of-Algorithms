// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*
    P = {1 <= n <= 300000 ^ 0 <= p <= n-1}
        fun resolver(vector<integer> v, int p) dev bool bd
    Q = {bd = (max k: 0 <= k <= p: v[k]) < (min l: p+1 <= l < v.size():v[l])}

    funcion de coste: t = p - i para el primer bucle
                      t = v.size() - i par el segundo bucle

    Complejidad:

    Las 2 primeras instrucciones tienen coste constante c O(1).

   En si vemos que los 2 bucles tienen coste constante, pues vemos
   que el coste de las instrucciones condicionales de ambos bucles es constante.

   Tambien se observa que, si juntamos ambos bucles se recorre el vector de inicio a fin.
   
   La instruccion return tiene coste constante c O(1).

   En definitiva, como el coste de todas las vueltas es contante la complejidad del algoritmo es
   del orden de n c O(n) siendo n = nº elementos del vector
*/

// función que resuelve el problema
bool resolver(const vector<int>& v, int p)
{
    int maximoIzq = v[0];
    int minimoDer = 100000;

    for (int i = 0; i <= p; i++)
    {
        if (v[i] > maximoIzq)
        {
            maximoIzq = v[i];
        }
    }

    for (int i = p+1; i < v.size(); i++)
    {
        if (v[i] < minimoDer)
        {
            minimoDer = v[i];
        }
    }

    return maximoIzq < minimoDer;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int numElementos;
    int  p;

    cin >> numElementos >> p;

    vector<int> elementos(numElementos);

    for (int i = 0; i < numElementos; i++)
    {
        cin >> elementos[i];
    }

    bool sol = resolver(elementos, p);
    
    if (sol)
    {
        cout << "SI\n";
    }
    else
    {
        cout << "NO\n";
    }
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