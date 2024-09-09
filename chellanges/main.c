/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
