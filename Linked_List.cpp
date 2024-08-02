#include <iostream>
#include <vector>
//
// Created by vinayak on 02-08-2024.
//
using namespace std;
#include "ListNode.h"

ListNode* convertArrToLL(vector<int>& list) {
    ListNode* head = new ListNode(list[0]);
    ListNode* mover = head;
    for (int i=1;i<list.size();i++) {
        ListNode* temp = new ListNode(list[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

ListNode* removeHead(ListNode* head) {
    if (head == NULL) return head;
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head;
}

ListNode* removeTail(ListNode* head) {
    if (head == NULL || head->next == NULL) return NULL;
    ListNode* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

// if given an eleemt to remove check for temp.val == element then execute the condition
ListNode* removeK(ListNode* head,int k) {
    if (k == 1) return removeHead(head);
    int cnt = 0;
    ListNode* temp = head;
    ListNode* prev = NULL;
    while (temp != NULL) {
        cnt++;
        if (cnt == k) {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

ListNode* insertHead(ListNode* head,int val) {
    ListNode* temp = new ListNode(val,head);
    return temp;
    // return new ListNode(val,head);
}

ListNode* insertTail(ListNode* head,int val) {
    if (head == NULL) {
        return new ListNode(val);
    }
    ListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    ListNode* newNode = new ListNode(val);
    temp->next = newNode;
    return head;
}

ListNode* insertAtK(ListNode* head,int val,int k) {
    if (head == NULL) {
        if (k == 1) {
            return new ListNode(val);
        }else {
            return NULL;
        }
    }
    if (k == 1) {
        insertHead(head,val);
    }
    int cnt = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        cnt++;
        if(cnt == k-1) {
            ListNode* newNode = new ListNode(val);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}
//insert before some value k will be done by yourself in future if you are seing this code again

int main() {
    vector<int> list = {1,2,3,4,5,6};
    ListNode* head = convertArrToLL(list);
}