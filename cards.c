#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cards.h"

Card* createCard() {
	
	Card *n = (Card*)malloc(sizeof(Card));
	
	int randNum = ((rand() % 11) + 0);
	int randVal;
	
	if (randNum == 0) {
		n->currCard = RUN;
		randVal = (rand() % (8)) + 1;
	} else if (randNum > 0 && randNum < 5) {
		n->currCard = ATTACK;
		randVal = (rand() % (5)) + 1;
	} else if (randNum >= 5) {
		n->currCard = DEFEND;
		randVal = (rand() % (6)) + 3;
	}
	n->val = randVal;
	
	n->next = NULL;
	
	return n;
	
}

Card* removeCard(Card* head) {
	
	if (head == NULL) {
		return NULL;
	}
	
	Card *temp = head;
    head = head->next;
	free(temp);
	
	return head;
}

Card* addCard(Card* head, Card* c) {
	
	Card* n = c;
    n->next = head;
    return n;
	
}

int getLength(Card* head) {
	
	int len = 0;
    Card* t = head;
	
    while(t != NULL) {
	  len++;
	  t = t->next;
	}
	
	return len;
	
}

void printCard(Card* head) {
	
	if (head->currCard == ATTACK) {
		printf("A%d ", head->val);
	} else if (head->currCard == DEFEND) {
		printf("D%d ", head->val);
	} else if (head->currCard == RUN) {
		printf("R%d ", head->val);
	}
	
}

void printCards(Card* head) {
	
	Card* t = head;
	while (t != NULL) {
		
		
		printCard(t);
		t = t->next;
		
	}
	
	printf("\n");
	free (t);
}

Card* buildCards(int n) {
	
	Card* ptr = NULL;
	Card* head = NULL;
	
	for (int i = 0; i < n; i++) {
	ptr = createCard();
	head = addCard(head, ptr);
	}
	
	return head;
	
}

Card* destroyCards(Card* head){
	
	while (head != NULL) {
		
		Card* t = head;
		head = head->next;
		free(t);
	}
	
	return head;
	
}