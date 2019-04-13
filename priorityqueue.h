/******************************
 * Addeline Mitchell
 * April 2019
 ******************************
 * Header file for a priority
 * queue that holds integers
 ******************************
 * This file contains the implementation for a
 * Priority Queue data structure that holds
 * integers and for which the highest priority
 * integer is the lowest in value
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
    if((* head) == NULL)
    {
        (* head) = new_node(val);
    }
    else
    {
        node * new_val = new_node(val);

        node * item = (* head);
        node * prev = NULL;

        // in the case that the new value has higher priority
        // than the current head
        if (new_val->data < (* head)->data)
        {
            new_val->next = (* head);
            (* head) = new_val;
        }
        else
        {
            while (item != NULL)
            {
                // in the case that the new value belongs somewhere
                // in the middle
                if (new_val->data < item->data && prev != NULL)
                {
                    prev->next = new_val;
                    new_val->next = item;
                }
                // in the case that the new value is larger than every
                // other value in the PQ
                else if (new_val->data > item->data && item->next == NULL)
                {
                    item->next = new_val;
                }
                
                prev = item;
                item = item->next;
            }
        }
    }
}

// Removes a value from the front of a PQ
// and establishes a new front
void pop(node** head)
{
    if ((* head) != NULL)
    {
        node * del = (* head);
        (* head) = del->next;
        
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

    if ((* head) != NULL)
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
    return (* head) == NULL;
}