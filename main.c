#include <stdio.h>
#include <stdlib.h>
#include "MySort.h"
#include "Macro.h"

//���������
void integerOutput(void* a);

//���αȽ���
int integerCompare(void * a, void * b);

int main(void) {
//    int arr[] = {342,444,234,1112,442};
//    quickSort(arr,sizeof (arr[0]), sizeof (arr)/sizeof (arr[0]),integerCompare);
//    arrPrint(arr, sizeof (arr[0]), sizeof (arr)/sizeof (arr[0]),integerOutput);
}

void integerOutput(void* a) {
    printf("%d\n", *((int *)a));
}

int integerCompare(void * a, void * b){
    return *((int*) b) - *((int*) a);
}