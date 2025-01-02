// Nicolae Gabriel Caliman

/*
    P = {0<n<200000 ^ 0<=alturaEdificio<200000}
        fun resolver(vector<struct> v) dev vector<string> edificios
    Q = {edificios = pt i: 0<=i<v.size(): w[i].id == edificioConPV(v,w,i)}

    siendo edificioConPV(v,w,i): w[i] = 7ex k: i<=k<v.size(): edificioMasAlto(v, k) > v[k].alturaPiso
    siendo edificioMasAlto(v,k): max b: k<=b<v.size(): v[b]

    funcion de cota: t = i

    Complejidad:
    Las 1as instrucciones tienen coste constante c O(1).
    El bucle for() se ejecuta v.size()-1 veces.
    Las instrucciones condicionales tienen coste constante (acceso a vector, comparacion, asignacion...) c O(1)
    Por tanto, el coste total del bucle for es lineal c O(v.size())

    La instruccion return tiene coste constante c O(1).
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct tEdificio
{
    string id;
    int alturaEdificio;
    int alturaPiso;
};

// función que resuelve el problema
vector<string> resolver(const vector<tEdificio>& v)
{
    vector<string> edificios;
    int alturaMasAlto = -1;

    for (int i = v.size()-1; i >= 0; --i)
    {
        if (v[i].alturaPiso != -1 && v[i].alturaPiso > alturaMasAlto)
        {
            edificios.push_back(v[i].id);
        }

        if (v[i].alturaEdificio > alturaMasAlto)
        {
            alturaMasAlto = v[i].alturaEdificio;
        }
    }

    return edificios;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector<tEdificio>edificios(n);

    for (int i = 0; i < n; i++)
    {
        cin >> edificios[i].id >> edificios[i].alturaEdificio >> edificios[i].alturaPiso;
    }

   vector<string> sol = resolver(edificios);

   if (sol.empty())
   {
       cout << "Ninguno";
   }

   else
   {
       cout << sol.size() << "\n";

       for (int i = 0; i < sol.size(); i++)
       {
           cout << sol[i] << " ";
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