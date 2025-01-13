#ifndef UTILISATEURS_H
#define UTILISATEURS_H

#define MAX_USERS 100

// Structure pour stocker les informations d'un utilisateur
typedef struct {
    char username[25];
    char password[25];
    char role[10];  // "client" ou "proprietaire"
} Utilisateur;

// Declarations des fonctions
int authentifierUtilisateur(char *nomFichier, char *username, char *role);
int ajouterUtilisateur(char *nomFichier, Utilisateur utilisateur);
int chargerUtilisateursDepuisFichier(char *nomFichier, Utilisateur utilisateurs[], int *nbUtilisateurs);

#endif
