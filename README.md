# Campo Minado
##### (Atividade realizada para a Disciplina de Introdução às Técnicas de Programação)

### Instruções:

Essa semana vocês vão implementar um jogo de campo minado! Nunca jogou? Pois
corra aqui: http://minesweeperonline.com/#

Esse jogo consiste em um tabuleiro, inicialmente com todas as casas “escondidas”,
o qual o jogador deve ir clicando para revelar o conteúdo da casa. O objetivo é conseguir
abrir todas as casas sem detonar nenhuma bomba.

Ao clicar em uma casa, um de três resultados pode acontecer:
* Se for uma bomba, o jogador perde o jogo!
* Se não for uma bomba, exibe o número de bombas presentes em casas adjacentes.
* Se não houver nenhuma bomba em volta, abre todas as casas vizinhas.

O jogador deve iniciar a partida escolhendo um tamanho de tabuleiro a partir das
seguintes opções:
* 9x9 - terá 10 minas
* 16x16 - terá 40 minas
* 16x30 - terá 99 minas

Com o início da partida, o tabuleiro será gerado colocando as bombas em posições
aleatórias do tabuleiro, e um tabuleiro totalmente escondido será printado para o usuário
(exemplo com tabuleiro 9x9):

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

O jogador terá duas ações para fazer no mapa: escolher uma posição X,Y para abrir,
ou escolher uma posição X,Y para marcar como bomba. As linhas de comando do jogador
terão o seguinte formato: 
### X Y ACAO
  
**1 1 B** - marca a posição 1,1 da matriz com uma bomba (correspondente a colocar uma
bandeira para sinalizar o perigo da posição).

B | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

**3 3 A** - Jogador pede para abrir a posição 3,3 do campo:


\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | 3 | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---

\* | \* | \* | \* | \* | \* | \* | \* | \*
---|----|----|----|----|----|----|----|---


\* \* \* \* \* \* \* \* \*

\* \* \* \* \* \* \* \* \*

\* \* 3 \* \* \* \* \* \*

\* \* \* \* \* \* \* \* \*

\* \* \* \* \* \* \* \* \*

\* \* \* \* \* \* \* \* \*

\* \* \* \* \* \* \* \* \*

\* \* \* \* \* \* \* \* \*

\* \* \* \* \* \* \* \* \*

Seu programa deve simular um jogo de campo minado até que o jogador consiga
abrir todas as casas que não possuem bombas, ou clicar em uma bomba e ser derrotado.
Joguem um pouco o campo minado online para entender bem as regras do jogo, e mandem
bala!
