/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {
    char nomComplet[50];
    char mail[30];
    char numTel[10];
} contact;
contact info[300];

int main()
{
    int choix, j, trouveContact, check;
    char choixRecherche[50];
    char trouve[50];
    int compteur=0;
    do {
        printf("________________________________________________________________________________________________________________________\n");
        printf("____________________________________________________MENU________________________________________________________________\n\n\n");
        printf("1 - Ajouter un contact.");
        printf("                          2 - rechercher un contact.\n\n");
        printf("3 - modifier un contact.");
        printf("                         4 - supprimer un contact.\n\n");
        printf("5 - afficher vos contacts.");
        printf("                       6 - exit\n\n");
        printf("________________________________________________________________________________________________________________________\n");
        printf("________________________________________________________________________________________________________________________\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch(choix)
        {
            case 1: //add//
            printf("\n_________________________________________AJOUTER UN NOUVEAU CONTACT _____________________________________________________\n\n");
            if (compteur < 300){
                printf("nom complet      : ");
                scanf(" %[^\n]s", info[compteur].nomComplet);
                printf("numero telephone : ");
                scanf(" %[^\n]s", info[compteur].numTel);
                printf("mail             : ");
                scanf(" %[^\n]s", info[compteur].mail);
                compteur++;
                printf("\ncontact ajoute avec succee\n");
            }else{
                printf("liste pleine");
            }
            break;
            case 2: //search//
            printf("\n_____________________________________________RECHERCHE UN CONTACT___________________________________________________________\n");
            printf("entrez nom complet de contact a rechercher  :  ");
            scanf(" %[^\n]s", choixRecherche);
            check=0;
                for(int i=0; i<compteur; i++){
                    if (strcmp(info[i].nomComplet,choixRecherche)==0){
                        printf("||  %s  ||  %s  ||  %s  ||\n", info[i].nomComplet, info[i].numTel, info[i].mail);
                        check=1;
                        break;
                    }
                }
                if(!check){
                    printf("contact introuvable. \n");
                }
            break;
            case 3: //modifier//
            printf("\n______________________________________________MODIFIER UN CONTACT_______________________________________________________\n");
            printf("entrez nom complet de contact a modifier  :  ");
            scanf(" %[^\n]s", trouve);
            check=0;
            for (int i=0; i<compteur; i++){
                    if (strcmp(info[i].nomComplet,trouve)==0){
                        printf("entrez nouveau numero de telephone  :  ");
                        scanf(" %[^\n]s", info[i].numTel);
                        printf("entrez vouvelle adresse mail        :  ");
                        scanf(" %[^\n]s", info[i].mail);
                        printf("contact modifie avec succés.\n");
                        check=1;
                        break;
                    }
                }
            if(!check){
                        printf("contact introuvable.\n");
                    }
            break;
            case 4: //supprimer//
            printf("\n______________________________________________SUPPRIMER UN CONTACT__________________________________________________________\n");
            printf("entrez nom complet de contact a supprimer  :  ");
            scanf(" %[^\n]", trouve);
            check=0;
            for (int i=0; i<compteur; i++){
                if (strcmp(info[i].nomComplet,trouve)==0){
                    for (j=i; j<compteur; j++){
                        info[j]=info[j+1];
                    }
                    compteur--;
                    check=1;
                    printf("Contact supprimee avec succee.\n");
                    break;
                }
            }
            if(!check){
                printf("contact introuvable.\n");
            }
            break;
            case 5: //afficher//
            printf("\n_________________________________________________________AFFICHER LES CONTACTS_________________________________________________\n");
            printf("||  nom complet  ||  telephone  ||  email  ||\n");
            for (int i=0; i<compteur; i++){
                printf("||  %s  ||  %s  ||  %s  ||\n", info[i].nomComplet, info[i].numTel, info[i].mail);
                }
            break;
            case 6:
            printf("exiting...\n");
            exit(0);
            default:
            printf("choix impossible.\n");
        }
    } while (choix != 6);
    return 0;
}