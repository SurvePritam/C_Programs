#include<stdio.h>
#include<malloc.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

void insert_at_first(struct node ** , struct node ** , int);
void insert_at_last(struct node ** , struct node ** , int);
void insert_at_position(struct node ** , struct node ** , int , int);

int delete_at_first(struct node ** , struct node **);
int delete_at_last(struct node ** , struct node **);
int delete_at_position(struct node **, struct node ** , int);

int search_first_occurence(struct node * , struct node * , int);
int search_last_occurence(struct node * , struct node * , int);
int search_all_occurences(struct node * , struct node * , int);

int count_node(struct node * , struct node *);

void reverse_list(struct node ** , struct node **);
void reverse_display(struct node * , struct node *);

void concat_list(struct node ** , struct node ** , struct node ** , struct node **);
void concat_at_position(struct node ** , struct node ** , struct node ** , struct node ** , int);

void display(struct node * , struct node *);
void delete_all(struct node ** , struct node **);

int main(void)
{
	struct node *first = NULL , *second= NULL , *last2 = NULL;																								// MAIN FUNCTION
	struct node *last = NULL;

	insert_at_last(&first , &last , 10);
	insert_at_last(&first , &last , 20);
	insert_at_last(&first , &last , 30);
	insert_at_last(&first , &last , 40);
	insert_at_last(&first , &last , 50);
	insert_at_last(&first , &last , 60);

	display(first , last);
	
	
	printf("\n Deleted Data at pos 2 : %d \n", delete_at_position(&first , &last , 3));
	display(first , last);

	return 0;
}

void insert_at_first(struct node **head , struct node **tail , int no)
{
	struct node *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode == NULL)
	{
		printf("Memory Allocation Failed");
		return ;
	}

	newnode->data = no;
	if(*head==NULL)
	{
		*head = newnode;
		*tail = newnode;
	}
	else
	{
		newnode->next = *head ; 
		*head = newnode;
	}
	(*head)->prev = *tail;
	(*tail)->next = *head ;

}

void insert_at_last(struct node **head , struct node **tail , int no)
{
	struct node *newnode = NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return ;
	}
	
	newnode->data = no;

	if(*head==NULL)
	{
		*head = newnode;
		*tail = newnode;
		(*head)->prev = *tail;
		(*tail)->next = *head;
		return ;
	}
	
	(*tail)->next = newnode;
	newnode->prev = *tail;

	*tail = newnode ;
	
	(*tail)->next = *head;
	(*head)->prev = *tail;
	
}

void insert_at_position(struct node **head , struct node **tail , int no , int pos)
{
	int count;
	struct node *newnode = NULL , *temp = NULL;

	count = count_node(*head , *tail);
	
	if(pos<=0 || pos > count+1)
	{
		printf("\nInvalid Position\n");
		return ;
	}

	if(pos==1)
	{
		insert_at_first(head , tail , no);
		return ;
	}

	if(pos==count+1)
	{
		insert_at_last(head , tail ,no);
		return ;
	}
	
	newnode = (struct node *) malloc (sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return ;
	}
	newnode->data = no;
	temp = *head ;
	count = 1;
	while(count<pos-1)
	{
		count++ ;
		temp = temp->next;
	}
	newnode->next=temp->next;
	newnode->prev = temp;
	temp->next = newnode;
}

int count_node(struct node *head , struct node *tail)
{
	int count = 0;
	
	if(head==NULL)
		return 0;

	do
	{
		count++;
		head = head->next;

	}while(head!=(tail)->next);

	return count;
}
void display(struct node *head , struct node *tail)
{
	if(head==NULL)
	{
		printf(" Linked List is Empty\n");
		return ;
	}
	do
	{
		printf("|%d|->" , head->data);
		head = head->next;

	}while(head!=tail->next);

}

int delete_at_first(struct node **head , struct node **tail)
{
	int del_data ;
	if(*head==NULL)
		return -1 ;
	
	del_data = (*head)->data;

	if( *head==*tail )
	{
		(*head)->prev = NULL;
		(*head)->next = NULL;
		free(*head);
		*head = *tail = NULL;
		return del_data;
	}
	*head = (*head)->next;
	(*tail)->next->next = NULL;
	(*tail)->next->prev = NULL;
	free((*tail)->next);

	(*head)->prev = *tail;
	(*tail)->next = *head ;

	return del_data;
}

int delete_at_last(struct node **head , struct node **tail)
{
	int del_data;
	if(*head==NULL)
		return -1;

	del_data = (*tail)->data;

	if(*head==*tail)
	{
		(*tail)->prev = (*tail)->next = NULL;
		free(*tail);
		*head = *tail = NULL;
		return del_data;
	}

	(*tail)->next = NULL;
	*tail = (*tail)->prev;
	(*tail)->next->prev = NULL;
	free((*tail)->next);

	(*tail)->next = *head;
	(*head)->prev = *tail;
	return del_data;;

}

int delete_at_position(struct node **head , struct node **tail , int pos)
{
	int del_data;
	struct node *temp = NULL;
	if(*head==NULL)
		return -1;
	del_data = count_node(*head , *tail);

	if(pos<=0 || pos > del_data)
	{
		printf("\nInvalid Position\n");
		return -1;
	}
	
	if(pos==1)
		return delete_at_first(head , tail);
	if(pos==del_data)
		return delete_at_last(head , tail);

	temp = *head ;
	del_data = 1;
	while(del_data < pos)
	{
		del_data++;
		temp = temp->next;
	}
	
	del_data = temp->data;
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	temp = NULL;
	return del_data;
}

int search_first_occurence(struct node *head , struct node *tail , int no)
{
	int pos = 0;
	if(head==NULL)
		return 0;
	do
	{
		pos++;

		if(head->data == no)
			break;

		head = head->next;

	}while(head!=tail->next);

	if(head==tail->next)
		pos=0;

	return pos;
}

int search_last_occurence(struct node *head , struct node *tail , int no)
{
	int pos = 0 , count = 0;
	if(head==NULL)
		return pos;
	do
	{
		count ++;
		if(head->data==no)
			pos = count;
		head = head->next;
	}while(head!=tail->next);

	return pos;
}

int search_all_occurences(struct node *head , struct node *tail , int no)
{
	int count = 0;
	if(head==NULL)
		return count;
	do
	{
		if(head->data==no)
			count++;

		head = head->next;
	}while(head!=tail->next);

	return count;
}

void reverse_list(struct node **head , struct node **tail)
{
	struct node *current=NULL , *next = NULL;
	
	if(*head==NULL)
		return;

	current = *head ;
	do
	{
		next = current->next;
		current->next = current->prev;
		current->prev = next;
		
		if(*head == next)
		{
			*head = current;
			*tail = next;
			 next = NULL;
		}

		current = next ;

	}while(next!=NULL);

}

void reverse_display(struct node *head , struct node *tail)
{
	if(head==NULL)
		return;
	
	head = tail;

	do
	{
		printf("|%d|->", head->data);
		head = head->prev;
	}while(head!=tail);

}

void concat_list(struct node **head1 , struct node **tail1 , struct node **head2 , struct node **tail2)
{
	if(*head2==NULL)
		return;

	if(*head1==NULL)
	{
		*head1 = *head2;
		*tail1 = *tail2;
		*head2 = *tail2 = NULL;
		return;
	}

	(*tail1)->next = *head2;
	(*head2)->prev = *tail1;
	*tail1 = *tail2;

	(*head1)->prev = *tail1;
	(*tail1)->next = *head1;
	
	*head2 = *tail2 = NULL;
}

void concat_at_position(struct node **head1 , struct node **tail1 , struct node **head2 , struct node **tail2 , int pos)
{
	int count;
	struct node *temp = NULL;
	if(*head2==NULL)
		return ;
	count = count_node(*head1 , *tail1);
	
	if(pos<=0 || pos>count+1)
	{
		printf("\nInvalid Position\n");
		return ;
	}

	if(pos==1)
	{
		concat_list(head2 , tail2 , head1 , tail1);
		*head1 = *head2;
		*tail1 = *tail2;
		*head2 = *tail2 = NULL;
		return;
	}

	if(pos==count+1)
	{
		concat_list(head1 , tail1 , head2 , tail2);
		return ;
	}

	count = 1;
	temp = *head1;
	while(count<pos-1)
	{
		count++;
		temp = temp->next;
	}

	(*tail2)->next = temp->next;
	temp->next->prev = *tail2;

	temp->next = *head2;
	(*head2)->prev = temp;

	*tail2 = *head2 = NULL;
}


void delete_all(struct node **head , struct node **tail)
{
	struct node *temp = NULL;

	if(head==NULL)
		return;

	temp = *head ;
	do
	{
		*head = temp->next;

		if(*tail == temp)
			*head= *tail = NULL;

		temp->prev = NULL;
		temp->next = NULL;
		free(temp);

		temp = *head;

	}while(temp!=NULL);
}