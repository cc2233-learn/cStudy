#include <stdio.h>
#include <stdlib.h>
#include "mySort.h"

typedef struct listNode{
    int data;
    struct listNode* next;
}listNode;

//创建一个空结点
listNode * creatNode(){
    listNode *temp = (listNode *) malloc(sizeof (listNode));
    temp->next = NULL;
    return temp;
}

//以数组形式创建链表
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

//遍历链表
void visitList(listNode *root) {
    if (root == NULL) {
        return;
    }
    for (listNode *i = root->next; i != NULL; i = i->next) {
        printf("%d\n",i->data);
    }
}

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

//数组输出（数组指针，每个元素大小，数组元素个数，元素的输出打印方法）
void arrPrint(void* arr, int elementSize, int length, void output(void *));

//整数输出器
void integerOutput(void* a);

//整形比较器
int integerCompare(void * a, void * b);

int main(void) {
    int arr[] = {342,444,234,1112,442};
    quickSort(arr,sizeof (arr[0]), sizeof (arr)/sizeof (arr[0]),integerCompare);
    arrPrint(arr, sizeof (arr[0]), sizeof (arr)/sizeof (arr[0]),integerOutput);
}

void arrPrint(void* arr, int elementSize, int length, void output(void *)){
    for (int i = 0; i < length; ++i) {
        output(arr + i * elementSize);
    }
}

void integerOutput(void* a) {
    printf("%d\n", *((int *)a));
}

int integerCompare(void * a, void * b){
    return *((int*) b) - *((int*) a);
}