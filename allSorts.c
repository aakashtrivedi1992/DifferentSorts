#include <stdio.h>

//BUBBLE SORT
void bubbleSort(int* array, int n)
{
   int x = 0;
   int y = 0;
   int temp = 0;

   for(x = 0; x < n; x++)
   {
      for(y = 0; y < n-1; y++)
      {
         if(array[y] > array[y + 1])
         {
            temp = array[y + 1];
            array[y + 1] = array[y];
            array[y] = temp;
         }
      }
   }
}

//RADIX SORT
void radixSort(int *theArray, int size)
{
   int i;
   int sorted[size];
   int largestNumber = theArray[0];
   int exp = 1;

   for (i = 0; i < size; i++)
   {
      if (theArray[i] > largestNumber)
      {
         largestNumber = theArray[i];
      }
   }

   while (largestNumber / exp > 0)
   {
      int bucket[10] = { 0 };
   
      for (i = 0; i < size; i++)
      {
         bucket[theArray[i] / exp % 10]++;
      }
   
      for (i = 1; i < 10; i++)
      {
         bucket[i] += bucket[i - 1];
      }
   
      for (i = size - 1; i >= 0; i--)
      {
         sorted[--bucket[theArray[i] / exp % 10]] = theArray[i];
      }
   
      for (i = 0; i < size; i++)
      {
         theArray[i] = sorted[i];
      }
   
      exp *= 10;
   }
}

//INSERTION SORT
void insertionSort(int *array, int size)
{
   int c = 0;
   int d = 0;
   int temp = 0;

   for (c = 1 ; c <= size - 1; c++)
   {
      d = c;
   
      while ( d > 0 && array[d] < array[d - 1])
      {
         temp = array[d];
         array[d] = array[d - 1];
         array[d - 1] = temp;
         d--;
      }
   }
}

//MERGE SORT
int merge(int arr[], int l, int m, int h, int size)
{
   int arr1[size];
   int arr2[size];
   int n1 = 0;
   int n2 = 0;
   int i = 0;
   int j = 0;
   int k = 0;

   n1 = m - l + 1;
   n2 = h - m;

   for(i = 0; i < n1; i++)
   {
      arr1[i] = arr[l + i];
   }

   for(j = 0; j < n2; j++)
   {
      arr2[j] = arr[m + j + 1];
   }

   arr1[i] = 9999;
   arr2[j] = 9999;

   for(k = l; k <= h; k++)
   {
      if(arr1[i] <= arr2[j])
      {
         arr[k] = arr1[i++];
      }
      
      else
      {
         arr[k] = arr2[j++];
      }
   }

   return 0;
}

//MERGE SORT (CONTINUED)
int mergeSort(int arr[], int low, int high, int size)
{
   int mid;

   if(low < high)
   {
      mid = (low + high) / 2;
   
      mergeSort(arr, low, mid, size);
      mergeSort(arr, mid + 1, high, size);
   
      merge(arr, low, mid, high, size);
   }

   return 0;
}

//SHELL'S SORT
void shellSort(int *array, int size)
{
   int i = 0;
   int j = 0;
   int increment = 0;
   int temp = 0;

   for(increment = size / 2; increment > 0; increment /= 2)
   {
      for(i = increment; i < size; i++)
      {
         temp = array[i];
      
         for(j = i; j >= increment; j -= increment)
         {
            if(temp < array[j - increment])
            {
               array[j] = array[j - increment];
            }
            
            else
            {
               break;
            }
         }
      
         array[j] = temp;
      }
   }
}


int main(int argc, char *argv[])
{
   int arraySize = 0;
   int sortChoice = 0;
   int i = 0;

   printf("HELLO. WELCOME TO THE SORTING PROGRAM.\n\n");
   printf("Please enter the number corresponding to the sort that you would like to do.\n\n");

   printf("1. BUBBLE SORT\n2. RADIX SORT\n3. INSERTION SORT\n4. MERGE SORT\n5. SHELL'S SORT\n\n");
   scanf("%d", &sortChoice);

   printf("\n\nPlease enter the size of the array: ");
   scanf("%d", &arraySize);

   int theArray[arraySize];

   printf("Please enter the %d elements in the array (INTEGERS).\n", arraySize);

   for (i = 0; i < arraySize; i++)
   {
      scanf("%d", &theArray[i]);
   }

   switch(sortChoice)
   {
      case 1:
         {
            bubbleSort(theArray, arraySize);
            break;
         }
      
      case 2:
         {
            radixSort(theArray, arraySize);
            break;
         }
      
      case 3:
         {
            insertionSort(theArray, arraySize);
            break;
         }
      
      case 4:
         {
            mergeSort(theArray, 0, arraySize - 1, arraySize);
            break;
         }
      
      case 5:
         {
            shellSort(theArray, arraySize);
            break;
         }
   }

   printf ("SORTED ARRAY:\n\n");

   for (i = 0; i < arraySize; i++)
   {
      printf("%d   ", theArray[i]);
   }

   printf("\n");

   return 0;
}
