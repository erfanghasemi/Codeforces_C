#include <stdio.h>

int find_max(int a[], int length);
void counting_sort(int a[], int length);


int main() {

    int n, q ;
    long long sum = 0;

    scanf("%d", &n);
    scanf("%d", &q);

    int array_n[200000] = {0};
    int array_temp[200001]= {0};

    for (int i = 0; i < n; i++) {
        scanf("%d", &array_n[i]);
        array_temp[i] = 0;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d", &l);
        scanf("%d", &r);
        array_temp[l-1]++;
        array_temp[r]--;
    }


    for (int i = 1; i <= n; i++) {
        array_temp[i] = array_temp[i - 1] + array_temp[i];
    }

    counting_sort(array_n , n);
    counting_sort(array_temp , n);

    for(int i = 0 ; i < n  ; i++){
        sum += (array_temp[i] * array_n[i]);
    }

    printf("%I64d" , sum);

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