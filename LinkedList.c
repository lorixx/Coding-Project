#include <stdio.h>
#include <stdlib.h>


typedef struct IntElement {
	struct IntElement *next;
	int data;
} IntElement;


int deleteElement(IntElement **head, int targetNum){
	
	if ((*head)->data == targetNum) {
		IntElement* current = (*head);
		*head = (*head)->next;
		free(current);
		return 0;
	}
	IntElement *start = *head;
	
	while (start) {
		if ((start)->next->data == targetNum) {
			IntElement* current = (start)->next;

			(start)->next = (start)->next->next;
			free(current);
			return 0;
		}

		start = start->next;
		
		
	}
	
	
	
	return -1;
	
	
}

int insertElement(int data, IntElement ** head) {
	
	IntElement * element = malloc(sizeof(IntElement));
	
	if(!element){
		return -1;		
	}
	
	element->next = *head;
	element->data = data;
	*head = element;
	return 0;
	
	
}

IntElement* reverseLinkedList(IntElement **head){
	if( (*head)->next == NULL){
		return *head;
	}
	
	IntElement * notYet = *head;
	IntElement * newHead;
	
	int firstElement = 1;
	if (firstElement) {
		notYet = notYet->next;
		newHead = *head;
		newHead->next = NULL;
		firstElement = 0;
	}
	
	while(notYet){
				
		IntElement *temp = notYet;
		notYet = notYet->next;
		temp->next = newHead;
		newHead = temp;		
	}
	
	return newHead;
	
}


void printList(IntElement * head) {
	while (head) {
		printf("%d\n", head->data);
		head = head->next;
	}
	printf("\n\n\n");

}

int bigrand()
{    
    return RAND_MAX*rand() + rand();
}

// genknuth:顺序输出随即不重复的数
void genknuth(int m, int n)
{
	int i;
	srand((int)(time(0)));
	for(i = 0; i < n; i++)
		if(rand()%(n - i) < m)  //以m/(n - i)的概率选择数目；
		{
			printf("%d  ",i);
			m --;
		}
}


int main(int argc, char *argv[]) {
	
	IntElement * head = NULL;
	int  i;
	for (i = 0; i<8; i++) {
		
		insertElement(i,  &head);
		
	}
	
	printList(head);
	

	deleteElement(&head, 3);
	printList(head);
	
	
	IntElement* result = reverseLinkedList(&head);
	
	printList(result);

	genknuth(10, 1599999999);
	
	return 0;
	
	
	
}

	