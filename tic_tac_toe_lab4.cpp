#include <iostream>
#include <iomanip> // For formatting output
#include <string>
using namespace std;

const int ROWS = 4;
const int COLS = 4;

// Function declarations
void display_board(string board[ROWS][COLS]);
bool is_move_valid(int move, string board[ROWS][COLS]);
void make_move(int move, string player, string board[ROWS][COLS]);
bool check_win(string board[ROWS][COLS], string player); // check winner
bool is_board_full(string board[ROWS][COLS]);            // check if board is full

int main()
{
    string board[ROWS][COLS] = {
        {"1", "2", "3", "4"},
        {"5", "6", "7", "8"},
        {"9", "10", "11", "12"},
        {"13", "14", "15", "16"}};

    string player = "X";
    int move;
    bool game_won = false;

    while (true)
    {
        display_board(board);
        cout << "Player " << player << ", enter your move (1-16) or '0' to quit: ";
        cin >> move;

        if (move == 0)
        {
            cout << "Game exited. Goodbye!" << endl;
            break;
        }

        if (!is_move_valid(move, board))
        {
            cout << "Invalid move, try again." << endl;
            continue;
        }

        make_move(move, player, board);

        if (check_win(board, player))
        {
            display_board(board);
            cout << "Player " << player << " wins!" << endl;
            game_won = true;
            break;
        }

        if (is_board_full(board))
        {
            display_board(board);
            cout << "It's a draw!" << endl;
            break;
        }

        player = (player == "X") ? "O" : "X"; // Switch player
    }

    return 0;
}

// Function definitions
void display_board(string board[ROWS][COLS])
{
    cout << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            cout << setw(4) << board[i][j]; // Use setw(4) for better alignment
        }
        cout << endl;
    }
    cout << endl;
}

bool is_move_valid(int move, string board[ROWS][COLS])
{
    if (move < 1 || move > 16)
    {
        return false;
    }
    int row = (move - 1) / COLS;
    int col = (move - 1) % COLS;
    return board[row][col] != "X" && board[row][col] != "O";
}

void make_move(int move, string player, string board[ROWS][COLS])
{
    int row = (move - 1) / COLS;
    int col = (move - 1) % COLS;
    board[row][col] = player;
}

// TODO: complete definition of the funtion
bool check_win(string board[ROWS][COLS], string player)
{
    for (int i = 0; i < ROWS; i++)
    {
        bool row_win = true;
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != player)
            {
                row_win = false;
                break;
            }
        }
        if (row_win)
            return true;
    }
    // Check rows and columns
    for (int i = 0; i < COLS; i++)
    {
        bool col_win = true;
        for (int j = 0; j < ROWS; j++)
        {
            if (board[i][j] != player)
            {
                col_win = false;
                break;
            }
        }
        if (col_win)
            return true;
    }
    // Check diagonals
    bool diag1_win = true, diag2_win = true;
    for (int i = 0; i < ROWS; i++)
    {
        if (board[i][i] != player)
            diag1_win = false;
        if (board[i][ROWS - 1 - i] != player)
            diag2_win = false;
    }
    if (diag1_win || diag2_win)
        return true;

    return false;
}

// TODO: complete definition of the funtion
bool is_board_full(string board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] != "X" && board[i][j] != "O")
            {
                return false;
            }
        }
    }
    return true;
}
