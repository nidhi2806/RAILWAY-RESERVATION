#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
int t=0;
struct node
{
   int tick,age;
   char name[100];
   struct node *next; 
}*nn=NULL,*start=NULL,*ptr=NULL,*temp=NULL,*ttemp=NULL,*can=NULL;

struct node* book(struct node*);
struct node* display(struct node*); 
struct node* cancel(struct node*); 

void main()
{
   int op; 
   do
   {
      printf("---------------MAIN MENU---------------\n\n1.Book a ticket\n2.Display tickets booked\n3.Cancel a ticket\n4.Exit\nEnter a option:");
      scanf("%d",&op); switch(op)
      {
         case 1:
            start=book(start);
            break;
         case 2:
            start=display(start); 
            break;
         case 3:
            start=cancel(start); 
            break;
         case 4:
            exit(0); 
         default:
            printf("Invalid option");
      } 
   }
   while(op<=4); 
}
struct node* book(struct node* start) 
{
   int a;
   char s[100];
   printf("\n--------Booking ticket----------\n\nEnter NAME:"); 
   scanf("%s",s);
   printf("\nEnter Age:");
   scanf("%d",&a);
   nn=(struct node*)malloc(sizeof(struct node)); 
   strcpy(nn->name,s);
   nn->age=a;
   t++;
   nn->tick=t;
   nn->next=NULL;
   if(start==NULL)
   {
      start=nn;
   }
   else 
   {
      ptr=start; 
      while(ptr->next!=NULL)
      {
         ptr=ptr->next; 
         ptr->next=nn;
      }
   }
   printf("\nTicket Booked"); return start;
}
struct node* display(struct node* start) 
{
   int l
   int i; 
   printf("\n---------------TICKETS booked---------------\n"); 
   printf("TICKET NO.\t NAME \t AGE\n"); 
   ptr=start;
   while(ptr!=NULL)
   {
      printf(" %d \t ",ptr->tick); 
      printf("%s ",ptr->name); 
      printf("\t %d \n",ptr->age); 
      ptr=ptr->next;
   }
   return start; 
}
struct node* cancel(struct node* start) 
{
   int c;
   printf("Enter ticket number to be cancelled:"); 
   scanf("%d",&c);
   ptr=start;
   if(start->tick==c)
   {
      start=start->next; can=start; free(ptr);
   } 
   else 
   {
      while(ptr->tick!=c) 
      {
         temp=ptr; 
         ptr=ptr->next; 
         if(ptr==NULL) 
         {
            printf("\nTicket number does not exist\n"); goto a;
         } 
      }
      can=ptr; 
      ttemp=ptr->next; 
      temp->next=ttemp;
   } 
   while(can!=NULL)
   {
      (can->tick)--; 
      can=can->next;
   }
   t--;
   printf("\nTicket has been cancelled\n"); 
   a:return start;
}
