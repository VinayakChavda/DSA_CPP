#include <wchar.h>

#include "DListNode.h"
//
// Created by vinayak on 03-08-2024.
//
using namespace std;

DListNode* addTwoNumbers(DListNode* l1, DListNode* l2) {
    DListNode* temp1 = l1;
    DListNode* temp2 = l2;
    DListNode* dummy = new DListNode(-1);
    DListNode* curr = dummy;
    int carry = 0;
    while (temp1 != NULL || temp2 != NULL) {
        int sum = carry;
        if (temp1) sum+=temp1->val;
        if (temp2) sum+=temp2->val;
        DListNode* newNode = new DListNode(sum%10);
        carry = sum/10;
        curr->next = newNode;
        curr = curr->next;
        if (temp1) temp1 = temp1->next;
        if (temp2) temp2 = temp2->next;
    }
    if (carry) {
        DListNode* newNode = new DListNode(carry);
        curr->next = newNode;
    }
    return dummy->next;
}