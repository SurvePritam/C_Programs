#include<stdio.h>
#include<malloc.h>

struct node
{
	int data;
	struct node *next;
};

void insert_first(struct node **,struct node ** , int);
void insert_last(struct node ** , struct node ** , int);
void insert_at_position(struct node ** , struct node ** , int , int);

int delete_first(struct node ** , struct node **);
int delete_last(struct node ** , struct node **);
int delete_at_position(struct node ** , struct node ** , int);

int search_first_occure(struct node * , struct node * , int);
int search_last_occure(struct node * , struct node * , int);
int search_all_occure(struct node * , struct node * , int);

int count_node(struct node * , struct node *);

void reverse_list(struct node ** , struct node **);
void reverse_display(struct node * , struct node *);

void concat_list(struct node ** , struct node ** ,struct node ** , struct node ** );
void concat_at_position(struct node ** , struct node ** ,struct node ** , struct node ** , int );

void display(struct node * , struct node *);
void delete_all(struct node ** , struct node **);

int main(void)
{																											// MAIN FUNCTION HERE
	struct node *first=NULL ;
	struct node *last=NULL ;

	insert_first(&first , &last , 30);
	insert_first(&first , &last , 20);
	insert_first(&first , &last , 10);

	display(first , last);

	delete_all(&first , &last);

	display(first , last);

	return 0;
}

void insert_first(struct node **head ,struct node **tail , int no)
{
	struct node *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	
	if(newnode==NULL)
	{
		printf("Memory Allocation FAILED");
		return ;
	}
	
	newnode->data = no;
	if(*head==NULL)
	{
		*head = newnode ;
		*tail = newnode ;
		(*tail)->next = *head ;
		return ;
	}
	
	newnode->next = *head;
	*head = newnode;
	(*tail)->next = *head ;

}

void insert_last(struct node **head , struct node **tail , int no)
{
	struct node *newnode=NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation FAILED");
		return ;
	}
	newnode->data=no;

	if(*head==NULL)
		*head=newnode;
	else
		(*tail)->next=newnode;

	*tail = newnode;
	(*tail)->next = *head;
}

void insert_at_position(struct node **head , struct node **tail , int no , int pos)
{
	int count = 0;
	struct node *newnode=NULL , *temp=NULL ;
	count = count_node(*head , *tail);
	if(pos<=0 || pos >count+1)
	{
		printf("\nInvalid Position\n");
		return ;
	}
	if(pos==1)
	{
		insert_first(head , tail , no);
		return ;
	}

	if(pos==count+1)
	{
		insert_last(head , tail , no);
		return ;
	}
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation FAILED");
		return ;
	}
	newnode->data=no;
	temp=*head;
	count = 1;
	while(count<pos-1)
	{
		count++;
		temp = temp->next;
	}
	newnode->next = temp->next;
	temp->next = newnode;

}

int delete_first(struct node **head , struct node **tail)
{
	int del_data;
	if(*head==NULL)
		return -1;
	del_data = (*head)->data;
	if(*head==*tail)
	{
		(*head)->next = NULL;
		free(*head);
		*head = *tail = NULL;
		return del_data;
	}
	
	*head = (*head)->next;
	(*tail)->next->next = NULL;
	free((*tail)->next);
	(*tail)->next = *head;
	return del_data;

}

int delete_last(struct node **head , struct node **tail)
{
	int del_data;
	struct node *temp = NULL;
	if(*head==NULL)
		return -1;
	del_data = (*tail)->data;

	if(*head==*tail)
	{
		(*tail)->next = NULL;
		free(*tail);	
		*tail = *head = NULL;
		return del_data;
	}

	temp = *head;
	while(temp->next!=*tail)
		temp = temp->next;

	(*tail)->next = NULL;
	free(*tail);
	*tail = temp;
	(*tail)->next = *head ;
	return del_data;

}

int delete_at_position(struct node **head , struct node **tail , int pos)
{
	int count;
	struct node *temp1 = NULL , *temp2 = NULL;
	count = count_node(*head , *tail);
	if(pos <= 0 || pos > count)
	{
		printf("\nInvalid Position\n");
		return -1;
	}
	if(*head==NULL)
		return -1;
	if(pos==1)
		return delete_first(head , tail);
	if(pos==count)
		return delete_last(head , tail);
	
	temp1 = *head;
	count= 1;
	while(count<pos-1)
	{
		count++;
		temp1 = temp1->next;
	}
	temp2 = temp1->next;
	count = temp2->data;
	temp1->next = temp2->next;
	temp2->next = NULL;
	free(temp2);
	temp1=temp2=NULL;
	return count;

}


int search_first_occure(struct node *head , struct node *tail , int no)
{
	int pos = 0;
	do
	{
		pos++;
		if(head->data == no)
			return pos;
		head = head->next;
			
	}while(head!=tail->next);

	pos = 0;
	return pos;

}
int search_last_occure(struct node *head , struct node *tail , int no)
{
	int pos=0 , count=0;

	do
	{
		pos++;
		if(head->data == no)
			count = pos;
		head = head->next;

	}while(head!=tail->next);

	return count;

}
int search_all_occure(struct node *head , struct node *tail , int no)
{
	int count = 0;

	do
	{
		if(head->data == no)
			count++;
		head = head->next ;

	}while(head!=tail->next);

	return count;
}

void reverse_list(struct node **head , struct node **tail)
{
	struct node *prev=NULL , *next=NULL , *current=NULL ;

	current = *head ;
	prev = *tail ;

	do
	{
		next = current->next ;
		current->next = prev ;
		prev = current ;
		current = next ;
	}while(prev!=*tail) ;

	*head = prev;
	*tail = current;
}

void reverse_display(struct node *head , struct node *tail)
{
	reverse_list(&head , &tail);
	do
	{
		printf("|%d|->" , head->data);
		head = head->next;
	}while(head!=tail->next);

	reverse_list(&head , &tail);

}

void concat_list(struct node **head1 , struct node **tail1 ,struct node **head2 , struct node **tail2)
{
	if(*head2==NULL)
		return ;
	if(*head1==NULL)
	{
		*head1 = *head2 ;
		*tail1 = *tail2 ;
		*tail2 = *head2 = NULL;
		return ;
	}

	(*tail1)->next = *head2 ;
	*tail1 = *tail2 ;
	*head2 = *tail2 = NULL;
	(*tail1)->next = *head1;

}

void concat_at_position(struct node **head1 , struct node **tail1 ,struct node **head2 , struct node **tail2 , int pos )
{
	int count;
	struct node *temp = NULL;
	count = count_node(*head1 , *tail1);
	if(pos<=0 || pos >count+1)
	{
		printf("\nInvalid Position\n");
		return ;
	}

	if(pos==1)
	{
		concat_list(head2 , tail2 , head1 , tail1);
		*head1 = *head2 ;
		*tail1 = *tail2 ;
		*head2 = *tail2 = NULL;
		return ;
	}

	if(pos == count+1)
	{
		concat_list(head1 , tail1 , head2 , tail2);
		return ;
	}

	count = 1;
	temp = *head1 ;
	while(count<pos-1)
	{
		count++;
		temp = temp->next;
	}
	(*tail2)->next = temp->next;
	temp->next = *head2 ;
	*head2 = *tail2 = NULL;
}

int count_node(struct node *head , struct node *tail)
{
	int count= 0;

	if(head==NULL)
		return 0;

	do
	{
		count++;
		head = head->next;

	}while(head!=tail->next);

	return count;
}

void display(struct node *head , struct node *tail)
{
	if(head==NULL)
	{
		printf("Linked List Is Empty\n");
		return ;
	}
	do
	{
		printf("|%d|->", head->data);
		head = head->next;

	}while(head!=tail->next);

}


void delete_all(struct node **head , struct node **tail)
{
	
	struct node *temp = NULL;
	temp = *head ;

	if(*head==NULL)
		return ;
	do
	{
		*head = temp->next;

		if(temp==*tail)
			*tail=*head=NULL;

		temp->next = NULL;
		free(temp);
		temp = *head ;

	}while(temp!=NULL);
}
