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
{
	int  choice1 , choice2 , choice3 , no , pos;
	struct node *first=NULL , *last1 = NULL;
	struct node *second=NULL , *last2 = NULL;

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
						insert_first(&first ,&last1 , no);
						printf("\nLinked list :  ");
						display(first , last1);
						break;
				case 2 :
						printf("\nEnter The Data You Want To Insert : ");
						scanf_s("%d", &no);
						insert_last(&first ,&last1, no);
						printf("\nLinked list :  ");
						display(first , last1);
						break;
				case 3 :
						
						printf("\nEnter The Position : ");
						scanf_s("%d", &pos);

						if(pos<=0||pos>count_node(first , last1)+1)
							{
								printf("\nInvalid Position\n");
								break;
							}

						printf("\nEnter The Data You Want To Insert : ");
						scanf_s("%d", &no);
						insert_at_position(&first ,&last1 , no , pos);
						printf("\nLinked list :  ");
						display(first , last1);
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
					no =  delete_first(&first , &last1) ;
					if(no==-1)
					{
						printf("\nLinked List Is Empty\n");
						break;
					}
					printf("\nDeleted Data : %d \nAfter Deletion List :  " , no);
					display(first , last1);
					break;
				case 2 :
					no =  delete_last(&first, &last1) ;
					if(no==-1)
					{
						printf("\nLinked List Is Empty\n");
						break;
					}
					printf("\nDeleted Data : %d \nAfter Deletion List :  ", no);
					display(first , last1);
					break;
				case 3 :

					if(first==NULL)
					{
						printf("\nLinked List Is Empty\n");
						break;
					}
					printf("Enter The Position Of Data You Want To Delete : ");
					scanf_s("%d",&pos);
					if(pos<=0||pos>count_node(first , last1))
							{
								printf("\nInvalid Position\n");
								break;
							}

					printf("\nDeleted Data : %d \nAfter Deletion List :  ", delete_at_position(&first , &last1, pos));
					display(first , last1);
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
						pos = search_first_occure(first ,last1 , no);
						if(pos!=0)
							printf("Found At Position %d : " ,pos );
						else
							printf("Not Found ");
						break;
				case 2 :
						printf("Enter The No To Be searched : ");
						scanf_s("%d",&no);
						pos = search_last_occure(first ,last1 ,  no);
						if(pos!=0)
							printf("Found At Position %d : " ,pos );
						else
							printf("Not Found ");
						break;
				case 3 :
						printf("Enter The No To Be searched : ");
						scanf_s("%d",&no);
						pos = search_all_occure(first , last1 ,no);
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
				printf("Total No Of Nodes Are %d ", count_node(first , last1));
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
						reverse_list(&first , &last1);
						printf("\nRevesed Linked-List :  ");
						display(first , last1);
						break;
				case 2 :
						reverse_display(first , last1);
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
										
										insert_first(&second , &last2 , no);
										printf("\nSecond Linked list :  ");
										display(second, last2);
										break;
								case 2 :	
										insert_last(&second , &last2 , no);
										printf("\nSecond Linked list :  ");
										display(second, last2);
										break;
								case 3 :
										printf("\nEnter The Position : ");
										scanf_s("%d", &pos);
										if(pos<=0||pos>count_node(second , last2)+1)
											{
												printf("\nInvalid Position\n");
												break;
											}
										printf("\nEnter The Data You Want To Insert : ");
										scanf_s("%d", &no);	
										insert_at_position(&second , &last2 ,no , pos);
										printf("\nSecond Linked list :  ");
										display(second, last2);
										break;
								case 4:
										concat_list(&first ,&last1 , &second , &last2);
										printf("\nList 1 :  ");
										display(first , last1);
										printf("\nList 2 :  ");
										display(second, last2);
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
									
										insert_first(&second , &last2 , no);
										printf("\nSecond Linked list :  ");
										display(second, last2);
										break;
								case 2 :
										
										insert_last(&second , &last2 , no);
										printf("\nSecond Linked list :  ");
										display(second, last2);
										break;
								case 3 :
										printf("\nEnter The Position : ");
										scanf_s("%d", &pos);

										if(pos<=0||pos>count_node(second ,last2)+1)
											{
												printf("\nInvalid Position\n");
												break;
											}

										printf("\nEnter The Data You Want To Insert : ");
										scanf_s("%d", &no);
										insert_at_position(&second , &last2 ,no , pos);
										printf("\nSecond Linked list :  ");
										display(second, last2);
										break;
								case 4:
										printf("Enter The Position You Want To Concat : ");
										scanf_s("%d",&pos);

										if(pos<=0||pos>count_node(first , last1)+1)
											{
												printf("\nInvalid Position\n");
												break;
											}

										concat_at_position(&first, &last1 , &second , &last2 , pos);
										printf("\nList 1 :  ");
										display(first , last1);
										printf("\nList 2 :  ");
										display(second, last2);
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
		delete_all(&first  , &last1 );
	if(second!=NULL)
		delete_all(&second , &last2);

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
