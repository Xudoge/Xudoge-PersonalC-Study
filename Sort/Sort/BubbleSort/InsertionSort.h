#pragma once





void InsertionSort(int* array, int length)
{
	
	for (size_t i=1;i<length;i++)
	{
		for (size_t j=i;j>0;j--)
		{
			if (array[j]<array[j-1])
			{
				swap(array[j], array[j - 1]);
			}
		}

	}
};

