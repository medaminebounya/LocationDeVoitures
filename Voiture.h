#ifndef VOITURES_H
#define VOITURES_H

#define MAX_VOITURES 100

// Structure pour les voitures
typedef struct {
    int ID;              // Identifiant de la voiture
    char Marque[25];     // Marque de la voiture
    char User[25];       // Proprietaire ou locataire
    char Model[25];      // Model de la marque
    char Carb[10];       // Type de carburant
    int Seat;            // Nombre de places
    char Trans[10];      // Transmission
    float Prix_Loca;     // Prix de location
    int Dispo;           // Disponibilite (1 pour disponible, 0 pour indisponible)
} Voiture;

// Prototypes des fonctions
void ajouterVoiture(Voiture voitures[], int *nbVoitures);
void afficherVoitures(Voiture voitures[], int nbVoitures);
void chercherVoiture(Voiture voitures[], int nbVoitures);
void afficherUneVoiture(Voiture voiture);
void trierVoitures(Voiture voitures[], int nbVoitures);
void sauvegarderDansCSV(Voiture voitures[], int nbVoitures);
int chargerVoituresDepuisFichier(Voiture voitures[], int *nbVoitures);
void modifierVoiture(Voiture voitures[], int *nbVoitures);
void supprimerVoiture(Voiture voitures[], int *nbVoitures, int ID);

#endif
