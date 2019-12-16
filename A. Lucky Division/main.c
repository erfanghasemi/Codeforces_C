#include <stdio.h>

int main() {

    int n , flag = 0;
    scanf("%d" , &n);

    int lucky_array[] = {4,7,47,74,44,444,447,474,477,777,774,744};

    for(int i = 0 ; i < 12 ; i++){
        if(n %lucky_array[i] == 0){
            flag = 1;
        }
    }

    if(flag == 1){
        printf("YES");
    }
    else{
        printf("NO");
    }

}
