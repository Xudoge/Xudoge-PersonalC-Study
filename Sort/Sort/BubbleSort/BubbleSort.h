#pragma once
#include "Swap.h"

//冒泡排序
void BubbleSort(int* array, int length) {


	for (size_t i = 1; i < length; i++)
	{
		for (size_t j = 0; j < length - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}

}