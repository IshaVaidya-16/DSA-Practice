#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int val)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    return newnode;
}
struct node *head=NULL;
void insertatBegin(int val)
{
    printf("enter val:");
    scanf("%d",&val);
    struct node *newnode=createNode(val);
    if(newnode==NULL)
    {
        return;
    }
    newnode->next=head;
    head=newnode;
    printf("node inserted\n");
    
}

struct node *reverse(struct node *head)
{
    struct node *prev=NULL;
    struct node *curr=head;
    struct node *next=NULL;
    while(curr!=NULL)
    {
      next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;
    }
    return prev;
}

bool isPalindrome()
{
  if(head==NULL || head->next==NULL)
  {
      return true;
  }
  struct node *slow=head;
  struct node *fast=head;
  while(fast!=NULL && fast->next!=NULL)
  {
      slow=slow->next;
      fast=fast->next->next;
  }
  struct node *secondHalf=reverse(slow);
  struct node *firstHalf=head;
  struct node *temp=secondHalf;
  while(temp!=NULL)
  {
      if(firstHalf->data!=temp->data)
      {
          return false;
      }
      firstHalf=firstHalf->next;
      temp=temp->next;
  }
  return true;
}

void display()
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int n,val;
    printf("Enter n:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        insertatBegin(val);
    }
    printf("Linked list:\n");
    display();
    if(isPalindrome())
    {
        printf("LL is a Palindrome");
    }
    else
    {
        printf("Not a palindrome");
    }
    return 0;
}