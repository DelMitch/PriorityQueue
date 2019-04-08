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


struct priority_queue
{
    int value;
    int priority;
    struct priority_queue * next;
} *head = NULL;


// Shows value of element at the front of the PQ
int front()
{
    // write this
    return 0;
}

// Removes a value from the front of a PQ
// and establishes a new front
void pop()
{
    // write this
}

// Adds an element to the PQ, then sorts
void push(int item)
{
    // write this
}

// Returns the size of the PQ
int size()
{
    // write this
    return 0;
}

// Returns true if the PQ is empty, false otherwise
bool empty()
{
    // write this
    return false;
}