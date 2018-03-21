#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

// The values have no particular purpose.
// I just chose one to avoid unnecessary
// and confusing initiation later.
Card::Card()
{
    value = "Ace";
    color = "Clubs";
}

Card::Card(string v, string c)
{
    value = v;
    color = c;
}

string Card::getValue()
{
    return value;
}

string Card::getColor()
{
    return color;
}

void Card::setValue(string v)
{
    value = v;
}

void Card::setColor(string c)
{
    color = c;
}

ostream& operator<<(ostream& s, Card c)
{
    s << c.value << " " << c.color << endl;
    return s;
}

// Two Cards are the same if their value is the same and their color is the same.
bool Card::isSame(Card c)
{
    return (value == c.value && color == c.color);
}
