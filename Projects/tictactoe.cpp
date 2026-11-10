#include <iostream>
#include <string>

// To genrate a random number for the bot
#include <ctime>
#include <cstdlib>



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


// Switcher Function (Helper) Only function to change the player who is to make a move.
void switch_player(char &current_player) {
    current_player = (current_player == 'X') ? 'O' : 'X';
}

// Make move function
bool make_move(char board[], char &current_player, std::string &status_msg) {
    // Initializing the move
    int move{0};

    // Getting the user move as an input
    std::cout << "Enter a position: (1-9) (" << current_player << ") --> ";
    std::cin >> move;

    // Error handeling 
    // Check the user doesen't go outside the (1-9) legal moves range
    if (move > 9 || move < 1) {
        status_msg = "Illegal Move! Play a legal move between (1-9)";
        return false;
    }

    // Checking if the move is already made
    if ((board[move - 1] == 'X') || (board[move - 1] == 'O')) {
        status_msg = "Move already made make another legal move to continue."; 
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

// Random Move Bot Function
bool random_bot_move(char board[]) {

    while(true) {
        // Randomly picks a number and playes that as a move if it is available on the board if not then the loop continues.  
        int bot_move = (rand() % 9) + 1;
        if (board[bot_move - 1] != 'X' && board[bot_move - 1] != 'O'){
            board[bot_move - 1] = 'O';

            std::cout << "Bot move: " << bot_move << std::endl;

            return true;
        }
    }
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

    // Gets the current time to genrate the random number for the bot move
    srand(time(0));


    bool game_over = false;
    std::string status_msg = "";

    // Game loop
    while (!game_over) {
        // Wipes the whole screen off whenever the loop runs again so that there is a fresh new board with only the latest position
        system("cls");

        
        std::cout << "=============================== Tic Tac Toe ===============================" << std::endl;

        print_board(game_board);

        if (!status_msg.empty()) {
            std::cout << status_msg << std::endl;
        }

        status_msg = "";

        // Checking whose move is it
        // Asking the player for move
        if (current_player == 'X') {
            if (make_move(game_board, current_player, status_msg)) {
                // Adding a move if everthing works fine without any illegal move or anything
                moves_played ++;

                // Checking if the function found a winner 
                if (check_winner(game_board)) {
                    print_board(game_board);
                    std::cout << "Player (" << current_player << ") won!" << std::endl;
                    game_over = true;
                    break;
                }

                // Checking for a draw
                if (moves_played >= 9) {
                    std::cout << "It's a tie! No one wins." << std::endl;
                    game_over = true;
                    break;
                }

                if (!game_over) {
                    // Only switch players if the game is successfully continuing
                    switch_player(current_player);


                }
                
            }

        }
        // Asking the bot for move
        else {
            if (random_bot_move(game_board)) {
                // Adding a move if everthing works fine without any illegal move or anything
                moves_played ++;   

                // Checking if the function found a winner 
                if (check_winner(game_board)) {
                    print_board(game_board);
                    std::cout << "Player (" << current_player << ") won!" << std::endl;
                    game_over = true;
                    break;
                }

                // Checking for a draw
                if (moves_played >= 9) {
                    std::cout << "It's a draw! No one wins." << std::endl;
                    game_over = true;
                    break;
                }

                if (!game_over) {
                    // Only switch players if the game is successfully continuing
                    switch_player(current_player);


                } 

            }
        }



        
    }

    return 0;
}