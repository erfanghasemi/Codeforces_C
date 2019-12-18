#include <stdio.h>
#include <ctype.h>

int pcount(char str[], int n);
int maxlength(char str[], int n);

int main() {

    int n;
    scanf("%d" , &n);

    char str[n];

    for(int i= 0; i < n ;i++){
        scanf(" %c" , &str[i]);
    }

    printf("%d ", maxlength(str , n));
    printf("%d", pcount(str , n));

    return 0;
}

int pcount(char str[], int n){

    int flagp = 0;
    int flagu = 1;
    int count =0;
    for(int i= 0; i < n ;i++){

        if (str[i]== '('){
            flagp = 1;
            continue;
        }

        if (flagp ==1 && flagu ==1 && isalpha(str[i])){
            count++;
            flagu=0;
            continue;
        }

        if(str[i]=='_' && flagp == 1){
            flagu =1;
            continue;
        }

        if(str[i]==')'){
            flagp =0;
            flagu =1;
        }


    }

    return count;
}

int maxlength(char str[], int n){

    int flagp = 1;
    int maxlen = 0;
    int currentlen = 0;

    for(int i= 0; i < n ;i++){


        if(str[i]=='('){
            flagp =0;
            if(currentlen > maxlen){
                maxlen = currentlen;
            }
            currentlen=0;
            continue;
        }


        if(str[i]==')'){
            flagp =1;
            continue;
        }

        if (flagp ==1 && isalpha(str[i])){
            currentlen++;
            if(i == n-1){
                if(currentlen > maxlen){
                    maxlen = currentlen;
                }
            }
            continue;
        }

        if(str[i]=='_' && flagp == 1){
            if(currentlen > maxlen){
                maxlen = currentlen;
            }
            currentlen =0;
            continue;
        }

    }


    return maxlen;
}
