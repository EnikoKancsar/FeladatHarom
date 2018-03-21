#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>    // random_shuffle

#include <stdio.h>      // NULL
#include <stdlib.h>     // srand, rand
#include <time.h>       // time

using namespace std;

Deck::Deck(int deckLength)
{
    // Temporary Card variable
    Card card;
    // Using the current time as seed for generating random numbers.
    srand (time(NULL));
    // Starting the process to make every card in the deck different.
    for (int i = 0; i < deckLength; i++)
    {
        // Making sure every color is different if there's less than 5 cards in the deck.
        // Also making sure all 4 colors appear in every deck, even in those having more than 4 cards.
        // Not random.
        if (i < 4)
        {
            if (i == 0)
                card.setColor("Clubs");
            else if (i == 1)
                card.setColor("Diamonds");
            else if (i == 2)
                card.setColor("Hearts");
            else if (i == 3)
                card.setColor("Spades");
        }
        // Randomly generating a card's suit.
        else
        {
            switch(rand() % 4 + 1)
            {
                case 1:
                    card.setColor("Clubs");
                    break;
                case 2:
                    card.setColor("Diamonds");
                    break;
                case 3:
                    card.setColor("Hearts");
                    break;
                case 4:
                    card.setColor("Spades");
                    break;
            }
        }

        // Randomly generating a card's value.
        switch(rand() % 12 + 1)
        {
        case 1:
            card.setValue("Ace");
            break;
        case 2:
            card.setValue("2");
            break;
        case 3:
            card.setValue("3");
            break;
        case 4:
            card.setValue("4");
            break;
        case 5:
            card.setValue("5");
            break;
        case 6:
            card.setValue("6");
            break;
        case 7:
            card.setValue("7");
            break;
        case 8:
            card.setValue("8");
            break;
        case 9:
            card.setValue("9");
            break;
        case 10:
            card.setValue("Jack");
            break;
        case 11:
            card.setValue("Queen");
            break;
        case 12:
            card.setValue("King");
            break;
        }
        // Make a new seed for the next iteration.
        srand (rand());
        // Temporary variable indicating if the current card is already in the deck.
        bool b = false;
        // Check if the new card is already in the deck.
        // Compare the current card to every card before it.
        for(int j = 0; j < i; j++)
        {
            // If the new card is the same as one of the old cards
            if(card.isSame(cards.at(j)))
            {
                // then adjust the indicator variable.
                b = card.isSame(cards.at(j));
                // And do the whole iteration again
                // since it didn't add any card to the deck.
                i--;
                // Also we don't have to compare it to more cards,
                // because those are different from each other,
                // we checked them in the previous iterations.
                break;
            }
        }
        // If the card is unique we put it in the deck.
        if(b == false)
            cards.push_back(card);
    }
}

vector<Card> Deck::getCards()
{
    return cards;
}

int Deck::clubs()
{
    int tmp = 0;
    for(unsigned int i = 0; i < cards.size(); i++)
    {
        if (cards.at(i).getColor() == "Clubs")
            tmp++;
    }
    return tmp;
}

int Deck::hearts()
{
    int tmp = 0;
    for(unsigned int i = 0; i < cards.size(); i++)
    {
        if (cards.at(i).getColor() == "Hearts")
            tmp++;
    }
    return tmp;
}

int Deck::diamonds()
{
    int tmp = 0;
    for(unsigned int i = 0; i < cards.size(); i++)
    {
        if (cards.at(i).getColor() == "Diamonds")
            tmp++;
    }
    return tmp;
}

int Deck::spades()
{
    int tmp = 0;
    for(unsigned int i = 0; i < cards.size(); i++)
    {
        if (cards.at(i).getColor() == "Spades")
            tmp++;
    }
    return tmp;
}

ostream& operator<<(ostream& s, Deck d)
{
    s << d.cards.size() << " cards - " <<
         d.clubs() << " Clubs, " <<
         d.hearts() << " Hearts, " <<
         d.diamonds() << " Diamonds, " <<
         d.spades() << " Spades"  << endl;
    return s;
}

void Deck::shuffle()
{
    random_shuffle(cards.begin(), cards.end());
}

Card Deck::draw()
{
    Card c = cards.back();
    cards.pop_back();
    return c;
}
