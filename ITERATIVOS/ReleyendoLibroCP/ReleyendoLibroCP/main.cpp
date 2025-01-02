// Nicolae Gabriel Caliman
// FAL A-73

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// función que resuelve el problema
int resolver(std::vector<int> const& v, int l) {
    int sumaParcial = v[0], max = v[0], posMax = 0, sol = 0;
    for (int i = 1; i < l; i++) {
        sumaParcial += v[i];
        if (v[i] >= max) {
            max = v[i];
            posMax = i;
        }
    }
    int sumaMax = sumaParcial;
    for (int j = 0; j < v.size() - l; j++) {
        sumaParcial += v[j + l];
        sumaParcial -= v[j];
        if (v[j + l] > max) {
            max = v[j + l];
            posMax = j + l;
            sol = j + 1;
            sumaMax = sumaParcial;
        }
        else {
            if (v[j + l] == max)
                posMax = j + l;
            if (posMax > j && sumaParcial >= sumaMax) {
                sol = j + 1;
                sumaMax = sumaParcial;
            }
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, l;
    std::cin >> n >> l;
    if (n == 0 && l == 0)
        return false;
    std::vector<int>v(n);
    for (int i = 0; i < v.size(); i++) {
        std::cin >> v[i];
    }
    // resolver
    int sol = resolver(v, l);
    // escribir sol
    std::cout << sol << std::endl;

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