#include<stdio.h>
#include<malloc.h>

struct node 
{
	struct node *prev;
	int data;
	struct node *next;
};

void insert_at_first(struct node ** , int );
void insert_at_last(struct node ** , int );
void insert_at_position(struct node ** , int , int);

int count_node(struct node *);
void display(struct node *);


int delete_at_first(struct node **);
int delete_at_last(struct node **);
int delete_at_position(struct node ** , int);

int search_first_occurence(struct node * , int );
int search_last_occurence(struct node * , int);
int search_all_occurences(struct node * , int);

void physical_reverse(struct node **);
void reverse_display(struct node *);

void concat_list(struct node ** , struct node **);
void concat_at_position(struct node ** , struct node ** , int);

void delete_all(struct node **);
int main(void)
{
	int no , pos ;
	struct node *first=NULL;
	struct node *second=NULL;

	insert_at_first(&first , 30);
	insert_at_first(&first , 20);
	insert_at_first(&first , 10);
	insert_at_first(&second , 50);
	insert_at_first(&second , 40);

	printf("\nBefore Concat\nList 1 : ");
	display(first);
	printf("\nList 2 : ");
	display(second);

	delete_all(&first);

	printf("\nAfter concat\nList 1 : ");
	display(first);
	printf("\nList 2 : ");
	display(second);

	return 0;
}


void delete_all(struct node **head)
{
	struct node *temp = NULL;
	temp = *head ;

	while(temp!=NULL)
	{
		*head = temp->next;
		temp->next = NULL;
		temp->prev = NULL;
		free(temp);
		temp = *head ;
	}

}


void insert_at_first(struct node **head , int no)
{
	struct node *newnode=NULL;
	newnode= (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation FAILED");
		return;
	}

	newnode->data=no;
	newnode->prev=NULL;
	if(*head==NULL)
	{
		newnode->next=NULL;
		*head=newnode;
		return;
	}
	 newnode->next=*head;
	 (*head)->prev = newnode;
	 *head=newnode;
}

void insert_at_last(struct node **head , int no)
{
	struct node *newnode=NULL	, *temp = NULL;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return ;
	}
	newnode->next=NULL;
	newnode->data=no;
	if(*head==NULL)
	{
		newnode->prev=NULL;
		*head = newnode;
		return ;
	}

	temp = *head;
	while(temp->next!=NULL)
		temp = temp->next;

	newnode->prev=temp;
	temp->next=newnode;
}

void insert_at_position(struct node **head , int no , int pos)
{
	int count;
	struct node *newnode=NULL , *temp=NULL;
	count = count_node(*head);
	if(pos<=0 || pos > count+1)
	{
		printf("\nInvalid Position\n");
		return ;
	}
	if(pos==1)
	{
		insert_at_first(head , no);
		return;
	}
	if(pos==count+1)
	{
		insert_at_last(head , no);
		return;
	}
	count = 1;
	temp = *head ;
	while(count<pos-1)
	{
		count++;
		temp = temp->next;
	}
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return ;
	}
	newnode->data=no;
	newnode->prev=temp;
	newnode->next=temp->next;
	temp->next->prev=newnode;
	temp->next=newnode;
}
int count_node(struct node *head)
{
	int count = 0;
	while(head!=NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

void display(struct node *head)
{
	if(head==NULL)
	{
		printf("Linked List Is Empty\n");
		return ;
	}
	while(head!=NULL)
	{
		printf("|%d|->" , head->data);
		head = head->next;
	}
}

int delete_at_first(struct node **head)
{
	int del_data;
	if(*head==NULL)
		return -1;

	if((*head)->next==NULL)
	{
		del_data = (*head)->data;
		free(*head);
		*head=NULL;
		return del_data;
	}

	del_data = (*head)->data;
	*head = (*head)->next;
	(*head)->prev->next=NULL;
	free((*head)->prev);
	(*head)->prev=NULL;
	return del_data;
}

int delete_at_last(struct node **head)
{
	int del_data;
	struct node *temp=NULL;
	if(*head==NULL)
		return -1;
	if((*head)->next==NULL)
	{
		del_data = (*head)->data;
		free(*head);
		*head=NULL;
		return del_data;
	}

	temp = *head;
	while(temp->next!=NULL)
		temp = temp->next;
	del_data = temp->data;
	temp->prev->next=NULL;
	temp->prev=NULL;
	free(temp);
	temp=NULL;
	return del_data;

}

int delete_at_position(struct node **head , int pos)
{
	int count;
	struct node *temp=NULL;
	if(*head==NULL)
		return -1;
	count = count_node(*head);
	if(pos<=0 || pos >count)
	{
		printf("\nInvalid Position\n");
		return -1 ;
	}
	
	if(pos==1)
		return delete_at_first(head);
	if(pos==count)
		return delete_at_last(head);

	temp = *head ;
	count = 1;
	while(count < pos)
	{
		count++;
		temp = temp->next;
	}
	
	count = temp->data;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	temp = NULL;
	return count;
}

int search_first_occurence(struct node *head , int no)
{
	int pos=0;
	while(head!=NULL)
	{
		pos++;
		if(head->data == no)
			break;
		head = head->next;
	}
	if(head==NULL)
		pos = 0;
	return pos ;
}

int search_last_occurence(struct node *head , int no)
{
	int pos = 0 , count = 0;
	while(head!=NULL)
	{
		pos++;
		if(head->data == no)
			count = pos;
		head = head->next ;
	}
	return count;
}

int search_all_occurences(struct node *head , int no)
{
	int count = 0 ; 
	while(head!=NULL)
	{
		if(head->data == no )
			count++;
		head = head->next ;
	}
	return count ;
}

void physical_reverse(struct node **head)
{
	struct node *current=NULL , *next=NULL;
	current = *head ;
	while(current!=NULL)
	{
		next = current->next ;
		current->next = current->prev ;
		current->prev = next ;
		if(next==NULL)
			*head = current ;
		current = next ;
	}

}

void reverse_display(struct node *head)
{
	while(head->next!=NULL)
		head = head->next;

	while(head!=NULL)
	{
		printf("|%d|->" , head->data);
		head = head->prev;
	}
}

void concat_list(struct node **head1 , struct node **head2 )
{
	struct node *temp=NULL;

	if(*head2==NULL)
		return;

	if(*head1==NULL)
	{
		*head1 = *head2;
		*head2 = NULL;
		return ;
	}
	temp = *head1;
	while(temp->next!=NULL)
		temp = temp->next ;

	temp->next = *head2;
	(*head2)->prev=temp;
	*head2=NULL;

}

void concat_at_position(struct node **head1 , struct node **head2 , int pos)
{
	int count;
	struct node *temp1=NULL , *temp2=NULL;
	count = count_node(*head1);
	if(pos<=0 || pos>count+1 )
	{
		printf("\nInvalid Position\n");
		return ;
	}
	if(*head2==NULL)
		return;

	if(pos==1)
	{
		concat_list(head2 , head1);
		*head1 = *head2;
		*head2 = NULL;
		return ;
	}

	if(pos==count+1)
	{
		concat_list(head1 , head2);
		return ;
	}

	count = 1;
	temp1 = *head1;
	while(count<pos-1)
	{
		temp1 = temp1->next;
		count++;
	}
	temp2 = *head2;
	while(temp2->next!=NULL)
		temp2 = temp2->next;
	
	temp2->next = temp1->next;
	temp1->next->prev = temp2;

	temp1->next = *head2;
	(*head2)->prev = temp1;
	*head2 = NULL;

}