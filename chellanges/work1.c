#include <stdio.h>
#include <stdlib.h>
int main (){
    int a, b;
    printf("a= ");
    scanf("%d", &a);
    printf("b=  \n");
    scanf("%d", &b);
    if (a==b){
        printf("comme a=b le triple de la somme est : %d", 3*(a+b));
    }else{
        printf("a+b= %d", a+b);
    }
return 0;
}
