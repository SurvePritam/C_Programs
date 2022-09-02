#include<stdio.h>
#include<malloc.h>

struct node 
{
	int data;
	struct node *next;
};

void insert_first(struct node ** , int);
void insert_last(struct node ** , int);
void insert_at_position(struct node ** , int , int);
int  delete_first(struct node **);
int  delete_last(struct node **);
int  delete_at_position(struct node **, int);
int  search_first_occurence(struct node * , int );
int  search_last_occurence(struct node * , int );
int  search_all_occurences(struct node * , int );
int count_node(struct node *);
void physical_reverse(struct node **);
void reverse_display(struct node *);
void concat_list(struct node ** , struct node **);
void concat_at_position(struct node ** , struct node ** , int);
void display(struct node *);

int main(void)
{
	int no;
	struct node *first=NULL;
	struct node *second=NULL;
	
	 insert_first(&first , 20);
	 insert_first(&first , 10);
	 insert_first(&first , 10);
	 insert_last(&first , 30);
	 insert_last(&first , 40);
	 insert_at_position(&first , 50 , 6);
	 insert_at_position(&first , 50 , 7);
	 insert_at_position(&first , 50 , 8);
	
	 insert_first(&second , 11);
	 insert_first(&second , 22);

	 printf("Linked List 1: \n");
	 display(first);
	 printf("\nLinked List 2: \n");
	 display(second);

	 printf("\nDeleted Data : |%d| After Deleting First Node Linkedkist : \n" , delete_first(&first));
	 display(first);
	 
	 printf("\nDeleted Data : |%d| After Deleting Last Node Linkedkist : \n" ,delete_last(&first));
	 display(first);

	 printf("\nDeleted Data : |%d| After Deleting Pos 2 Node Linkedkist : \n" ,delete_at_position(&first , 2));
	 display(first);

	 printf("\nFirst Occurence Of 50 Is At Pos : %d \n" ,search_first_occurence(first , 50) );
	 printf("\nLast Occurence Of 50 Is At Pos : %d \n" ,search_last_occurence(first , 50) );
	 printf("\nTotal Occurence Of 50 Are : %d \n" ,search_all_occurences(first , 50) );
	 
	
	 physical_reverse(&first);
	 printf("\nAfter Reversing The List : \n");
	 display(first);
	 printf("\nPrinting The Reversed List : \n");
	 reverse_display(first);
	 
	 concat_list(&first , &second);
	 printf("\nAfter Concatination \nList 1 :  ");
	 display(first);
	 printf("\nList 2 :  ");
	 display(second);

	 concat_at_position(&first , &second , 2);
	 printf("\nAfter Concatination Of Second List To First At Pos 2 : \nList 1 :  ");
	 display(first);
	 printf("\nList 2 :  ");
	 display(second);

	return 0;
}
void insert_first(struct node **head , int no)
{
	struct node *newnode = NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return;
	}
	newnode->data=no;
	newnode->next=*head;
	*head=newnode;
}

void insert_last(struct node **head , int no)
{
	struct node *newnode=NULL  , *temp=NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return;
	}
	newnode->data=no;
	newnode->next=NULL;
	if(*head==NULL)
	{
		*head=newnode;
		return;
	}
	temp=*head;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newnode;

}


void insert_at_position(struct node **head , int no, int pos)
{
	int count;
	struct node *newnode=NULL , *temp=NULL ;

	count=count_node(*head);

	if(pos<=0||pos>count+1)
	{
		printf("Invalid Position");
		return ;
	}
	if(pos==1)
	{
		insert_first(head , no);
		return ;
	}

	/*if(pos==count+1)
	{
		insert_last(head , no);
		return ;
	}*/

	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return;
	}
	newnode->data=no;
	count = 1 ;
	temp = *head;
	while(count < pos -1)
	{
		count++;
		temp = temp->next ;
	}
	newnode->next = temp ->next;
	temp->next=newnode;
}


int  delete_first(struct node **head)
{
	int del_data;
	struct node *temp = NULL;
	if(*head==NULL)
		return -1;
	
	/*if((*head)->next==NULL)
	{
		del_data = (*head)->data ;
		free(*head);
		*head = NULL;
		return del_data;
	}*/

	temp = *head;
	*head = temp->next ;
	temp->next = NULL;
	del_data = temp->data ;
	free(temp);
	temp = NULL;
	return del_data;
}
int  delete_last(struct node **head)
{
	int del_data;
	struct node *temp = NULL ;

	if(*head==NULL)
		return -1; 

	if((*head)->next==NULL)
	{
		del_data = (*head)->data ;
		free(*head);
		*head = NULL;
		return del_data;
	}

	temp = *head ;
	while(temp->next->next != NULL)
		temp = temp->next;

	del_data = temp->next->data;
	free(temp->next);
	temp->next = NULL ;
	temp = NULL;
	return del_data ;
}


int  delete_at_position(struct node **head, int pos)
{
	int count ;
	struct node *temp=NULL , *temp2=NULL;
	count = count_node(*head);
	if(pos<=0 || pos > count )
	{
		printf("Invalid Position");
		return ;
	}

	if(pos==1)
		return delete_first(head);

	if(pos==count)
		return delete_last(head);

	count = 1;
	temp = *head ;
	while(count < pos -1)
	{
		count++;
		temp = temp->next ;
	}

	temp2=temp->next;
	temp->next = temp2->next;
	count = temp2->data ;
	temp2->next = NULL;
	free(temp2);
	temp=temp2=NULL;
	return count;
}

int  search_first_occurence(struct node *head , int no )
{
	int pos = 0;
	while(head!=NULL)
	{
		pos++;
		if(head->data==no)
			break ;
		head = head->next ;
	}
	if(head==NULL)
		pos=0;
	return pos;

}

int  search_last_occurence(struct node *head , int no )
{
	int count = 0 , pos = 0;
	while(head!=NULL)
	{
		count++;
		if(head->data==no)
			pos = count;
		head = head->next ;
	}
	return pos ;
}
int  search_all_occurences(struct node *head , int no )
{
	int count = 0;
	while(head!=NULL)
	{
		if(head->data==no)
			count++;
		head = head->next ;
	}
	return count ;
}

int count_node(struct node *head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head = head->next ;
	}
	return count;
}
void physical_reverse(struct node **head)
{
	struct node *prev=NULL , *next=NULL , *current=*head ;
	
	while(current!=NULL)
	{
		next = current->next;
		current->next=prev;
		prev = current;
		current = next ;
	}
	*head = prev;
	prev=NULL;
}
void reverse_display(struct node *head)
{
	if(head==NULL)
	{
		printf("List Is Empty");
		return ;
	}
	physical_reverse(&head);
	display(head);
	physical_reverse(&head);

}
void concat_list(struct node **head1 , struct node **head2)
{
	struct node *temp = NULL;
	if(*head2==NULL)
		return ;

	if(*head1==NULL)
	{
		*head1 = *head2 ;
		*head2 = NULL;
		 return ;
	}
	
	temp = *head1 ;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next = *head2;
	*head2=NULL;

}
void concat_at_position(struct node **head1 , struct node **head2 , int pos)
{
	int count ;
	struct node *temp=NULL , *temp2=NULL;
	
	count=count_node(*head1);
	if(pos<=0||pos>count+1)
	{
		printf("Invalid Position");
		return ;
	}

	if(*head2==NULL)
		{
			*head1 = *head2 ;
			*head2 = NULL;
			return ;
		}
	if(pos==1)
	{
		concat_list(head2 , head1 );
		*head1=*head2;
		*head2=NULL;
		return ;
	}
	if(pos==count+1)
	{
		concat_list(head1 , head2);
		return ;
	}
	temp=*head1;
	count=1;
	while(count<pos-1)
	{
		count++ ;
		temp=temp->next;
	}

	temp2=*head2;
	while(temp2->next!=NULL)
		temp2=temp2->next;
	temp2->next=temp->next;
	temp->next=*head2;
	*head2=NULL;

}
void display(struct node *head)
{
	if(head==NULL)
	{
		printf("Linked List Is Empty \n");
	}
	while(head!=NULL)
	{
		printf("|%d|->" , head->data);
		head=head->next;
	}
}

