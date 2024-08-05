#include <wchar.h>
//
// Created by vinayak on 03-08-2024.
//
using namespace std;
#include "DListNode.h"

DListNode* reverseDLL(DListNode * head)
{
        if (head == NULL || head->next == NULL) {
                return head;
        }
        DListNode* pre = NULL;
        DListNode* curr = head;
        while (curr != NULL) {
                pre = curr->prev;
                curr->prev = curr->next;
                curr->next = pre;
                curr = curr->prev;
        }
        return pre->prev;
}