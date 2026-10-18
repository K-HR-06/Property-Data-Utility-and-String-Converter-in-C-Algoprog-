#include <stdio.h>
#include <string.h>


int main(){

    char s[100];

    scanf("%s", s);
    getchar();

    char new[100];
    int a = 0;

    for (int i = strlen(s) - 1; i >= 0; i--){
        new[a] = s[i];
        a++;
    }

    for (int j = 0; j < strlen(s); j++){
        if (new[j] >= 'A' && new[j] <= 'Z'){
            new[j] = new[j] + 32;
        } else if (new[j] >= 'a' && new[j] <= 'z'){
            new[j] = new[j] - 32;
        }
    }


    for (int k = 0; k < strlen(s); k++){
        printf("%c", new[k]);
    }

    printf("\n");

    return 0;
}