<p align="center">
  <a href="https://github.com/diegofilbal/campo-minado/blob/master/README-en.md">English</a>&nbsp;&nbsp;&nbsp;•&nbsp;&nbsp;
  <a href="https://github.com/diegofilbal/campo-minado/blob/master/README.md">Português (Brasil)</a>
</p>

# Minefield

***Instructions:***

This week, you are going to implement a minefield game! Never played? Then
run here: http://minesweeperonline.com/#

This game consists of a board, initially with all the "hidden" squares, which the player must click to reveal the contents of the house. The objective is to open all the houses without detonating any bombs.

When clicking on a house, one of three results can happen:
* If it's a bomb, the player loses the game!
* If not a bomb, displays the number of bombs present in adjacent squares.
* If there is no bomb around, open all neighboring houses.

The player must start the game one board size from following options:
* 9x9 - will have 10 mines
* 16x16 - will have 40 mines
* 16x30 - will have 99 mines

With the start of the game, the board will be generated by placing the bombs in positions randoms from the board, and a fully hidden board will be printed for the user.

(example with board 9x9):

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

The player will have two actions to do on the map: choose an X,Y position to open, or choose an X,Y position to mark as bomb. The player's command lines must have the following format: ** X Y ACTION **
  
**1 1 B** - marks position 1,1 of the matrix with a bomb (corresponding to put a flag to signal the danger of the position).

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

**3 3 A** - Player asks to open position 3,3 the field:


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

Your program should simulate a minefield game until the player gets open all houses that don't have bombs, or click on a bomb and be defeated.
Play a little online minefield to understand the rules of the game, and send bullet!
