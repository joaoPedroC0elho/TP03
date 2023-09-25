#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"


Poligono criarPoligono(const char *nomeArquivo) {
    FILE *arquivo;
    int numVertices;
    Ponto *vertices;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    fscanf(arquivo, "%d", &numVertices);
    vertices = (Ponto *)malloc(sizeof(Ponto) * numVertices);

    if (vertices == NULL) {
        perror("Erro ao alocar memória para vertices");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numVertices; i++) {
        fscanf(arquivo, "%lf %lf", &vertices[i].x, &vertices[i].y);
    }

    fclose(arquivo);

    Poligono poligono;
    poligono.numVertices = numVertices;
    poligono.vertices = vertices;

    return poligono;
}


double calcularAreaPoligono( Poligono *poligono) {
    double area = 0.0;

    for (int i = 0; i < poligono->numVertices; i++) {
        int j = (i + 1) % poligono->numVertices;
        area += (poligono->vertices[i].x * poligono->vertices[j].y) -
                (poligono->vertices[j].x * poligono->vertices[i].y);
    }

    return 0.5 * abs(area);
}


void liberarPoligono(Poligono *poligono) {
    free(poligono->vertices);
    poligono->numVertices = 0;
}
