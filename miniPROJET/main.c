#include <stdio.h>
#include <string.h>

#define MAX_LIVRES 100
#define MAX_TAILLE 100

char titres[MAX_LIVRES][MAX_TAILLE];
char auteurs[MAX_LIVRES][MAX_TAILLE];
float prix[MAX_LIVRES];
int quantites[MAX_LIVRES];
int livreNumero = 0;
int total = 0;
int trouve;

int main() {
    int choix;
    char titre_recherche[MAX_TAILLE];
    do {
        printf("________________________________________________________________________________________________________________________\n");
        printf("________________________________________________MENU______________________________________________________________\n\n\n");
        printf("1 - Ajouter un livre.");
        printf("                         2 - Afficher tous les livres.\n\n");
        printf("3 - Rechercher un livre.");
        printf("            4 - Mettre à jour la quantité de stock d'un livre.\n\n");
        printf("5 - Supprimer un livre.");
        printf("                               6 - Afficher le nombre total de livres en stock.\n\n");
        printf("7 - exit");
        printf("________________________________________________________________________________________________________________________\n");
        printf("________________________________________________________________________________________________________________________\n");
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                if (livreNumero >= MAX_LIVRES) {
                    printf("Le stock est plein, impossible d'ajouter plus de livres.\n");
                }else{
                    printf("Entrez le titre du livre : ");
                    scanf("%[^\n]%*c", titres[livreNumero]);
                    printf("Entrez l'auteur du livre : ");
                    scanf("%[^\n]%*c", auteurs[livreNumero]);
                    printf("Entrez le prix du livre : ");
                    scanf("%f", &prix[livreNumero]);
                    printf("Entrez la quantité en stock : ");
                    scanf("%d", &quantites[livreNumero]);
                }
                livreNumero++;
                break;
            case 2:
                if (livreNumero == 0) {
                printf("Aucun livre en stock.\n");
                 }else{
                     for (int i = 0; i < livreNumero; i++) {
                        printf("Titre: %s\n", titres[i]);
                        printf("Auteur: %s\n", auteurs[i]);
                        printf("Prix: %.2f\n", prix[i]);
                        printf("Quantité: %d\n", quantites[i]);
                        printf("-----------------------------\n");
                    }
                }
                break;
            case 3:
                {
                    trouve=0;
                    printf("Entrez le titre du livre à rechercher : ");
                    scanf("%[^\n]%*c", titre_recherche);

                    for (int i = 0; i < livreNumero; i++) {
                        if (strcmp(titres[i], titre_recherche) == 0) {
                            printf("Livre trouvé!\n");
                            printf("Titre: %s\n", titres[i]);
                            printf("Auteur: %s\n", auteurs[i]);
                            printf("Prix: %.2f\n", prix[i]);
                            printf("Quantité: %d\n", quantites[i]);
                            trouve=1;
                            break;
                        }
                    }
                    if (!trouve){
                        printf("Livre non trouvé.\n");
                    }
                }
                break;
            case 4:
                {
                    trouve=0;
                    printf("Entrez le titre du livre pour mettre à jour la quantité : ");
                    scanf("%[^\n]%*c", titre_recherche);

                    for (int i = 0; i < livreNumero; i++) {
                        if (strcmp(titres[i], titre_recherche) == 0) {
                            printf("Entrez la nouvelle quantité : ");
                            scanf("%d", &quantites[i]);
                            printf("Quantité mise à jour.\n");
                            trouve=1;
                            break;
                        }
                    }
                    if (!trouve){
                        printf("Livre non trouvé.\n");
                    }
                }
                break;
            case 5:
                {
                    trouve=0;
                    printf("Entrez le titre du livre à supprimer : ");
                    scanf("%[^\n]%*c", titre_recherche);

                    for (int i = 0; i < livreNumero; i++) {
                        if (strcmp(titres[i], titre_recherche) == 0) {
                            for (int j = i; j < livreNumero - 1; j++) {
                                strcpy(titres[j], titres[j + 1]);
                                strcpy(auteurs[j], auteurs[j + 1]);
                                prix[j] = prix[j + 1];
                                quantites[j] = quantites[j + 1];
                            }
                            livreNumero--;
                            printf("Livre supprimé.\n");
                            trouve=1;
                            break;
                        }
                    }
                    if (!trouve){
                        printf("Livre non trouvé.\n");
                    }
                }
                break;
            case 6:
                for (int i = 0; i < livreNumero; i++) {
                    total += quantites[i];
                }
                printf("Nombre total de livres en stock : %d\n", total);
                break;
            case 7:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Essayez encore.\n");
                break;
        }
    } while (choix != 7);

    return 0;
}
