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
//
// PQs may be created with the head as NULL
// and with the head containing valid data
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

    printf("\nTotal Passed: %i/%i\n\n", pass_num, test_num);
}

// Tests the push() and pop() functions
void push_tests()
{
    int pass_num = 0, test_num = 0;
    
    printf("ASSERT: front(&pq0) == 4 after node * pq0 = new_node(4)\n");
    ++test_num;
    node * pq0 = new_node(4);
    if (front(&pq0) == 4)
    {
        printf("PASS: highest priority element is 4 after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 4 after creation with new_node\n\n");
    }

    printf("\nTotal Passed: %i/%i\n\n", pass_num, test_num);
}

// Tests the push() and pop() functions
void pop_tests()
{
    int pass_num = 0, test_num = 0;
    
    printf("ASSERT: front(&pq0) == 4 after node * pq0 = new_node(4)\n");
    ++test_num;
    node * pq0 = new_node(4);
    if (front(&pq0) == 4)
    {
        printf("PASS: highest priority element is 4 after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 4 after creation with new_node\n\n");
    }

    printf("\nTotal Passed: %i/%i\n\n", pass_num, test_num);
}

// Tests the front(), size(), and empty() functions
void front_tests()
{
    int pass_num = 0, test_num = 0;

    printf("ASSERT: front(&pq0) == 4 after node * pq0 = new_node(4)\n");
    ++test_num;
    node * pq0 = new_node(4);
    if (front(&pq0) == 4)
    {
        printf("PASS: highest priority element is 4 after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 4 after creation with new_node\n\n");
    }

    printf("ASSERT: front(&pq1) == 5 after node * pq1 = NULL and push(&pq1, 5)\n");
    ++test_num;
    node * pq1 = NULL;
    push(&pq1, 5);
    if (front(&pq1) == 5)
    {
        printf("PASS: highest priority element is 4 after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 4 after creation with new_node\n\n");
    }

    printf("ASSERT: front(&pq0) == 4 after push(&pq0, 7)\n");
    ++test_num;
    push(&pq0, 7);
    if (front(&pq0) == 4)
    {
        printf("PASS: highest priority element is 4 after pushing 7\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 4 after pushing 7\n\n");
    }

    printf("ASSERT: front(&pq0) == 2 after push(&pq0, 2)\n");
    ++test_num;
    push(&pq0, 2);
    if (front(&pq0) == 2)
    {
        printf("PASS: highest priority element is 2 after pushing 2\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 2 after pushing 2\n\n");
    }

    printf("ASSERT: front(&pq0) == 4 after pop(&pq0)\n");
    ++test_num;
    pop(&pq0);
    if (front(&pq0) == 4)
    {
        printf("PASS: highest priority element is 4 after popping\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 4 after popping\n\n");
    }

    printf("ASSERT: pq1 == NULL after pop(&pq1)\n");
    ++test_num;
    pop(&pq1);
    if (pq1 == NULL)
    {
        printf("PASS: head is NULL after popping\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: head is NOT NULL after popping\n\n");
    }

    printf("\nTotal Passed: %i/%i\n\n", pass_num, test_num);
}

// Tests the push() and pop() functions
void size_tests()
{
    int pass_num = 0, test_num = 0;
    
    printf("ASSERT: front(&pq0) == 4 after node * pq0 = new_node(4)\n");
    ++test_num;
    node * pq0 = new_node(4);
    if (front(&pq0) == 4)
    {
        printf("PASS: highest priority element is 4 after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 4 after creation with new_node\n\n");
    }

    printf("\nTotal Passed: %i/%i\n\n", pass_num, test_num);
}

// Tests the push() and pop() functions
void empty_tests()
{
    int pass_num = 0, test_num = 0;
    
    printf("ASSERT: empty(&pq0) == true after node * pq0 = NULL\n");
    ++test_num;
    node * pq0 = NULL;
    if (empty(&pq0))
    {
        printf("PASS: empty is TRUE after creation with NULL\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: empty is FALSE after creation with NULL\n\n");
    }

    printf("ASSERT: empty(&pq1) == false after node * pq1 = new_node(4)\n");
    ++test_num;
    node * pq1 = new_node(4);
    if (!empty(&pq1))
    {
        printf("PASS: empty is FALSE after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL:  empty is TRUE after creation with new_node\n\n");
    }
    
    printf("ASSERT: empty(&pq1) == false after pop(&pq1)\n");
    ++test_num;
    pop(&pq1);
    if (empty(&pq1))
    {
        printf("PASS: empty is TRUE after popping\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: empty is FALSE after popping\n\n");
    }

    printf("\nTotal Passed: %i/%i\n\n", pass_num, test_num);
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