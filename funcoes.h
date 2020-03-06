#ifndef STRUCT_H
#define STRUCT_H
#include "struct.h"

void gerarBombas (int lin, int col, int maxbomb, tCampo campo[lin][col]);
void mostraCampo (int lin, int col, tCampo campo[lin][col], int bandeiras);
void marcarBomba (int lin, int col, tCampo campo[lin][col], int ci, int cj, int *bandeiras);
void abrirCasa (int lin, int col, tCampo campo [lin][col], int verifica[lin][col], int ci, int cj);
int ganhou (int lin, int col, tCampo campo[lin][col], int maxbomb);

#endif