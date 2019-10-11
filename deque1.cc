#include <deque>
#include <iostream>
#include <string>

using namespace std;

typedef deque<string> deque_t;

static deque_t deck_of_cards;
static deque_t current_hand;

void initialize_cards(deque_t & cards)
{
    cards.push_front("ace of spades");
    cards.push_front("king of spades");
    cards.push_front("queen of spades");
    cards.push_front("jack of spades");
    cards.push_front("ten of spades");
}


template<class It, class It2> void print_current_hand(It start, It2 end)
{
    while (start < end)
        cout << *start++ << endl;
}


template<class It, class It2> void deal_cards(It, It2 end)
{
    for (int i = 0; i < 5; i++) {
        current_hand.insert(current_hand.begin(), *end);
        deck_of_cards.erase(end++);
    }
}


void play_poker()
{
    initialize_cards(deck_of_cards);
    deal_cards(current_hand.begin(), deck_of_cards.begin());
}


int main(void)
{
    play_poker();

    print_current_hand(current_hand.begin(), current_hand.end());

    return 0;
}
