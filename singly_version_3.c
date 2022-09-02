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

void delete_all(struct node **);
void display(struct node *);

int main(void)
{
	int  choice1 , choice2 , choice3 , no , pos;
	struct node *first=NULL;
	struct node *second=NULL;

	do
	{

	printf("\n 1] Insert\n 2] Delete\n 3] Search\n 4] Count\n 5] Reverse\n 6] Concat \n 7] Exit\n Enter Which Operation You Want To Perform : \n");
	scanf_s("%d",&choice1);
	switch(choice1)
	{
		case 1 :
			do
			{
			printf("\n 1] Insert At First\n 2] Insert At Last\n 3] Insert At Position\n 4] Back \n Enter Which Action You Want To Perform : ");
			scanf_s("%d",&choice2);
			switch (choice2)
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

						if(pos<=0||pos>count_node(first)+1)
							{
								printf("\nInvalid Position\n");
								break;
							}

						printf("\nEnter The Data You Want To Insert : ");
						scanf_s("%d", &no);
						insert_at_position(&first ,no , pos);
						printf("\nLinked list :  ");
						display(first);
						break;
				case 4 :
						break;
				default :
						printf("\n Invalid Choice \n");
			}
			}while(choice2!=4);
			break;

		case 2 :
			if(first==NULL)
			{
				printf("\nList Is Empty\n");
				break;
			}

			do
			{
			printf("\n 1] Delete At First\n 2] Delete At Last\n 3] Delete At Position\n 4] Back \n Enter Which Action You Want To Perform : ");
			scanf_s("%d",&choice2);
			switch (choice2)
			{
				case 1 :
					no = delete_first(&first) ;
					if(no==-1)
					{
						printf("\nLinked List Is Empty\n");
						break;
					}
					printf("\nDeleted Data : %d \nAfter Deletion List :  " , no);
					display(first);
					break;
				case 2 :
					no =  delete_last(&first) ;
					if(no==-1)
					{
						printf("\nLinked List Is Empty\n");
						break;
					}
					printf("\nDeleted Data : %d \nAfter Deletion List :  ", no);
					display(first);
					break;
				case 3 :

					if(first==NULL)
					{
						printf("\nLinked List Is Empty\n");
						break;
					}
					printf("Enter The Position Of Data You Want To Delete : ");
					scanf_s("%d",&pos);
					if(pos<=0||pos>count_node(first))
							{
								printf("\nInvalid Position\n");
								break;
							}

					printf("\nDeleted Data : %d \nAfter Deletion List :  ", delete_at_position(&first , pos));
					display(first);
					break;
				case 4 :
						break;
				default :
						printf(" Invalid Choice ");
			}
			}while(choice2!=4);
			break;

		case 3 :
			if(first==NULL)
			{
				printf("\nList Is Empty\n");
				break;
			}

			do
			{
			printf("\n 1] Search First Occurence \n 2] Search Last Occurence \n 3] Search All Occurences\n 4] Back \n Enter Which Action You Want To Perform : ");
			scanf_s("%d",&choice2);
			switch (choice2)
			{
				case 1 :
						printf("Enter The No To Be searched : ");
						scanf_s("%d",&no);
						pos = search_first_occurence(first , no);
						if(pos!=0)
							printf("Found At Position %d : " ,pos );
						else
							printf("Not Found ");
						break;
				case 2 :
						printf("Enter The No To Be searched : ");
						scanf_s("%d",&no);
						pos = search_last_occurence(first , no);
						if(pos!=0)
							printf("Found At Position %d : " ,pos );
						else
							printf("Not Found ");
						break;
				case 3 :
						printf("Enter The No To Be searched : ");
						scanf_s("%d",&no);
						pos = search_all_occurences(first , no);
						printf("Total Occurences Of %d Are %d : " ,no , pos );
						break;
				case 4 :
						break;
				default :
						printf(" Invalid Choice ");
			}
			}while(choice2!=4);
			break;

		case 4 :
				printf("Total No Of Nodes Are %d ", count_node(first));
				break;

		case 5 :
			if(first==NULL)
			{
				printf("\nList Is Empty\n");
				break;
			}
			do
			{
			printf("\n 1] Physical Reverse\n 2] Reverse Display\n 3] Back\n Enter Which Action You Want To Perform : ");
			scanf_s("%d",&choice2);
			switch (choice2)
			{
				case 1 :
						physical_reverse(&first);
						printf("\nRevesed Linked-List :  ");
						display(first);
						break;
				case 2 :
						reverse_display(first);
						break;
				case 3 :
					break;
				default:
					printf("\nINVALID CHOICE\n");
				
			}
			}while(choice2!=3);
			break;

		case 6 :
			do
			{
			printf("\n 1] Concat List \n 2] Concat List At Position\n 3] Back\n Enter Which Action You Want To Perform : ");
			scanf_s("%d",&choice2);
			switch (choice2)
			{
				case 1 :
					do
						{
							printf("\nEnter Which Action You Want to Perform :\n 1]   Insert At First\n 2]   Insert At Last\n 3]   Insert At Position\n 4]   Concat\n 5]   Back \n");
							scanf_s("%d",&choice3);
							if(choice3==1 || choice3==2)
							{
								printf("\nEnter The Data You Want To Insert : ");
								scanf_s("%d", &no);
							}
							switch(choice3)
							{
								case 1 :
										
										insert_first(&second , no);
										printf("\nSecond Linked list :  ");
										display(second);
										break;
								case 2 :
	
										insert_last(&second , no);
										printf("\nSecond Linked list :  ");
										display(second);
										break;
								case 3 :
										printf("\nEnter The Position : ");
										scanf_s("%d", &pos);
										if(pos<=0||pos>count_node(second)+1)
											{
												printf("\nInvalid Position\n");
												break;
											}
										printf("\nEnter The Data You Want To Insert : ");
										scanf_s("%d", &no);	
										insert_at_position(&second ,no , pos);
										printf("\nSecond Linked list :  ");
										display(second);
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
								default :
									printf("\nInvalid Choice\n");
								}
							}while(choice3!=4 && choice3!=5);
						break;
				case 2 :
					do
						{
							printf("\nEnter Which Action You Want to Perform :\n 1]   Insert At First\n 2]   Insert At Last\n 3]   Insert At Position\n 4]   Concat At Position \n 5]   Back \n");
							scanf_s("%d",&choice3);
							if(choice3==1 || choice3==2)
							{
								printf("\nEnter The Data You Want To Insert : ");
								scanf_s("%d", &no);
							}
							switch(choice3)
							{
								case 1 :
									
										insert_first(&second , no);
										printf("\nSecond Linked list :  ");
										display(second);
										break;
								case 2 :
										
										insert_last(&second , no);
										printf("\nSecond Linked list :  ");
										display(second);
										break;
								case 3 :
										printf("\nEnter The Position : ");
										scanf_s("%d", &pos);

										if(pos<=0||pos>count_node(second)+1)
											{
												printf("\nInvalid Position\n");
												break;
											}

										printf("\nEnter The Data You Want To Insert : ");
										scanf_s("%d", &no);
										insert_at_position(&second ,no , pos);
										printf("\nSecond Linked list :  ");
										display(second);
										break;
								case 4:
										printf("Enter The Position You Want To Concat : ");
										scanf_s("%d",&pos);

										if(pos<=0||pos>count_node(first)+1)
											{
												printf("\nInvalid Position\n");
												break;
											}

										concat_at_position(&first , &second , pos);
										printf("\nList 1 :  ");
										display(first);
										printf("\nList 2 :  ");
										display(second);
										break;
								case 5 :
										break;
								default :
									printf("\nInvalid Choice\n");
								}
							}while(choice3!=4 && choice3!=5);
					break;
				case 3 :
					break;
				default :
					printf("\nInvalid Entry\n");
			}
			}while(choice2!=3);
			break;

		case 7 :
			break;

		default :
			printf("\nINVALID ENTRY\n");

	}
	}while(choice1!=7);

	if(first!=NULL)
		delete_all(&first);
	if(second!=NULL)
		delete_all(&second);

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
			return ;

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

void delete_all(struct node **head)
{
	struct node *temp = NULL;
	temp = *head ;

	while(temp!=NULL)
	{
		*head = temp->next;
		temp->next = NULL;
		free(temp);
		temp = *head ;
	}

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