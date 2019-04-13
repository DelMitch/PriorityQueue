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
    
    printf("ASSERT: push(&pq0, 3) after node * pq0 = new_node(4)\n");
    ++test_num;
    node * pq0 = new_node(4);
    int pq0_size = size(&pq0);
    push(&pq0, 3);
    if (front(&pq0) == 3 && size(&pq0) == pq0_size + 1)
    {
        printf("PASS: head->data == 3 when pushed in after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: head->data != 3 when pushed in after creation with new_node\n\n");
    }
    
    printf("ASSERT: push(&pq0, 7) after node * pq1 = NULL\n");
    ++test_num;
    node * pq1 = NULL;
    int pq1_size = size(&pq1);
    push(&pq1, 7);
    if (front(&pq1) == 7 && size(&pq1) == pq1_size + 1)
    {
        printf("PASS: head->data == 7 when after creation with NULL\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: head->data != 7 when after creation with NULL\n\n");
    }
    
    printf("ASSERT: push(&pq0, 9) inserted as tail\n");
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
        printf("PASS: tail->data == 9 after pushing\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: tail->data != 9 after pushing\n\n");
    }
    
    printf("ASSERT: push(&pq0, 6) inserted in middle\n");
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
        printf("PASS: mid->data == 6 after pushing\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: mid->data != 6 after pushing\n\n");
    }
    
    printf("ASSERT: data in expected order -- 3, 4, 6, 9\n");
    ++test_num;
    node * pq3 = new_node(4);
    push(&pq3, 3);
    push(&pq3, 9);
    push(&pq3, 6);
    if (pq3->data == 3 && pq3->next->data == 4 &&
    pq3->next->next->data == 6 && pq3->next->next->next->data == 9)
    {
        printf("PASS: data is in expected order\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: data is NOT in expected order\n\n");
    }

    printf("=== Total Passed: %i/%i ===\n\n\n", pass_num, test_num);
    t_vals[0] = pass_num;
    t_vals[1] = test_num;
}

// Tests the pop() function
void pop_tests(int t_vals[])
{
    int pass_num = 0, test_num = 0;
    
    printf("ASSERT: pq0 == NULL after node * pq0 = new_node(4) is popped\n");
    ++test_num;
    node * pq0 = new_node(4);
    pop(&pq0);
    if (pq0 == NULL)
    {
        printf("PASS: PQ is NULL after popping\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: PQ is NOT NULL after popping\n\n");
    }
    
    printf("ASSERT: pq0 == NULL after pop is attempled on node * pq0 = NULL\n");
    ++test_num;
    node * pq1 = NULL;
    pop(&pq1);
    if (pq1 == NULL)
    {
        printf("PASS: PQ is still NULL after pop attempt\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: PQ is NOT still NULL after pop attempt\n\n");
    }
    
    printf("ASSERT: pq0 != NULL after 4, 5, 6, & 2 are pushed and one pop is performed\n");
    ++test_num;
    push(&pq0, 4);
    push(&pq0, 5);
    push(&pq0, 6);
    push(&pq0, 2);
    pop(&pq0);
    if (pq0 != NULL)
    {
        printf("PASS: PQ is NOT NULL after popping\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: PQ is NULL after popping\n\n");
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
        printf("PASS: highest priority element is 5 after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: highest priority element is NOT 5 after creation with new_node\n\n");
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
    
    printf("ASSERT: size(&pq0) == 0 after node * pq0 = NULL\n");
    ++test_num;
    node * pq0 = NULL;
    if (size(&pq0) == 0)
    {
        printf("PASS: size is 0 after creation with NULL\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: size is NOT 0 after creation with NULL\n\n");
    }
    
    printf("ASSERT: size(&pq0) == 2 after push(&pq0, 8) and push(&pq0, 3)\n");
    ++test_num;
    push(&pq0, 8);
    push(&pq0, 3);
    if (size(&pq0) == 2)
    {
        printf("PASS: size is 2 after pushing two integers\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: size is NOT 2 after pushing two integers\n\n");
    }

    printf("ASSERT: size(&pq1) == 1 after node * pq1 = new_node(4)\n");
    ++test_num;
    node * pq1 = new_node(4);
    if (size(&pq1) == 1)
    {
        printf("PASS: size is 1 after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: size is NOT 1 after creation with new_node\n\n");
    }
    
    printf("ASSERT: size(&pq1) == 0 after pop(&pq1)\n");
    ++test_num;
    pop(&pq1);
    if (size(&pq1) == 0)
    {
        printf("PASS: size is 0 TRUE after popping\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: size is NOT 0 after popping\n\n");
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

    printf("ASSERT: !empty(&pq1) == true after node * pq1 = new_node(4)\n");
    ++test_num;
    node * pq1 = new_node(4);
    if (!empty(&pq1))
    {
        printf("PASS: !empty is TRUE after creation with new_node\n\n");
        ++pass_num;
    }
    else
    {
        printf("FAIL: !empty is FALSE after creation with new_node\n\n");
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