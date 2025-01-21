#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "voiture.h"
#include "utilisateurs.h"

void afficherMenuProprietaire() {
    printf("\n----- Menu Proprietaire -----\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Afficher toutes les voitures\n");
    printf("3. Chercher une voiture\n");
    printf("4. Trier les voitures\n");
    printf("5. Sauvegarder les voitures dans un fichier CSV\n");
    printf("6. Modifier l'info d'une voiture\n");
    printf("7. Ajouter un utilisateur\n");
    printf("8. Supprimer une voiture\n");
    printf("9. Quitter\n");
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
    Utilisateur newUser;
    int nbVoitures = 0,nbUtilisateurs = 0,choix,ID;
    char username[25]={0}, role[10]={0},motDePasseEntre[25] = {0};

    // Charger les données depuis les fichiers au démarrage
    if (chargerVoituresDepuisFichier(voitures, &nbVoitures) != 0) {
        printf("Erreur lors du chargement des voitures.\n");
        return 1; // Si l'échec, quitter le programme
    }

    if (chargerUtilisateursDepuisFichier(utilisateurs, &nbUtilisateurs) != 0) {
        printf("Erreur lors du chargement des utilisateurs.\n");
        return 1; // Si l'échec, quitter le programme
    }

    // Authentification de l'utilisateur
    if (!authentifierUtilisateur(username, role)) {
        return 1; // Fin du programme en cas d'échec d'authentification
    }
    printf("Bienvenue %s! Vous etes connecte en tant que %s.\n",username,role);

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
                case 3:
                    chercherVoiture(voitures, nbVoitures);
                    break;
                case 4:
                    trierVoitures(voitures, nbVoitures);
                    break;
                case 5:
                    sauvegarderDansCSV(voitures, nbVoitures);
                    break;
                case 6:
                    modifierVoiture(voitures, &nbVoitures);
                    break;
                case 7:
                    // Vérifier si on peut ajouter un nouvel utilisateur
                    if (nbUtilisateurs < MAX_USERS) {
                    // Demande au proprietaire les infos du nouvel utilisateur
                    printf("Entrez le nom d'utilisateur : ");
                    scanf("%s", newUser.username);
                    printf("Entrez le mot de passe : ");
                    scanf("%s", newUser.password);
                    printf("Entrez le role (par exemple, proprietaire ou client) : ");
                    scanf("%s", newUser.role);

                    // Ajouter l'utilisateur au tableau et incrémenter le compteur
                    utilisateurs[nbUtilisateurs++] = newUser;

                    // Appel fonction
                    ajouterUtilisateur(newUser);
                    printf("Utilisateur ajoute avec succes !\n");
                } else {
                    printf("Limite d'utilisateurs atteinte !\n");
                }
                break;
                case 8:
                   printf("Entrez l'ID de la voiture que vous voulez supprimer: ");
                   scanf("%d",&ID);
                   supprimerVoiture(voitures, nbVoitures, ID);
                    break;
                case 9:
                   printf("Au revoir!\n");
                    break;
                default:
                    printf("Choix invalide. Veuillez reessayer.\n");
            }
        } while (choix != 9);
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
