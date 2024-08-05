#include <wchar.h>

#include "DListNode.h"
//
// Created by vinayak on 03-08-2024.
//
using namespace std;

DListNode* oddEvenList(DListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    DListNode* head1 = head;
    DListNode* temp1 = head1;
    DListNode* head2 = head->next;
    DListNode* temp2 = head2;
    while(temp2 != NULL && temp2->next != NULL) {
        temp1->next = temp1->next->next;
        temp2->next = temp2->next->next;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = head2;
    return head1;
}