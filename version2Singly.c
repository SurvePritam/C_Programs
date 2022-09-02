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
	int choice , no , pos;
	struct node *first=NULL;
	struct node *second=NULL;

	do
	{
	printf("\nEnter The Number of Operation You Want to Perform :\n "
		"1]   Insert At First\n 2]   Insert At Last\n 3]   Insert At Position\n 4]   Delete Fisrt Node\n 5]   Delete Last Node\n 6]   Delete At Position\n "
		"7]   Search First Occurence\n 8]   Search Last Occurence\n 9]   Search All Occurences\n 10]  Count Of Node\n 11]  Reverse The Linked-List\n 12]  Display Reverse\n "
		"13]  Concatinate Two Lists\n 14]  Concatinate At Position\n 15]  Display\n 16]  Exit()\n ");

	scanf_s("%d",&choice);
	switch(choice)
	{
	case 1 :
		printf("\nEnter The Data You Want To Insert : ");
		scanf_s("%d", &no);
		insert_first(&first , no);
			printf("\nLinked list :  ");
			display(first);
		break;
	case 2 :
		printf("\nEnter The Data You Want To Insert : ");
		scanf_s("%d", &no);
		insert_last(&first , no);
			printf("\nLinked list :  ");
			display(first);
		break;
	case 3 :
		printf("\nEnter The Position : ");
		scanf_s("%d", &pos);
		printf("\nEnter The Data You Want To Insert : ");
		scanf_s("%d", &no);
		insert_at_position(&first ,no , pos);
		printf("\nLinked list :  ");
		display(first);
		break;
	case 4 :
		printf("Deleted Data : %d \nAfter Deletion List :  ", delete_last(&first));
		display(first);
		break;
	case 5 :
		printf("Deleted Data : %d \nAfter Deletion List :  ", delete_last(&first));
		display(first);
		break;
	case 6 :
		printf("Enter The Position Of Data You Want To Delete : ");
		scanf_s("%d",&pos);
		printf("Deleted Data : %d \nAfter Deletion List :  ", delete_at_position(&first , pos));
		display(first);
		
		break;
	case 7 :
		printf("Enter The No To Be searched : ");
		scanf_s("%d",&no);
		pos = search_first_occurence(first , no);
		if(pos!=0)
			printf("Found At Position %d : " ,pos );
		else
			printf("Not Found ");
		break;
	case 8 :
		printf("Enter The No To Be searched : ");
		scanf_s("%d",&no);
		pos = search_last_occurence(first , no);
		if(pos!=0)
			printf("Found At Position %d : " ,pos );
		else
			printf("Not Found ");
		break;
	case 9 :
		printf("Enter The No To Be searched : ");
		scanf_s("%d",&no);
		pos = search_all_occurences(first , no);
		printf("Total Occurences Of %d Are %d : " ,no , pos );
		break;
	case 10 :
		printf("Total No Of Nodes Are %d ", count_node(first));
		break;
	case 11 :
		physical_reverse(&first);
		printf("\nRevesed Linked-List :  ");
		display(first);
		break;
	case 12 :
		reverse_display(first);
		break;
	case 13 :
		do
		{
			printf("Enter Which Action You Want to Perform :\n 1]   Insert At First\n 2]   Insert At Last\n 3]   Insert At Position\n 4]   Concat\n 5]   Back \n");
			scanf_s("%d",&choice);
			switch(choice)
			{
					case 1 :
						printf("\nEnter The Data You Want To Insert : ");
						scanf_s("%d", &no);
						insert_first(&second , no);
						break;
					case 2 :
						printf("\nEnter The Data You Want To Insert : ");
						scanf_s("%d", &no);
						insert_last(&second , no);
						break;
					case 3 :
						printf("\nEnter The Position : ");
						scanf_s("%d", &pos);
						printf("\nEnter The Data You Want To Insert : ");
						scanf_s("%d", &no);
						insert_at_position(&second ,no , pos);
						break;
					case 4:
						concat_list(&first , &second);
						printf("\nList 1 :  ");
						display(first);
						printf("\nList 2 :  ");
						display(second);
						break ;
					case 5 :
						break;
			}
		}while(choice!=4 && choice!=5);

		break;
	case 14 :
		printf("Enter The Position You Want To Concat : ");
		scanf_s("%d",&pos);
		concat_at_position(&first , &second , pos);
		printf("\nList 1 :  ");
		display(first);
		printf("\nList 2 :  ");
		display(second);
		break;
	case 15 :
		display(first);
		break;
	case 16 :
		break;
	default :
		printf(" Invalid Choice ");
	}
	}while(choice!=16);

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
		return -1;
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