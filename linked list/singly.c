/*
|-----------------------|		
| Single linked list    |
| Author : Azarudeen A  |
|-----------------------|
*/
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
	int data;
	struct ListNode *next;
};

struct ListNode *head = NULL;

void insertBegining(struct ListNode **head, int data)
{
	struct ListNode *newnode = (struct ListNode*) malloc(sizeof(struct ListNode));
	newnode->data = data;
    newnode->next = *head;
    *head = newnode;	
}

void view(struct ListNode *head)
{
	struct ListNode *curr = head;
	if(curr == NULL)
	{
		printf("List Empty!");
		return;
	}
	while(curr != NULL)
	{
		printf("%d ", curr->data);
		curr = curr->next;
	}
}


void insertAtEnd(struct ListNode **head, int data)
{
	struct ListNode *temp = (struct ListNode*) malloc(sizeof(struct ListNode));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL)
		*head = temp;
	else
	{
		struct ListNode *curr;
		curr = *head;
		while(curr->next != NULL)
			curr = curr->next;
		curr->next = temp;	
	}
}

void insertAtPosition(struct ListNode **head, int data)
{
	int pos;
	printf("Position [0 - index based]: ");
	scanf("%d", &pos);
	struct ListNode *pred = *head;
	struct ListNode *newnode = (struct ListNode*) malloc(sizeof(struct ListNode));
	newnode->data = data;
	if(pos<=0)
	{
		newnode->next = *head;
		*head = newnode;
		return;
	}
	else
	{
		while(--pos && pred != NULL)
			pred = pred->next;
		if(pred == NULL)
		{
			printf("position invalid!\n");
			return;
		}
		newnode->next = pred->next;
		pred->next = newnode;
	}
}

int deleteFirst(struct ListNode **head)
{
	
	if(*head == NULL)
	{
		return 0;
	}
	struct ListNode *temp = *head;
	*head = (*head)->next;
	return temp->data;
	
}

int deleteLast(struct ListNode **head)
{
	if(*head == NULL)
	{
		return 0;
	}
	struct ListNode *temp = NULL, *curr = *head;
	while(curr->next)
	{
		temp = curr;
		curr = curr->next;
	}
	int data = curr->data;
	if(temp)
	{
		temp->next = NULL;
	}
	else *head = NULL;
	free(curr);
	return data;
}

int deletePosition(struct ListNode **head)
{
	int pos;
	printf("Position [0 - index based]: ");
	scanf("%d", &pos);
	struct ListNode *pred = *head, *temp = NULL;
	if(*head == NULL)
	{
		return 0;
	}
	if(pos == 0)
	{
		int data = (*head)->data;
		*head = (*head)->next;
		free(pred);
		return data;
	}
	else
	{
		int k = 0;
		while(pred && k < pos-1)
		{
			k++;
			temp = pred;
			pred = pred->next;
		}
		if(pred == NULL || pred->next == NULL)
		{
			printf("position doesn't exist!\n");
			return 0;
		}
		temp = pred->next;
		pred->next = temp->next;
		int data = temp->data;
		free(temp);
		return data;
	}
}


void deleteList(struct ListNode **head)
{
	struct ListNode *auxilaryNode, *iterator = *head;
	while(iterator)
	{
		auxilaryNode = iterator->next;
		free(iterator);
		iterator = auxilaryNode;
	}
	*head = NULL;
	printf("List deleted!\n");
}

int main()
{
	do
	{
		printf("\n1.insert begining\n2.view\n3.insert at end\n4.insert and position\n5.delete first\n6.delete last\n7.delete position\n8.delete list\n");
		int n;
		printf("Choice: ");
		scanf("%d", &n);
		if(n == -1) break;
		int data;
		switch(n)
		{
			case 1:
				printf("Data: ");
				scanf("%d",&data);
				insertBegining(&head,data);
				break;
			case 2:
				view(head);
				break;
			case 3:
				printf("Data: ");
				scanf("%d",&data);
				insertAtEnd(&head,data);
				break;
			case 4:
				printf("Data: ");
				scanf("%d",&data);
				insertAtPosition(&head,data);
				break;
			case 5:
				printf("%d deleted from list!",deleteFirst(&head));
				break;
			case 6:
				printf("%d deleted from list!",deleteLast(&head));
				break;
			case 7:
				printf("%d deleted from list!",deletePosition(&head));
				break;
			case 8:
				deleteList(&head);
				break;
		}
	}while(1);
	return 0;
}
