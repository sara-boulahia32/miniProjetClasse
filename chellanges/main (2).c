/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main (){
    int a, choix;
    int b=0;
    do {

        printf("entrée année: ");
        scanf("%d", &a);
        printf("MENU\n");
        printf("1- convertir annee en mois\n ");
        printf("2- convertir annee en jours \n");
        printf("3- convertir annee en heures \n");
        printf("4- convertir annee en minutes \n");
        printf("5- convertir annee en secondes \n");
        printf("6- exit. \n");
        scanf("%d", &choix);
        
        if (choix==2||choix==3|| choix==4||choix==5){
            if((a%4==0 && a%100!=0)||(a%400==0)){
                b=366;
            }else{
                b=365;
            }
        }
        switch (choix){
        case 1:
            printf("l'année en mois est : %d\n", a*12);
        break;    
        case 2:
            printf("l'année en jours est : %d\n", a*b);
        break;
        case 3:
            printf("l'année en heures est : %d\n", a*b*24);
        break;
        case 4:
            printf("l'année en mois est : %d\n", a*b*24*60);
        break;
        case 5:
            printf("l'année en mois est : %d\n", a*b*24*360);
        break;
        case 6:
            printf("exiting...");
            exit(0);
        break;
        default:
            printf("choix impossible\n");
        break;
        }
    }while(choix!=6);

    return 0;
}

