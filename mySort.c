#include <stdbool.h>
#include <memory.h>

//
// Created by 14130 on 2024/12/2.
//


//冒泡排序
void myBubbleSort(void* arr,int elementSize, int elementNum, int compare(void* ,void *));

//交换两个指针的数据
void swapS(void * a, void * b, int size);

//快速排序
void quickSort(void* arr,int elementSize, int elementNum, int compare(void* ,void *));

//快速排序递归实现
void myQuickSort(void* arr, int left, int right, int size,int compare(void* ,void *));

//快速排序
void myQuickSort(void* arr, int left, int right, int size,int compare(void* ,void *)){
    if (left >= right) {
        return;
    }
    void* standard = arr + right * size;
    int target = left;
    for (int i = left; i < right - 1; ++i) {
        if (compare(arr + i * size,standard) > 0) {
            if (i == target) {
                target++;
                continue;
            }
            swapS(arr + target * size, arr + i * size,size);
            target++;
        }
    }
    swapS(arr + target * size, standard, size);
    myQuickSort(arr, left, target - 1,size,compare);
    myQuickSort(arr,target + 1,right,size,compare);
}

void quickSort(void* arr,int elementSize, int elementNum, int compare(void* ,void *)){
    myQuickSort(arr, 0, elementNum - 1, elementSize,compare);
}


//冒泡排序(数组指针，每个元素大小，数组元素个数，元素比较器)
void myBubbleSort(void* arr,int elementSize, int elementNum, int compare(void* ,void *)){
    for (int i = elementNum - 1; i > 0; --i) {
        bool swapped = true;
        for (int j = 0; j < i; j++){
            if (compare(arr + j * elementSize, arr + (j + 1) * elementSize) > 0) {
                swapS(arr + j * elementSize, arr + (j + 1) * elementSize, elementSize);
                swapped = false;
            }
        }
        if (swapped){
            break;
        }
    }
}

//交换两个指针指向的数据
void swapS(void * a, void * b, int size) {
    char* temp[size];
    memcpy(temp,a,size);
    memcpy(a,b,size);
    memcpy(b,temp,size);
}
