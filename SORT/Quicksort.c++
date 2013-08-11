/* Quick sort */

#include <stdio.h>


void QuickSort(int arr[], int left, int right) 
{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
 
      /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
 
      /* recursion */
      if (left < j)
            QuickSort(arr, left, j);
      if (i < right)
            QuickSort(arr, i, right);
}

int main()
{
	int array[100], n, c, d, swap;
	
	printf("Enter number of elements\n");
	scanf("%d", &n);
	
	printf("Enter %d integers\n", n);
	
	for (c = 0; c < n; c++)
		scanf("%d", &array[c]);
	
	QuickSort(array, 0,n-1);	
	
	printf("Sorted list in ascending order:\n");
	
	for ( c = 0 ; c < n ; c++ )
		printf("%d\n", array[c]);
	
	return 0;
}