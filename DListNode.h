//
// Created by vinayak on 02-08-2024.
//

#ifndef DLISTNODE_H
#define DLISTNODE_H



class DListNode {
public:
    int val;
    DListNode* next;
    DListNode* prev;
    DListNode();
    DListNode(int val);
    DListNode(int val,DListNode* next,DListNode* pre);
};



#endif //DLISTNODE_H
