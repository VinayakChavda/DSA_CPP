//
// Created by vinayak on 02-08-2024.
//

#include "DListNode.h"

DListNode::DListNode():val(0),prev(nullptr),next(nullptr){}

DListNode::DListNode(int val):val(val),prev(nullptr),next(nullptr){}

DListNode::DListNode(int val, DListNode *next, DListNode *pre):val(val),next(next),prev(prev){}


