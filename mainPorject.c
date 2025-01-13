#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voiture.h"
#include "utilisateurs.h"
#include "voiture.c"
#include "utilisateurs.c"

void afficherMenuProprietaire() {
    printf("\n----- Menu Proprietaire -----\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Afficher toutes les voitures\n");
    printf("3. Chercher une voiture\n");
    printf("4. Trier les voitures\n");
    printf("5. Sauvegarder les voitures dans un fichier CSV\n");
    printf("6. Modifier l'info d'une voiture\n");
    printf("7. Quitter\n");
    printf("Votre choix : ");
}

void afficherMenuClient() {
    printf("\n----- Menu Client -----\n");
    printf("1. Afficher toutes les voitures\n");
    printf("2. Chercher une voiture\n");
    printf("3. Quitter\n");
    printf("Votre choix : ");
}

int main() {
    Voiture voitures[MAX_VOITURES];
    Utilisateur utilisateurs[MAX_USERS];
    int nbVoitures = 0,nbUtilisateurs = 0,choix;
    char username[25]={0}, role[10]={0},motDePasseEntre[25] = {0};

    // Authentification de l'utilisateur
    if (!authentifierUtilisateur("utilisateurs.txt", username, role)) {
        return 1; // Fin du programme en cas d'échec d'authentification
    }
    printf("Bienvenue!\n");

    if (strcmp(role, "proprietaire") == 0) {
        do {
            afficherMenuProprietaire();
            scanf("%d", &choix);
            switch (choix) {
                case 1:
                    ajouterVoiture(voitures, &nbVoitures);
                    break;
                case 2:
                    afficherVoitures(voitures, nbVoitures);
                    break;
                case 3: {
                    chercherVoiture(voitures, nbVoitures);
                    break;
                }
                case 4:
                    trierVoitures(voitures, nbVoitures);
                    break;
                case 5:
                    sauvegarderDansCSV("voitures.csv", voitures, nbVoitures);
                    break;
                case 6:
                    modifierVoiture(voitures, &nbVoitures);
                    break;
                case 7:
                    printf("Au revoir!\n");
                    break;
                default:
                    printf("Choix invalide. Veuillez reessayer.\n");
            }
        } while (choix != 7);
    } else if (strcmp(role, "client") == 0) {
        do {
            afficherMenuClient();
            scanf("%d", &choix);
            switch (choix) {
                case 1:
                    afficherVoitures(voitures, nbVoitures);
                    break;
                case 2: {
                    chercherVoiture(voitures, nbVoitures);
                    break;
                }
                case 3:
                    printf("Au revoir!\n");
                    break;
                default:
                    printf("Choix invalide. Veuillez reessayer.\n");
            }
        } while (choix != 3);
    } else {
        printf("Role non reconnu !\n");
    }
    return 0;
}
