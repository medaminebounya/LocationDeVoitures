#include <stdio.h>
#include <string.h>
#include "utilisateurs.h"

// Fonction pour authentifier un utilisateur

int authentifierUtilisateur(char *username, char *role) {
    char ligne[100],nomUtilisateur[25], motDePasse[25], roleUtilisateur[13], motDePasseEntre[25];

    FILE *fichier = fopen("utilisateurs.txt","r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier !\n");
        return 0;
    }

    // Demander à l'utilisateur de saisir son nom d'utilisateur et mot de passe
    printf("Entrez votre nom d'utilisateur : ");
    scanf("%s", username);
    printf("Entrez votre mot de passe : ");
    scanf("%s", motDePasseEntre);

    // Parcours du fichier pour chercher une correspondance
    while (fgets(ligne, sizeof(ligne), fichier)) {
        ligne[strcspn(ligne, "\n")] = 0; // Enlever le retour à la ligne

        // Découper la ligne en parties : nom d'utilisateur, mot de passe et rôle
        if (sscanf(ligne, "%[^,],%[^,],%s", nomUtilisateur, motDePasse, roleUtilisateur) == 3) {
            // Vérifier si le nom d'utilisateur et le mot de passe correspondent
            if (strcmp(nomUtilisateur, username) == 0 && strcmp(motDePasse, motDePasseEntre) == 0) {
                strcpy(role, roleUtilisateur);  // Copier le rôle de l'utilisateur
                fclose(fichier);
                return 1;  // Authentification réussie
            }
        }
    }

    fclose(fichier);
    printf("Nom d'utilisateur ou mot de passe incorrect !\n");
    return 0;  // Échec de l'authentification
}

// Fonction pour ajouter un nouvel utilisateur
int ajouterUtilisateur(Utilisateur utilisateur) {
    FILE *fichier = fopen("utilisateurs.txt", "a");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier pour ecriture !\n");
        return 0;
    }

    // Ajoute les informations de l'utilisateur dans le fichier
    fprintf(fichier, "%s,%s,%s\n", utilisateur.username, utilisateur.password, utilisateur.role);

    fclose(fichier);
    printf("Utilisateur ajoute avec succes !\n");
    return 1;
}

// Fonction pour charger tous les utilisateurs depuis le fichier
int chargerUtilisateursDepuisFichier(Utilisateur utilisateurs[], int *nbUtilisateurs) {
    *nbUtilisateurs = 0;  // Initialise le nombre d'utilisateurs a zero
    char ligne[100];
    int i = 0;

    FILE *fichier = fopen("utilisateurs.txt", "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier !\n");
        return 0;
    }

    // Lecture du fichier ligne par ligne
    while (fgets(ligne, sizeof(ligne), fichier)) {
        sscanf(ligne, "%24[^,],%24[^,],%13s",
               utilisateurs[i].username,
               utilisateurs[i].password,
               utilisateurs[i].role);
        i++;
        (*nbUtilisateurs)++;
    }

    fclose(fichier);
    return 1;  // Succes
}

