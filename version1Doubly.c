#include<stdio.h>
#include<malloc.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

void insert_first(struct node ** , int);
void insert_last(struct node ** , int);
void insert_at_position(struct node ** , int , int);

int delete_first(struct node ** );
int delete_last(struct node ** );
int delete_at_position(struct node ** , int);

int search_first_occurence(struct node * , int);
int search_last_occurence(struct node * , int);
int search_all_occurences(struct node * , int);

int count_node(struct node *);

void physical_reverse(struct node **);
void reverse_display(struct node *);

void concat_list(struct node ** ,struct node **);
void concat_at_position(struct node ** ,struct node **, int);

void display(struct node *);
int main(void)
{
	
	struct node *first=NULL;
	struct node *second=NULL;

	insert_first(&first , 10);
	insert_first(&first , 20);
	insert_first(&first , 30);
	insert_first(&first , 40);
	insert_first(&second , 11);
	insert_first(&second , 22);
	insert_last(&first , 50);
	insert_at_position(&first , 20 , 2);
	insert_at_position(&first , 20 , 2);
	insert_at_position(&first , 20 , 2);
	printf("\nLinked List\n");
	display(first);

	printf("\nDeleted Data = %d \nLinked List After Deleting First Node : " , delete_first(&first));
	display(first);
	
	printf("\nDeleted Data = %d \nLinked List After Deleting Last Node : " ,delete_last(&first));
	display(first);
	
	printf("\nDeleted Data = %d \nLinked List After Deleting No. 2 Node : " ,delete_at_position(&first , 2));
	display(first);

	printf("\nFirst Occurenc of 20 : %d  \n " , search_first_occurence(first , 20));
	 printf("\nLast Occurenc of 20 : %d  \n " , search_last_occurence(first , 20));
	 printf("\nTotal Occurences of 20 : %d  \n " , search_all_occurences(first , 20));

	printf("\nTotal nodes : %d\n" , count_node(first));

	physical_reverse(&first);
	printf("\nReversed Linked List\n");
	display(first);
	printf("\nReversed Linked List Display\n");
	reverse_display(first);

	 printf("\nLinked List before Concatination\n	List 1 : ");
	 display(first);
	 printf("\n List 2 : ");
	 display(second);

	 concat_list(&first , &second);

	 printf("\nLinked List After Concatination\n	List 1 : ");
	 display(first);
	 printf("\n	List 2 : ");
	 display(second);

	  insert_first(&second , 55);
	 concat_at_position(&first , &second , 3);
	  printf("\nLinked List After Concatination	at pos 3\n List 1 : ");
	 display(first);
	  printf("\n List 2 : ");
	  display(second);

	return 0;
}
void insert_first(struct node **head , int no)
{
	struct node *newnode=NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return ;
	}
	newnode->data=no;
	newnode->prev=NULL; 
	 if(*head==NULL)
	 {
		 newnode->next=NULL;
		 *head = newnode;
		 return;
	 }
	 newnode->next = *head ;
	 (*head)->prev=newnode;
	 *head=newnode;
}

void insert_last(struct node **head , int no)
{
	struct node *newnode=NULL , *temp=NULL;
	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return ;
	}
	newnode->data=no;
	newnode->next=NULL;
	if(*head==NULL)
	{
		newnode->prev=NULL;
		*head=newnode;
		return;
	}
	temp=*head;
	while(temp->next!=NULL)
		temp=temp->next;
	newnode->prev=temp;
	temp->next=newnode;
}

void insert_at_position(struct node **head , int no, int pos)
{
	int count;
	struct node *newnode=NULL , *temp=NULL;
	count=count_node(*head);

	if(pos<=0||pos>count+1)
	{
		printf("\nInvalid Position \n");
		return;
	}
	if(pos==1)
	{
		insert_first(head , no);
		return;
	}

	if(pos==count+1)
	{
		insert_last(head , no);
		return ;
	}

	newnode = (struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("Memory Allocation Failed");
		return ;
	}
	newnode->data=no;
	temp=*head;
	count=1;
	while(count<pos-1)
	{
		temp = temp->next;
		count++;
	}
	temp->next->prev=newnode;
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->prev=temp;
}

int delete_first(struct node **head )
{
	int del_data ;
	if(*head==NULL)
		return -1;
	del_data=(*head)->data;
	if((*head)->next==NULL)
	{
		free(*head);
		*head=NULL;
		return;
	}
	else
	{
		*head = (*head)->next;
		(*head)->prev->next=NULL;
		free((*head)->prev);
		(*head)->prev=NULL;
	}
	return del_data;
}
int delete_last(struct node **head )
{
	int del_data;
	struct node *temp=NULL;

	if(*head==NULL)
		return -1 ;
	
	temp = *head ;
	while(temp->next!=NULL)
		temp=temp->next;

	del_data = temp->data ;
	if(temp->prev!=NULL)
	{
		temp->prev->next=NULL;
		temp->prev=NULL;
	}
	else
		*head=NULL;
	free(temp);
	temp=NULL;
	return del_data;

}
int delete_at_position(struct node **head , int pos)
{
	int count;
	struct node *temp=NULL;
	count= count_node(*head);
	if(pos<=0 || pos > count)
	{
		printf("\nInvalid Position\n");
		return -1;
	}
	if(pos==1)
		return delete_first(head);
	if(pos==count)
		return delete_last(head);
	count = 1;
	temp = *head;
	while(count < pos)
	{
		count++;
		temp=temp->next;
	}
	count = temp->data;
	temp->next->prev=temp->prev;
	temp->prev->next=temp->next;
	temp->prev = temp->next = NULL;
	free(temp);
	temp=NULL;
	return count ;
}

int search_first_occurence(struct node *head , int no)
{
	int pos = 0;
	while(head!=NULL)
	{
		pos++;
		if(head->data==no)
			break;
		head = head->next;
	}

	if(head==NULL)
		pos=0;
	return pos;
}
int search_last_occurence(struct node *head , int no)
{
	int pos=0 , count=0;
	while(head!=NULL)
	{
		count++;
		if(head->data==no)
			pos=count;
		head=head->next;
	}
	return pos;
}
int search_all_occurences(struct node *head , int no)
{
	int count = 0;
	while(head!=NULL)
	{
		if(head->data == no)
			count++;
		head = head ->next;
	}
	return count;
}

int count_node(struct node *head)
{
	int count=0;
	while(head!=NULL)
	{
		count++;
		head=head->next;
	}
	return count;
}

void physical_reverse(struct node **head)
{
	struct node *next=NULL , *current=NULL;
	current = *head;

	while(current!=NULL)
	{
		next = current->next;
		current->next=current->prev;
		current->prev=next;
		if(next==NULL)
			*head=current;
		current = next;
	}
}

void reverse_display(struct node *head)
{
	if(head==NULL)
	{
		printf("\nList Is Empty\n");
		return ;
	}
	while(head->next!=NULL)
		head=head->next;

	while(head!=NULL)
	{
		printf("|%d|->",head->data);
		head = head->prev;
	}
}

void concat_list(struct node **head1 ,struct node **head2)
{
	struct node *temp=NULL;
	if(*head2==NULL)
		return;
	if(*head1==NULL)
	{
		*head1=*head2;
		*head2=NULL;
		return;
	}
	temp = *head1;
	while(temp->next!=NULL)
		temp = temp->next;
	temp->next = *head2;
	(*head2)->prev = temp;
	*head2 = NULL ;
}
void concat_at_position(struct node **head1 ,struct node **head2, int pos)
{
	int count ;
	struct node *temp = NULL , *temp2=NULL;
	count = count_node(*head1);
	if(pos<=0 || pos > count+1)
	{
		printf("\nInvalid Position\n");
		return;
	}
	if(pos==1)
	{
		concat_list(head2 , head1);
		*head1 = *head2;
		*head2=NULL;
		return ;
	}
	if(pos==count+1)
	{
		concat_list(head1 , head2);
		return ;
	}
	temp = *head1;
	count = 1;
	while(count<pos-1)
	{
		count++;
		temp=temp->next;
	}
	temp2=*head2;
	while(temp2->next!=NULL)
		temp2=temp2->next;
	
	temp2->next = temp->next;
	temp->next->prev=temp2;
	
	
	temp->next = *head2;
	(*head2)->prev=temp;
	*head2=NULL;
}

void display(struct node *head)
{
	if(head==NULL)
	{
		printf("List Is Empty");
		return ;
	}
	while(head!=NULL)
	{
		printf("|%d|->",head->data);
		head = head->next;
	}
}