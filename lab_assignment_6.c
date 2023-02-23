#include <stdio.h>
#include <stdlib.h>

int search(int numbers[], int low, int high, int value) 
{
	//If low is greater than high, value was not in array
	if(low > high)
        return -1; 
   
    else
	{
		//find the middle of the array
        int avg = (high + low) / 2;

		//if value is at the middle index return index
        if (value == numbers[avg])
			return avg;

		//if value is greater/equal tothe middle index, shift to the right one
    	else if (value >= numbers[avg])
			//recursion; add one to low to increase the index      
            return search(numbers, low + 1, high, value);
			
		//if value is less then the middle index, shift to the left one
        else
			//recursion;subtract high by one to lower the index                        
            return search(numbers, low, high - 1, value);
	}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}