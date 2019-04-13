/******************************
 * Addeline Mitchell
 * April 2019
 ******************************
 * Source file for testing the
 * priority queue
 *****************************/

// Include std libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Include PQ header file
#include "priorityqueue.h"

// Tests the ability to create a PQ
void creation_tests()
{
    int pass_num = 0, test_num = 0;

    printf("ASSERT: node * pq = new_node(4)\n");
    ++test_num;
    if (new_node(4))
    {
        printf("PASS: priority queue created with head->data == 4\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: priority queue NOT created with head->data == 4\n\n");
    }

    printf("ASSERT: node * pq = new_node(NULL)\n");
    ++test_num;
    node * pq = NULL;
    if (pq == NULL)
    {
        printf("PASS: priority queue created with head == NULL\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: priority queue NOT created with head == NULL\n\n");
    }

    printf("Total Passed: %i/%i\n\n", pass_num, test_num);
}

// Tests the push() and pop() functions
void push_tests()
{
    
}

// Tests the push() and pop() functions
void pop_tests()
{
    
}

// Tests the front(), size(), and empty() functions
void front_tests()
{
    node * pq = new_node(4);

    printf("ASSERT: front(&pq) == 4\n");
    if (front(&pq) == 4)
    {
        printf("PASS: highest priority element is 4\n\n");
    }
    else
    {
        printf("FAIL: highest priority element is NOT 4\n\n");
    }

    push(&pq, 2);
    printf("%d\n", front(&pq));


    node * pq2 = NULL;
    push(&pq2, 5);
    printf("%d\n", front(&pq2));
}

// Tests the push() and pop() functions
void size_tests()
{
    
}

// Tests the push() and pop() functions
void empty_tests()
{
    
}


int main ()
{
    printf(".:: PQ CREATION TESTING START ::.\n\n");
    creation_tests();
    printf(".:: PQ CREATION TESTING END ::.\n\n");

    printf("\n\n.:: PQ PUSH TESTING START ::.\n\n");
    push_tests();
    printf(".:: PQ PUSH TESTING END ::.\n\n");

    printf("\n\n.:: PQ POP TESTING START ::.\n\n");
    pop_tests();
    printf(".:: PQ POP TESTING END ::.\n\n");

    printf("\n\n.:: PQ FRONT TESTING START ::.\n\n");
    front_tests();
    printf(".:: PQ FRONT TESTING END ::.\n\n");

    printf("\n\n.:: PQ SIZE TESTING START ::.\n\n");
    size_tests();
    printf(".:: PQ SIZE TESTING END ::.\n\n");

    printf("\n\n.:: PQ EMPTY TESTING START ::.\n\n");
    empty_tests();
    printf(".:: PQ EMPTY TESTING END ::.\n\n");

    return 0;
}