#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//prototypes
void ajouterProduit();
void ajouterPlusieursProduits();
void afficherTous(int index);
float fprixTTC(float prix);
void afficherParTriAlphabetique();
void afficherParPrixDecroissant();
void acheterProduit();
void enregistrerDateAchat();
void alimenterStock();
void rechercherProduit();
void supprimerProduits();
void statistiqueDeVente();

//MEMOIRE

typedef struct {
	char code[20];
	char nom[30];
	float quantite;
	float prix;
	float prixTTC;
	float totalVentes;
	time_t dateAchat;
} produit;
produit info[300];
produit temp;
int n, i, j;
int compteur=0;
//MAIN

int main(void) {
    int choix;
	do {
		printf("________________________________________________________________________________________________________________________\n");
		printf("____________________________________________________MENU________________________________________________________________\n\n\n");
		printf("1 - Ajouter un nouveau produit.");
		printf("                                                   2 - ajoutre plusieurs nv produits.\n\n");
		printf("3 - afficher tous les produits (NOM || PRIX || PRIX TTC).");
		printf("                         4 - lister produit tri alphabetique.\n\n");
		printf("5 - lister les produits par tri dC)croissant de prix.");
		printf("                             6 - acheter produit.\n\n");
		printf("7 - rechercher un produit.");
		printf("                                                        8 - alimenter le stock.\n\n");
		printf("9 - supprimer les produits");
		printf("                                                       10 - statique de vente.\n\n");
		printf("11 - EXIT\n");
		printf("________________________________________________________________________________________________________________________\n");
		printf("________________________________________________________________________________________________________________________\n");
		printf("Entrez votre choix : ");
		system("cls");
		scanf("%d", &choix);
		switch(choix)
		{
		case 1:
			printf("\n_________________________________________AJOUTER UN NOUVEAU PRODUIT _____________________________________________________\n\n");
			if (compteur < 300) {
				ajouterProduit();
			} else {
				printf("liste pleine\n");
			}
		break;
		case 2:
			printf("\n________________________________________________AJOUTER PLUSIEURS PRODUITS________________________________________________\n\n");
			printf("combien de produits ajouterez vous?  \n");
			scanf("%d", &n);
			if (n+compteur < 300) {
				ajouterPlusieursProduits();
			} else {
				printf("memoire ne supporte pas\n");
			}
		break;
		case 3:
			printf("\n___________________________________________________AFFICHER TOUS LES PRODUITS______________________________________________\n");
			afficherTous(-1);
		break;
		case 4:
			printf("\n________________________________________________AFFICHER LES PRODUITS DE A C  Z_____________________________________________\n");
			afficherParTriAlphabetique();
		break;
		case 5:
			printf("\n__________________________________________AFFICHER LES PRODUITS PAR PRIX DECROISSANT________________________________________\n");
			afficherParPrixDecroissant();
		break;
		case 6:
			printf("\n_____________________________________________________ACHETER PRODUIT________________________________________________________\n");
			acheterProduit();
		break;
		case 7:
			printf("\n____________________________________________________RECHERCHER PRODUIT_______________________________________________________\n");
			rechercherProduit();
			break;
		case 8:
			printf("\n____________________________________________________ALIMENTER LE STOCK_______________________________________________________\n");
			alimenterStock();
		break;
		case 9:
			printf("\n_________________________________________________SUPPRIMER LES PRODUITS______________________________________________________\n");
			supprimerProduits();
		break;
		case 10:
			printf("\n___________________________________________________STATIQTIQUE DE VENTE______________________________________________________\n");
			statistiqueDeVente();
		break;
		case 11:
		printf("exiting...\n");
		exit(0);
		default:
		printf("choix impossible.\n");
		}
	} while(choix!=0);
	return 0;
}

//functions

void ajouterProduit() {
	printf("code du produit      : ");
	scanf(" %[^\n]s", info[compteur].code);
	printf("nom du produit     : ");
	scanf(" %[^\n]s", info[compteur].nom);
	printf("quantite             : ");
	scanf(" %f", &info[compteur].quantite);
	printf("prix             : ");
	scanf(" %f", &info[compteur].prix);
	info[compteur].prixTTC=fprixTTC(info[compteur].prix);
	info[compteur].totalVentes=0;
	info[compteur].dateAchat=0;
	compteur++;
	printf("\nproduit ajoute avec succee.\n");
}
void ajouterPlusieursProduits() {
	for (i=0; i<n; i++) {
		printf("entrez les details du produit %d\n", i+1);
		ajouterProduit();
	}
}
float fprixTTC(float prix) {
	return prix+0.15*prix;
}
void afficherTous(int index) {
    //pour afficher tout
    if(index==-1){
	    printf("||  nom  ||  prix  ||  prix TTC  ||\n");
	    for (i=0; i<compteur; i++) {
		    printf("||  %s  ||  %.2f  ||  %.2f  ||\n", info[i].nom, info[i].prix, info[i].prixTTC);
	    }
    }else{//afficher un article seulement
        printf("||  code  ||  nom  ||  quantite  ||  prix  ||  prix TTC  || totalVentes  ||  date d'achat ||\n");
        printf("||  %s  ||  %s  ||  %.2f  ||  %.2f  ||  %.2f  ||  %.2f  ||  %s  ||\n", info[index].code, info[index].nom, info[index].quantite, info[index].prix, info[index].prixTTC , info[index].totalVentes, ctime(&info[index].dateAchat));
        printf("Produit trouve :\n");
        printf("Code : %s\n", info[index].code);
        printf("Nom : %s\n", info[index].nom);
        printf("Quantite : %.2f\n", info[index].quantite);
        printf("Prix : %.2f\n", info[index].prix);
        printf("Prix TTC : %.2f\n", info[index].prixTTC);
        printf("Total Ventes : %.2f\n", info[index].totalVentes);
        printf("Date d'achat : %s", ctime(&info[index].dateAchat));
    }
}
void afficherParTriAlphabetique() {
	for (i=0; i<compteur-1; i++) {
		for(j=i+1; j<compteur; j++) {
			if (strcmp(info[i].nom, info[j].nom)>0) {
				temp=info[i];
				info[i]=info[j];
				info[j]=temp;
			}
		}
	}
	afficherTous(-1);
}
void afficherParPrixDecroissant() {
	for (i=0; i<compteur-1; i++) {
	    for(j=i+1; j<compteur; j++){
	        if (info[i].prix < info[j].prix) {
			    temp=info[i];
			    info[i]=info[j];
			    info[j]=temp;
	        }
		}
	}
	afficherTous(-1);
}
void acheterProduit() {
    char code[20];
    float quantiteDeduite;
	printf("entrez le code du produit C  acheter :  ");
	scanf(" %[^\n]s", code);
	printf("combien de ce produit voulez vous acheter ?  ");
	scanf("%f", &quantiteDeduite);
	for(i=0; i<compteur ; i++) {
		if(strcmp(info[i].code, code)==0) {
			if(info[i].quantite>=quantiteDeduite) {
				info[i].quantite-=quantiteDeduite;
				info[i].totalVentes += quantiteDeduite * info[i].prixTTC;
				enregistrerDateAchat();
				printf("achat effectue avec succee \n");
				return;
			} else {
				printf("produit en rupture de stock.\n");
				return;
			}
		}
	}
	printf("produit introuvable.\n");
}
void enregistrerDateAchat() {
	time_t tempsAchat;
	time(&tempsAchat);
    printf("Date d'achat : %s\n", ctime(&tempsAchat));
}
void rechercherProduit() {
	int choix;
	printf("________________________________________________________________________________________________________________________\n");
	printf("__________________________________________________SOUS-MENU_____________________________________________________________\n\n\n");
	printf("1 - rechercher produit par code.");
	printf("                          2 - recherher produit par quantite.\n\n");
	printf("3 - rechercher produits dont la quantité est inférieure à 3.\n");
	printf("________________________________________________________________________________________________________________________\n");
	printf("________________________________________________________________________________________________________________________\n");
	printf("\n");
	scanf("%d", &choix);
	int trouve=-1;
	switch (choix)
	{
	case 1:
	char code[20];
	printf("entrez code du produit : ");
	scanf(" %[^\n]s", code);
	trouve=-1;
	for(i=0; i<compteur; i++) {
		if(strcmp(info[i].code, code)==0) {
		    trouve=i;
		    printf("produit trouvé\n");
			break;
		}
	}
	if(trouve!=-1){
	    afficherTous(trouve);
	}else{
	    printf("prouduit introuvable\n");
	}
	break;
	case 2:
    float quantite;
    printf("Entrez la quantité du produit : ");
    scanf("%f", &quantite);
    trouve=-1;
    for (int i = 0; i < compteur; i++) {
        if (info[i].quantite == quantite) {
            trouve=i;
            afficherTous(trouve);
            return;
        }
    }
    if(trouve!=-1){
        afficherTous(trouve);
    }else{
        printf("produit introuvable\n");
    }
    break;
	case 3:
	int trouve=0;
    for (int i = 0; i < compteur; i++) {
        if (info[i].quantite < 3) {
            afficherTous(i);
            trouve=1;
        }
    }
    if(!trouve){
        printf("aucun produit trouvé avec quantite inf à 3\n");
    }
	break;
	default :
	printf("choix invalide\n");
	break;
	}
}
void alimenterStock() {
    char code[20];
    float quantiteAjoute;
    printf("entrez code du produit : ");
	scanf(" %[^\n]s", code);
	for (i=0; i<compteur; i++){
	    if (strcmp(info[i].code, code)==0){
	        printf("quantite a ajouter  : ");
	        scanf(" %f", &quantiteAjoute);
	        info[i].quantite+=quantiteAjoute;
	        printf("stock mis à jour avec succee\n");
	        return;
	    }
	}
	printf("produit introuvable\n");
}
void supprimerProduits(){
    char code[20];
    printf("entrez code du produit : ");
	scanf(" %[^\n]s", code);
	for (i=0; i<compteur; i++){
	    if (strcmp(info[i].code, code)==0){
	        for(j=0; j<compteur; j++){
	            info[j]=info[j+1];
	        }
	        compteur--;
	        printf("produit supprimé\n");
	        return;
	    }
	}
	printf("produit introuvable\n");
}
void statistiqueDeVente(){
    float total=0.00, min=-1.00, max=-1.00, moyenne=0.00;
    int compt=0;
    time_t now;
    struct tm *tm_now;
    time(&now);
    tm_now=localtime(&now);
	printf("________________________________________________________________________________________________________________________\n");
	printf("__________________________________________________SOUS-MENU_____________________________________________________________\n\n\n");
	printf("1 - Afficher total des prix des produits vendus aujourd'hui.");
	printf("      2 -  Afficher moyenne des prix des ventes aujourd'hui\n\n");
	printf("3 - Afficher Max des prix des produits vendus aujourd'hui.");
	printf("         4 - Afficher Min des prix des ventes aujourd'hui\n\n");
	printf("________________________________________________________________________________________________________________________\n");
	printf("________________________________________________________________________________________________________________________\n");
	int choix;
	scanf("%d", &choix);
	for (i = 0; i < compteur; i++) {
        struct tm *tm_achat = localtime(&info[i].dateAchat);
        if (tm_achat->tm_year == tm_now->tm_year &&
            tm_achat->tm_mon == tm_now->tm_mon &&
            tm_achat->tm_mday == tm_now->tm_mday) {
            total += info[i].totalVentes;
            compt++;
            if (min == -1 || info[i].totalVentes < min) min = info[i].totalVentes;
            if (max == -1 || info[i].totalVentes > max) max = info[i].totalVentes;
        }
    }
    if (compt > 0) {
        moyenne = total / compt;
    }
    
    switch (choix) {
        case 1:
            printf("Total des ventes aujourd'hui : %.2f\n", total);
            break;
        case 2:
            printf("Moyenne des ventes d'aujourd'hui : %.2f\n", moyenne);
            break;
        case 3:
            printf("Prix maximum des ventes aujourd'hui : %.2f\n", max);
            break;
        case 4:
            printf("Prix minimum des ventes aujourd'hui : %.2f\n", min);
            break;
        default:
            printf("Choix invalide\n");
            break;
    }
}