#include <stdio.h>
#include "ponto.h"

int main() {
    const char *nomeArquivo = "trianguloABC.txt";
    Poligono poligono;

    poligono = criarPoligono(nomeArquivo);
    double area = calcularAreaPoligono(&poligono);

    printf("A area do poligono e: %.2lf\n", area);

    liberarPoligono(&poligono);

    return 0;
}
