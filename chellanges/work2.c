#include <stdio.h>
#include <stdlib.h>
int main (){
    int a, choix;
    do {

        printf("entr�e ann�e: ");
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
            printf("l'ann�e en mois est : %d", a*12);
        break;
        case 2:
            printf("l'ann�e en jours est : %d", a*365);
        break;
        case 3:
            printf("l'ann�e en heures est : %d", a*365*24);
        break;
        case 4:
            printf("l'ann�e en mois est : %d", a*365*24*60);
        break;
        case 5:
            printf("l'ann�e en mois est : %d", a*365*24*60*60);
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
