#include <stdio.h>
#include <stdlib.h>

#include "funcoes.h"

int main(){

    int optam, lin, col, i, j, maxbomb, flag = 0, coordi, coordj, bandeiras;
    char op;

    system("cls || clear");

    printf("Escolha o tamanho do campo:\n1 - 9x9 (10 bombas)\n2 - 16x16 (40 bombas)\n3 - 16x30 (99 bombas)\n"); 
    scanf("%d", &optam);
    getchar();

    if(optam == 1){
        lin = 11;
        col = 11;
        maxbomb = 10;
    }else{
        if(optam == 2){
            lin = 18;
            col = 18;
            maxbomb = 40;
        }else{
            lin = 18;
            col = 32;
            maxbomb = 99;
        }
    }

    tCampo campo[lin][col];

    gerarBombas(lin, col, maxbomb, campo);

    bandeiras = maxbomb;

    do{

        mostraCampo(lin, col, campo, bandeiras);

        printf("\nDigite a coordenada e a operacao que deseja fazer (A - Abrir casa ou B - Marcar/Desmarcar bomba): ");
        scanf("%d %d %c", &coordi, &coordj, &op);
        getchar();

        if(coordi > 0 && coordi < lin-1 && coordj > 0 && coordj < col-1){
            if(op == 'A' || op == 'a'){

                if(campo[coordi][coordj].map == -1){

                    printf("Bandeiras restantes: %d\n\n", bandeiras);

                    printf("   ");
                    for(j = 1; j < col - 1; j++){
                        (j < 10) ? printf("0%d ", j) : printf("%d ", j);
                    }
                    printf("\n");
                    for(i = 1; i < lin - 1; i++) {
                        for(j = 1; j < col - 1; j++){
                            if(j == 1){
                                (i < 10) ? printf("0%d ", i) : printf("%d ", i);
                            }
                            
                            if(campo[i][j].map == -1){
                                printf(" # ");
                            }else{
                                if(campo[i][j].user == 'B'){
                                    printf(" X ");
                                }else{
                                    printf(" %c ", campo[i][j].user);
                                }
                            }

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

                    printf("# - Bombas\n");
                    printf("X - Marcacao de bombas erradas\n\n");

                    printf("\n===============================");
                    printf("\nXABLAU!!! VOCE PERDEU!!!");
                    printf("\n===============================\n");
                    getchar();
                    printf("\n\n───────▄▀▀▀▀▀▀▀▀▀▀▄▄\n────▄▀▀░░░░░░░░░░░░░▀▄\n──▄▀░░░░░░░░░░░░░░░░░░▀▄\n──█░░░░░░░░░░░░░░░░░░░░░▀▄\n─▐▌░░░░░░░░▄▄▄▄▄▄▄░░░░░░░▐▌\n─█░░░░░░░░░░░▄▄▄▄░░▀▀▀▀▀░░█\n▐▌░░░░░░░▀▀▀▀░░░░░▀▀▀▀▀░░░▐▌\n█░░░░░░░░░▄▄▀▀▀▀▀░░░░▀▀▀▀▄░█\n█░░░░░░░░░░░░░░░░▀░░░▐░░░░░▐▌\n▐▌░░░░░░░░░▐▀▀██▄░░░░░░▄▄▄░▐▌\n─█░░░░░░░░░░░▀▀▀░░░░░░▀▀██░░█\n─▐▌░░░░▄░░░░░░░░░░░░░▌░░░░░░█\n──▐▌░░▐░░░░░░░░░░░░░░▀▄░░░░░█\n───█░░░▌░░░░░░░░▐▀░░░░▄▀░░░▐▌\n───▐▌░░▀▄░░░░░░░░▀░▀░▀▀░░░▄▀\n───▐▌░░▐▀▄░░░░░░░░░░░░░░░░█\n───▐▌░░░▌░▀▄░░░░▀▀▀▀▀▀░░░█\n───█░░░▀░░░░▀▄░░░░░░░░░░▄▀\n──▐▌░░░░░░░░░░▀▄░░░░░░▄▀\n─▄▀░░░▄▀░░░░░░░░▀▀▀▀█▀\n▀░░░▄▀░░░░░░░░░░▀░░░▀▀▀▀▄▄▄▄▄\n\n");
                    flag = 1;
                }else{
                    if(campo[coordi][coordj].user == 'B'){
                        printf("\nNao eh posivel abrir uma casa marcada como bomba!\n");
                        getchar();
                    }else{
                        int verifica[lin][col];
                        for(i = 0; i < lin; i++){
                            for(j = 0; j < col; j++){
                                verifica[i][j] = 0;
                            }
                        }
                        abrirCasa(lin, col, campo, verifica, coordi, coordj);
                    }
                }
            }else{
                if(op == 'B' || op == 'b'){
                    if(campo[coordi][coordj].user == '*' || campo[coordi][coordj].user == 'B'){
                        marcarBomba(lin, col, campo, coordi, coordj, &bandeiras);
                    }else{
                        printf("\nVoce nao pode marcar uma bomba em uma casa aberta!\n");
                        getchar();
                    }
                }else{
                    printf("\nEntrada de operacao invalida!\n");
                    getchar();
                }
            }
        }else{
            printf("\nEntrada de coordenadas invalida!\n");
            getchar();
        }

        if(ganhou(lin, col, campo, maxbomb)){
            mostraCampo(lin, col, campo, bandeiras);
            printf("\n===============================");
            printf("\nPARABENS!!! VOCE EH UM GENIO!!!");
            printf("\n===============================\n\n");
            printf("░░░░░░░░░░░░░░░░░░░░░░░▄▄▄▄▄▄░░░░░░░░░░\n░░░░░░░░░░░░░░░░█▀█▄▄▀▀░░░░░░▀█▄░░░░░░░\n░░░░░░░░░░░█▀▀▀▀░░░░░░░░░░░░░░░░▀▄▄▄▄░░\n░░░░░░░░░▄▄▀░░░▄█░░░░░░░░░░░░░░░░▄▄██▄░\n░░░░░░░░░█░░▄█▀░░▀▀▀▀▀▄▄░░░░░░░▄▄█░▀█░░\n░░░░░░░░░█░▄▀░░░░░░░░░░░▀▀▀▀▄▄███░░░▀▄░\n░░░░░░░░░▀▄█▄███▄▄░░░▄▄▄▄░░░░▄▀░░░░░░█░\n░░░░░░░░░░█▄█▀██▀░░░░█▀▄▄▀░░█░░░░░░░█▀░\n░░░░░░░░░██░██▀░░░░░▄█▄███░░█░░░░░░░█░░\n░░░░░░░▄▄█▀█▄░░▄▄▄▄░░█░░░░▄▀░░░░░░░█░░░\n░░░░░▄▀░░███▄░░▀▀░▀░░░░░▄█▄░░░░░░░█▀░░░\n░░░▄▀░░░▄█░█▄▄▄▄▄▄▄░░░░░█▀███░░░░░█░░░░\n░░▄▀░░░░░██████▀▀▀█░░░░░░██░█▄▄▄▄▄█░░░░\n░█▀░░░░░░██░▄██▀▀██░█░░░▄▀██▀░░░░▀▀▀▄░░\n▀▀░░░░░░░█▀██░░▄███░█░░░█▀░░░░░░░░░░░█▄\n░░░░░░░░░░▄█▀▀▀██▀░░░░▄▀░░░░░░░░░░░░░▀▀\n░░░░░░░░░░▀▄░░░░░░░░▄▀░░░░░░░░░░░░░░░░░\n░░░░░░░░░░░░█▄▀▀▀▄▀▀░░░░░░░░░░░░░░░░░░░\n");
            flag = 1;
        }

    }while(flag != 1);

    return 0;

}