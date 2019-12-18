#include <stdio.h>

int detection(char first,char two,char three,char four );

int main() {

    int n , m;
    scanf("%d" , &n);
    scanf("%d" , &m);

    if((m==1) || (n==1)){
        printf("%d" , 0);
        return 0;
    }


    char arrayImage[n][m];
    int counterFace = 0;

    for(int i =0 ; i < n ; i++){
        for(int j=0 ; j< m ; j++){
            scanf(" %c" , &arrayImage[i][j]);
        }
    }




    for(int i = 0 ; i < n-1 ; i++){
        for(int j= 0 ; j< m-1 ; j++){
            counterFace += detection( arrayImage[i][j], arrayImage[i][j+1],arrayImage[1+i][j+1],arrayImage[i+1][j]);
        }
    }

    printf("%d" , counterFace);


    return 0;
}

 detection(char first,char two,char three,char four ){
    char faceString[4];
    faceString[0] = first;
    faceString[1] = two;
    faceString[2] = three;
    faceString[3] = four;

    int existenceF = 0;
    int existenceA = 0;
    int existenceC = 0;
    int existenceE = 0;

    for(int i = 0 ; i < 4 ; i++){
        if (faceString[i] == 'f'){
            existenceF++;
        }

        else if (faceString[i] == 'a'){
            existenceA++;
        }

        else if (faceString[i] == 'c'){
            existenceC++;
        }

        else if (faceString[i] == 'e'){
            existenceE++;
        }
    }

    if(existenceA == 1 && existenceF == 1 && existenceC == 1 && existenceE == 1 ){
        return 1;
    }

    return 0;
}
