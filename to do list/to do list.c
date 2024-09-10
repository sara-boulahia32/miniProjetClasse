//TO DO LIST
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

enum statut {
    aRealiser, 
    enCoursDeRealisation, 
    finalisee
};
typedef struct{
    int min;
    int h;
    int j;
    int m;
    int a;
}date;

typedef struct{
    char id[10];
    char titre[20];
    char description[50];
    date deadline;
    enum statut st;
}tache;

tache info[300];
int compteur=0;

int main()
{
    int choix, etat, n, i, j;
    int choixAffichage, jours, trouve; 
    char identifiantModifier[10], nvDescription[50], identifiantSupprimer[10], titreRecherche[20], identifiantRecherche[10];
    int nvStatut, nvJ, nvM, nvA, nvH, nvMin, choixModifier, choixRechercher, choixStatistique, choixExit, complete, incomplete;
    long deadlinejj, deadlinej, deadlinej1;
    time_t current_time;
	time (&current_time);
    struct tm *local_time = localtime(&current_time);
	int year = local_time->tm_year + 1900;
    int month = local_time->tm_mon + 1;
    int day = local_time->tm_mday;
	long tempsActuel=year*365+month*12+day*jours;
	long minuteur;
    do{
        printf("________________________________________________________________________________________________________________________\n");
		printf("____________________________________________________MENU________________________________________________________________\n\n\n");
		printf("1 - Ajouter une nouvelle tache.                          2 - ajoutre plusieurs nv taches.\n\n");
		printf("3 - afficher la liste de toutes les taches.              4 - modifier une tache.\n\n");
		printf("5 - supprimer une tache.                                 6 - rechercher des taches .\n\n");
		printf("7 - statistiques                                         8 - EXIT\n\n");
		printf("________________________________________________________________________________________________________________________\n");
		printf("________________________________________________________________________________________________________________________\n\n");
		printf("Entrez votre choix : ");
		scanf("%d", &choix);
		if(choix==1 || choix==2){
		    if(choix==2){
		        printf("________________________________________AJOUTER PLUSIEURS NOUVELLES TACHES___________________________________________________\n\n\n");
		        printf("combien de taches voulez vous saisir?\n");
		        scanf("%d", &n);
		    }else {
		        printf("_____________________________________________AJOUTER NOUVELLE TACHE__________________________________________________________\n\n\n");
		        n=1;
		    }
		    if(compteur+n<300){
		        for(i=0; i<n; i++){
		            char idEntree[10];
		            int idTrouve;
		            do{
		                idTrouve=1;
		                printf("Entrez l'identifiant de la tache : ");
		                scanf(" %s", idEntree);
		                for (int j = 0; j < compteur; j++) {
		                    if (strcmp(info[j].id, idEntree) == 0) {
		                        idTrouve=0;
		                        printf("identifiant existe deja.\n");
		                        break;
		                    }
		                }
		            }while(!idTrouve);
		            strcpy(info[i + compteur].id, idEntree);
		            printf("entrez le titre de la tache  :   ");
		            scanf(" %[^\n]s", info[i+compteur].titre);
		            printf("entrez une description à la tache  :   ");
		            scanf(" %[^\n]s", info[i+compteur].description);
		            printf("entrez le statut de la tache  :   ");
		            do{
		                printf("\n1 - à réaliser.");
		                printf("                      2 - en cours de réalisation.\n");
		                printf("3 - finalisee.");
		                scanf("%d", &etat);
		            }while(etat>3 || etat<1);
		            info[compteur+i].st=etat-1;
		            printf("Deadline(à quand est elle due?) format(JJ/MM/AA)  :   ");
		            scanf(" %d/%d/%d", &info[i+compteur].deadline.j, &info[i+compteur].deadline.m, &info[i+compteur].deadline.a);
		            printf("a quelle heure est elle due format(hh:mm)  :   ");
		            scanf(" %d:%d", &info[i+compteur].deadline.h, &info[i+compteur].deadline.min);
		            compteur+=n;
		        }
		    } else {
                printf("La liste est pleine.\n");
		    }
		    break;
		}
		switch(choix)
		{
		    case 3:
		    printf("________________________________________________________________________________________________________________________\n");
		    printf("________________________________________________SOUS-MENU_______________________________________________________________\n\n\n");
		    printf("1 - Trier les tâches par ordre alphabétique.                     2 - Trier les tâches par deadline.\n\n");
		    printf("3 - Afficher les tâches dont le deadline est dans 3 jours ou moins\n\n");
		    scanf("%d", &choixAffichage);
		    printf("\n");
		    if(choixAffichage==1 || choixAffichage==2){
		        if(choixAffichage==1){
		            printf("______________________________________________TRI-ALPHABETIQUE____________________________________________________________\n\n\n");
		            for(i=0; i<compteur-1; i++){
		                for(j=0; j<compteur-i-1; j++){
		                    if(strcmp(info[j].titre, info[j+1].titre)>0){
		                        tache temp=info[j];
		                        info[j]=info[j+1];
		                        info[j+1]=temp;
		                    }
		                }
		            }
		        }
		        if(choixAffichage==2){
		            printf("______________________________________________TRI DE DEADLINE______________________________________________________________\n\n\n");
		            for(i=0; i<compteur-1; i++){
		                for(j=0; j<compteur-i-1; j++){
		                    if(info[j].deadline.m==4 || info[j].deadline.m==6 || info[j].deadline.m==9  || info[j].deadline.m==11){
		                        jours=30;
		                    }else if(info[j].deadline.m==1 || info[j].deadline.m==3 || info[j].deadline.m==5  || info[j].deadline.m==7  || info[j].deadline.m==8  || info[j].deadline.m==10 || info[j].deadline.m==12){
		                        jours=31;
		                    }else if(info[j].deadline.m==2){
		                        jours=28;
		                    }
		                    deadlinejj=info[j].deadline.a*365+info[j].deadline.m*12+info[j].deadline.j*jours;
	                        deadlinej=info[j].deadline.a*365+info[j].deadline.m*12+info[j].deadline.j*jours+info[j].deadline.h*24+info[j].deadline.min*60;
	                        deadlinej1=info[j+1].deadline.a*365+info[j+1].deadline.m*12+info[j+1].deadline.j*jours+info[j+1].deadline.h*24+info[j+1].deadline.min*60;
	                        if(deadlinej> deadlinej1){
		                        tache temp=info[j];
		                        info[j]=info[j+1];
		                        info[j+1]=temp;
		                    }
		                }
		            }
		        }
		        printf("___________________________________________AFFICHER LA LISTE DES TACHES______________________________________________________\n\n\n");
		        printf("  || identifiant  ||  titre  ||  desciption  ||  deadline  ||  statut  ||\n");
		        for(i=0; i<compteur; i++){
		            printf("  || %s  ||  %s  ||  %s  ||  %d/%d/%d - %d:%d  ||  %d  ||\n", info[i].id, info[i].titre, info[i].description, info[i].deadline.j, info[i].deadline.m, info[i].deadline.a, info[i].deadline.h, info[i].deadline.min, info[i].st+1);
		        }
		        if (choixAffichage==3){
		            printf("____________________________________________TRI DEADLINE DANS 3 JOURS_________________________________________________________\n\n\n");
		            for(i=0; i<compteur; i++){
		                deadlinejj=info[j].deadline.a*365+info[j].deadline.m*12+info[j].deadline.j*jours;
		                minuteur=deadlinejj-tempsActuel;
		                if(minuteur<=3){
		                printf("  ||  %s  ||  %s  ||  %s  ||  %d/%d/%d - %d:%d  ||  %d  ||\n", info[i].id, info[i].titre, info[i].description, info[i].deadline.j, info[i].deadline.m, info[i].deadline.a, info[i].deadline.h, info[i].deadline.min, info[i].st+1);
		                }
		            }
		        }
		    }
		    break;
		    case 4:
		    do{
		        printf("_______________________________________________MODIFIER UNE TACHE____________________________________________________________\n\n\n");
		        printf("________________________________________________________________________________________________________________________\n");
		        printf("____________________________________________________SOUS-MENU________________________________________________________________\n\n\n");
		        printf("1 - Modifier la description d'une tâche.         2 - Modifier le statut d’une tâche.\n\n");
		        printf("3 - Modifier le deadline d’une tâche.\n\n");
		        scanf("%d", &choixModifier);
		    }while(choixModifier<1 || choixModifier>3);
		    switch(choixModifier){
		        case 1:
		        for(i=0; i<compteur; i++){
		            if(strcmp(identifiantModifier, info[i].id)==0){
		                switch (choixModifier){
		                    case 1:
		                    printf("_____________________________________MODIFIER DESCRIPTION DE TACHE_______________________________________________________\n\n\n");
		                    printf("entrez l'identifiant de la tache à modifier : ");
		                    scanf(" %s", identifiantModifier);
		                    for(i=0; i<compteur; i++){
		                        if(strcmp(info[i].id, identifiantModifier)==0){
		                            printf("entrez nouvelle description\n");
		                            scanf("%[^\n]s", nvDescription);
		                            strcpy(info[i].description, nvDescription);
		                        }
		                    }
		                    break;
		                    case 2:
		                    trouve=0;
		                    printf("_________________________________________MODIFIER STATUT DE TACHE________________________________________________________\n\n\n");
		                    printf("description de la tache %d est modifiee avec succes\n", i+1);
		                    printf("entrez l'identifiant de la tache à modifier : ");
		                    scanf(" %s", identifiantModifier);
		                    for(i=0; i<compteur; i++){
		                        if(strcmp(info[i].id, identifiantModifier)==0){
		                            printf("entrez nouveau statut\n");
		                            do{
		                               printf("\n1 - à réaliser.          2 - en cours de réalisation.\n");
		                               printf("3 - finalisee.");
		                               scanf("%d", &nvStatut);
		                            }while(nvStatut<1||nvStatut>3);
		                            info[i].st=nvStatut;
		                            trouve=1;
		                        }
		                        if(trouve) {
                                    printf("statut de la tache %d est modifiee avec succes\n", i+1);
                                } else {
                                    printf("tache introuvable\n");
                                }
		                    }
		                    break;
		                    case 3:
		                    trouve=0;
		                    printf("_______________________________________MODIFIER DEADLINE DE TACHE________________________________________________________\n\n\n");
		                    printf("entrez l'identifiant de la tache à modifier : ");
		                    scanf(" %s", identifiantModifier);
		                    for(i=0; i<compteur; i++){
		                        if(strcmp(info[i].id, identifiantModifier)==0){
		                            printf("entrez nouveau deadline\n");
		                            printf("Deadline(à quand est elle due?) format(JJ/MM/AA)  :   ");
		                            scanf(" %d/%d/%d", &nvJ, &nvM, &nvA);
		                            printf("a quelle heure est elle due format(hh:mm)  :   ");
		                            scanf(" %d:%d", &nvH, &nvMin);
		                            info[i].deadline.j=nvJ;
		                            info[i].deadline.m=nvM;
		                            info[i].deadline.a=nvA;
		                            info[i].deadline.h=nvH;
		                            info[i].deadline.min=nvMin;
		                            trouve=1;
		                        }
		                        if(trouve){
		                            printf("tache modifiee avec succes\n");
		                        }else{
		                            printf("tache introuvable\n");
		                        }
		                    }
		                    break;
		            }
		            break;
		    }
		    break;
		    case 5:
		    char identifiantSupprimer[10];
		    printf("_______________________________________________SUPPRIMER UNE TACHE___________________________________________________________\n\n\n");
		    printf("entrez l'identifiant de la tache  :  ");
		    scanf("%[^\n]s", identifiantSupprimer);
		    int trouve=0;
		    for(i=0; i<compteur; i++){
		        if(strcmp(info[i].id, identifiantSupprimer)==0){
		            for(j=i; j<compteur-1; j++){
		                info[j] = info[j+1];
		            }
		            trouve=1;
		            compteur--;
		            break;
		        }
		        if(trouve){
		            printf("tache supprimee avec succes.\n");
		        }else{
		            printf("tache introuvable\n");
		        }
		    }
		    break;
		    case 6:
		    do{
		        printf("______________________________________________RECHERCHER DES TACHES__________________________________________________________\n\n\n");
		        printf("________________________________________________________________________________________________________________________\n");
		        printf("____________________________________________________SOUS-MENU________________________________________________________________\n\n\n");
		        printf("1 - Rechercher une tâche par son Identifiant.              2 - Rechercher une tâche par son Titre\n\n");
		        scanf("%d", &choixRechercher);
		    }while(choixModifier>=1||choixModifier<=3);
		    switch(choixRechercher){
		        case 1:
		        printf("___________________________________________AFFICHAGE DES TACHES PAR ID______________________________________________________\n\n\n");
		        printf("entrez l'Identifiant de la tache  :  ");
		        scanf(" %[^\n]s", identifiantRecherche);
		        printf("  || identifiant  ||  titre  ||  desciption  ||  deadline  ||  statut  ||\n");
		        for(i=0; i<compteur; i++){
		            if(strcmp(info[i].id, identifiantRecherche)==0){
		                printf("  || %s  ||  %s  ||  %s  ||  %d/%d/%d - %d:%d  ||  %d  ||\n", info[i].id, info[i].titre, info[i].description, info[i].deadline.j, info[i].deadline.m, info[i].deadline.a, info[i].deadline.h, info[i].deadline.min, info[i].st+1);
		            }
		        }
		        break;
		        case 2:
		        printf("___________________________________________AFFICHAGE DES TACHES PAR TITRES__________________________________________________\n\n\n");
		        printf("entrez le titre de la tache  :  ");
		        scanf(" %[^\n]s", titreRecherche);
		        printf("  || identifiant  ||  titre  ||  desciption  ||  deadline  ||  statut  ||\n");
		        for(i=0; i<compteur; i++){
		            if(strcmp(info[i].titre, titreRecherche)==0){
		                printf("  || %s  ||  %s  ||  %s  ||  %d/%d/%d - %d:%d  ||  %d  ||\n", info[i].id, info[i].titre, info[i].description, info[i].deadline.j, info[i].deadline.m, info[i].deadline.a, info[i].deadline.h, info[i].deadline.min, info[i].st+1);
		            }
		        }
		        break;
		    }
		    break;
		    case 7:
		    printf("_________________________________________________STATISTIQUES________________________________________________________________\n\n\n");
		    do{
		        printf("________________________________________________________________________________________________________________________\n");
		        printf("____________________________________________________SOUS-MENU________________________________________________________________\n\n\n");
		        printf("1 - Afficher le nombre total des tâches.");
		        printf("                                             2 - Afficher le nombre de tâches complètes et incomplètes..\n\n");
		        printf("3 - Afficher le temps restants jusqu'au délai de chaque tâche.\n\n");
		        scanf("%d", &choixStatistique);
		    }while(choixStatistique>3||choixStatistique<1);
		    int complete=0;
		    int incomplete=0;
		    switch (choixStatistique){
		        case 1: 
		        printf("le nombre total de taches est  %d\n", compteur);
		        break;
		        case 2:
		        for(i=0; i<compteur; i++){
		            if(info[i].st==finalisee){
		                complete++;//
		            }
		        }
		        printf("il y a %d taches completes", complete);
		        for(i=0; i<compteur; i++){
		            if(info[i].st==enCoursDeRealisation){
		                incomplete++;
		            }else{
		                incomplete++;
		            }
		        }
		        printf("il y a %d taches incompletes", incomplete);
		        break;
		        case 3:
		        for(i=0; i<compteur; i++){
		            printf("la tache %d il reste %ld jours avant atteindre son délai\n", i+1, minuteur);
		        }
		        break;
		        default:
		        printf("choix impossible\n");
		        break;
		    }
        break;
	    case 8:
	    printf("________________________________________________CONFIRAMATION________________________________________________________________\n\n\n");
	    printf("                      etes vous sure?  :(  \n");
	    do{
		    printf("1 - oui                   2 - non\n\n");
		    scanf("%d", &choixExit);
	        }while(choixExit!=2 || choixExit!=1);
	    switch (choixExit){
		        case 1:
		        printf("exiting...\n");
		        exit(0);
		        break;
		        case 2:
		        break;
		        default:
		        printf("choix invalide\n");
	    }
		break;
		default:
		printf("choix invalide. veuilllez reesayer\n");
		break;
		}
    }while(choix!=8);
    return 0;
}
