//
// Created by 14130 on 2024/12/9.
//
#include <stdlib.h>
#include <stdio.h>
#include "LinkList.h"

//创建一个空结点
listNode * creatNode();

void appendData(listNode *root,const int *input,int length);

void visitList(listNode *root);

void deleteNode(listNode *root,int input);

//根据data删除结点
void deleteNode(listNode *root,int input) {
    if (root == NULL || root->next == NULL) {
        return;
    }
    if (root->next->data == input) {
        free(root->next);
        root->next = NULL;
        return;
    }
    listNode *last = root;
    for (listNode *i = root->next; i != NULL; i = i->next) {
        if(i->data == input) {
            last->next = i->next;
            free(i);
            i = NULL;
            return;
        }
        last = last->next;
    }
}

//遍历链表
void visitList(listNode *root) {
    if (root == NULL) {
        return;
    }
    for (listNode *i = root->next; i != NULL; i = i->next) {
        printf("%d\n",i->data);
    }
}

//以数组形式创建链表，链表的头结点不存数据
void appendData(listNode *root,const int *input,int length){
    if (root == NULL) {
        return;
    }
    listNode *now = root;
    for (int i = 0; i < length; ++i) {
        listNode *temp = creatNode();
        temp->data = input[i];
        now->next = temp;
        now = temp;
    }
}

listNode * creatNode(){
listNode *temp = (listNode *) malloc(sizeof (listNode));
temp->next = NULL;
return temp;
}
