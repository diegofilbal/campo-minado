main: campominado.c funcoes.o
	gcc campominado.c funcoes.o -o campo -W -gcc

objeto: funcoes.c
	gcc -c funcoes.c -W -g