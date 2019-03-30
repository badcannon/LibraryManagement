#include <stdio.h>

struct Node{
	char name [100];
	int id ;
	struct Node *next
	
};

typedef struct Node NODE;
NODE *first = NULL; 
 
 
 void add()
  {
  	 NODE *temp;
  	 temp=(NODE*)malloc(sizeof(NODE));
  	 if(temp==NULL)
  	 {
  	 	printf("No space ");
  	 	exit(0);
	   }
  	 printf("Enter The name :");
  	 scanf("%s",temp->name);
  	 printf("Enter The ID :");
  	 scanf("%d",&(temp->id));
  	 if(first==NULL)
  	 {
  	 	first =temp;
  	 	temp->next=NULL;
	   }
else {	   NODE *cur=first;
           while (cur->next!=NULL)
		   {
		   
		    	cur=cur->next;
			 } 
			 cur->next =temp ;
			 temp->next=NULL;
}
  
  }
  
  void display() 
  {
  	NODE *temp=first;
  	while (temp!=NULL)
  	 {
  	 	printf("Name is :%s\n",temp->name);
  	 	printf("Id is :%d\n",temp->id);
  	 	temp=temp->next;
	   }
  }


void main()
 {
 	while(1)
 	{
	
 	add();
 	display();}
 }
