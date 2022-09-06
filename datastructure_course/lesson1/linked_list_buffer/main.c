/*
 * main.c
 *
 *  Created on: Sep 1, 2022
 *      Author: MOSTAFA
 */
#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"conio.h"
#define PRINT(...) {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

typedef struct
{
	int ID;
	float height;
	char name[50];
	struct Node*next;
}NEWnode;

typedef NEWnode* nodeptr;
nodeptr front = NULL;
nodeptr  rear = NULL;
int empty()
{
	if (front == NULL && rear==NULL)
		return 1;
	else
		return 0;
}

void ADDSTUDENT()
{
	char temp[50];
	nodeptr p;
	p= (nodeptr)malloc(sizeof(NEWnode));
	p->next=NULL;
	if(empty())
	{
		front=rear=p;
	}
	else
	{
		rear->next=p;
		rear=p;
	}
	PRINT("enter name: ");
	gets(p->name);
	PRINT("enter id: ");
	gets(temp);
	p->ID=atoi(temp);
	PRINT("enter height: ");
	gets(temp);
	p->height=atof(temp);
}
void DISPLAY_LIST()
{
	int i;
	if(empty())
	{
		PRINT("list is empty");
	}
	else
	{
		nodeptr p=front;
		for(i=0;p->next!=NULL;p=p->next,i++)
		{
			PRINT("\n name of student %d is: %s \n",i+1,p->name);
			PRINT("\n id of student %d is: %d \n",i+1,p->ID);
			PRINT("\n height of student %d is: %f \n",i+1,p->height);
		}
		PRINT("\n name of student %d is: %s \n",i+1,p->name);
		PRINT("\n id of student %d is: %d \n",i+1,p->ID);
		PRINT("\n height of student %d is: %f \n",i+1,p->height);
		p=NULL;
	}
}
void DELETE_STUDENT()
{
	nodeptr p = front;
	nodeptr prev=NULL;
	int id;

	if(!empty())
	{
		PRINT("enter id: ");
		scanf("%d",&id);
		while(p)
		{
			if(p->ID==id)
			{
				if (prev == NULL && p->next == NULL)
				{
					rear = front = NULL;
					break;
				}
				if(prev==NULL)
				{
					front=front->next;
					free (p);
					prev=p;
					p=p->next;

					break;
				}
				else if(p->next==NULL)
				{
					rear=prev;
					rear->next=NULL;
					free (p);
					prev=p;
					p=p->next;

					break;
				}
				else
				{
					prev->next=p->next;
					free (p);
					prev=p;
					p=p->next;

					break;
				}

			}
			prev=p;
			p=p->next;
		}
	}
	if(empty())
	{
		printf("list is empty");
	}


}
void get_N_NODE()
{
	nodeptr p=front;
	int index,count=1;
	PRINT ("\nenter the index of the needed node: ");
	scanf("%d",&index);
	if(empty())
	{
		PRINT("\n======= the list is empty =======\n");
	}
	else if(!empty()){
		while(p)
		{
			if(count==index)
			{
				PRINT("\n name of student %d is: %s \n",index,p->name);
				PRINT("\n id of student %d is: %d \n",index,p->ID);
				PRINT("\n height of student %d is: %f \n",index,p->height);
			}
			count++;
			p=p->next;
		}}
	else
	{
		printf("====invalid index====");
	}
}


void get_length()
{
	nodeptr p=front;
	int count=0;
	while(p)
	{
		count++;
		p=p->next;
	}
	if(empty())
	{
		PRINT("\n======= the list is empty =======\n");
	}
	else
		printf("length of the listis: %d",count);
}



int length_recursive(nodeptr p)
{
	if(empty())
	{
		PRINT("\n======= the list is empty =======\n");
		return 0;
	}
	if (p==NULL)
	{
		return 0;
	}
	else
	{
		p=p->next;
		return 1 + length_recursive(p);
	}
}



void get_n_node_f_end()
{
	int i,index;
	nodeptr p,x;
	p=x=front;
	PRINT ("\nenter the index of the needed node: ");
	scanf("%d",&index);
	if(empty())
	{
		PRINT("\n======= the list is empty =======\n");
	}
	else
	{
		for(i=0;i<index;i++)
		{
			p=p->next;
		}
		while(p)
		{
			x=x->next;
			p=p->next;
		}
		PRINT("\n name of student %d from the end is: %s \n",index,x->name);
		PRINT("\n id of student %d from the end is: %d \n",index,x->ID);
		PRINT("\n height of student %d from the end is: %f \n",index,x->height);
	}
}



void DELETE_ALL()
{
	front=rear=NULL;
	if(empty())
	{
		PRINT("\n======= the list is deleted =======\n");
	}
}



int main()
{
	int i,choice;
	PRINT ("1- insert item into the list\n");
	PRINT ("2- remove item from the list\n");
	PRINT ("3- display all student\n");
	PRINT ("4- get the length of the list by recursive\n");
	PRINT ("5- get the length of the list\n");
	PRINT ("6- get n node\n");
	PRINT ("7- get n node from end\n");
	PRINT ("8- delete all student\n");
	PRINT ("please enter your choice(1,2,3,4,5,6,7,8):= ");
	scanf("%d",&choice);
	while (choice!=8)
	{
		int num_of_student;
		if (choice == 1)
		{
			PRINT("how many student to insert?= ");
			scanf("%d",&num_of_student);
			for (i= 0; i < num_of_student; i++)
			{
				ADDSTUDENT();
			}
		}//end of insert

		if (choice == 2)
		{
			DELETE_STUDENT();
		}//end of remove

		if (choice == 3)
		{
			DISPLAY_LIST();
		}//end of display all

		if (choice == 4)
		{
			nodeptr p;
			p=front;
			PRINT("the length of the list is: %d",length_recursive(p));
		}

		if (choice == 5)
		{
			get_length();
		}

		if (choice == 6)
		{
			get_N_NODE();
		}

		if (choice == 7)
		{
			get_n_node_f_end();
		}
		PRINT ("\nplease enter another your choice(1,2,3,4,5,6,7,8):= ");
		scanf("%d",&choice);
	}
	if (choice == 8)
	{
		DELETE_ALL();
	}//end of remove all
	return 0;
}
