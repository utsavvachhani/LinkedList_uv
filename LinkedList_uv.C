#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
//------------------------------node makeing--------------------------------
struct node{
 int INFO;
 struct node*LINK;
};
//----------------------------funtion decleared------------------------------
void constructnode();
void FIRSTADD();
void LASTADD();
void ANYEREADD();
void FIRSTDELET();
void LASTDELET();
void BEFORDELET();
void AFTERDELET();
void CHANGE();
void SHOW();
//-----------------------------------------------------------------------
struct node*FIRST=NULL;
int count=0;
//----------------------number of nodfe checked---------------------------
int numofnode()
{
 int n=0;
 struct node *temp;
 temp=FIRST;
 while(temp->LINK!=NULL)
 {
  n++;
  temp=temp->LINK;
 }
 n++;
 return n;
}
//-----------------------------construct the node--------------------------
void constructnode()
{
 count++;
 if(count==1)
 {
  FIRSTADD();
 }
 else
 {
  printf("\n");
  LASTADD();
 }
}
//-------------------------case 1:add number at first-------------------------
void FIRSTADD()
{
 int x;
 struct node *newnode=(struct node*)malloc(sizeof(struct node*));
 printf("Enter the INFO:");
 scanf("%d",&x);
 newnode->INFO=x;
 if(FIRST==NULL)
 {
  newnode->LINK=NULL;
 }
 else
 {
 newnode->LINK=FIRST;
 }
 FIRST=newnode;
 printf("node inserted %d=[%d,%d]",FIRST,FIRST->INFO,FIRST->LINK);
}
//-------------------------case 2:number added at last------------------------
void LASTADD()
{
 int x;
 struct node *newnode=(struct node*)malloc(sizeof(struct node*));
 struct node *temp=(struct node*)malloc(sizeof(struct node*));
 temp=FIRST;
 if(FIRST==NULL)
 {
  FIRSTADD();
 }
 else
 {
  while(temp->LINK!=NULL)
  {
   temp=temp->LINK;
  }
 }
 printf("Enter the INFO:");
 scanf("%d",&x);
 newnode->INFO=x;
 newnode->LINK=NULL;
 temp->LINK=newnode;
 temp=temp->LINK;
 printf("node inserted %d=[%d,%d]",temp,temp->INFO,temp->LINK);
}
//----------------case 3:add after give node--------------------------
void ANYWEREADD()
{
 int x;
 struct node *temp=(struct node*)malloc(sizeof(struct node*));
 struct node *newnode=(struct node*)malloc(sizeof(struct node*));
 struct node *loc=(struct node*)malloc(sizeof(struct node*));
 temp=FIRST;
 while(temp->LINK!=NULL)
 {
  printf("\n%d",temp);
  temp=temp->LINK;
 }
 printf("\n%d",temp);
 printf("\nEnter the node number where you enter the node:");
 scanf("%d",&loc);
 temp=FIRST;
 while(temp->LINK!=NULL)
 {
  if(temp==loc)
  {
   break;
  }
  temp=temp->LINK;
 }
 if(temp->LINK==NULL && temp!=loc)
 {
  printf("Your given node is not founded!!!");
 }
 else
 {
  printf("Enter the INFO:");
  scanf("%d",&x);
  newnode->INFO=x;
  newnode->LINK=loc->LINK;
  loc->LINK=newnode;
  loc=loc->LINK;
  printf("node id inserted %d=[%d,%d]",loc,loc->INFO,loc->LINK);
 }
}
//-------------case 4:DELET first node-----------------------------
void FIRSTDELET()
{
 struct node *y;
 if(FIRST==NULL)
 {
  printf("\nNDERFLOW!!!!!!!!");
 }
 else
 {
  y=FIRST;
  FIRST=FIRST->LINK;
  printf("remove node is %d=[%d,%d]",y,y->INFO,y->LINK);
 }
 free(y);
}
//-------------case 5:DELET at last---------------------------------------
void LASTDELET()
{
 int n,i=1;
 struct node *temp;
 struct node *y;
 if(FIRST==NULL)
 {
  printf("UNDERFLOW!!!!!");
 }
 else
 {
  n=numofnode();
  temp=FIRST;
  while(i!=n-1)
  {
   temp=temp->LINK;
   i++;
  }
  y=temp->LINK;
  temp->LINK=NULL;
  printf("deleted node is %d=[%d,%d]",y,y->INFO,y->LINK);
 }
 free(y);
}
//-------------case 6:befor delet the given node-------------------------
void BEFORDELET()
{
 int index,n;
 n=numofnode();
 printf("here you have total node is %d",n);
 printf("\nEnter the index of node which after you wont to delet node:");
 scanf("%d",&index);
 if(index>=n && index == 1)
 {
  printf("You Enter wrong index!!!!");
 }
 else
 {
  if(index==2)
  {
   FIRSTDELET();
  }
  else
  {
   int i=1;
   struct node *temp=FIRST;
   struct node *y;
   while(i!=index-2)
   {
    i++;
    temp=temp->LINK;
   }
   y=temp->LINK;
   temp->LINK=y->LINK;
   printf("mord is deleted %d=[%d,%d]",y,y->INFO,y->LINK);
   free(y);
  }
 }
}
//-------------case 7:after  delet the given node--------------------
void AFTERDELET()
{
 int index,n;
 n=numofnode();
 printf("here you have total node is %d",n);
 printf("\nEnter the index of node which after you wont to delet node:");
 scanf("%d",&index);
 if(index>=n)
 {
  printf("You Enter wrong index!!!!");
 }
 else
 {
  int i=1;
  struct node *temp=FIRST;
  struct node *y;
  while(i!=index)
  {
   i++;
   temp=temp->LINK;
  }
  y=temp->LINK;
  temp->LINK=y->LINK;
  printf("mord is deleted %d=[%d,%d]",y,y->INFO,y->LINK);
  free(y);
 }
}
//------------case 8:Show the linklist.------------------------------------
void SHOW()
{
 struct node*temp=(struct node*)malloc(sizeof(struct node*));
 temp=FIRST;
 while(temp->LINK!=NULL)
 {
  printf("%d=[%d,%d]\n",temp,temp->INFO,temp->LINK);
  temp=temp->LINK;
 }
 printf("%d=[%d,%d]",temp,temp->INFO,temp->LINK);
}
//--------------------case 9:change info--------------------------
void CHANGE()
{
 int x;
 struct node *temp=(struct node*)malloc(sizeof(struct node*));
 struct node *loc=(struct node*)malloc(sizeof(struct node*));
 SHOW();
 printf("Enter the node of which you Went to chang INFO:");
 scanf("%d",&loc);
 temp=FIRST;
 while(temp->LINK!=NULL)
 {
  if(temp==loc)
  {
   break;
  }
  temp=temp->LINK;
 }
 if(temp->LINK==NULL && temp!=loc)
 {
  printf("Your given node is not founded!!!");
 }
 else
 {
  printf("Enter the INFO which you chang:");
  scanf("%d",&x);
  loc->INFO=x;
  printf("after changhing %d=[%d,%d]",loc,loc->INFO,loc->LINK);
 }
}
//--------------------MAIN FUNCTIONNNNNNNNNNN-----------------------
int main()
{
 int i=5,ch,a=1,n,j,x;
 //clrscr();
 printf("Code by utsav vachhani(uv)");
 printf("it's program of singly Linklist.");
 printf("\nEnter the number of element you went to enter in Linklist:");
 scanf("%d",&n);
 for(j=0;j<n;j++)
 {
  constructnode();
 }
 printf("\nElement before opertion:");
 SHOW();
 while(a!=0)
 {
  if(i==5)
  {
   printf("\n-------------------------------------------------------------------------------");
   printf("\n1. insert at First.");
   printf("\n2. insert at last.");
   printf("\n3. insert at after given node.");
   printf("\n4. delet at First");
   printf("\n5. delet at Last");
   printf("\n6. delet at before specifide node.");
   printf("\n7. delet at after specifide node.");
   printf("\n8. show the linklist");
   printf("\n9. change value of node INFO.");
   printf("\n10. exite");
  }
  i--;
  if(i==0)
  {
   i=5;
  }
  printf("\n\nEnter choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:
   {
    FIRSTADD();
    break;
   }
   case 2:
   {
    LASTADD();
    break;
   }
   case 3:
   {
    ANYWEREADD();
    break;
   }
   case 4:
   {
    FIRSTDELET();
    break;
   }
   case 5:
   {
    LASTDELET();
    break;
   }
   case 6:
   {
    BEFORDELET();
    break;
   }
   case 7:
   {
    AFTERDELET();
    break;
   }
   case 8:
   {
    SHOW();
    break;
   }
   case 9:
   {
    CHANGE();
    break;
   }
   case 10:
   {
    a=0;
    break;
   }
   default:
   {
    printf("Invalid choice");
   }
  }
 }
 return 0;
 //getch();
}