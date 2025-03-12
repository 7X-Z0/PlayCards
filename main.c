//TESTING TESTING UNIX & WINDOWS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NCARDS 52
#define NPROPS 2
#define NSUITS 4
#define NFACES 13

// card text values using array of pointers to preinitialized constant text strings
char* suit[]={"hearts","spades","clubs","diamonds"};

char* face[]={"blank","ace","two","three","four","five","six","seven","eight","nine",
"ten","jack","queen","king"};

// function prototypes used for manipulating cards
void PrintCard(int deck[NCARDS][NPROPS], int i);
void InitDeck(int deck[NCARDS][NPROPS]);
void ShuffleDeck(int deck[NCARDS][NPROPS]);
void SwapCards(int deck[NCARDS][NPROPS], int src, int dest);

int main()
{

• First, modify PrintCard to return the card ‘playvalue’ (so scores can be totaled)
int PrintCard(int deck[NCARDS][NPROPS], int i);
and
return playval;
• Declare variables for the two hands:
// declare the variables
int hand1[5][2], hand2[5][2]; //5 card ‘decks’
int play1=0, play2=0;
int index1=0, index2=0;
• Deal the cards from the top of the deck – Even card to hand1, odd to hand2
//Deal the cards
for (i=0; i< 10; i++){ // deal ten cards off the deck - even hand 1, odd hand 2
    if(i & 0x01){ //odd card
    hand2[index2][0] = deck[i][0];
    hand2[index2][1] = deck[i][1];
    index2++;
}

else{ //even card
    hand1[index1][0] = deck[i][0];
    hand1[index1][1] = deck[i][1];
    index1++;
    }

}
• Print the cards and accumulate values for each hand
printf("\nHand1: \n");
for(i=0; i<5; i++) play1 += PrintCard(hand1, i);
printf("Total for Hand1 is: %d\n", play1);
printf("\nHand2: \n");
for(i=0; i<5; i++) play2 += PrintCard(hand2, i);
printf("Total for Hand2 is: %d\n", play2);
• Then print out the winner or if there is a tie
if(play1 == play2)
{
printf("\tThey are Tied!, deal again\n");
}
else
{
if(play1>play2)
{
printf("\tHand1 is the winner!\n");
}
else
{
printf("\tHand2 is the winner!\n");
}
}


return 0;
}

void PrintCard(int deck[NCARDS][NPROPS], int i){
    int cardFace = deck[i][0];
    int cardSuit = deck[i][1];
    printf("%s of %s \n", face[cardFace], suit[cardSuit]);
}

void InitDeck(int deck[NCARDS][NPROPS]){
    for (int i=0; i<NCARDS; i++){
    //Face
    deck[i][0] = (i % NFACES) + 1;
    //Suit
    deck[i][1] = i % NSUITS;
    }
}
void SwapCards(int deck[NCARDS][NPROPS], int src, int dest){
    int tmp;
    int i;
    for (i=0; i<2; i++){
        tmp = deck[dest][i];
        deck[dest][i] = deck[src][i];
        deck[src][i] = tmp;
    }
}
void ShuffleDeck(int deck[NCARDS][NPROPS]){
    for(int i=0; i<NCARDS-1; i++){

    }
}
