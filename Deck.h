#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>      // NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // time


class Deck
{
private:
    vector<Card> cards;
public:
    Deck(int deckLength);
    vector<Card> getCards();
    int getLength();
    // Functions to count. They make operator overloading simpler and shorter.
    int clubs();
    int hearts();
    int diamonds();
    int spades();
    friend ostream& operator<<(ostream& s, Deck d);
    // Function to shuffle the deck.
    void shuffle();
    // Function to draw a card from the deck.
    Card draw();
};

#endif // DECK_H_INCLUDED
