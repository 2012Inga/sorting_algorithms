/* File: 1000-sort_deck.c */

#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare two cards for sorting
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative value if card1 is less than card2,
 *         0 if card1 is equal to card2,
 *         Positive value if card1 is greater than card2.
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = *((const card_t **)card1);
    const card_t *c2 = *((const card_t **)card2);

    int value_diff = strcmp(c1->value, c2->value);
    if (value_diff != 0)
        return value_diff;

    return c1->kind - c2->kind;
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t count = 0;
    deck_node_t *current = *deck;
    card_t *cards[52];

    while (current != NULL)
    {
        cards[count] = (card_t *)current->card;
        current = current->next;
        count++;
    }

    qsort(cards, count, sizeof(card_t *), compare_cards);

    current = *deck;
    for (size_t i = 0; i < count; i++)
    {
        current->card = cards[i];
        current = current->next;
    }
}
