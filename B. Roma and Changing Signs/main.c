#include <stdio.h>

int find_max(int a[], int length);
void counting_sort(int a[], int length);

int main() {

    int n , k , in , sum = 0;
    scanf("%d"  , &n);
    scanf("%d"  , &k);

    int arrayIncome[n];

    for(int i = 0 ; i < n ;i++ ){

        scanf("%d" , &in);
        if(in < 0 && k > 0){
            in *= -1;
            k--;
        }
        arrayIncome[i] = in;

    }



    if(k % 2 == 1){
        counting_sort(arrayIncome , n);
        arrayIncome[0] *= -1;
    }


    for(int i = 0 ; i < n ; i++){
        sum += arrayIncome[i];
    }

    printf("%d" , sum);
}



void counting_sort(int a[], int length){

    int i, max = find_max(a, length);
    int c[max+1];

    for(i = 0; i < max + 1; c[i++] = 0);

    for(i = 0; i < length; i++) c[a[i]]++;

    for(i = 1; i < max + 1; i++) c[i] = c[i - 1] + c[i];


    int b[length];
    int j = length - 1;
    for(i = 0; i < length; i++) {
        b[--c[a[j]]] = a[j];
        j--;
    }

    for(i = 0; i < length; i++)	a[i] = b[i];

}

int find_max(int a[], int length) {
    int i, max = a[0];
    for (i = 1; i < length; i++) {
        if (max < a[i]) max = a[i];
    }
    return max;
}