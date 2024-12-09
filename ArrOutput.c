//
// Created by 14130 on 2024/12/9.
//
#include "ArrOutput.h"
void arrPrint(void* arr, int elementSize, int length, void output(void *));

void arrPrint(void* arr, int elementSize, int length, void output(void *)){
    for (int i = 0; i < length; ++i) {
        output(arr + i * elementSize);
    }
}