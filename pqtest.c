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
void creation_tests(int t_vals[])
{
    int pass_num = 0, test_num = 0;

    // Success when PQ is created with initial head value
    printf("ASSERT: node * pq = new_node(4) successfully creates pq with head == 4\n");
    ++test_num;
    if (new_node(4))
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    // Success when PQ is created without an initial head value
    printf("ASSERT: node * pq = NULL successfully creates pq == NULL\n");
    ++test_num;
    node * pq = NULL;
    if (pq == NULL)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    printf("=== Total Passed: %i/%i ===\n\n\n", pass_num, test_num);
    t_vals[0] = pass_num;
    t_vals[1] = test_num;
}

// Tests the push()function
//
// Can push an element that becomes highest,
// lowest, or middlin' priority
void push_tests(int t_vals[])
{
    int pass_num = 0, test_num = 0;
    
    // Success when head == 3 and the size has increased by 1
    printf("ASSERT: push(&pq0, 3) after node * pq0 = new_node(4) and 3 is now head\n");
    ++test_num;
    node * pq0 = new_node(4);
    int pq0_size = size(&pq0);
    push(&pq0, 3);
    if (front(&pq0) == 3 && size(&pq0) == pq0_size + 1)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when head == 7 and size has increased by 1
    printf("ASSERT: push(&pq1, 7) after node * pq1 = NULL and 7 is now head\n");
    ++test_num;
    node * pq1 = NULL;
    int pq1_size = size(&pq1);
    push(&pq1, 7);
    if (front(&pq1) == 7 && size(&pq1) == pq1_size + 1)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when head == 7, tail == 7, and size has increased by 1
    printf("ASSERT: push(&pq1, 7) a second time and there are now two 7s\n");
    ++test_num;
    pq1_size = size(&pq1);
    push(&pq1, 7);
    if (front(&pq1) == 7 && pq1->next->data == 7 && size(&pq1) == pq1_size + 1)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when tail == 9 and size has increased by 1
    printf("ASSERT: push(&pq0, 9) and 9 is now tail\n");
    ++test_num;
    pq0_size = size(&pq0);
    push(&pq0, 9);
    int pq0_size_post = size(&pq0);
    while(pq0->next != NULL)
    {
        pq0 = pq0->next;
    }
    if (pq0->data == 9 && pq0_size_post == pq0_size + 1)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when 6 is present, but not head or tail, and size has increased by 1
    printf("ASSERT: push(&pq2, 6) and 6 is now between head and tail\n");
    ++test_num;
    node * pq2 = new_node(4);
    push(&pq2, 3);
    push(&pq2, 9);
    int pq2_size = size(&pq2);
    push(&pq2, 6);
    int pq2_size_post = size(&pq2);
    while(pq2->next != NULL && pq2->data < 6)
    {
        pq2 = pq2->next;
    }
    if (pq2->data == 6 && pq2_size_post == pq2_size + 1)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when data is in the correctly prioritized order (3->4->6->9)
    printf("ASSERT: pq3 data order is (3->4->6->9) after multiple values pushed\n");
    ++test_num;
    node * pq3 = new_node(4);
    push(&pq3, 3);
    push(&pq3, 9);
    push(&pq3, 6);
    if (pq3->data == 3 && pq3->next->data == 4 &&
    pq3->next->next->data == 6 && pq3->next->next->next->data == 9)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    printf("=== Total Passed: %i/%i ===\n\n\n", pass_num, test_num);
    t_vals[0] = pass_num;
    t_vals[1] = test_num;
}

// Tests the pop() function
//
// Removes the highest priority item
// from the priority queue
void pop_tests(int t_vals[])
{
    int pass_num = 0, test_num = 0;
    
    // Success when PQ is NULL
    printf("ASSERT: pq0 == NULL for node * pq0 = new_node(4) after pop(&pq0)\n");
    ++test_num;
    node * pq0 = new_node(4);
    pop(&pq0);
    if (pq0 == NULL)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when PQ is NULL
    printf("ASSERT: pq0 == NULL after pop(&pq1) is attempted after node * pq0 = NULL\n");
    ++test_num;
    node * pq1 = NULL;
    pop(&pq1);
    if (pq1 == NULL)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when PQ is NOT NULL
    printf("ASSERT: pq0 != NULL after multiple values pushed followed by pop(&pq0)\n");
    ++test_num;
    push(&pq0, 4);
    push(&pq0, 5);
    push(&pq0, 6);
    push(&pq0, 2);
    pop(&pq0);
    if (pq0 != NULL)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    printf("=== Total Passed: %i/%i ===\n\n\n", pass_num, test_num);
    t_vals[0] = pass_num;
    t_vals[1] = test_num;
}

// Tests the front() function
//
// Front of the PQ is the highest priority item,
// in this case: the lowest integer
void front_tests(int t_vals[])
{
    int pass_num = 0, test_num = 0;

    // Success when head == 4
    printf("ASSERT: front(&pq0) == 4 after node * pq0 = new_node(4)\n");
    ++test_num;
    node * pq0 = new_node(4);
    if (front(&pq0) == 4)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    // Success when head == 5
    printf("ASSERT: front(&pq1) == 5 after node * pq1 = NULL and push(&pq1, 5)\n");
    ++test_num;
    node * pq1 = NULL;
    push(&pq1, 5);
    if (front(&pq1) == 5)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    // Success when head == 4
    printf("ASSERT: front(&pq0) == 4 after push(&pq0, 7)\n");
    ++test_num;
    push(&pq0, 7);
    if (front(&pq0) == 4)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    // Success when head == 2
    printf("ASSERT: front(&pq0) == 2 after push(&pq0, 2)\n");
    ++test_num;
    push(&pq0, 2);
    if (front(&pq0) == 2)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    // Success when head == 4
    printf("ASSERT: front(&pq0) == 4 after pop(&pq0)\n");
    ++test_num;
    pop(&pq0);
    if (front(&pq0) == 4)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    // Success when PQ is NULL
    printf("ASSERT: pq1 == NULL after pop(&pq1)\n");
    ++test_num;
    pop(&pq1);
    if (pq1 == NULL)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    printf("=== Total Passed: %i/%i ===\n\n\n", pass_num, test_num);
    t_vals[0] = pass_num;
    t_vals[1] = test_num;
}

// Tests the size() functions
//
// Size of a PQ is the number of non-NULL nodes,
// cannot be negative
void size_tests(int t_vals[])
{
    int pass_num = 0, test_num = 0;
    
    // Success when size == 0
    printf("ASSERT: size(&pq0) == 0 after node * pq0 = NULL\n");
    ++test_num;
    node * pq0 = NULL;
    if (size(&pq0) == 0)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when size == 2
    printf("ASSERT: size(&pq0) == 2 after push(&pq0, 8) and push(&pq0, 3)\n");
    ++test_num;
    push(&pq0, 8);
    push(&pq0, 3);
    if (size(&pq0) == 2)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    // Success when size == 1
    printf("ASSERT: size(&pq1) == 1 after node * pq1 = new_node(4)\n");
    ++test_num;
    node * pq1 = new_node(4);
    if (size(&pq1) == 1)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when size == 0
    printf("ASSERT: size(&pq1) == 0 after pop(&pq1)\n");
    ++test_num;
    pop(&pq1);
    if (size(&pq1) == 0)
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    printf("=== Total Passed: %i/%i ===\n\n\n", pass_num, test_num);
    t_vals[0] = pass_num;
    t_vals[1] = test_num;
}

// Tests the empty() functions
//
// PQs created as NULL and popped until the head
// is NULL are empty
void empty_tests(int t_vals[])
{
    int pass_num = 0, test_num = 0;
    
    // Success when empty is true
    printf("ASSERT: empty(&pq0) == true after node * pq0 = NULL\n");
    ++test_num;
    node * pq0 = NULL;
    if (empty(&pq0))
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    // Success when NOT empty is true
    printf("ASSERT: !empty(&pq1) == true after node * pq1 = new_node(4)\n");
    ++test_num;
    node * pq1 = new_node(4);
    if (!empty(&pq1))
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }
    
    // Success when empty is true
    printf("ASSERT: empty(&pq1) == true after pop(&pq1)\n");
    ++test_num;
    pop(&pq1);
    if (empty(&pq1))
    {
        printf("PASS\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL\n\n");
    }

    printf("=== Total Passed: %i/%i ===\n\n\n", pass_num, test_num);
    t_vals[0] = pass_num;
    t_vals[1] = test_num;
}


int main ()
{
    int passed = 0, tests = 0;

    int t_vals[2];

    printf(".:: PQ CREATION TESTING START ::.\n\n");
    creation_tests(t_vals);
    passed += t_vals[0];
    tests += t_vals[1];

    printf(".:: PQ PUSH TESTING START ::.\n\n");
    push_tests(t_vals);
    passed += t_vals[0];
    tests += t_vals[1];

    printf(".:: PQ POP TESTING START ::.\n\n");
    pop_tests(t_vals);
    passed += t_vals[0];
    tests += t_vals[1];

    printf(".:: PQ FRONT TESTING START ::.\n\n");
    front_tests(t_vals);
    passed += t_vals[0];
    tests += t_vals[1];

    printf(".:: PQ SIZE TESTING START ::.\n\n");
    size_tests(t_vals);
    passed += t_vals[0];
    tests += t_vals[1];

    printf(".:: PQ EMPTY TESTING START ::.\n\n");
    empty_tests(t_vals);
    passed += t_vals[0];
    tests += t_vals[1];

    printf("=== Tests Passing: %i/%i ===\n\n", passed, tests);

    return 0;
}