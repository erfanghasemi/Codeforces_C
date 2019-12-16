#include <stdio.h>

int main() {
    int n;
    scanf("%d" , &n);

    int capacity=0;
    int stillnow=0;
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d" , &a);
        scanf("%d" , &b);
        stillnow -= a;
        stillnow += b;
        if(stillnow > capacity){
            capacity = stillnow;
        }

    }
    printf("%d" , capacity);

    return 0;
}