#include <stdio.h>

int my_array[] = {1,23,17,4,-5, 100};
int *ptr;

int main(void)
{
	int i;
	ptr = my_array;
	
	printf("sizeof array: %d\n", sizeof(my_array[0]));
	printf("\n\n");
	for(i=0;i<6;i++)
	{
		printf("my_array[%d] = %d",i,my_array[i]);
		printf("\tptr + %d = %d \n", i, *(ptr++));
	}
	return 0;
}
