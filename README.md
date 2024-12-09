c语言学习
Mysort.h包含对任意类型数组冒泡排序和快速排序的实现
void quickSort(void* arr,int elementSize, int elementNum, int compare(void* ,void *))
第一个参数传入数组指针，第二个参数数组元素大小，第三个参数元素个数，第四个参数为比较器


LinkList.h包含对于链表一般操作的实现

ArrOutput实现了一个数组输出函数arrPrint:void arrPrint(void* arr, int elementSize, int length, void output(void *))
第一个参数传入数组指针，第二个参数数组元素大小，第三个参数元素个数，第四个参数为元素输出方法
