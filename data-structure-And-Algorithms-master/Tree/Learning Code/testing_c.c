#include <stdio.h>
#include <string.h>
int main(){
    char string[50];
    gets(string);
    int i ;
    for(i=0;i<strlen(string);i++){
            if(string[i]==' '){
                printf("\n");
            }else{
                printf("%c",string[i]);
            }
    }
    return 0;
}
