//Brendan O'Dowd CS282
#include <stdlib.h>
#include <stdio.h>
#include "node.h"

void insert();
void delete();

int main() {

	node* head = malloc(sizeof(node)); //initial node
	node* pointer = malloc(sizeof(node)); //node that will traverse list
	head -> next = pointer;	
	int choice, num;
	
	for(;;) {
		
		printf("1. Add item\n");
		printf("2. Remove item\n");
		printf("3. Print list\n");
		printf("4. Exit\n");
		printf("Please choose an option: ");
		scanf("%d", &choice);
	
		if (choice == 1) {
			printf("What integer would you like to add? ");
			scanf("%d", &num);
			insert(pointer, num);
		}
		
		else if (choice == 2) {
			printf("What integer would you like to remove? ");
			scanf("%d", &num);
			delete(head, num);
		}
		else if (choice == 3) {	
			if (head -> next != NULL) {
				printf("The current list: ");
				do {		
					pointer = pointer -> next;
					printf("%d ", pointer -> value);
				} while (pointer -> next != NULL);
			}
			else {
				printf("The list has no elements.");
			}
			pointer = head -> next;
			printf("\n");
		}	
		else if (choice == 4) {
			exit(0);		
		}
		else {
			printf("Please enter a valid integer.\n");
		}
	}

	free(pointer);

	return 0;
}

void insert(node* point, int num) {

	while(point -> next != NULL) {
		point = point -> next;
	}

	point -> next = (node*)malloc(sizeof(node));
	point = point -> next;
	point -> value = num;
	point -> next = NULL;

}

void delete(node* point, int num) {

	node *pnext = point -> next;

	while(point -> next != NULL && (pnext -> value) != num) {
		point = point -> next;
		pnext = point -> next;
	}
	
	if(point -> next == NULL) {
		printf("Number not found in the list.\n");
		return;
	}

	node *temp;
	temp = point -> next;
	point -> next = temp -> next;
	free(temp);
	return;
		
}
