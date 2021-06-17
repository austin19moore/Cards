#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cards.h"

int main(int argc, char *argv[]) {
	
	srand(time(0));
	
	if (argc == 2) { // ends program if there is not the correct number of command line arguements
        
    } else {
        printf("ERROR NO ARGS");
        return -1;
    }
	
	if (atoi(argv[1]) < 0) {
		printf("ERROR ARG < 0");
		return -1;
	}
	
	int roundNumber = 1;
	int numCards = atoi(argv[1]);
	
	if (numCards > 0) {
		
	Card* head1 = NULL;
	head1 = buildCards(numCards);
	
	Card* head2 = NULL;
	head2 = buildCards(numCards);
	
	printf("Start size: %d cards\n", numCards);
		
	printf("Player 1 starting cards: ");
	printCards(head1);
	
	
	printf("Player 2 starting cards: ");
	printCards(head2);
	printf("\n");
	
	
	while ((getLength(head1) > 0) && (getLength(head2) > 0)) { // game loop
		
		int sit = 0;
		
		printf("ROUND: %d\n", roundNumber);
		roundNumber += 1;
		printf("Player 1 (%d): ", getLength(head1));
		printCard(head1);
		printf("\n");
		printf("Player 2 (%d): ", getLength(head2));
		printCard(head2);
		printf("\n");
	
		
		
		if ((head1->currCard == ATTACK) && (head2->currCard == ATTACK)) {
			
			printf("Both players ATTACK.\n");
			
			if (head1->val > head2->val) {
				printf("Player 1 wins and gets a new card.\n");
				head1 =  addCard(head1, createCard());
				sit = 1;
			} else if (head1->val == head2->val) {
				printf("It's a draw. Nothing happens.\n");
				sit = 3;
			} else {
				printf("Player 2 wins and gets a new card.\n");
				head2 =  addCard(head2, createCard());
				sit = 2;
			}
			
		}
		
		if ((head1->currCard == DEFEND) && (head2->currCard == DEFEND)) {
			printf("Both players DEFEND.\n");
			printf("Nothing happens.\n");
			sit = 3;
		}
		
		if ((head1->currCard == RUN) && (head2->currCard == RUN)) {
			printf("Both players RUN away.\n");
			printf("Both lose their next card into the abyss.\n");
			sit = 3;
		}
		
		if ((head1->currCard == ATTACK) && (head2->currCard == DEFEND)) {
			
			printf("Player 1 ATTACKs and Player 2 DEFENDs.\n");
			
			if (head1->val > head2->val) {
				printf("Player 2 loses and Player 1 survives.\n");
				sit = 1;
			} else if (head1->val == head2->val) {
				printf("Player 1 loses and Player 2 survives.\n");
				sit = 2;
			} else {
				printf("Player 1 loses and Player 2 survives.\n");
				sit = 2;
			}
			
		}
		
		if ((head1->currCard == DEFEND) && (head2->currCard == ATTACK)) {
			
			printf("Player 2 ATTACKs and Player 1 DEFENDs.\n");
			
			if (head1->val > head2->val) {
				printf("Player 2 loses and Player 1 survives.\n");
				sit = 1;
			} else if (head1->val == head2->val) {
				printf("Player 2 loses and Player 1 survives.\n");
				sit = 1;
			} else {
				printf("Player 1 loses and Player 2 survives.\n");
				sit = 2;
			}
			
		}
		
		if ((head1->currCard == ATTACK) && (head2->currCard == RUN)) {
			printf("Player 1 ATTACKs and Player 2 RUNs.\n");
			printf("Player 2 loses their next card into the abyss.\n");
			sit = 1;
		}
		
		if ((head1->currCard == RUN) && (head2->currCard == ATTACK)) {
			printf("Player 2 ATTACKs and Player 1 RUNs.\n");
			printf("Player 1 loses their next card into the abyss.\n");
			sit = 2;
		}
		
		if ((head1->currCard == DEFEND) && (head2->currCard == RUN)) {
			printf("Player 1 DEFENDs and Player 2 RUNs.\n");
			printf("Player 1 gets a new card.\n");
			printf("Player 2 loses their next card into the abyss.\n");
			head1 = addCard(head1, createCard());
			sit = 1;
		}
		
		if ((head1->currCard == RUN) && (head2->currCard == DEFEND)) {
			printf("Player 2 DEFENDs and Player 1 RUNs.\n");
			printf("Player 2 gets a new card.\n");
			printf("Player 1 loses their next card into the abyss.\n");
			head2 =  addCard(head2, createCard());
			sit = 2;
		}
		
	
	
		
		switch (sit) {
			
			case 0:
			printf("Error no update: \n");
			return -1;
			break;
			
			case 1:
			head2 = removeCard(head2);
			break;
			
			case 2:
			head1 = removeCard(head1);
			break;
			
			case 3:
			head1 = removeCard(head1);
			head2 = removeCard(head2);
			break;
			
			default:
			break;
			
		}
	
	}
	
	printf("\n");
	printf("GAME OVER\n\n");
	
	printf("Player 1 ending cards: ");
	printCards(head1);
	
	printf("Player 2 ending cards: ");
	printCards(head2);
	
	if ((getLength(head1) <= 0) && (getLength(head2) <= 0)) {
		printf("Both players ran out of cards, so both players lose.\n");
	} else if (getLength(head1) <= 0) {
		printf("Player 1 ran out of cards. Player 2 wins.\n");
	} else if (getLength(head2) <= 0) {
		printf("Player 2 ran out of cards. Player 1 wins.\n");
	}
	
	destroyCards(head1);
	destroyCards(head2);
	
	printf("The end.");
	
	} else {
		printf("Please enter a command line arguement greater than 0.");
	}
	
	return 0;
}