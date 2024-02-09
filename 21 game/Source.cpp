#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

int main() {
    setlocale(0, "");
    vector<int> deck = { 6, 7, 8, 9, 10, 2, 3, 4, 11 };
    random_device rd;
    mt19937 g(rd());
    shuffle(deck.begin(), deck.end(), g);

    cout << "Давайте сыграем в очко!\n";
    int playerScore = 0;
    int computerScore = 0;

    while (true) {
        char choice;
        cout << "Вы хотите брать карту? (y/n)\n";
        cin >> choice;

        if (choice == 'y') {
            int current = deck.back();
            deck.pop_back();
            cout << "Вы вытянули карту" << current << endl;
            playerScore += current;

            if (playerScore > 21) {
                cout << "Извините, вы проиграли\n";
                break;
            }
            else if (playerScore == 21) {
                cout << "Поздравляю, у вас 21 !\n";
                break;
            }
            else {
                cout << "Вы имеете " << playerScore << " очков.\n";
            }
        }
        else if (choice == 'n') {
            cout << " " << playerScore << " очков.\n";
            break;
        }
        else {
            cout << "Пожалуйста выбирите 'y' or 'n'.\n";
        }

        // Computer's turn
        if (computerScore < 18) {
            int current = deck.back();
            deck.pop_back();
            cout << "Компьютер вытащил карточку с числом " << current << endl;
            computerScore += current;

            if (computerScore > 21) {
                cout << "мпьютер проиграл.\n";
                break;
            }
            else if (computerScore == 21) {
                cout << "Компьютер набрал 21!\n";
                break;
            }
            else {
                cout << "Компьютер имеет " << computerScore << " очков\n";
            }
        }
    }

    // Determine the winner
    if (playerScore > computerScore && playerScore <= 21) {
        cout << "Ты победил! У тебя есть " << playerScore << " очков, в то время как компьютер имеет " << computerScore << " очков\n";
    }
    else if (computerScore > playerScore && computerScore <= 21) {
        cout << "Компьютер побеждает! Он имеет" << computerScore << " очков, в то время как у вас есть " << playerScore << " очков\n";
    }
    else if (playerScore == computerScore) {
        cout << "Ничья! И у вас, и у компьютера есть " << playerScore << " очков\n";
    }
    else {
        cout << "Ты проиграл! У тебя есть " << playerScore << " очков, в то время как компьютер имеет " << computerScore << " очков.\n";
    }

    return 0;
}