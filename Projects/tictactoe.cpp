#include <iostream>


// Initializing who is playing currently
char current_player = 'X'; 

// Print board function
void print_board(char board[]) {
    // Displaying the board
    for (int i = 0; i < 9; i++){

        std::cout << board[i];
        
        // Formatting the board to display | and a new line 
        if (((i + 1) % 3) == 0) {
            std::cout << std::endl;
        }
        else {
            std::cout << " | ";
        }
    }
}


// Make move function
bool make_move(char board[], char &current_player) {
    // Initializing the move
    int move{0};

    // Getting the user move as an input
    std::cout << "Enter a position: (1-9) (" << current_player << ") --> ";
    std::cin >> move;

    // Error handeling 
    // Check the user doesen't go outside the (1-9) legal moves range
    if (move > 9 || move < 1) {
        std::cout << "Illegal Move! Play a leal move between (1-9)" << std::endl;
        return false;
    }

    // Checking if the move is already made
    if ((board[move - 1] == 'X') || (board[move - 1] == 'O')) {
        std::cout << "Move already made make another legal move to continue." << std::endl; 
        return false;
    }
    
    // Seprating the logic from the print board function and displaying X on the user move
    board[move - 1] = current_player;


    return true;
}

// Check winner function
bool check_winner(char board[]) {
    // Checks board and stops the loos if there is a winner

    // Checking for horizontal wins (3) 
    if (board[0] == board[1] && board[1] == board[2]) {
        if (board[0] == 'X' || board[0] == 'O'){
            return true;
        }
    }
    if (board[3] == board[4] && board[4] == board[5]){
        if (board[3] == 'X' || board[3] == 'O') {
            return true;
        }
    }
    if (board[6] == board[7] && board[7] == board[8]){
        if (board[6] == 'X' || board[6] == 'O') {
            return true;
        }
    }

    // Checking for vertical wins (3)
    if (board[0] == board[3] && board[3] == board[6]){
        if (board[0] == 'X' || board[0] == 'O') {
            return true;
        }
    }
    if (board[1] == board[4] && board[4] == board[7]){
        if (board[1] == 'X' || board[1] == 'O') {
            return true;
        }
    }
    if (board[2] == board[5] && board[5] == board[8]){
        if (board[2] == 'X' || board[2] == 'O') {
            return true;
        }
    }

    // Cheking for diagonal wins (2)
    if (board[0] == board[4] && board[4] == board[8]){
        if (board[0] == 'X' || board[0] == 'O') {
            return true;
        }
    }
    if (board[2] == board[4] && board[4] == board[6]){
        if (board[2] == 'X' || board[2] == 'O') {
            return true;
        }
    }

    // Continue the game if there is no winner
    return false;
}


// Main function
int main() {

    // Creating the board
    char game_board[9] {
        '1', '2', '3', 
        '4', '5', '6', 
        '7', '8', '9'
        };

    // Keeping count of how many moves have been played
    int moves_played {0};

    std::cout << "========================== Tic Tac Toe ==========================" << std::endl;

    bool game_over = false;

    // Game loop
    while (!game_over) {

        print_board(game_board);

        if (make_move(game_board, current_player)) {
            // Adding a move if everthing works fine without any illegal move or anything
            moves_played ++;

            // Cheking for a draw
            if (moves_played >= 9) {
                std::cout << "It's a draw! No one wins." << std::endl;
                game_over = true;
            }

            // Checking if the function found a winner or draw
            if (check_winner(game_board)) {
                print_board(game_board);
                std::cout << "Player (" << current_player << ") won!" << std::endl;
                game_over = true;
            } 
            else {
                // Only switch players if the game is successfully continuing
                current_player = (current_player == 'X') ? 'O' : 'X';
            }
        }

        
    }

    return 0;
}