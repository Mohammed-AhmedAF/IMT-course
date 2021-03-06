#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int num;
	struct node * next;
} node_t;

void showHelp();
void createLinkedList();
void fillLinkedList();
void growList(node_t *);
void printLinkedList();

char answer[10];
int size;
node_t * current;
node_t * start;
node_t * previous;
int i, addedNodes;

int main() {
	printf("Show help (h); or build linked list (ll)\n");
	scanf("%s",&answer);
	if(strcmp(answer,"h") == 0) {
		showHelp();
	}
	else if (strcmp(answer,"ll") == 0) {
		while(1) {
			createLinkedList();
			printf("Print linked list:\n");
			printLinkedList();
			break;
		}
	}
	return 0;
}

void createLinkedList() {	
	printf("What is the initial size of the list?\n");
	scanf(" %d",&size);
	if(size > 0) {
		printf("Creating list..\n");
		start = malloc(sizeof(node_t));
		start->next = NULL;
		current = start;
		printf("Created first node.\n");
		for (i = 2; i <= size;i++) {
			printf("Created node %d\n",i);
			previous = current;
			current = malloc(sizeof(node_t));
			previous->next = current;
			current->next = NULL;
		}
		fillLinkedList();
	}
	else {
		printf("Invalid size.\n");
	}
}

void fillLinkedList() {
	current = start;
	for (i = 1; i <= size; i++) {
		printf("Enter number: \n");
		scanf(" %d",&current->num);
		current = current->next;
	}
	printf("List filled successfully.\n");
	growList(current);
}

void growList(node_t * current) {
	printf("Do you want to grow the linked list\n");
	scanf(" %c",answer);
	if(strcmp(answer,"y") == 0 || strcmp(answer,"Y") == 0) {
		printf("How many nodes to add?\n");
		scanf(" %d",addedNodes);
		for(i = 1; i <= addedNodes;i++) {
			previous = current;
			current = malloc(sizeof(node_t));
			current->num = i;
			previous->next = current;
			current->next = NULL;		
		}
	}
	else {
		printf("Exiting..\n");
	}
}

void printLinkedList() {
	current = start;
	while (current != NULL) {
		printf("Number is %d\n",current->num);
		current = current->next;
	}
}

void showHelp() {
	printf("This program allows you to create a linked list.\n");
	printf("You will be asked for an initial size of the linked list\n");
	printf("Then you may fill the linked list, and then you will be asked if you want");
	printf(" to grow the linked list and add more items.\n");
}
