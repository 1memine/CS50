/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */

#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);
int find_row(int);
int find_col(int);


int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2) {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX) {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL) {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();
    
    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();

        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }

    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}


/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).
 */
void init(void) {
    // fill in descending order from d*d-1 to 0
    int filler = d*d-1;
    for (int row = 0; row < d; row++) {
        for(int col = 0; col < d; col++) {
            board[row][col] = filler;
            filler--;
        }
    }
    // for simple implementation of won function
    board[d-1][d-1] = d*d;

    // swap 2 elements before last
    if(d%2 == 0) {
        int temp = board[d-1][d-2];
        board[d-1][d-2] = board[d-1][d-3];
        board[d-1][d-3] = temp;
    }
}


/**
 * Prints the board in its current state.
 */
void draw(void) {
    for (int row = 0; row < d; row++) {
        for(int col = 0; col < d; col++) {
            if(board[row][col] != d*d) {
                printf("%2d  ", board[row][col]);
            } else {
                printf("    ");
            }
        }
    printf("\n\n");
    }
}


/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false.
 */
bool move(int tile) {
    // Ensure proper usage
    if(tile > d*d-1 || tile < 0) {
        printf("Invalid tile!\n");
        return false;
    }

    // coordinates of empty tile
    static int empty_row, empty_col;
    if (board[d-1][d-1] == d*d) {
        empty_row = d-1;
        empty_col = d-1;
    }

    // figure out indexes of tile
    int tile_row = find_row(tile), tile_col = find_col(tile);

    //regular statements for simple if condition below
    bool equal_row = (tile_row == empty_row),
         equal_col = (tile_col == empty_col),
         adjacent = (abs(tile_col-empty_col) == 1)
                 || (abs(tile_row-empty_row) == 1);

    // Swap and remember new coordinates
    if ((equal_row || equal_col) && adjacent) {
        // swap
        int temp = 0;
        temp = board[tile_row][tile_col];
        board[tile_row][tile_col] = board[empty_row][empty_col];
        board[empty_row][empty_col] = temp;

    //remember new coordinates of empty tile
        empty_col = tile_col;
        empty_row = tile_row;

        return true;
    } else
        return false;

}


/**
 * Returns true if game is won (i.e., board is in winning configuration),
 * else false.
 */
bool won(void) {
    int counter = 1;
    for(int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if (board[i][j] != counter) {
                return false;
            }
            counter++;
        }
    }
    return true;
}


// find row of tile
int find_row(int tile) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if(tile == board[i][j]) {
                return i;
            }
        }
    }
    return -1;
}


// find column of tile
int find_col(int tile) {
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            if(tile == board[i][j]) {
                return j;
            }
        }
    }
    return -1;
}