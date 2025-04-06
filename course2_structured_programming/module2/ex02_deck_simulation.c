/*
    Card shuffle
    Domingo Gallardo Saavedra
    April 6, 2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define MIN_PIP 1
#define MAX_PIP 13
#define HAND_SIZE 7
#define NUM_SIMULATIONS 1000000

// Enum for card suits
typedef enum CardSuit {
    CARD_SUIT_HEART,
    CARD_SUIT_DIAMOND,
    CARD_SUIT_CLUB,
    CARD_SUIT_SPADE
} CardSuit;

// Struct for a card
typedef struct Card {
    CardSuit suit;
    short pip;
} Card;

typedef enum HandRank {
    NO_PAIR,
    ONE_PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    HAND_RANK_COUNT
} HandRank;

Card deck[DECK_SIZE];

// Prototypes
const char* get_suit_name(CardSuit suit);
void create_deck(Card *deck);
void shuffle_deck(Card* deck);
void deal_hand(Card* deck, Card* hand);
int evaluate_hand(const Card* hand);
void run_simulation();

int main() {
    srand(time(NULL));
    run_simulation();
    return 0;
}

const char* get_suit_name(CardSuit suit) {
    switch (suit) {
        case CARD_SUIT_HEART: return "Heart";
        case CARD_SUIT_DIAMOND: return "Diamond";
        case CARD_SUIT_CLUB: return "Club";
        case CARD_SUIT_SPADE: return "Spade";
        default: return "None";
    }
}

void create_deck(Card *deck) {
    for(short i=0; i<DECK_SIZE; ++i) {
        deck[i].suit = i % 4; 
        deck[i].pip = (i % MAX_PIP) + MIN_PIP;
    }
}

void shuffle_deck(Card* deck) {
    for (int i = DECK_SIZE - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal_hand(Card* deck, Card* hand) {
    for (int i = 0; i < HAND_SIZE; ++i) {
        hand[i] = deck[i];
    }
}

int evaluate_hand(const Card* hand) {
    int pip_count[14] = {0};

    for (int i = 0; i < HAND_SIZE; ++i) {
        pip_count[hand[i].pip]++;
    }

    int pairs = 0;
    int three_of_a_kind = 0;
    int four_of_a_kind = 0;

    for (int i = 1; i < 14; ++i) {
        if (pip_count[i] == 2) pairs++;
        else if (pip_count[i] == 3) three_of_a_kind++;
        else if (pip_count[i] == 4) four_of_a_kind++;
    }

    if (four_of_a_kind) return FOUR_OF_A_KIND;
    if (three_of_a_kind && pairs) return FULL_HOUSE;
    if (three_of_a_kind) return THREE_OF_A_KIND;
    if (pairs == 2) return TWO_PAIR;
    if (pairs == 1) return ONE_PAIR;

    return NO_PAIR;
}

void run_simulation() {
    int stats[HAND_RANK_COUNT] = {0};
    Card hand[HAND_SIZE];

    for (int i = 0; i < NUM_SIMULATIONS; ++i) {
        create_deck(deck);
        shuffle_deck(deck);
        deal_hand(deck, hand);
        int result = evaluate_hand(hand);
        stats[result]++;
    }

    printf("Results after %d simulations:\n", NUM_SIMULATIONS);
    printf("No Pair:         %.4f%%\n", (stats[NO_PAIR] * 100.0) / NUM_SIMULATIONS);
    printf("One Pair:        %.4f%%\n", (stats[ONE_PAIR] * 100.0) / NUM_SIMULATIONS);
    printf("Two Pair:        %.4f%%\n", (stats[TWO_PAIR] * 100.0) / NUM_SIMULATIONS);
    printf("Three of a Kind: %.4f%%\n", (stats[THREE_OF_A_KIND] * 100.0) / NUM_SIMULATIONS);
    printf("Full House:      %.4f%%\n", (stats[FULL_HOUSE] * 100.0) / NUM_SIMULATIONS);
    printf("Four of a Kind:  %.4f%%\n", (stats[FOUR_OF_A_KIND] * 100.0) / NUM_SIMULATIONS);
}