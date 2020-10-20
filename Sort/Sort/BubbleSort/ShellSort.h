#pragma once
#include "Swap.h"





void ShellSort(int* array, int length)
{
	int a = length / 2;
	for (int step= a; step>=1 ; step = step / 2)
	{
		

		for (int x=0;x<step;++x)
		{
			for (int y=x+step;y<length;y=y+step)
			{
				for (int z=y;z>0;z=z-step)
				{
					if (array[z]<array[z-step])
					{
						swap(array[z], array[z - step]);
					}
				}
			}
		}
	}
}