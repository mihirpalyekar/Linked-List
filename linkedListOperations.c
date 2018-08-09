#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *next;
}typedef node; 

node *start = NULL;
node *insertBegining(node *start);
node *insertEnd(node *start);
node *insertBefore(node *start);
node *insertAfter(node *start);
node *deleteBegining(node *start);
node *deleteEnd(node *start);
node *deleteAfter(node *start);
node *deleteList(node *start);
node *deleteNode(node *start);
node *display(node *start);
node *creatLinkedList(node *start);
node *sortList(node *start);

node *createLinkedList(node *start) {
	node *newNode, *ptr;
	int value;
	printf("\nEnter -1 to stop inserting : ");
	printf("\nEnter data : ");
	scanf("%d", &value);
	while(value != -1) {
		newNode = (node *)malloc(sizeof(node));
		newNode->data = value;
		if(start == NULL) {
			newNode->next = NULL;
			start = newNode;
		} else {
			ptr = start;
			while(ptr->next != NULL) {
				ptr = ptr->next;
			}
			ptr->next = newNode;
			newNode->next = NULL;
		}
		printf("\nEnter the value : ");
		scanf("%d", &value);
	}
	return start;
}

node *insertBegining(node *start) {
	node *newNode;
	int value;
	
	printf("\nEnter the value : ");
	scanf("%d", &value);
	
	newNode = (node *)malloc(sizeof(node));
	newNode->data = value;
	newNode->next = start;
	start = newNode;
	return start;
}

node *insertEnd(node *start) {
	node *newNode, *ptr;
	int value;
	
	printf("\nEnter the value : ");
	scanf("%d", &value);
	
	newNode = (node *)malloc(sizeof(node));
	newNode->data = value;
	ptr = start;
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = newNode;
	newNode->next = NULL;
	return start;
}

node *insertBefore(node * start) {
	node *newNode, *ptr, *prepointer;
	int value , insertBefore;
	
	printf("\nEnter the value before you want to insert : ");
	scanf("%d", &insertBefore);
	
	printf("\nEnter value you want add : ");
	scanf("%d" , &value);
	ptr = start;
	
	while(ptr->data != insertBefore) {
		prepointer = ptr;
		ptr = ptr->next;
	}
		newNode = (node *)malloc(sizeof(node));
		newNode->data = value;
		prepointer->next = newNode;
		newNode->next = ptr;		
	return start;
}

node *insertAfter(node * start) {
	node *newNode, *ptr, *prepointer;
	int value , insertAfter;
	
	printf("\nEnter the value After you want to insert : ");
	scanf("%d", &insertAfter);
	printf("\nEnter value you want add : ");
	scanf("%d" , &value);
	ptr = start;
	prepointer = ptr;
	
	while(prepointer->data != insertAfter) {
		prepointer = ptr;
		ptr = ptr->next;
	}
	
	newNode = (node *)malloc(sizeof(node));
	newNode->data = value;
	prepointer->next = newNode;
	newNode->next = ptr;		
	return start;
}

node *deleteBegining(node *start) {
	int value;
	node *ptr;
	value = start->data;
	ptr = start;
	start = start->next;
	printf("\nValue deleted is : %d " , value);
	free(ptr);	
	return start;
}

node *deleteEnd(node *start) {
	node *ptr , *prepointer;
	ptr = start;
	while(ptr->next != NULL) {
		prepointer = ptr;
		ptr = ptr->next;
	}
	prepointer->next = NULL;
	free(ptr);
	return start;
}

node *deleteAfter(node *start) {
	node *ptr, *prepointer;
	int value;
	
	printf("\nEnter the value after which you want to delete : ");
	scanf("%d" , &value);
	
	ptr = prepointer = start;
	while(prepointer->data != value) {
		prepointer = ptr;
		ptr = ptr->next;
	}
	prepointer->next = ptr->next;
	free(ptr);
	return start;
}

node *deleteList(node *start) {
	node *ptr;
	if(start != NULL) {
		ptr = start;
		while(ptr != NULL) {
			printf("\n %d is to be deleted next " , ptr->data);
			start = deleteBegining(ptr);
			ptr = start;
		}
	}
	return start;
}

node *deleteNode(node *start) {
	node *ptr,*prepointer;
	int value;
	
	printf("\nEnter the value to be deleted : ");
	scanf("%d" , &value);
	
	ptr = prepointer = start;
	if(ptr->data == value) {
		start = deleteBegining(start);
		return start;
	} else {
			while(ptr->data != value) {
				prepointer = ptr;
				ptr = ptr->next;
		}
		prepointer->next = ptr->next;
		free(ptr);
		return start;
	}

}

node *display(node * start) {
	node *ptr;
	ptr = start;
	printf("\n");
	while(ptr != NULL) {
		printf(" %d \t" , ptr->data);
		ptr = ptr->next;
	}
	return start;
}

node *sortList(node *start) {
	node *ptr1,*ptr2;
	int temp;
	
	ptr1 = start;
	while(ptr1->next != NULL) {
		ptr2 = ptr1->next;
		while(ptr2 != NULL) {
			if(ptr1->data > ptr2->data) {
				temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp;
			}
			ptr2 = ptr2->next;
		}
		ptr1 = ptr1->next;
	} 
	return start;
}

void main() {
	int option;
	do {
		printf("\n\n***********MENU************");
		printf("\n 1. Create a List");
		printf("\n 2. Display List");
		printf("\n 3. Add node at the begining");
		printf("\n 4. Add a node at the end");
		printf("\n 5. Add node before a given node");
		printf("\n 6. add node after a given node");
		printf("\n 7. Delete a node from the begining");
		printf("\n 8. Delete a node from the end");
		printf("\n 9. Delete a given node");
		printf("\n 10. Delete a node after a given node");
		printf("\n 11. Delete the entire List");
		printf("\n 12. Sort the List");
		printf("\n 13. Exit");
		printf("\n\n Enter your option : ");
		scanf("%d", &option);
		switch(option) {
			case 1:
				start = createLinkedList(start);
				printf("\nLinked List Created");
			break;
			case 2:
				start = display(start);
			break;
			case 3:
				start = insertBegining(start);
			break;
			case 4:
				start = insertEnd(start);
			break;
			case 5:
				start = insertBefore(start);
			break;
			case 6:
				start = insertAfter(start);
			break;
			case 7:
				start = deleteBegining(start);
			break;
			case 8:
				start = deleteEnd(start);
			break;
			case 9:
				start = deleteNode(start);
			break;
			case 10:
				start = deleteAfter(start);
			break;
			case 11:
				start = deleteList(start);
			break;
			case 12:
				start = sortList(start);
			break;
		}
	} while(option != 13);
	return ;
}
