#pragma once


int AreaFastSortSwap (int* array, int l, int r) {
	int i = l, j = r;
	int x = array[l];


	while (i<j)
	{
		while (i < j && array[j] >= x)
			j--;
		if (i<j)
		{
			array[i] = array[j];
			i++;
		}
		
		while (i < j && array[i] < x)
			i++;

		if (i<j)
		{
			array[j] = array[i];
			j--;
		}

	}

	array[i] = x;

	return i;
}


void FastSort(int* array, int l, int r) {
	
	if (l<r)
	{
		int i = AreaFastSortSwap(array, l, r);
		FastSort(array, l, i-1);
		FastSort(array, i + 1, r);
	}

}

void FastSort(int* array, int length)
{
	FastSort(array, 0, length - 1);
}