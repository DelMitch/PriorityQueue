/******************************
 * Addeline Mitchell
 * April 2019
 ******************************
 * Header file for a priority
 * queue that holds integers
 *****************************/

// Include std libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Include memory allocation library
#include <malloc.h>


typedef struct pq_node
{
    int data;
    struct pq_node * next;
} node;

//node * head = NULL;

node * new_node(int val) 
{ 
    node * temp = (node*)malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;
  
    return temp; 
} 

// Adds an element to the PQ according to priority
void push(node** head, int val)
{
    if(head == NULL)
    {
        (* head)->data = val;
        (* head)->next = NULL;
    }
    else
    {
        node * new_val = new_node(val);

        node * item = (* head);
        node * prev = NULL;

        while (item != NULL)
        {
            // in the case that the new value has higher priority
            // than the current head
            if (new_val->data < item->data && prev == NULL)
            {
                new_val->next = item;
                (* head) = new_val;
            }
            // all other cases
            else if (new_val->data < item->data && prev != NULL)
            {
                prev->next = new_val;
                if (item->next != NULL)
                {
                    new_val->next = item;
                }
                else
                {
                    new_val->next = NULL;
                }
            }
            
            prev = item;
            item = item->next;
        }
    }
}

// Removes a value from the front of a PQ
// and establishes a new front
void pop(node** head)
{
    if (head == NULL)
    {
        printf("Priority queue is already empty...\n");
    }
    else
    {
        node * del = (* head);
        (* head) = (* head)->next;
        printf("%d\n", del->data);
        free(del);
    }
}

// Shows value of element at the front of the PQ
int front(node** head)
{
    return (* head)->data;
}

// Returns the size of the PQ
int size(node** head)
{
    int count = 0;

    if (head != NULL)
    {
        node * item = (* head);

        while (item != NULL)
        {
            ++count;
            item = item->next;
        }
    }

    return count;
}

// Returns true if the PQ is empty, false otherwise
bool empty(node** head)
{
    return head == NULL;
}