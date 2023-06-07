#include <stdio.h>
#include <stdlib.h>

void ResetBoard();
void ShowBoard();

int PlayerX(int round);
char PlayerSymbol(int round);

int CheckPosition(int position);
void placePosition(int position, int round);
int CheckWin();

char Board[3][3];
int CopyBoard[3][3];
int InputPosition[9];

const int Xwin[3] = {0, 0, 0};
const int Owin[3] = {1, 1, 1};
const int CheckBoard[3][3] = {{7, 8, 9},{4, 5, 6},{1, 2, 3}};

int main()
{
  ResetBoard();
  ShowBoard();
  printf("\n");
  
  int i, num;
  
  i = 0;
  while(i < 9)
  {
    printf("Player %d (%c), Enter position (1-9): ", PlayerX(i), PlayerSymbol(i));
    scanf("%d", &num);

    while(num > 9 || num < 1)
    {
      printf("Invalid position, please re-enter position again.\n");
      printf("\nPlayer %d (%c), Enter position (1-9): ", PlayerX(i), PlayerSymbol(i));
      scanf("%d", &num);
    }

    while(CheckPosition(num))
    {
      printf("Occupied, please re-enter position again.\n");
      printf("\nPlayer %d (%c), Enter position (1-9): ", PlayerX(i), PlayerSymbol(i));
      scanf("%d", &num);
    }
  
    placePosition(num, i);
    
    InputPosition[i] = num;
    
    system("cls");
    
    ShowBoard();
    printf("\n");
    
    if(CheckWin()) {
      break;
    }
    i++;
  }

  if(i == 9) {
    printf("DRAW");
  }
  printf("\n");
  
  system("pause");

  return 0;
}

/*******************************************************************************/
/*
  f(ResetBoard): Clear O-X played board.
  
  Parameters: NONE.
  
  Returns: NONE.
  
  Notes: Also clear position data in CopyBoard[][].
*/
/*******************************************************************************/
void ResetBoard()
{
  int i, j;
  
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      Board[i][j] = '-';
  
  for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      CopyBoard[i][j] = -32768;
  
  for(i = 0; i < 9; i++)
    InputPosition[i] = -32768;
}

/*******************************************************************************/
/*
  f(ShowCard): Display the played board and hint position board.
  
  Parameters: NONE.
  
  Returns: NONE.
  
  Notes: NONE.
*/
/*******************************************************************************/
void ShowBoard()
{
  int i, j;

  printf("\n\t\t\tO-X Played Board\n");
  printf("\t\t\t---------------\n");

  for(i = 0; i < 3; i++)
  {
    printf("\t\t\t");

    for(j = 0; j < 3; j++)
    {
      printf("| %c |", Board[i][j]);
    }

    printf("\n\t\t\t---------------");
    printf("\n");
  }

  printf("\nHint: Board position\n");

  for(i = 0; i < 3; i++)
  {
    printf("---------------\n");

    for(j = 0; j < 3; j++)
    {
      printf("| %d |", CheckBoard[i][j]);
    }

    printf("\n");
  }

  printf("---------------\n");
}

/*******************************************************************************/
/*
  f(PlayerX): Check round and tell user are 1st player or 2nd player.
  
  Parameters: int round // 1-9 round.
  
  Returns: 1 or 2 //Player.
  
  Notes: NONE.
*/
/*******************************************************************************/
int PlayerX(int round)
{
  if(round % 2 == 0)
    return 1;
  else
    return 2;
}

/*******************************************************************************/
/*
  f(PlayerSymbol): Check round and tell user are X or O.
  
  Parameters: int round // 1-9 round.
  
  Returns: X or O //Player symbol.
  
  Notes: Give 'X' equal to 0 and 'O' equal to 1.
*/
/*******************************************************************************/
char PlayerSymbol(int round)
{
  char symbol;

  switch(round % 2)
  {
    case 0:
      symbol = 'X'; break;
    case 1:
      symbol = 'O'; break;
  }

  return symbol;
}

/*******************************************************************************/
/*
  f(CheckPosition): Check duplicate position.
  
  Parameters: int position //user entered number(position).
  
  Returns: 0 or 1 // If it is a duplicate position return 0 --> while loop
  
  Notes:
*/
/*******************************************************************************/
int CheckPosition(int position)
{
  int i,duplicate;
  
  for(i = 0; i < 9; i++)
    if(InputPosition[i] == position)
    {
      duplicate = 1;
      break;
    }
    else
      duplicate = 0;
  
  return duplicate;
}

/*******************************************************************************/
/*
  f(placePosition): place X or O in to played board.
  
  Parameters:
  int position // User entered number(position)
  int round
  
  Returns: NONE.
  
  Notes: Give 'X' = 0 and 'O' = 1, copy board[][] to CopyBoard[][] and then
  assign 0 or 1 in position that user entered.
*/
/*******************************************************************************/
void placePosition(int position, int round)
{
  int i, j, CopyCode;
  
  for(i = 0; i < 3; i++)
  {
    for(j = 0; j < 3; j++)
    {
      if(CheckBoard[i][j] == position)
      {
        Board[i][j] = PlayerSymbol(round);

        switch(round % 2)
        {
          case 0:
            CopyCode = 0; break;
          case 1:
            CopyCode = 1; break;
        }

        CopyBoard[i][j] = CopyCode;
      }
    }
  }
}

/*******************************************************************************/
/*
  f(CheckWin): Check for win the game.
  
  Parameters: NONE.
  
  Returns: 0 or 1 // If return 0, continue to the game. Return 1, end the game.
  
  Notes: NONE.
*/
/*******************************************************************************/
int CheckWin()
{
  int i, j;
  
  //Check row
  for(i = 0; i < 3; i++)
  {
    if(Xwin[0] == CopyBoard[i][0])
      if(Xwin[1] == CopyBoard[i][1])
        if(Xwin[2] == CopyBoard[i][2])
        {
          printf("Player 1 WIN"); return 1;
        }

    if(Owin[0] == CopyBoard[i][0])
      if(Owin[1] == CopyBoard[i][1])
        if(Owin[2] == CopyBoard[i][2])
        {
          printf("Player 2 WIN"); return 1;
        }
  }

  //Check column
  for(j = 0; j < 3; j++)
  {
    if(Xwin[0] == CopyBoard[0][j])
      if(Xwin[1] == CopyBoard[1][j])
        if(Xwin[2] == CopyBoard[2][j])
        {
          printf("Player 1 WIN"); return 1;
        }
    if(Owin[0] == CopyBoard[0][j])
      if(Owin[1] == CopyBoard[1][j])
        if(Owin[2] == CopyBoard[2][j])
        {
          printf("Player 2 WIN"); return 1;
        }
  }

  //Check diagonal
  if(Xwin[0] == CopyBoard[0][0])
    if(Xwin[1] == CopyBoard[1][1])
      if(Xwin[2] == CopyBoard[2][2])
      {
        printf("Player 1 WIN"); return 1;
      }

  if(Owin[0] == CopyBoard[0][0])
    if(Owin[1] == CopyBoard[1][1])
      if(Owin[2] == CopyBoard[2][2])
      {
        printf("Player 2 WIN"); return 1;
      }

  if(Xwin[0] == CopyBoard[0][2])
    if(Xwin[1] == CopyBoard[1][1])
      if(Xwin[2] == CopyBoard[2][0])
      {
        printf("Player 1 WIN"); return 1;
      }

  if(Owin[0] == CopyBoard[0][2])
    if(Owin[1] == CopyBoard[1][1])
      if(Owin[2] == CopyBoard[2][0])
      {
        printf("Player 2 WIN"); return 1;
      }

  return 0;
}
