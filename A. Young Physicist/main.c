#include <stdio.h>

int main() {

    int n ,sumOfX = 0 , sumOfY = 0 , sumOfZ = 0;
    scanf("%d" ,&n );



    int vectors[n][3];

    for(int i = 0 ; i < n ; i++){
        for(int j= 0 ; j < 3 ; j++){
            scanf("%d" , &vectors[i][j]);
        }
    }

    for(int i = 0 ; i < n ; i++){
        sumOfX += vectors[i][0];
        sumOfY += vectors[i][1];
        sumOfZ += vectors[i][2];
    }

    if(sumOfX == 0 && sumOfY == 0 && sumOfZ == 0){
        printf("YES");
    }
    else{
       printf("NO");
    }




}
