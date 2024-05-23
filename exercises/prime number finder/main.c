#include <stdio.h>
void
quicksort (int *A, int len)
{
  if (len < 2)
	return;
  int pivot = A[len / 2];
  int i, j;
  for (i = 0, j = len - 1;; i++, j--)
	{
	  while (A[i] < pivot)
		i++;
	  while (A[j] > pivot)
		j--;
	  if (i >= j)
		break;
	  int temp = A[i];
	  A[i] = A[j];
	  A[j] = temp;
	}
  quicksort (A, i);
  quicksort (A + i, len - i);
}

int
main ()
{
//   printf ("Hello World");
  int array[]={10,3,7,15,2,1};
    quicksort(array, 6);
    
    for(int i=0; i<6;i++){
        printf("%d ", array[i]);
    }
  return 0;
}
