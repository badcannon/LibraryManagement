#include <windows.h>		
#include<stdio.h>            //contains printf,scanf etc       
#include<conio.h>            //contains delay(),getch(),gotoxy(),etc       
#include <stdlib.h>			 
#include<string.h>          //contains strcmp(),strcpy(),Strlen(),etc        
#include<ctype.h>           //contains toupper(),tolower(),etc        
#include<dos.h>             //contains dos getdate       
#include<time.h>
#define RETURNTIME 1
#define MAX 100
char catagories[][16]={"Mathematics","Psycology","Biology","Accounting","Economics","English"}; 	//global variables

int s;
char findbook;
struct Faculty{
	int Id;
	char Name[100];
	char Password[100];
    struct Faculty *next;
};
typedef struct Faculty Fac;

struct meroDate
{
    int mm,dd,yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Writer[20];
    int quantity;
    float Amount;
    int bookno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};
struct books r;
struct Hash {
	struct Faculty *First;
	int count;

};

struct Hash *HashInto;

int Hasher(int Id){
	
	return (Id%MAX);
}
void returnfunc(void);
void welcome(void);
void addbooks(void);		//declaration for the add function
void deletebooks(void);		//declaration for the delete function
void editbooks(void);		//declaration for the edit function
void searchbooks(void);		//declaration for search function
void issuebooks(void);		//declaration for issuing function
void bookslist(void);		//declaration for viewing bok list function
void welcome(void);			//declaration for welcome function
void login(void);			//declaration for login function
void mainmenu(void);
void MasterLogin(void);
void FacultyLogin(void);
void FacultyEdit(void);
void AddFaculty(void);
void RemFaculty(void);
void ModFaculty(void);
void bookslist(void);
void exitapplication(void);	
int  getdata();
int  checkid(int);
int t(void);
void issuerecord();	

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();		//shows the processor clock time used since the beginning of an
											//implementation defined era (normally the beginning of the program).
    while (goal > clock());
}
FILE *fp,*ft,*fs;
void delay(void)
{
	int i,j;
	for(i=0;i<100;i++) 
	 {
	 	for (j=0;j<1000;j++)
	 	 {
	 	 	
		  }
	 }
}



void login(void)
{
	printf("~~~~Login Menu~~~~~");
	printf("1.Master Login");
	printf("2.Faculty Login");
	printf("Enter Your Choice! (1/2)");
	switch(getch())
	 {
	 	case 1: MasterLogin();
	 	break;
	 	case 2: FacultyLogin();
	 	break;
	 	default :printf("Wrong Choice!");
	 	         if(getch())
	 	         login();
	 	         
	 }
}

void MasterLogin()
 {
 	char u[100],p[100];
 do{
	printf("\n\n\n\t\t\t ENTER THE USERNAME AND PASSWORD\n\n\n\n");
	printf("\n\t\t\tUSERNAME: ");
	scanf("%s",&u);						//scanf is used to read input such as character, string, numeric data from keyboard.
	printf("\n\t\t\tPASSWORD: ");
	scanf("%s",&p);
	if((strcmp(u,"Shreenidhi")==0) && (strcmp(p,"12345")==0))
	{
		printf("\n\n\t\t login successful");
		printf("\n\n\n\t\t\t\t Press any key to continue.....");
		getch();
		printf("~~~Master Admin Menu~~~~~");
		printf("\n1.Faculty Options");
		printf("\n2.Read Log");
		printf("\n3.Return to Login");
		printf("\n4.Exit");
		printf("\nEnter your option :");
		switch(getch())
		 {
		 	case 1: FacultyEdit();
		 	break;
		 	case 2: ReadLog();
		 	break;
		 	case 3: printf("Please Wait .. Press Any key to return");
		 	        if(getch())
		 	        login();
		 	break;
		 	case 4:printf("Press Any key to Exit");
		 	       exit(0);
		 }
	}
	else
	{
		printf("\n\n\t\tInvalid username and password");
	}
	
	}while("number_of_try");
	
 }
 
void FacultyEdit(void)
 {
 	system("cls");	 
 	printf("~~~~~~~~~Faculty Edit Menu~~~~~~~");
 	printf("\n1.Add New Faculty");
 	printf("\n2.Remove Faculty");
 	printf("\n3.Modify Faculty");
 	printf("\n4.Exit");
 	printf("\n Enter your Choice ");
 	switch(getch())
 	 {
 	 	case 1: AddFaculty();
 	 	        break;
 	 	case 2 :RemFaculty();
		        break;
		case 3: ModFaculty();
		        break;
		case 4: printf("Press Any key to exit..........");
                getch();
				exit(0);
		default:printf("Wrong option try angin \n");
		        FacultyEdit();
				break;	  
	  }
     
  
 }
 
 void AddFaculty(void) 
  {
  	 Fac *temp,Det; 
  	 printf("~~Faculty ADDITION~~");
  	 printf("\n1.Enter the Name :");
  	 fgets(Det.Name,100,stdin);
  	 printf("\n2.Enter the Id:");
  	 scanf("%d",Det.Id);
  	 printf("\n3.Enter the Password:");
  	 fgets(Det.Password,100,stdin);
  	 printf("Details Entered!");
  	 delay();
  	 temp = (Fac*)malloc(sizeof(Det));
  	 if(temp==NULL)
  	  {
  	  	printf("Memory Error");
  	  	exit(EXIT_FAILURE);
		}
	 	  temp->Id=Det.Id;
	 	  strcpy(temp->Name,Det.Name);
	 	  strcpy(temp->Password,Det.Password);
	 	  temp->next=NULL;
	int HashIndex = Hasher(Det.Id);
	if(HashInto[HashIndex].First==NULL)
	{
		HashInto[HashIndex].First=temp;
		HashInto[HashIndex].count=1;
		HashInto[HashIndex].First->next=HashInto[HashIndex].First;
		
	}
	else{
	Fac *cur;
	 cur=&HashInto[HashIndex].First;
	    while(cur->next!=HashInto[HashIndex].First)
	     {
	     	cur = cur->next; 
		 }
		 cur->next= temp ;
		 temp->next = HashInto[HashIndex].First;
	     	  
        }
	fp = fopen("FacultyLogins.bin","wb");
	if(fp!=null){
	
	fwrite();
  }
  else {
  	printf("Error! Opening File!");
    }
  
  }
