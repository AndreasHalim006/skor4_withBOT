#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int glrow, glmax;     // Another Global !!
int line4; // counters
int line3oo, line3o, line3, line3xox, line3xox_old; // line3 open-open, line3 open, line3
int line2oo, line2o, line2; // line2 open-open, line2 open, line2
    char boardBot[6][7];
    char boardBot2[6][7];
    char boardBot3[6][7];
    char boardBot99[6][7];

void initBoard(char board[6][7]){
    int i, j;
    for (i=0; i<6; i++){
        for (j=0; j<7; j++){
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[6][7]){
    int i, j;
    system("cls");  // Clears the screen

    printf("\n\n\n\n");
    for (i=0; i<6; i++){
        printf("\t\t");
        for (j=0; j<7; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("\t\t-----------------------------\n");
    printf("\t\t (1) (2) (3) (4) (5) (6) (7)\n\n");
}

bool isMoveLegal(char board[6][7], int column){
    // Checks if you selected a unbound column
    if (column < 0 || column > 6)
        return false;
    // Checks if you selected a full column
    if (board[0][column] != ' ')
        return false;
return true;
}

void playMove(char board[6][7], int column, char symbol){
    int i;

    for (i = 5; i >= 0; i--){
        if (board[i][column] == ' '){
            board[i][column] = symbol;
            glrow = i;
            return;
        }
    }
return;
}

bool gameHasEnded(char board[6][7], int column, char symbol){
    int line, open;

    line4 = 0;
    line3oo = 0; line3o = 0; line3 = 0;
    line2oo = 0; line2o = 0; line2 = 0;

line = 1; open = 0;
    // Check row (right)
    if ((column+1 <= 6) && (board[glrow][column+1] == symbol)){
        line++;
        if ((column+2 <= 6) && (board[glrow][column+2] == symbol)){
            line++;
            if ((column+3 <= 6) && (board[glrow][column+3] == symbol)){
                line++;
            }
            else if ((column+3 <= 6) && (board[glrow][column+3] == ' ')) open++;
        }
        else if ((column+2 <= 6) && (board[glrow][column+2] == ' ')) open++;
    }
    else if ((column+1 <= 6) && (board[glrow][column+1] == ' ')) open++;

    // Check row (left)
    if ((column-1 >= 0) && (board[glrow][column-1] == symbol)){
        line++;
        if ((column-2 >= 0) && (board[glrow][column-2] == symbol)){
            line++;
            if ((column-3 >= 0) && (board[glrow][column-3] == symbol)){
                line++;
            }
            else if ((column-3 >= 0) && (board[glrow][column-3] == ' '))  open++;
        }
        else if ((column-2 >= 0) && (board[glrow][column-2] == ' '))  open++;
    }
    else if ((column-1 >= 0) && (board[glrow][column-1] == ' '))  open++;

    if (line >= 4)  line4++;
    if (line == 3){
        if (open == 2) line3oo++;
        else if (open == 1) line3o++;
        else line3++;
    }
    if (line == 2){
        if (open == 2) line2oo++;
        else if (open == 1) line2o++;
        else line2++;
    }

line = 1; open = 0;
    // Check column (down)
    if ((glrow+1 <= 5) && (board[glrow+1][column] == symbol)){
        line++;
        if ((glrow+2 <= 5) && (board[glrow+2][column] == symbol)){
            line++;
            if ((glrow+3 <= 5) && (board[glrow+3][column] == symbol)){
                line++;
            }
            else if ((glrow+3 <= 5) && (board[glrow+3][column] == ' '))  open++;
        }
        else if ((glrow+2 <= 5) && (board[glrow+2][column] == ' '))  open++;
    }
    else if ((glrow+1 <= 5) && (board[glrow+1][column] == ' '))  open++;

    if (line >= 4)  line4++;
    if (line == 3){
        if (open == 2) line3oo++;
        else if (open == 1) line3o++;
        else line3++;
    }
    if (line == 2){
        if (open == 2) line2oo++;
        else if (open == 1) line2o++;
        else line2++;
    }

line = 1; open = 0;
    // Check diagonal (right-down)
    if ((glrow+1 <= 5) && (column+1 <= 6) && (board[glrow+1][column+1] == symbol)){
        line++;
        if ((glrow+2 <= 5) && (column+2 <= 6) && (board[glrow+2][column+2] == symbol)){
            line++;
            if ((glrow+3 <= 5) && (column+3 <= 6) && (board[glrow+3][column+3] == symbol)){
                line++;
            }
            else if ((glrow+3 <= 5) && (column+3 <= 6) && (board[glrow+3][column+3] == ' '))  open++;
        }
        else if ((glrow+2 <= 5) && (column+2 <= 6) && (board[glrow+2][column+2] == ' '))  open++;
    }
    else if ((glrow+1 <= 5) && (column+1 <= 6) && (board[glrow+1][column+1] == ' '))  open++;

    // Check diagonal (left-up)
    if ((glrow-1 >= 0) && (column-1 >= 0) && (board[glrow-1][column-1] == symbol)){
        line++;
        if ((glrow-2 >= 0) && (column-2 >= 0) && (board[glrow-2][column-2] == symbol)){
            line++;
            if ((glrow-3 >= 0) && (column-3 >= 0) && (board[glrow-3][column-3] == symbol)){
                line++;
            }
            else if ((glrow-3 >= 0) && (column-3 >= 0) && (board[glrow-3][column-3] == ' '))  open++;
        }
        else if ((glrow-2 >= 0) && (column-2 >= 0) && (board[glrow-2][column-2] == ' '))  open++;
    }
    else if ((glrow-1 >= 0) && (column-1 >= 0) && (board[glrow-1][column-1] == ' '))  open++;

    if (line >= 4)  line4++;
    if (line == 3){
        if (open == 2) line3oo++;
        else if (open == 1) line3o++;
        else line3++;
    }
    if (line == 2){
        if (open == 2) line2oo++;
        else if (open == 1) line2o++;
        else line2++;
    }

line = 1; open = 0;
    // Check diagonal (right-up)
    if ((glrow-1 >= 0) && (column+1 <= 6) && (board[glrow-1][column+1] == symbol)){
        line++;
        if ((glrow-2 >= 0) && (column+2 <= 6) && (board[glrow-2][column+2] == symbol)){
            line++;
            if ((glrow-3 >= 0) && (column+3 <= 6) && (board[glrow-3][column+3] == symbol)){
                line++;
            }
            else if ((glrow-3 >= 0) && (column+3 <= 6) && (board[glrow-3][column+3] == ' '))  open++;
        }
        else if ((glrow-2 >= 0) && (column+2 <= 6) && (board[glrow-2][column+2] == ' '))  open++;
    }
    else if ((glrow-1 >= 0) && (column+1 <= 6) && (board[glrow-1][column+1] == ' '))  open++;

    // Check diagonal (left-down)
    if ((glrow+1 <= 5) && (column-1 >= 0) && (board[glrow+1][column-1] == symbol)){
        line++;
        if ((glrow+2 <= 5) && (column-2 >= 0) && (board[glrow+2][column-2] == symbol)){
            line++;
            if ((glrow+3 <= 5) && (column-3 >= 0) && (board[glrow+3][column-3] == symbol)){
                line++;
            }
            else if ((glrow+3 <= 5) && (column-3 >= 0) && (board[glrow+3][column-3] == ' '))  open++;
        }
        else if ((glrow+2 <= 5) && (column-2 >= 0) && (board[glrow+2][column-2] == ' '))  open++;
    }
    else if ((glrow+1 <= 5) && (column-1 >= 0) && (board[glrow+1][column-1] == ' '))  open++;

    if (line >= 4)  line4++;
    if (line == 3){
        if (open == 2) line3oo++;
        else if (open == 1) line3o++;
        else line3++;
    }
    if (line == 2){
        if (open == 2) line2oo++;
        else if (open == 1) line2o++;
        else line2++;
    }

// Final check
    if (line4 >= 1)  return true;
    else  return false;
}

//  my connect-4 bot : The 4seer  [foreseer = (person who predicts the future)]
void printRobot(){
    int a, b=1;
    system("cls");
    printf("\n ");
printf("\n           ___ ");
printf("\n          |_|_| ");
printf("\n          |_|_|              _____ ");
printf("\n          |_|_|     ____    |*_*_*| ");
printf("\n _______   _\\__\\___/ __ \\____|_|_   _______  ");
printf("\n/ ____  |=|      \\  <_+>  /      |=|  ____ \\  ");
printf("\n~|    |\\|=|======\\\\______//======|=|/|    |~ ");
printf("\n |_   |    \\      |      |      /    |    |    ");
printf("\n  \\==-|     \\     |  XO  |     /     |----|~~/");
printf("\n  |   |      |    |      |    |      |____/~/   ");
printf("\n  |   |       \\____\\____/____/      /    / /  ");
printf("\n  |   |         {----------}       /____/ / ");
printf("\n  |___|        /~~~~~~~~~~~~\\     |_/~|_|/ ");
printf("\n   \\_/        |/~~~~~||~~~~~\\|     /__|\\  ");
printf("\n   | |         |    ||||    |     (/|| \\) ");
printf("\n   | |        /     |  |     \\       \\\\ ");
printf("\n   |_|        |     |  |     |        ");   printf("   @@@@@@@ @@@  @@@ @@@@@@@@    @@@  @@@  @@@@@@ @@@@@@@@ @@@@@@@@ @@@@@@@  ");
printf("\n              |_____|  |_____|        ");   printf("     @!!   @@!  @@@ @@!         @@@  @@@ !@@     @@!      @@!      @@!  @@@ ");
printf("\n              (_____)  (_____)        ");   printf("     @!!   @!@!@!@! @!!!:!      @!@!@!@!  !@@!!  @!!!:!   @!!!:!   @!@!!@!  ");
printf("\n              |     |  |     |        ");   printf("     !!:   !!:  !!! !!:              !!!     !:! !!:      !!:      !!: :!!  ");
printf("\n              |     |  |     |        ");   printf("      :     :   : : : :: ::          : : ::.: :  : :: ::  : :: ::   :   : : ");
printf("\n              |/~~~\\|  |/~~~\\| ");
printf("\n              /|___|\\  /|___|\\  ");
printf("\n             <_______><_______> ");

    for (a=0; a<600000000; a++){
        if (b > 0) b++; }
    //system("cls");
}

void copyboard(char board_paste[6][7], char board_copy[6][7]){ ///the one
    int i, j;
    for (i=0; i<6; i++){
        for (j=0; j<7; j++)
            board_paste[i][j] = board_copy[i][j];
    }
}

bool trap8(char board[6][7], int column, char player){
    int j;
    bool a = false, b = false;

    for (j=0; j<5; j++){
        glrow = j;
        if ((board[glrow][column] == ' ') && (gameHasEnded(board, column, player))) a = true;
        glrow = j + 1;
        if ((board[glrow][column] == ' ') && (gameHasEnded(board, column, player))) b = true;
        if (a && b) return true;
        a = false; b = false;
    }
    return false;
}

bool trap7(char board[6][7], char player){     // plays move -> needs copyboard
    int j;
    int type7 = 0;

    copyboard(boardBot99, board);
    for (j=0; j<7; j++){
        if (isMoveLegal(board, j)){
            playMove(board, j, player);
            if (gameHasEnded(board, j, player)) type7++;
        copyboard(board, boardBot99);
        }
    }
    if (type7 == 2) return true;
    else return false;
}

void line3xox_func(char board[6][7], char player){
    int i, j;
    line3xox = 0;

    copyboard(boardBot99, board);
    for (j=0; j<7; j++){
        while (isMoveLegal(board, j)){
            playMove(board, j, 'q');
            if (gameHasEnded(board, j, player))
                line3xox++;
        }
    copyboard(board, boardBot99);
    }
}

int botPick(char board[6][7], char player, char playerE){        /// $$$$$$$$$$$$$$$$$$$$$$$$ ///
    int i, j, k, h, c;
    float max;
    int move;
//    char boardBot[6][7];
//    char boardBot2[6][7];
//    char boardBot3[6][7];
    float columnRating[7] = {2, 3, 4, 5, 4, 3, 2};
    bool a = false, b = false;

   copyboard(boardBot, board);

/** all moves **/

    // build 3, 2 in a row
    for (j=0; j<7; j++){
        playMove(board, j, player);
        gameHasEnded(board, j, player);
        if ((line3 >= 1) || (line3o >= 1) || (line3oo >= 1) || (line2 >= 1) || (line2o >= 1) || (line2oo >= 1)){
            columnRating[j] = columnRating[j] + line2o + 4*line2oo; //+ 15*line3o + 30*line3oo;
        }
    copyboard(board, boardBot);
    }
    // block 3, 2 in a row
    for (j=0; j<7; j++){
        playMove(board, j, playerE);
        gameHasEnded(board, j, playerE);
        if ((line3 >= 1) || (line3o >= 1) || (line3oo >= 1) || (line2 >= 1) || (line2o >= 1) || (line2oo >= 1)){
            columnRating[j] = columnRating[j] + line2o + 4*line2oo; //+ 15*line3o + 30*line3oo;
        }
    copyboard(board, boardBot);
    }

    for (j=0; j<7; j++){
        line3xox_func(board, playerE);
        line3xox_old = line3xox;
        playMove(board, j, playerE);
        line3xox_func(board, playerE);
        if (line3xox > line3xox_old)
            columnRating[j] = columnRating[j] + 15*(line3xox - line3xox_old);
    copyboard(board, boardBot);
    }

    for (j=0; j<7; j++){
        line3xox_func(board, player);
        line3xox_old = line3xox;
        playMove(board, j, player);
        line3xox_func(board, player);
        if (line3xox > line3xox_old)
            columnRating[j] = columnRating[j] + 15*(line3xox - line3xox_old);
    copyboard(board, boardBot);
    }

    // not win in 2 moves (enemy can block a line4)
    for (j=0; j<7; j++){
        playMove(board, j, playerE);
        playMove(board, j, player);
        if (gameHasEnded(board, j, player))
            columnRating[j] = 0.5;
    copyboard(board, boardBot);
    }

/** lvl_3.5 **/

    // create 8-trap (step -2_under)
    for (j=0; j<7; j++){
        playMove(board, j, player);
        playMove(board, j, playerE);
        playMove(board, j, player);
        for (k=0; k<7; k++){
            if (trap8(board, k, player))
                columnRating[j] = 701;
        }
    copyboard(board, boardBot);
    }


/** lvl_2.5 **/

    // block 7/8-trap (step -1_under) [I must play where enemy need]
    for (j=0; j<7; j++){
        playMove(board, j, player);   /**/
        playMove(board, j, playerE);
        copyboard(boardBot2, board);
        for (k=0; k<7; k++){
            playMove(board, k, player);
            if (gameHasEnded(board, k, playerE)){
                copyboard(boardBot3, board);
                for (i=0; i<7; i++){
                    playMove(board, i, playerE);
                    for (h=0; h<7; h++){
                        if (trap8(board, h, playerE) || trap7(board, playerE))
                            columnRating[j] = 3;
                    }
                copyboard(board, boardBot3);
                }
            }
        copyboard(board, boardBot2);
        }
    copyboard(board, boardBot);
    }

    // create 7/8-trap (step -1_under) [enemy must play where I need]
    for (j=0; j<7; j++){
        playMove(board, j, 'i');   /**/
        playMove(board, j, player);         // Orestis clutch moment
        copyboard(boardBot2, board);
        for (k=0; k<7; k++){
            playMove(board, k, playerE);
            if (gameHasEnded(board, k, player)){
                copyboard(boardBot3, board);
                for (i=0; i<7; i++){
                    playMove(board, i, player);
                    for (h=0; h<7; h++){
                        if (trap8(board, h, player) || trap7(board, player))
                            columnRating[j] = 3;
                    }
                copyboard(board, boardBot3);
                }
            }
        copyboard(board, boardBot2);
        }
    copyboard(board, boardBot);
    }

/** lvl_2 **/
        for (j=0; j<7; j++){
        playMove(board, j, playerE);
        playMove(board, j, player);
        if (gameHasEnded(board, j, player))
            columnRating[j] = 0.5;
    copyboard(board, boardBot);
    }
    // block 7/8-trap (step -1) [I must play where enemy need]
    for (j=0; j<7; j++){
        playMove(board, j, playerE);
        copyboard(boardBot2, board);
        for (k=0; k<7; k++){
            playMove(board, k, player);
            if (gameHasEnded(board, k, playerE)){
                copyboard(boardBot3, board);
                for (i=0; i<7; i++){
                    playMove(board, i, playerE);
                    for (h=0; h<7; h++){
                        if (trap8(board, h, playerE) || trap7(board, playerE))
                            columnRating[j] = 801;
                    }
                copyboard(board, boardBot3);
                }
            }
        copyboard(board, boardBot2);
        }
    copyboard(board, boardBot);
    }

    // create 7/8-trap (step -1) [enemy must play where I need]
    for (j=0; j<7; j++){
        playMove(board, j, player);         // Orestis clutch moment
        copyboard(boardBot2, board);
        for (k=0; k<7; k++){
            playMove(board, k, playerE);
            if (gameHasEnded(board, k, player)){
                copyboard(boardBot3, board);
                for (i=0; i<7; i++){
                    playMove(board, i, player);
                    for (h=0; h<7; h++){
                        if (trap8(board, h, player) || trap7(board, player))
                            columnRating[j] = 800;
                    }
                copyboard(board, boardBot3);
                }
            }
        copyboard(board, boardBot2);
        }
    copyboard(board, boardBot);
    }

/** lvl_3 **/

    // block 8-trap (step -1_under)
    for (j=0; j<7; j++){
        playMove(board, j, player);
        playMove(board, j, playerE);
        for (k=0; k<7; k++){
            if (trap8(board, k, playerE))
                columnRating[j] = 1;
        }
    copyboard(board, boardBot);
    }

    // create 8-trap (step -1_under)
    for (j=0; j<7; j++){
        playMove(board, j, playerE);
        playMove(board, j, player);
        for (k=0; k<7; k++){
            if (trap8(board, k, player))
                columnRating[j] = 1;
        }
    copyboard(board, boardBot);
    }


/** lvl_1 **/

    // block 8-trap (step 0)
    for (j=0; j<7; j++){
        playMove(board, j, playerE);
        for (k=0; k<7; k++){
            if (trap8(board, k, playerE))
                columnRating[j] = 900;
        }
    copyboard(board, boardBot);
    }

    // create 8-trap (step 0)
    for (j=0; j<7; j++){
        playMove(board, j, player);
        for (k=0; k<7; k++){
            if (trap8(board, k, player))
                columnRating[j] = 901;
        }
    copyboard(board, boardBot);
    }

    // check existence of 8-trap
    for (j=0; j<7; j++){
        if (trap8(board, j, player)) columnRating[j] = 902;
    }


    // block 7-trap (step 0)
    for (j=0; j<7; j++){
        playMove(board, j, playerE);
        if (trap7(board, playerE))
            columnRating[j] = 903;
    copyboard(board, boardBot);
    }

    // create 7-trap (step 0)
    for (j=0; j<7; j++){
        playMove(board, j, player);
        if (trap7(board, player))
            columnRating[j] = 904;
    copyboard(board, boardBot);
    }

/** lvl_0 **/
copyboard(board, boardBot);
    // lose in 1 move
    for (j=0; j<7; j++){
        if (board[1][j] == ' '){
            playMove(board, j, player);
            playMove(board, j, playerE);
            if (gameHasEnded(board, j, playerE))
                columnRating[j] = 0;
            copyboard(board, boardBot);
        }
    }

    // not lose in 1 move
    for (j = 0; j < 7; j++){
        playMove(board, j, playerE);
        if (gameHasEnded(board, j, playerE))
            columnRating[j] = 999;
        copyboard(board, boardBot);
    }

    // win in 0 moves
    for (j = 0; j < 7; j++){
        playMove(board, j, player);
        if (gameHasEnded(board, j, player))
            columnRating[j] = 1000;
        copyboard(board, boardBot);
    }

/** end move **/

    // checks for illegal move
    for (j=0; j<7; j++){
        if (!isMoveLegal(board, j))
            columnRating[j] = -1;
    }

    move = give_botPick(columnRating);

   copyboard(board, boardBot);
return move;
}

int give_botPick(float columnRating[7]){
    int priority[7] = {3, 4, 2, 5, 1, 6, 0};
    float max;
    int move, i, c;

    // Finds the best ranked move
    max = -0.5;
    move = 0;
    for (i=0; i<7; i++){
        c = priority[i];                //priority[7] = {4, 2, 3, 1, 5, 6, 0}
        if (columnRating[i] > max){
            max = columnRating[i];
            move = i;
             glmax = max;
        }
    }
return move;
}

int main(){
    char board[6][7];
    int turn = 0;
    int column, pl_column;
    char player, playerE;;
    int option;
    int cheatCode;

    printf("Choose gamemode:\n\n");
    printf("1. vs player\n");
    printf("2. vs THE 4SEER\n\n");
    scanf("%d", &option);

    initBoard(board);

 switch(option) {
  case 1:
    printBoard(board);
    for (turn; turn < 42; turn++){
        player = (turn % 2 == 0)? 'X': 'O'; // player symbol

        // Get move
        printf("\nSelect the column you want to play (1 - 7) [%c]: ", player);
        scanf("%d", &pl_column);
        column = pl_column - 1;

        if (isMoveLegal(board, column)){  // Checks, plays and searches for win
            playMove(board, column, player);
            printBoard(board);
            if (gameHasEnded(board, column, player)){   // Checks if that move is the winning move
                printf("\nThe player %c won!!!\n", player);
                printf("\n~~Press Any Key to Exit~~\n"); getch();
                return 0;
            }
        } else {printf("\a");    turn--;}
    }

    printf("\nIt's a tie!!\n");
    printf("\n~~Press Any Key to Exit~~\n"); getch();
    return 0;
  break;

  case 2:
    printRobot();
    printBoard(board);
    for (turn = 0; turn < 42; turn++){

        // Get move from  player
        if (turn % 2 != 0){
            player = 'X';
            playerE = 'O';
            printf("\n %d", glmax);
            printf("\nSelect the column you want to play (1 - 7) [%c]: ", player);
            scanf("%d", &pl_column);
            column = pl_column - 1;
        }
        if (turn % 2 == 0){
            player = 'O';
            playerE = 'X';
       //     scanf("%d", &cheatCode);
       //     if (cheatCode == 99){
       //        printf("\nSelect the column you want to play (1 - 7) [%c]: ", player);
       //        scanf("%d", &pl_column);
       //         column = pl_column - 1;
       //     }
       //     else
            column = botPick(board, player, playerE);
          }

        if (isMoveLegal(board, column)){  // Checks, plays and searches for win
            playMove(board, column, player);
            printBoard(board);
            //int a, b=1;
            //for (a=0; a<600000000; a++){
                //if (b > 0) b++; }
            if (gameHasEnded(board, column, player)){   // Checks if that move is the winning move
                printf("\nThe player %c won!!!\n", player);
                printf("\n~~Press Any Key to Exit~~\n"); getch();
                return 0;
            }
        } else {printf("\a");    turn--;}
    }
    printf("\nIt's a tie!!\n");
    printf("\n~~Press Any Key to Exit~~\n"); getch();
    return 0;
  break;

  case 3:
    printRobot();
    printBoard(board);
    for (turn = 0; turn < 42; turn++){

        // Get move from  player OR bot
        if (turn % 2 == 0){
            player = 'X';
            playerE = 'O';
            //printf("\n %d", glmax);
            column = botPick(board, player, playerE);
        }
        if (turn % 2 != 0){
            player = 'O';
            playerE = 'X';
       //     scanf("%d", &cheatCode);
       //     if (cheatCode == 99){
       //        printf("\nSelect the column you want to play (1 - 7) [%c]: ", player);
       //        scanf("%d", &pl_column);
       //         column = pl_column - 1;
       //     }
       //     else
            column = botPick(board, player, playerE);
          }

        if (isMoveLegal(board, column)){  // Checks, plays and searches for win
            playMove(board, column, player);
            printBoard(board);
            printf("\n %d", glmax);
            int a, b=1;
            for (a=0; a<600000000; a++){
                if (b > 0) b++; }
            if (gameHasEnded(board, column, player)){   // Checks if that move is the winning move
                printf("\nThe player %c won!!!\n", player);
                printf("\n~~Press Any Key to Exit~~\n"); getch();
                return 0;
            }
        } else {printf("\a");  turn--;}
    }
    printf("\nIt's a tie!!\n");
    printf("\n~~Press Any Key to Exit~~\n"); getch();
    return 0;
  break;

   case 4:

    srand(time(0));
    int winX=0, winO=0, draw=0;

for(int game=0; game<100; game++){
        initBoard(board);
    for (turn = 0; turn < 42; turn++){

        // Get move from  player OR bot
        if (turn % 2 == 0){
            player = 'X';
            playerE = 'O';
            column = botPick(board, player, playerE);
        }
        if (turn % 2 != 0){
            player = 'O';
            playerE = 'X';
            column = rand() % 7;
        }

        if (isMoveLegal(board, column)){  // Checks, plays and searches for win
            playMove(board, column, player);

            if (gameHasEnded(board, column, player)){   // Checks if that move is the winning move
                printBoard(board);
                if(player == 'X') winX++;
                else winO++;
                break;
            }
        } else {printf("\a");  turn--;}
    }
    if (turn == 42) draw++;
}
printf("X: %d \t O: %d \t ties: %d", winX, winO, draw);
    return 0;

 }
}
