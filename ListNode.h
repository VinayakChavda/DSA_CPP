//
// Created by vinayak on 02-08-2024.
//

#ifndef LISTNODE_H
#define LISTNODE_H



class ListNode {
public:
    int val;
    ListNode* next;
    ListNode();
    ListNode(int x);
    ListNode(int x,ListNode *next);
};


#endif //LISTNODE_H
