// ECE 209, Spring 2025
// Simulator of single-player briscola-like card game
// (1) User enters expression: <card> <card> <card> <card> [<card>]* E, where <card> = <suit><value>
// (2) Print outcome of the game as follows:
//     cards in deck: <# of cards read from the input>, briscola: <trump suit>, score: <score>, cards won: [ <list of cards won> ]

#include <stdio.h>

int main(void) {

    // declare variables here
    char userInput[200] = "B";
    int points=0;
    char final[200] = " ";
    char hand[200] = "";
    char trump[3];
    char deal[200] = "";
    char future[200] = "";
    int won=0;
    int card=0;
    int amount=0;
    char battle;
    char play;
    int h=0;
    int p=0;
    int value;

    // print prompt for input sequence of cards
    printf("Enter a sequence of cards (terminated by 'E'):\n");
    int i=0;
    int m=0;
    int count=3;
    scanf("%s", trump);
    ++amount;
    while (count != 0) {
        scanf("%s", userInput);
        ++amount;
        if (userInput[i] == 'E') {
            break;
        }
        while (hand[m] != '\0') {
            ++m;
        }
        while (userInput[i] != '\0') {
            hand[m] = userInput[i];
            ++i;
            ++m;
        }
        hand[m] = ' ';
        i=0;
        m=0;
        --count;
    }
    while (userInput[i] != 'E') {
        scanf("%s", userInput);
        ++amount;
        if (userInput[i] == 'E') {
            break;
        }
        while (deal[m] != '\0') {
            ++m;
        }
        while (userInput[i] != '\0') {
            deal[m] = userInput[i];
            ++i;
            ++m;
        }
        deal[m] = ' ';
        i=0;
        m=0;
        
        scanf("%s", userInput);
        ++amount;
        if (userInput[i] == 'E') {
            break;
        }
        while (future[m] != '\0') {
            ++m;
        }
        while (userInput[i] != '\0') {
            future[m] = userInput[i];
            ++i;
            ++m;
        }
        future[m] = ' ';
        i=0;
        m=0;
    }
    // printf("%s\n", trump);
    // printf("%s\n", hand);
    // printf("%s\n", deal);
    // printf("%s\n", future);

    // write your code here to read the input sequence of cards, interpret it, 
    // simulate the gameplay, and print the outcome
    i=0;
    m=0;
    while (deal[h] != '\0') {
        if (won == 0) {
            if (deal[h+1] == 'A') {
                battle = ';';
            }
            if (deal[h+1] == 'K') {
                battle = ':';
            }
            if (deal[h+1] == 'Q') {
                battle = '9';
            }
            if (deal[h+1] == 'J') {
                battle = '8';
            }
            if (deal[h+1] != 'A' && deal[h+1] != 'K' && deal[h+1] != 'Q' && deal[h+1] != 'J') {
                battle = deal[h+1];
            }
            if (deal[h] == hand[0]) {
                if (hand[1] == 'A') {
                    play = ';';
                }
                if (hand[1] == 'K') {
                    play = ':';
                }
                if (hand[1] == 'Q') {
                    play = '9';
                }
                if (hand[1] == 'J') {
                    play = '8';
                }
                if (hand[1] != 'A' && hand[1] != 'K' && hand[1] != 'Q' && hand[1] != 'J') {
                    play = hand[1];
                }
                if (play > battle) {
                    battle = play;
                    card = 1;
                }
            }
            if (deal[h] == hand[3]) {
                if (hand[4] == 'A') {
                    play = ';';
                }
                if (hand[4] == 'K') {
                    play = ':';
                }
                if (hand[4] == 'Q') {
                    play = '9';
                }
                if (hand[4] == 'J') {
                    play = '8';
                }
                if (hand[4] != 'A' && hand[4] != 'K' && hand[4] != 'Q' && hand[4] != 'J') {
                    play = hand[4];
                }
                if (play > battle) {
                    battle = play;
                    card = 2;
                }
            }
            if (deal[h] == hand[6]) {
                if (hand[7] == 'A') {
                    play = ';';
                }
                if (hand[7] == 'K') {
                    play = ':';
                }
                if (hand[7] == 'Q') {
                    play = '9';
                }
                if (hand[7] == 'J') {
                    play = '8';
                }
                if (hand[7] != 'A' && hand[7] != 'K' && hand[7] != 'Q' && hand[7] != 'J') {
                    play = hand[7];
                }
                if (play > battle) {
                    battle = play;
                    card = 3;
                }
            }
            if (card > 0) {
                ++won;
                // printf("rule 1 card %d", card);
            }
        }
        if (trump[0] != deal[h] && won == 0) {
            battle = 'Z';
            if (trump[0] == hand[0]) {
                if (hand[1] == 'A') {
                    play = ';';
                }
                if (hand[1] == 'K') {
                    play = ':';
                }
                if (hand[1] == 'Q') {
                    play = '9';
                }
                if (hand[1] == 'J') {
                    play = '8';
                }
                if (hand[1] != 'A' && hand[1] != 'K' && hand[1] != 'Q' && hand[1] != 'J') {
                    play = hand[1];
                }
                if (play < battle) {
                    battle = play;
                    card = 1;
                }
            }
            if (trump[0] == hand[3]) {
                if (hand[4] == 'A') {
                    play = ';';
                }
                if (hand[4] == 'K') {
                    play = ':';
                }
                if (hand[4] == 'Q') {
                    play = '9';
                }
                if (hand[4] == 'J') {
                    play = '8';
                }
                if (hand[4] != 'A' && hand[4] != 'K' && hand[4] != 'Q' && hand[4] != 'J') {
                    play = hand[4];
                }
                if (play < battle) {
                    battle = play;
                    card = 2;
                }
            }
            if (trump[0] == hand[6]) {
                if (hand[7] == 'A') {
                    play = ';';
                }
                if (hand[7] == 'K') {
                    play = ':';
                }
                if (hand[7] == 'Q') {
                    play = '9';
                }
                if (hand[7] == 'J') {
                    play = '8';
                }
                if (hand[7] != 'A' && hand[7] != 'K' && hand[7] != 'Q' && hand[7] != 'J') {
                    play = hand[7];
                }
                if (play < battle) {
                    battle = play;
                    card = 3;
                }
            }
            if (card > 0) {
                ++won;
                // printf("Rule 2 Card %d", card);
            }
        }
        if (won == 0) {
            battle = 'Z';
            if (trump[0] != hand[0]) {
                if (hand[1] == 'A') {
                    play = ';';
                }
                if (hand[1] == 'K') {
                    play = ':';
                }
                if (hand[1] == 'Q') {
                    play = '9';
                }
                if (hand[1] == 'J') {
                    play = '8';
                }
                if (hand[1] != 'A' && hand[1] != 'K' && hand[1] != 'Q' && hand[1] != 'J') {
                    play = hand[1];
                }
                if (play < battle) {
                    battle = play;
                    card = 1;
                }
            }
            if (trump[0] != hand[3]) {
                if (hand[4] == 'A') {
                    play = ';';
                }
                if (hand[4] == 'K') {
                    play = ':';
                }
                if (hand[4] == 'Q') {
                    play = '9';
                }
                if (hand[4] == 'J') {
                    play = '8';
                }
                if (hand[4] != 'A' && hand[4] != 'K' && hand[4] != 'Q' && hand[4] != 'J') {
                    play = hand[4];
                }
                if (play < battle) {
                    battle = play;
                    card = 2;
                }
            }
            if (trump[0] != hand[6]) {
                if (hand[7] == 'A') {
                    play = ';';
                }
                if (hand[7] == 'K') {
                    play = ':';
                }
                if (hand[7] == 'Q') {
                    play = '9';
                }
                if (hand[7] == 'J') {
                    play = '8';
                }
                if (hand[7] != 'A' && hand[7] != 'K' && hand[7] != 'Q' && hand[7] != 'J') {
                    play = hand[7];
                }
                if (play < battle) {
                    battle = play;
                    card = 3;
                }
            }
            if (card == 1) {
                m=p;
                hand[0] = future[m];
                ++m;
                hand[1] = future[m];
                // printf("Rule 3a Current Hand: %s", hand);
            }
            if (card == 2) {
                m=p;
                hand[3] = future[m];
                ++m;
                hand[4] = future[m];
                // printf("Rule 3b Current Hand: %s", hand);
            }
            if (card == 3) {
                m=p;
                hand[6] = future[m];
                ++m;
                hand[7] = future[m];
                // printf("Rule 3c Current Hand: %s", hand);
            }
        }
        if (won == 1) {
            i = h;
            count=2;
            while (final[m] != '\0') {
                ++m;
            }
            while (count != 0) {
                final[m] = deal[i];
                ++i;
                ++m;
                --count;
            }
            final[m] = ' ';
            count=2;
            if (card == 1) {
                i=0;
                m=0;
                while (final[m] != '\0') {
                    ++m;
                }
                while (count != 0) {
                    final[m] = hand[i];
                    ++i;
                    ++m;
                    --count;
                }
                final[m] = ' ';
                i=0;
                m=p;
                hand[0] = future[m];
                ++m;
                hand[1] = future[m];
                // printf("It Won Current Hand: %s", hand);
            }
            if (card == 2) {
                i=3;
                m=0;
                while (final[m] != '\0') {
                    ++m;
                }
                while (count != 0) {
                    final[m] = hand[i];
                    ++i;
                    ++m;
                    --count;
                }
                final[m] = ' ';
                i=3;
                m=p;
                hand[3] = future[m];
                ++m;
                hand[4] = future[m];
                // printf("It Won Current Hand: %s", hand);
            }
            if (card == 3) {
                i=6;
                m=0;
                while (final[m] != '\0') {
                    ++m;
                }
                while (count != 0) {
                    final[m] = hand[i];
                    ++i;
                    ++m;
                    --count;
                }
                final[m] = ' ';
                i=6;
                m=p;
                hand[6] = future[m];
                ++m;
                hand[7] = future[m];
                // printf("It Won Current Hand: %s", hand);
            }
        }
        h=h+3;
        p=p+3;
        i=0;
        m=0;
        won=0;
        card=0;
    }
    i=2;
    while (final[i] != '\0') {
        if (final[i] == '\0') {
            break;
        }
        if (final[i] == 'A') {
            points = points + 11;
        }
        if (final[i] == 'K') {
            points = points + 10;
        }
        if (final[i] == 'Q') {
            points = points + 9;
        }
        if (final[i] == 'J') {
            points = points + 8;
        }
        if (final[i] != 'A' && final[i] != 'K' && final[i] != 'Q' && final[i] != 'J') {
            value = final[i] - '0';
            points = points + value;
        }
        i=i+3;
    }
    --amount;
    printf("cards in deck: %d, briscola: %c, score: %d, cards won: [%s]", amount, trump[0], points, final);
    printf("\n");
    return 0;
}
