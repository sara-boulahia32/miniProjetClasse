// Projet Fin de Sas: Gestion des etudiants dans une universite
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 500
#define MAX_NOM 20
#define MAX_DEPARTEMENTS 3

enum Departement {
    maths,
    physique,
    svt
};
enum Mention{
    passable,  //0
    assezbien, //1
    bien,      //2
    tresbien,   //3
};
typedef struct {
    int j;
    int m;
    int a;
} Date;

typedef struct {
    int id;
    char nom[MAX_NOM];
    char prenom[MAX_NOM];
    Date dateNaissance;
    float noteGeneral;
    enum Departement section;
    char mention[MAX_NOM];
} Etudiant;

Etudiant info[MAX_ETUDIANTS];
int compteur = 0;
int i, j;

void Menu();
void sousMenuAjouterEtudiant();
void ajoutEtudiant(int n);
void exitProgram();
void sousMenuModifierOuSupprimerEtudiant();
void supprimerEtudiant();
void modifierInfoEtudiant();
void afficherTous();
void calculMoyenneGeneraleUniversitaire();
void calculMoyenneGeneraleDepartement();
void calculMoyenneGenerale();
void sousMenuRechercherEtudiant();
int rechercherParNom();
int rechercheParNumero(char numeroTelephone[MAX_NOM]);
void sousMenuRechercherEtudiant();
void triAlpha(int n);
void sousMenuTriAlpha();
void sousMenuTriEtudiant();
void afficherEtudiantsParDepartement();
void sousMenuTriMoyenne();
void nombreEtudiantParDepartement();
void MoyenneSupSeuil();
void sousMenuStatistique();
void triMoyenne(int n);
void reussiParDepartement();
void top3();
//void chargerListe();
const char* convertirDepartement(int n);
char checkNumeroTelephone(int entree);
void afficherMention(char mention[], float note);
void afficherUnEtudiant(Etudiant info);
void triBullesNote();
void triDesReussi();


int main(){
    Menu();
    return 0;
}

void Menu(){
    int choix;
    do{
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\t----------------------- Gestion des etudiants d'universite --------------------------\n\n\n");
        printf("\t  1 - Ajouter un etudiant.                    2 - Modifier ou supprimer un etudiant.\n\n");
        printf("\t  3 - Afficher la liste des étudiants.        4 - Calculer la moyenne générale.\n\n");
        printf("\t  5 - Rechercher un étudiant.                 6 - Tri des etudiants .\n\n");
        printf("\t  7 - Statistiques                            8 - Charger la liste intialement.\n\n");
        printf("\t  9 - Quitter le programme.\n\n");
        printf("\t------------------------------------------------------------------------------------\n");
        printf("\t------------------------------------------------------------------------------------\n\n");
        printf("\n            Choix   :   ");
        scanf("%d", &choix);
        printf("\n\n");
        getchar();
        switch(choix)
        {
	    case 1:
	        sousMenuAjouterEtudiant();
        break;
        case 2:
            sousMenuModifierOuSupprimerEtudiant();
        break;
        case 3:
            afficherTous();
        break;
        case 4:
            calculMoyenneGenerale();
	    break;
	    case 5:
	        sousMenuRechercherEtudiant();
        break;
        case 6:
            sousMenuTriEtudiant();
        break;
        case 7:
            sousMenuStatistique();
	    break;
	    case 8:
	    break;
	    case 9:
            exitProgram();
	    break;
	    default:
	        printf("choix invalide \n");
            break;
            }
    }while(choix>0 && choix<=9);
}

void sousMenuAjouterEtudiant() {
    int choix, n;
    while (1) {
        printf("\t------------------------------- Sous-Menu Ajout -------------------------------------\n");
        printf("\t-------------------------------------------------------------------------------------\n");
        printf("\n\t  1 - Ajout simple.                  2 - Ajout multiple d'etudiants.\n\n");
        printf("\n\t  3 - Retour menu principal.         4 - Quitter le programme.\n\n");
        printf("\t------------------------------------------------------------------------------------\n");
        printf("\t------------------------------------------------------------------------------------\n\n");
        printf("\n            Choix   :   ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                ajoutEtudiant(1); //ajoute 1 etudiant
                break;
            case 2:
                ajoutEtudiant(0); //ajoute n etudiants
                break;
            case 3:
                return;
            case 4:
                exitProgram();
            default:
                printf("Choix invalide.\n");
                break;
        }
    }
}

void ajoutEtudiant(int n) {
    int departement;
    if (compteur + n > MAX_ETUDIANTS) {
            printf("\nLa liste est pleine.\n");
            return;}
    if (n == 0) {
        printf("\t------------------Ajouter plusieurs etudiants ---------------------\n\n");
        printf("\tEntrez le nombre d'etudiants que vous souhaitez entrer : ");
        scanf("%d", &n);
        getchar();
        }
    if (n == 1) {
        printf("\t----------------------- Ajouter un etudiant -----------------------\n\n");
    }
    for ( i = 0; i < n; i++) {
        printf("\n\t----------- Entrer les informations de l'etudiant %d -----------\n", compteur+1);
            char num[13];
            int trouve=0;

		    do{
		       trouve=1;
		      info[j].id++;

            }while(!trouve);
        // strcpy(info[compteur].numeroTelephone, num);
        printf("\tEntrez le nom de l'etudiant : ");
        scanf("%[^\n]s", info[compteur].nom);
        getchar();
        printf("\tEntrez le prenom de l'etudiant : ");
        scanf("%[^\n]s", info[compteur].prenom);
        getchar();  //NETTOYER LE BUFFER
        do {
            printf("\tEntrez la date de naissance de l'etudiant (format JJ/MM/AA) : ");
            scanf(" %d/%d/%d", &info[compteur].dateNaissance.j, &info[compteur].dateNaissance.m, &info[compteur].dateNaissance.a);
            getchar();
        } while (info[compteur].dateNaissance.j <= 0 || info[compteur].dateNaissance.j > 31 ||
                 info[compteur].dateNaissance.m <= 0 || info[compteur].dateNaissance.m > 12 || info[compteur].dateNaissance.a<=1970 || info[compteur].dateNaissance.a>2024 );
        do {
            printf("\tEntrez le departement de l'etudiant : ");
            printf("\n\t  1 - Maths     2 - Physique");
            printf("\n\t  3 - Svt");
            printf("\n\t      Choix   :   ");
            scanf(" %d", &departement);
            getchar();
        } while (departement < 1 || departement > 3);
        info[compteur].section = (enum Departement)(departement - 1);
        printf("\tEntrez la note generale de l'etudiant : ");
        scanf(" %f", &info[compteur].noteGeneral);
        getchar();
        system("cls");
        printf("\n\tAjout affectue avec succes\n\n");
        compteur++;
    }
}
void exitProgram(){
    char choix[4];
    system("cls");
    printf("\n\tVous etes sure de vouloir quitter (oui/non)  :  ");
    if (strcmp(choix, "oui")==0){
        printf("\n\tVous etes deconnecte....");
        exit(0);
        return;
    }else if (strcmp(choix, "non")==0){
        return;
    }else{
        printf("\n\tChoix invalide\n");
    }
}
void sousMenuModifierOuSupprimerEtudiant(){
    int choix;
    char numeroTelephone[MAX_NOM];
    do{
        printf("\n\t 1 - Supprimer un etudiant de la liste.             2 - Modifier une information sur un etudiant.\n\n");
        printf("\n\t 3 - Retour menu principal.                         4 - Quitter le programme.\n\n");
        printf("\n      Choix   :   ");
        scanf("%d", &choix);
        getchar();
        switch (choix)
        {
            case 1:
            supprimerEtudiant();
            break;
            case 2:
            modifierInfoEtudiant();
            break;
            case 3:
            return;
            case 4:
            exitProgram();
            break;
            default:
            printf("choix invalide. Veuillez reessayer\n");
        }
    }while(choix<=0&&choix>=3);
}

void supprimerEtudiant(){
    int chercheId;
    char choix[4];
    puts("\t----------------------- Supprimer un etudiant -----------------------  \n\n");
    printf("entrez l'id' de l etudiant  :  ");
	scanf("%d", &chercheId);
	getchar();
	for(i=0; i<compteur; i++){
        if(info[i].id== chercheId){
           printf("\nVoulez vous vraiment supprimer cet etudiant de la liste ? (oui/non)");
            scanf(" %s", choix);
            getchar();
            if (strcmp(choix, "oui")==0) {
                for (int i = 0; i < compteur ; i++) {
                    info[i] = info[i + 1];
                    compteur--;
                    system("cls");
                    printf("\nÉtudiant supprimé avec succès.\n");
                }
            }if (strcmp(choix, "non")==0) {
                system("cls");
                 printf("Suppression annulée.\n");
            }else{
                system("cls");
            Menu();
            }
        }else{
            printf("ok");
        }
		}
}


void modifierInfoEtudiant(){
    int choix;
    int chercheId;
    puts("\t ----------------------- Modifier un etudiant ------------------------  \n\n");
    int nvDepartement;
    Date nvDate;
    char nvPrenom[MAX_NOM], nvNom[MAX_NOM], nvTel[MAX_NOM];
    float nvNote;
    printf("entrez l'id' de l etudiant  :  ");
	scanf("%d", &chercheId);
	getchar();
	for(i=0; i<compteur; i++){
        if(info[i].id== chercheId){
	printf("\nQue voulez vous modifier?\n");
	printf("\t-------------------------------------------------------------------------------------\n\n\n");
	printf("\t 1 - Nom                               2 - Prenom.\n\n");
	printf("\t 3 - Departement                       4 - la moyenne generale.\n\n");
	printf(" \t5 - Date de naissance                   .\n\n");
	printf("\t------------------------------------------------------------------------------------\n");
	printf("\t------------------------------------------------------------------------------------\n\n");
	printf("\n\t      Choix   :   ");
	scanf("%d", &choix);
	getchar();
	switch (choix)
	{
	    case 1:
	    printf("\tEntrez le nouveau nom de l'etudiant  :  ");
        scanf(" %[^\n]s", nvNom);
        getchar();
        strcpy(info[i].nom, nvNom);
        printf("\nNom modifie avec succee.\n");
	    break;
	    case 2:
	    printf("\tEntrez le nouveau prenom de l'etudiant  :  ");
        scanf(" %[^\n]s", nvPrenom);
        getchar();
        strcpy(info[i].prenom, nvPrenom);
        printf("\nPrenom modifiee avec succee.\n");
	    break;
	    case 3:
	    printf("\tEntrez le departement de l'etudiant  :  ");
        do{
            printf("\n\t1 - maths          2 -  physique");
            printf("\n\t3 - svt               ");
            printf("\n\t      Choix   :   ");
		    scanf("%d", &nvDepartement);
		    getchar();
		}while(nvDepartement<1 || nvDepartement>4);
		info[i].section=(enum Departement)(nvDepartement - 1);
        printf("\nDepartement modifie avec succes.\n");
	    break;
	    case 4:
	    printf("\tEntrez la note general de l'etudiant  :  ");
        scanf(" %f", &nvNote);
        getchar();
	    info[i].noteGeneral=nvNote;
	    printf("\nNumero de telephone modifiee avec succee.\n");
	    break;
	    case 5:
	    printf("\tEntrez la date de naissance de l'etudiant  (format JJ/MM/AA)  :  ");
        scanf("%d/%d/%d", &nvDate.j, &nvDate.m, &nvDate.a);
        info[i].dateNaissance=nvDate;
        printf("\nDate modifiee avec succee.\n");
	    break;
	    default:
	    puts("choix impossible\n");
	    break;
	}
}
}
}

void afficherTous(){
    printf("\t----------------------- La liste des etudiants -----------------------\n\n");
    printf("\t+----------------------+----------------------+----------------------+----------------+----------------------+---------------+\n");
    printf("\t| %-20s | %-20s | %-20s | %-10s | %-20s | %-10s |\n", "IDENTIFIANT", "Nom", "Prenom", "Date Naissance", " Departement", "Note generale");
    printf("\t+----------------------+----------------------+----------------------+----------------+----------------------+---------------+\n");
    for(i=0; i<compteur; i++){
    char mention[30];
    afficherMention(mention, info[i].noteGeneral);
    printf("\t| %-20d | %-20s | %-20s |   %-2d/%-2d/%-4d   | %-20s | %-10.2f |\n",  i, info[i].nom, info[i].prenom, info[i].dateNaissance.j, info[i].dateNaissance.m, info[i].dateNaissance.a, convertirDepartement(info[i].section), info[i].noteGeneral);
    printf("\t+----------------------+----------------------+----------------------+----------------+----------------------+---------------+\n");
    }
}
void calculMoyenneGenerale(){
    calculMoyenneGeneraleDepartement();
    calculMoyenneGeneraleUniversitaire();
}
void calculMoyenneGeneraleDepartement(){
    float total[MAX_NOM] = {0};
    int compte[MAX_NOM] = {0};
    for (int i = 0; i < compteur; i++) {
        int departement = info[i].section;
        total[departement] += info[i].noteGeneral;
        compte[departement]++;
    }
    printf("Moyenne generale par departement :\n");
    printf("\t+---------------------+----------------------+\n");
    printf("\t| %-20s | %-20s |\n", " Departement", "Moyenne");
    printf("\t+---------------------+----------------------+\n");
    for (int i = 0; i < 4; i++) {
        if (compte[i] > 0) {
            float moyenne = total[i] / compte[i];
            printf("\t| %-20d | %-20.02f | \n",  i+1, moyenne);
            printf("\t+---------------------+----------------------+\n");

        } else {
            printf("\t|%-20d |Aucun etudiant          |\n",  i+1);
            printf("\t+---------------------+----------------------+\n");
        }
    }
}
void calculMoyenneGeneraleUniversitaire(){
    float total=0;
    int compte=0;
    for (int i = 0; i < compteur; i++) {
        total += info[i].noteGeneral;
        compte++;
    }
    if (compte > 0) {
        double moyenneUniversite = total / compte;
        printf("\t|%-30s| %-20.2f |\n",  "Moyenne general universitaire", moyenneUniversite);
        printf("\t+---------------------+----------------------+\n");
    } else {
        printf("\t| Aucun etudiant                      |\n");
        printf("\t+-------------------------------------+\n");
    }
}
void sousMenuRechercherEtudiant(){
    int choix;
    while (1) {
        puts("\n\t  1 - Rechercher un etudiant avec nom");
        puts("\t    2 - Afficher la liste des etudiants inscrits dans un departement specifique");
        puts("\t    3 - Retour au menu principal");
        printf("\n\tEntrer votre choix: ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                rechercherParNom();
                break;
            case 2:
                afficherEtudiantsParDepartement();
                break;
            case 3:
                return;
            default:
                printf("Choix invalid.");
        }
    }
}
int rechercherParNom(){
    char chercheNom[MAX_NOM];
    int trouve=0;
    puts("\nEntrez nom a chercher");
    scanf("%[^\n]s", chercheNom);
    getchar();
    for(i=0; i<compteur; i++){
        if(strcmp(info[i].nom, chercheNom)==0){
            afficherUnEtudiant(info[i]);
            trouve = 1;

        }
    }
    if(!trouve){
        puts("Nom introuvable\n");
    }
}


void afficherEtudiantsParDepartement(){
    int departement;
    printf("Entrez le numero du departement : ");
    scanf("%d", &departement);
    getchar();
    if (departement < 1 || departement > 4) {
        puts("Departement invalide.");
        return;
    }
    printf("Etudiants du departement %d :\n", departement);
    for (int i = 0; i < compteur; i++) {
        if (info[i].section == departement - 1) {
            afficherUnEtudiant(info[i]);
        }
    }
}
void sousMenuTriEtudiant(){
    int choix;
    while(1){
        printf("\t----------------------------------------------------------------\n\n");
        puts("\n\t  1 - Tri alphabetique des etudiants par nom (de A -> Z ou de Z -> A)");
        puts("\t    2 - Tri des etudiants par moyenne generale");
        puts("\t    3 - Tri des etudiants selon leur statut de reussite(moyenne superieure ou egale a 10/20)");
        puts("\t    4 - Retour au menu principal.");
        printf("\t----------------------------------------------------------------\n\n");
        printf("\nEntrer votre choix: ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                sousMenuTriAlpha();
                break;
            case 2:
                sousMenuTriMoyenne();
                break;
            case 3:
                triDesReussi();
                break;
            case 4:
                return;
            default:
                puts("Choix invalide.\n");
                break;
        }
    }
}
void sousMenuTriAlpha(){
    int choix;
    printf("\t----------------------------------------------------------------\n\n");
    printf("\n\t1 - Tri croissant ( A -> Z)    2 - Tri decroissant (A -> Z)\n");
    printf("\t----------------------------------------------------------------\n\n");
    printf("\nEntrez votre choix: ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
        case 1:
        triAlpha(1); //croissant
        break;
        case 2:
        triAlpha(0);
        break;
        default:
        return;
    }
}
void triAlpha(int n){
    if(n==1){
        for(i=0; i<compteur; i++){
            for(j=0; j<compteur-i-1; j++){
		        if(strcmp(info[j].nom, info[j+1].nom)>0){
		            Etudiant temp=info[j];
		            info[j]=info[j+1];
		            info[j+1]=temp;
		        }
            }
        }
    }
    if(n==0){
        for(i=0; i<compteur; i++){
            for(j=0; j<compteur-i-1; j++){
		        if(strcmp(info[j].nom, info[j+1].nom)<0){
		            Etudiant temp=info[j];
		            info[j]=info[j+1];
		            info[j+1]=temp;
		        }
            }
        }
    }
    afficherTous();
}
void sousMenuTriMoyenne(){
    int choix;
    printf("\t-------------Classement gloabal des etudiants------------------\n\n");
    printf("\n\t1 - Decroissant                        2 - Croissant \n");
    printf("\t----------------------------------------------------------------\n\n");
    printf("\nEntrez votre choix: ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
        case 1:
        triMoyenne(1);//decroissant

        break;
        case 2:
        triMoyenne(0);
        break;
        default:
        return;
    }
}
void triMoyenne(int n){
    if(n==1){
        triBullesNote();
        afficherTous();
    }
    if(n==0){
        for(i=0; i<compteur-1; i++){
		    if(info[i].noteGeneral> info[i+1].noteGeneral){
		        Etudiant temp=info[i];
		        info[i]=info[i+1];
		        info[i+1]=temp;
		        }
            }
            afficherTous();
        }
}





void sousMenuStatistique(){
    int choix;
    printf("\t----------------------------------------------------------------\n\n");
    printf("\n\t1 - Calculer le total d'etudiants inscrits.                      2 - Calculer le nombre d'etudiants dans chaque departement. \n");
    printf("\n\t3 - Afficher les etudiants adepassant un certain seuil           4 - Afficher les 3 �tudiants ayant les meilleures notes. \n");
    printf("\n\t5 - Afficher le nombre d'etudiants ayant reussi dans chaque departement(note superieure ou egale a 10/20).\n");
    printf("\t----------------------------------------------------------------\n\n");
    printf("\nEntrez votre choix: ");
    scanf("%d", &choix);
    getchar();
    switch (choix)
    {
        case 1:
        printf("le total d'etudiants inscrits est : %d\n", compteur);
        break;
        case 2:
        nombreEtudiantParDepartement();
        break;
        case 3:
        MoyenneSupSeuil();
        break;
        case 4:
        top3();
        break;
        case 5:
        reussiParDepartement();
        break;
        default:
        printf("Choix invalide\n");
        break;
    }
}
void nombreEtudiantParDepartement(){
    int count[MAX_ETUDIANTS]={0}; //initialiser compteur
    for (int i = 0; i < compteur; i++) {
        int dep = info[i].section;
        if (dep >= 0 && dep < MAX_ETUDIANTS) {
            count[dep]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("\n\tLe departement %d a %d etudiants.\n", i + 1, count[i]);
    }
}
void MoyenneSupSeuil(){
    float seuil;
    printf("\n\tEntrez le seuil :  ");
    scanf("%f", &seuil);
    for(i=0; i<compteur; i++){
        if(info[i].noteGeneral>=seuil){
            afficherUnEtudiant(info[i]);
        }
    }
}
void top3(){
    triMoyenne(1); // decroissant
    printf("Les 3 meilleurs etudiants sont :\n");
    for (int i = 0; i < 3 && i < compteur; i++) {
        afficherUnEtudiant(info[i]);
    }
}
void reussiParDepartement(){
    int count[MAX_ETUDIANTS] = {0};
    for (int i = 0; i < compteur; i++) {
        if (info[i].noteGeneral >= 10) {
            count[info[i].section]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        printf("Departement %d : %d etudiants qui ont reussi.\n", i + 1, count[i]);
    }
}
void afficherMention(char mention[], float note){
    if (note < 10)
    {
        strcpy(mention, "Insuffisant");
    }
    else if (note < 14)
    {
        strcpy(mention, "Passable");
    }
    else if (note < 17)
    {
        strcpy(mention, "Bien");
    }
    else
    {
        strcpy(mention, "Tres Bien");
    }
}
void afficherUnEtudiant(Etudiant info){
    char mention[10];
    afficherMention(mention, info.noteGeneral);
    printf("\n\t+---------------------------+-------------------------+\n");
    printf("\t | id                         : %d\n", info.id);
    printf("\t | Le Nom                     : %s\n", info.nom);
    printf("\t | Le Prenom                  : %s\n", info.prenom);
    printf("\t | La Note Generale           : %.2f\n", info.noteGeneral);
    printf("\t | La Mention                 : %s\n", mention);
    printf("\t | Le Departement             : %s \n",convertirDepartement(info.section));
    Date date = info.dateNaissance;
    printf("\t |La Date de naissance        : %02d/%02d/%4d\n", info.dateNaissance.j, info.dateNaissance.m, info.dateNaissance.a);
    printf("\n\t+---------------------------+-------------------------+\n");
}

const char* convertirDepartement(int n){
    switch (n)
    {
    case 0: return "maths";
    case 1: return "physique";
    case 2: return "svt";
    default: return "indefini";
    }
}
char checkNumeroTelephone(int entree){
    while(1){
        int trouve=0;
        printf("\tEntrer l'id de l'etudiant  :  ");
        scanf("%d", &entree);
        for (int i = 0; i < compteur; i++) {
        if(info[i].id== entree){
            printf("\nCe numero de telephone existe deja.\n");
            trouve=1;
            break;
        }
    }
    if(!trouve){
        break;
    }
}
}
void triBullesNote(){
    for(i=0; i<compteur; i++){
        if(info[i].noteGeneral< info[i+1].noteGeneral){
            Etudiant temp=info[i];
            info[i]=info[i+1];
            info[i+1]=temp;
        }
    }
}
void triDesReussi(){
    printf("\n\tTri des elements reussi\n");
    triMoyenne(0);
    for(j=0; j<compteur; j++){
        if(info[j].noteGeneral>=10){
            afficherUnEtudiant(info[j]);
        }
    }
}
