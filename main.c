#include <stdio.h>

void swap(int *xp, int *yp);
void bubbleSort(int arr[], int n);
int main()
{
    int n,flag = 0;

    scanf("%d" , &n);

    int arr[n];

    for(int i = 0 ; i < n ; i++ ) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr , n);

    for(int i = 1 ; i < n ; i++){
        if(arr [i] > arr[i-1])
        {
            printf("%d" , arr[i]);
            flag = 1;
            break;
        }
    }

    if(flag==0)
        printf("NO");

}


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}