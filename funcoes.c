#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "funcoes.h"

void gerarBombas (int lin, int col, int maxbomb, tCampo campo[lin][col]){

    int i, j, k, l, ri, rj, cont = 0;

    for (i = 0; i < lin; i++){
        for (j = 0; j < col; j++){
            campo[i][j].user = '*';
            campo[i][j].map = 0;
        }
    }

    srand(time(NULL));

    while (cont < maxbomb){
        ri = (rand() % (lin - 2)) + 1;
        rj = (rand() % (col - 2)) + 1;

        if (campo[ri][rj].map != -1){
            campo[ri][rj].map = -1;
            cont++;
        }
    }

    for (i = 1; i < lin - 1; i++){
        for (j = 1; j < col - 1; j++){

            if(campo[i][j].map == -1){
                for(k = i-1; k < i+2; k++){
                    for(l = j-1; l < j+2; l++){

                        if(campo[k][l].map != -1){
                            campo[k][l].map++;
                        }
                    }
                }
            }
        }
    }
}

void mostraCampo(int lin, int col, tCampo campo[lin][col], int bandeiras){

    int i, j;

    system("cls || clear");

    printf("Bandeiras restantes: %d\n\n", bandeiras);

    printf("   ");
    for(j = 1; j < col - 1; j++){
        (j < 10) ? printf("0%d ", j) : printf("%d ", j);
    }
    printf("\n");
    for(i = 1; i < lin - 1; i++){
        for(j = 1; j < col - 1; j++){
            if(j == 1){
                (i < 10) ? printf("0%d ", i) : printf("%d ", i);
            }

            printf(" %c ", campo[i][j].user);

            if(j == col - 2){
                (i < 10) ? printf(" 0%d ", i) : printf(" %d ", i);
            }
        }
        printf("\n");
    }
    printf("   ");
    for(j = 1; j < col - 1; j++){
        (j < 10) ? printf("0%d ", j) : printf("%d ", j);
    }
    printf("\n\n");
}

void marcarBomba (int lin, int col, tCampo campo[lin][col], int ci, int cj, int *bandeiras){

    if(campo[ci][cj].user == 'B'){
        campo[ci][cj].user = '*';
        (*bandeiras)++; 
    }else{
        campo[ci][cj].user = 'B';
        (*bandeiras)--;
    }
}

void abrirCasa (int lin, int col, tCampo campo[lin][col], int verifica[lin][col], int ci, int cj){

    int i, j;

    if (campo[ci][cj].map > 0 || ci == 0 || ci == lin-1 || cj == 0 || cj == col-1)
    {

        campo[ci][cj].user = campo[ci][cj].map + '0';
        verifica[ci][cj] = 1;

    }else{

        if(campo[ci][cj].map == 0){

            campo[ci][cj].user = ' ';
            verifica[ci][cj] = 1;

            for(i = ci - 1; i < ci + 2; i++){
                for(j = cj - 1; j < cj + 2; j++){

                    if(verifica[i][j] != 1){
                        abrirCasa(lin, col, campo, verifica, i, j);
                    }
                }
            }
        }
    }
}

int ganhou (int lin, int col, tCampo campo[lin][col], int maxbomb){

    int i, j, bombasv = 0, bombasf = 0;

    for(i = 0; i < lin-1; i++){
        for(j = 0; j < col-1; j++){
            if(campo[i][j].user == 'B'){
                if(campo[i][j].map == -1){
                    bombasv++;
                }else{
                    bombasf++;
                }
            }
        }
    }

    if(bombasv == maxbomb && bombasf == 0){
        return 1;
    }else{
        return 0;
    }
}