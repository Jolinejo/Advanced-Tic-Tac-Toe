#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>


typedef struct Node
{
    int data;
    struct Node* next;
} node;

void add_node( node **head , int val)
{
    node *new = malloc( sizeof(node));
    if (new == NULL)
    return;
    new->data= val;
    new->next = NULL;
    node *temp = head ;
    if (*head==NULL)
    *head = new;
   else while(temp->next)
        temp=temp->next;
    temp->next = new;

}

void print (node*head)
{
    if (head == NULL) return;
    node *temp = head;
    while(temp)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

node *findmiddle (node* head)
{
    node *slow = head;
    node *fast = head;
    if (head)
{

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast-> next-> next;
    }
    return (slow);
}
return (NULL);
}

void insert_middle ( node* head , int val)
{
  node *new = malloc (sizeof(node));
  node *middle = findmiddle( head );
  new ->data= val;
  new->next = middle->next;
  middle->next= new;
}

void remove_nth_node ( node *head , int n)
{
    node* first = head;
    node* second = head;
    node *temp;
   for (int i = 0; i < n ; i++)
    {
        second = second->next;
    }
    while (second->next)
    {
        first = first->next;
        second= second->next;
    }
    temp= first->next;
    first->next= temp->next;
    free(temp);
}

void remove_dup( node *head)
{
    node *current= head;
    node * temp;
    while (current->next)
    {
        if(current->data == current->next->data)
        {
           temp = current->next;
           current->next= temp->next ;
           free(temp);
        }
        else current = current->next;
    }
}

void selection_sort(node* head) {
    node *tmp1 = head, *tmp2 ;
    int temp;

    while(tmp1 != NULL) {
        tmp2 = tmp1->next;

        while(tmp2 != NULL) {
            if(tmp2->data < tmp1->data) {
                // Swap data fields
                temp = tmp1->data;
                tmp1->data = tmp2->data;
                tmp2->data = temp;
            }
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
}


 void remove_unsort(node *head)
 {
     selection_sort(head);
     remove_dup(head);
 }

int main ()
{
    node *head= NULL;

  add_node (&head, 7);
  add_node (&head, 8);
  add_node (&head, 8);
  add_node (&head, 8);
  add_node (&head, 12);
  add_node (&head, 11);
  add_node (&head, 9);
  add_node (&head, 12);
  add_node (&head, 14);
  add_node (&head, 14);
  add_node (&head, 9);
  add_node (&head, 9);

remove_unsort(head);
print(head);
 return ;
}
