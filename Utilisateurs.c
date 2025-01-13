#include <stdio.h>
#include <string.h>
#include "utilisateurs.h"

// Fonction pour authentifier un utilisateur
#include <stdio.h>
#include <string.h>

int authentifierUtilisateur(char *nomFichier, char *username, char *role) {
    char ligne[100];
    char nomUtilisateur[25], motDePasse[25], roleUtilisateur[13], motDePasseEntre[25];

    FILE *fichier = fopen(nomFichier, "r");
    if (!fichier) {
        printf("Erreur lors de l'ouverture du fichier !\n");
        return 0;
    }

    // Demander � l'utilisateur de saisir son nom d'utilisateur et mot de passe
    printf("Entrez votre nom d'utilisateur : ");
    scanf("%s", username);
    printf("Entrez votre mot de passe : ");
    scanf("%s", motDePasseEntre);

    // Parcours du fichier pour chercher une correspondance
    while (fgets(ligne, sizeof(ligne), fichier)) {
        ligne[strcspn(ligne, "\n")] = 0; // Enlever le retour � la ligne

        // D�couper la ligne en parties : nom d'utilisateur, mot de passe et r�le
        if (sscanf(ligne, "%[^,],%[^,],%s", nomUtilisateur, motDePasse, roleUtilisateur) == 3) {
            // V�rifier si le nom d'utilisateur et le mot de passe correspondent
            if (strcmp(nomUtilisateur, username) == 0 && strcmp(motDePasse, motDePasseEntre) == 0) {
                strcpy(role, roleUtilisateur);  // Copier le r�le de l'utilisateur
                fclose(fichier);
                return 1;  // Authentification r�ussie
            }
        }
    }

    fclose(fichier);
    printf("Nom d'utilisateur ou mot de passe incorrect !\n");
    return 0;  // �chec de l'authentification
}

// Fonction pour ajouter un nouvel utilisateur
int ajouterUtilisateur(char *nomFichier, Utilisateur utilisateur) {
    FILE *fichier = fopen(nomFichier, "a");
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
int chargerUtilisateursDepuisFichier(char *nomFichier, Utilisateur utilisateurs[], int *nbUtilisateurs) {
    *nbUtilisateurs = 0;  // Initialise le nombre d'utilisateurs a zero
    char ligne[100];
    int i = 0;

    FILE *fichier = fopen(nomFichier, "r");
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

