
#include <locale>
#include <vector>

#include "DListNode.h"
#include "ListNode.h"
//
// Created by vinayak on 02-08-2024.
//
using namespace std;

DListNode* ArrToDLL(vector<int>& arr) {
    int n = arr.size();
    DListNode* head = new DListNode(arr[0]);
    DListNode* prev = head;
    for (int i=1;i<n;i++) {
        DListNode* temp = new DListNode(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

DListNode* removeHead(DListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    DListNode* prev = head;
    head = head->next;

    head->prev = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

DListNode* removeTail(DListNode* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    DListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    DListNode* newTail = tail->prev;
    newTail->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    return head;
}

DListNode* removeKth(DListNode* head,int k) {
    if(head == NULL) return NULL;
    int cnt = 0;
    DListNode* kthNode = head;
    while (kthNode != NULL) {
        cnt++;
        if (cnt == k) {
            break;
        }
        kthNode = kthNode->next;
    }
    DListNode* prev = kthNode->prev;
    DListNode* front = kthNode->next;
    if (prev == NULL && front == NULL) {
        return NULL;
    }
    if(prev == NULL) {
        return removeHead(head);
    }
    if(front == NULL) {
        return removeTail(head);
    }
    prev->next = front;
    front->prev = prev;
    kthNode->next = nullptr;
    kthNode->prev = nullptr;
    delete kthNode;
    return head;
}

DListNode* insertBeforeHead(DListNode* head,int val) {
    DListNode* newNode = new DListNode(val,head,nullptr);
    head->prev = newNode;
    return newNode;
}

DListNode* insertBeforeTail(DListNode* head,int val) {
    if (head->next == NULL) {
        return insertBeforeHead(head,val);
    }
    DListNode* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    DListNode* pre = tail->prev;
    DListNode* newNode = new DListNode(val,tail,pre);
    tail->prev = newNode;
    pre->next = newNode;
    return head;
}

DListNode* insertBeforeKthElement(DListNode* head,int val,int k) {
    if (k==1) {
        return insertBeforeHead(head,val);
    }
    DListNode* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) break;
        temp = temp->next;
    }
    DListNode* pre = temp->prev;
    DListNode* newNode = new DListNode(val,temp,pre);
    pre->next = newNode;
    temp->prev = newNode;
    return head;
}