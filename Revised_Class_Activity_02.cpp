#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

const int WIDTH = 40;

string getRandomCard() {
    vector<string> suits = { "Hearts", "Diamonds", "Clubs", "Spades" };
    vector<string> ranks = {
        "Ace", "2", "3", "4", "5", "6", "7", "8",
        "9", "10", "Jack", "Queen", "King"
    };

    srand(static_cast<unsigned int>(time(nullptr)));

    string rank = ranks[rand() % ranks.size()];
    string suit = suits[rand() % suits.size()];

    return rank + " of " + suit;
}

string formatCardLine(const string& label, const string& value) {
    int dashCount = WIDTH - label.length() - value.length();
    dashCount = max(0, dashCount);
    return label + string(dashCount, '-') + value;
}

string centerText(const string& text) {
    int padding = (WIDTH - text.length()) / 2;
    return string(padding, ' ') + text;
}

void displayCard(const string& card) {
    string label = "Casino Card:";
    string formattedLine = formatCardLine(label, card);
    string centeredLine = centerText(formattedLine);

    // Top border
    cout << string(WIDTH, '*') << '\n';

    // Empty line
    cout << "*" << setw(WIDTH - 1) << " " << '\n';

    // Centered card description
    cout << "*" << centeredLine << setw(WIDTH - 1 - centeredLine.length()) << " " << "*" << '\n';

    // Empty line
    cout << "*" << setw(WIDTH - 1) << " " << '\n';

    // Bottom border
    cout << string(WIDTH, '*') << '\n';
}

int main() {
    string card = getRandomCard();
    displayCard(card);
    return 0;
}
