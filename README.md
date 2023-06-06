# Tic-Tac-Toe

Simple C Project: Tic-Tac-Toe

## Rules

The object of Tic Tac Toe is to get three in a row. You play on a three by three game board. The first player is known as X and the second is O. Players alternate placing Xs and Os on the game board until either oppent has three in a row or all nine squares are filled. X always goes first, and in the event that no one has three in a row, the stalemate is called a cat game.

## Sample

**Game start**

```
			O-X Played Board
			---------------
			| - || - || - |
			---------------
			| - || - || - |
			---------------
			| - || - || - |
			---------------

Hint: Board position
---------------
| 7 || 8 || 9 |
---------------
| 4 || 5 || 6 |
---------------
| 1 || 2 || 3 |
---------------

Player 1 (X), Enter position (1-9):
```

**Game end: player 1 win**

```
			O-X Played Board
			---------------
			| X || O || X |
			---------------
			| O || X || - |
			---------------
			| O || - || X |
			---------------

Hint: Board position
---------------
| 7 || 8 || 9 |
---------------
| 4 || 5 || 6 |
---------------
| 1 || 2 || 3 |
---------------

Player 1 WIN
```

## License

MIT license

Check out [LICENSE](/LICENSE) for more detail.
