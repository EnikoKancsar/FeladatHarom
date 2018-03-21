#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED
#include <string>

using namespace std;

class Card
{
private:
    string value;
    string color;
public:
    Card();
    Card(string value, string color);
    string getValue();
    string getColor();
    void setValue(string v);
    void setColor(string c);
    friend ostream& operator<<(ostream& s, Card c);
    // Function to compare two Cards.
    bool isSame(Card c);
};

#endif // CARD_H_INCLUDED
