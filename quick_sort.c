/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 01:16:26 by amessah           #+#    #+#             */
/*   Updated: 2021/12/22 16:59:39 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int ar[],int low,int high)
{
	int pivot;
	int i;
	
	pivot = ar[high];
	i = (low - 1);
	while (low < high)
	{
		if(ar[low] <= pivot)
		{
			i++;
			swap(&ar[i], &ar[low]);
		}
        low++;
	}
	swap(&ar[i + 1] , &ar[high]);
	return (i + 1);
}
void quicksort(int ar[], int low , int high)
{
	
	if(low < high)
	{
		int pi = partition(ar,low,high);
		quicksort(ar,low,pi - 1);
		quicksort(ar,pi + 1, high);
	}
}

int main()
{
	int ar[] = {8, 7, 2, 1, 0, -9, 6};
	int n;
	n = sizeof(ar) / sizeof(ar[0]);
	int i = 0;
		while(i < n)
	{
		printf("%d\n",ar[i]);
		i++;
	}	
	quicksort(ar,0,n - 1);
	i = 0;
	while(i < n)
	{
		printf("%d - %d \n",ar[i],i);
		i++;
	}	
}
6 - 5 - 2 - 3 - 1 - 0 - 4
6 - 5 - 1 - 0 - 4
 0 - 1 - 2 - 3 - 4 - 5 - 6


// void printArray(int array[], int size) {
//   for (int i = 0; i < size; ++i) {
//     printf("%d  ", array[i]);
//   }
//   printf("\n");
// }


// int main() {
//   int data[] = {8, 7, 2, 1, 0, -9, 6};
  
//   int n = sizeof(data) / sizeof(data[0]);
  
//   printf("Unsorted Array\n");
//   printArray(data, n);
  
//   // perform quicksort on data
//   quicksort(data, 0, n - 1);
  
//   printf("Sorted array in ascending order: \n");
//   printArray(data, n);
// }