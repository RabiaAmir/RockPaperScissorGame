#include <iostream>
#include <string>
#include <cstdlib> // Include cstdlib for rand()
#include <ctime>
#include <conio.h>

using namespace std;

int main() {
    // Variables
    string player_name;
    int rounds, player_score = 0, computer_score = 0;

    // Get player's name
    cout << "Enter your name: ";
    cin >> player_name;
    system("cls");

    // Get number of rounds
    cout << player_name << ", how many rounds do you want to play?: ";
    cin >> rounds;

    // Game loop
    for (int round = 1; round <= rounds; round++) {
        system("cls");
        int player_choice, computer_choice;

        // Display round information
        cout << "Round no: " << round << "/" << rounds << endl;
        cout << player_name << "'s score = " << player_score << endl;
        cout << "Computer's score = " << computer_score << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissor" << endl;

        // Get and validate player's choice
        do {
            cout << "Select your choice: ";
            cin >> player_choice;
        } while (player_choice != 1 && player_choice != 2 && player_choice != 3);

        // Generate computer's choice randomly
        srand(static_cast<unsigned int>(time(0))); // Use static_cast to avoid warning
        computer_choice = (rand() % 3) + 1;

        // Determine the winner of the round
        if ((player_choice == 1 && computer_choice == 3) ||
            (player_choice == 2 && computer_choice == 1) ||
            (player_choice == 3 && computer_choice == 2)) {
            cout << "Player wins." << endl;
            player_score++;
        }
        else if (player_choice == computer_choice) {
            cout << "Draw" << endl;
        }
        else {
            cout << "Computer wins." << endl;
            computer_score++;
        }

       
    }

    // Determine the overall winner of the game
    if (computer_score == player_score) {
        cout << "It's a Tie! Computer and Player have the same score." << endl;
    }
    else if (computer_score > player_score) {
        cout << "Computer Won the Game." << endl;
    }
    else {
        cout << player_name << " Won the Game!" << endl;
    }
    cin.get();
    return 0;
}
