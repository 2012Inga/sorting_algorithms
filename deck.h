/* File: deck.h */

#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Represents the kinds of a card
 * @SPADE: Spades
 * @HEART: Hearts
 * @CLUB: Clubs
 * @DIAMOND: Diamonds
 */
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;

/**
 * struct card_s - Represents a playing card
 * @value: Value of the card (Ace, 2-10, Jack, Queen, King)
 * @kind: Kind of the card (Spade, Heart, Club, Diamond)
 */
typedef struct card_s
{
    const char *value;
    const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Represents a node in a deck of cards
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 */
typedef struct deck_node_s
{
    const card_t *card;
    struct deck_node_s *prev;
    struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
