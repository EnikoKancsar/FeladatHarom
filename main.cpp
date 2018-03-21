#include <iostream>
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main()
{
    Deck deck(12);
    cout << deck;
    Card drawn = deck.draw();
    cout << drawn;
    cout << deck;

    return 0;
}
