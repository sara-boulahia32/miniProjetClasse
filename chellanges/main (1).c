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
    do {

        printf("entrée année: ");
        scanf("%d", &a);
        printf("MENU");
        printf("1- convertir annee en mois\n ");
        printf("2- convertir annee en jours \n");
        printf("3- convertir annee en heures \n");
        printf("4- convertir annee en minutes \n");
        printf("5- convertir annee en secondes \n");
        printf("6- exit. \n");
        scanf("%d", &choix);
        switch (choix){
        case 1:
            printf("l'année en mois est : %d", a*12);
        break;
        case 2:
            printf("l'année en jours est : %d", a*365);
        break;
        case 3:
            printf("l'année en heures est : %d", a*365*24);
        break;
        case 4:
            printf("l'année en mois est : %d", a*365*24*60);
        break;
        case 5:
            printf("l'année en mois est : %d", a*365*24*60*60);
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

