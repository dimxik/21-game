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

    cout << "������� ������� � ����!\n";
    int playerScore = 0;
    int computerScore = 0;

    while (true) {
        char choice;
        cout << "�� ������ ����� �����? (y/n)\n";
        cin >> choice;

        if (choice == 'y') {
            int current = deck.back();
            deck.pop_back();
            cout << "�� �������� �����" << current << endl;
            playerScore += current;

            if (playerScore > 21) {
                cout << "��������, �� ���������\n";
                break;
            }
            else if (playerScore == 21) {
                cout << "����������, � ��� 21 !\n";
                break;
            }
            else {
                cout << "�� ������ " << playerScore << " �����.\n";
            }
        }
        else if (choice == 'n') {
            cout << " " << playerScore << " �����.\n";
            break;
        }
        else {
            cout << "���������� �������� 'y' or 'n'.\n";
        }

        // Computer's turn
        if (computerScore < 18) {
            int current = deck.back();
            deck.pop_back();
            cout << "��������� ������� �������� � ������ " << current << endl;
            computerScore += current;

            if (computerScore > 21) {
                cout << "������� ��������.\n";
                break;
            }
            else if (computerScore == 21) {
                cout << "��������� ������ 21!\n";
                break;
            }
            else {
                cout << "��������� ����� " << computerScore << " �����\n";
            }
        }
    }

    // Determine the winner
    if (playerScore > computerScore && playerScore <= 21) {
        cout << "�� �������! � ���� ���� " << playerScore << " �����, � �� ����� ��� ��������� ����� " << computerScore << " �����\n";
    }
    else if (computerScore > playerScore && computerScore <= 21) {
        cout << "��������� ���������! �� �����" << computerScore << " �����, � �� ����� ��� � ��� ���� " << playerScore << " �����\n";
    }
    else if (playerScore == computerScore) {
        cout << "�����! � � ���, � � ���������� ���� " << playerScore << " �����\n";
    }
    else {
        cout << "�� ��������! � ���� ���� " << playerScore << " �����, � �� ����� ��� ��������� ����� " << computerScore << " �����.\n";
    }

    return 0;
}