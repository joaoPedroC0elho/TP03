#ifndef POLIGONO_H
#define POLIGONO_H


typedef struct {
    double x;
    double y;
} Ponto;


typedef struct {
    int numVertices;
    Ponto *vertices;
} Poligono;


Poligono criarPoligono(const char *nomeArquivo);
double calcularAreaPoligono( Poligono *poligono);
void liberarPoligono(Poligono *poligono);

#endif
