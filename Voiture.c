#include <stdio.h>
#include <string.h>
#include "voiture.h"

// Ajouter une nouvelle voiture
void ajouterVoiture(Voiture voitures[], int *nbVoitures) {
    if (*nbVoitures >= MAX_VOITURES) {
        printf("La liste des voitures est pleine !\n");
        return;
    }

    Voiture nouvelleVoiture;
    nouvelleVoiture.ID = *nbVoitures + 1;
    printf("Entrez la marque : ");
    scanf("%s", nouvelleVoiture.Marque);
    printf("Entrez le modele : ");
    scanf("%s", nouvelleVoiture.Model);
    printf("Entrez le type de carburant : ");
    scanf("%s", nouvelleVoiture.Carb);
    printf("Entrez le nombre de places : ");
    scanf("%d", &nouvelleVoiture.Seat);
    printf("Entrez la transmission : ");
    scanf("%s", nouvelleVoiture.Trans);
    printf("Entrez le prix de location : ");
    scanf("%f", &nouvelleVoiture.Prix_Loca);
    printf("Disponibilite (1 pour oui, 0 pour non) : ");
    scanf("%d", &nouvelleVoiture.Dispo);

    voitures[*nbVoitures] = nouvelleVoiture;
    (*nbVoitures)++;
    printf("Voiture ajoutee avec succes !\n");
}
// Fonction pour supprimer une voiture en fonction de son ID
void supprimerVoiture(Voiture voitures[], int *nbVoitures,int ID){
    int i, indexASupprimer = -1;
    printf("Entrez l'ID de la voiture à modifier : ");
    scanf("%d", &ID);
    for (i = 0; i < *nbVoitures; i++) {
        if (voitures[i].ID == ID) {
            indexASupprimer = i;
            break;
        }
    }
    if (indexASupprimer == -1) {
        printf("Voiture avec l'ID %d non trouvée.\n", ID);
        return;
    }
    for (i = indexASupprimer; i < *nbVoitures - 1; i++) {
        voitures[i] = voitures[i + 1];
    }
    (*nbVoitures)--;
    printf("Voiture avec l'ID %d a été supprimée avec succès.\n", ID);
}

// Afficher toutes les voitures
void afficherVoitures(Voiture voitures[], int nbVoitures) {
    if (nbVoitures == 0) {
        printf("Aucune voiture disponible.\n");
        return;
    }

    int i;
    for (i = 0; i < nbVoitures; i++) {
        printf("%d. %s %s, %s, %d places, %s, %.2f MAD, %s\n",
               voitures[i].ID,
               voitures[i].Marque,
               voitures[i].Model,
               voitures[i].Carb,
               voitures[i].Seat,
               voitures[i].Trans,
               voitures[i].Prix_Loca, //Prix location par jour
               voitures[i].Dispo ? "Disponible" : "Indisponible");
    }
}

// Rechercher une voiture
void chercherVoiture(Voiture voitures[], int nbVoitures) {
    char marqueRecherchee[50];
    int trouve = 0;

    printf("Entrez la marque de la voiture : ");
    scanf("%s", marqueRecherchee);
    printf("Resultat(s) de la recherche :\n");
    for (int i = 0; i < nbVoitures; i++) {
        if ((strcmp(voitures[i].Marque, marqueRecherchee) == 0) && voitures[i].Dispo == 1) {
            afficherUneVoiture(voitures[i]);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucune voiture ne correspond a la recherche.\n");
    }
}

//Affiche une seule voiture
void afficherUneVoiture(Voiture voiture) {
    printf("ID: %d\n", voiture.ID);
    printf("Marque: %s\n", voiture.Marque);
    printf("Modele: %s\n", voiture.Model);
    printf("Carburant: %s\n", voiture.Carb);
    printf("Nombre de places: %d\n", voiture.Seat);
    printf("Transmission: %s\n", voiture.Trans);
    printf("Prix de location (par jour): %.2f MAD\n", voiture.Prix_Loca);
    printf("Disponibilite: %s\n", voiture.Dispo ? "Disponible" : "Non disponible");
    printf("-------------------------\n");
}

//Fonction pour modifier les infos de la voiture
void modifierVoiture(Voiture voitures[], int *nbVoitures) {
    int id, i,trouve = 0;
    printf("Entrez l'ID de la voiture à modifier : ");
    scanf("%d", &id);
    for (i = 0; i < *nbVoitures; i++) {
        if (voitures[i].ID == id) {
            trouve = 1;
            //Afficher la voiture qu'on va modifier ses donnees
            printf("Détails actuels de la voiture avec l'ID %d :\n", id);
            afficherUneVoiture(voitures[i]);

            printf("Entrez la nouvelle Marque : ");
            scanf("%s", voitures[i].Marque);
            printf("Entrez le nouveau Propriétaire (User) : ");
            scanf("%s", voitures[i].User);
            printf("Entrez le nouveau Modèle : ");
            scanf("%s", voitures[i].Model);
            printf("Entrez le nouveau Type de Carburant : ");
            scanf("%s", voitures[i].Carb);
            printf("Entrez le nouveau nombre de Places : ");
            scanf("%d", &voitures[i].Seat);
            printf("Entrez le nouveau Type de Transmission : ");
            scanf("%s", voitures[i].Trans);
            printf("Entrez le nouveau Prix de Location : ");
            scanf("%f", &voitures[i].Prix_Loca);
            printf("Entrez la nouvelle Disponibilité (1 pour disponible, 0 pour non) : ");
            scanf("%d", &voitures[i].Dispo);
            break;
        }
    }
    if (!trouve) {
        printf("Aucune voiture trouvée avec l'ID %d.\n", id);
        return;
    }
    FILE *fichier = fopen("voitures.txt", "r+");
    for (i = 0; i < *nbVoitures; i++) {
        fprintf(fichier, "%d %s %s %s %s %d %s %.2f %d\n",
                voitures[i].ID,
                voitures[i].Marque,
                voitures[i].User,
                voitures[i].Model,
                voitures[i].Carb,
                voitures[i].Seat,
                voitures[i].Trans,
                voitures[i].Prix_Loca,
                voitures[i].Dispo);
    }
    fclose(fichier);
    printf("Les détails de la voiture ont été mis à jour avec succès !\n");
}

// Trier les voitures par marque
void trierVoitures(Voiture voitures[], int nbVoitures) {
    int i, j;
    for (i = 0; i < nbVoitures - 1; i++) { //0 => 98
        for (j = i + 1; j < nbVoitures; j++) { //1 => 99
            if (strcmp(voitures[i].Marque, voitures[j].Marque) > 0 && (voitures[i].Prix_Loca < voitures[j].Prix_Loca)) {
                Voiture temp = voitures[i];
                voitures[i] = voitures[j];
                voitures[j] = temp;
            }
        }
    }
    printf("Voitures triees par marque.\n");
}

// Sauvegarder dans un fichier CSV
void sauvegarderDansCSV(char *nomFichier,Voiture voitures[], int nbVoitures) {
    FILE *file = fopen(nomFichier, "w");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    int i;
    for (i = 0; i < nbVoitures; i++) {
        fprintf(file, "%d,%s,%s,%s,%d,%s,%.2f,%d\n",
                voitures[i].ID,
                voitures[i].Marque,
                voitures[i].Model,
                voitures[i].Carb,
                voitures[i].Seat,
                voitures[i].Trans,
                voitures[i].Prix_Loca,
                voitures[i].Dispo);
    }

    fclose(file);
    printf("Voitures sauvegardees dans le fichier %s.\n", nomFichier);
}

// Charger les voitures depuis un fichier
int chargerVoituresDepuisFichier(char *nomFichier, Voiture voitures[], int *nbVoitures) {
    FILE *file = fopen(nomFichier, "r");
    if (!file) {
        printf("Erreur lors de l'ouverture du fichier %s.\n", nomFichier);
        return 0;
    }

    *nbVoitures = 0;
    int i = 0;
    while (fscanf(file, "%d,%24[^,],%24[^,],%9[^,],%d,%9[^,],%f,%d\n", //24 Buffer limit pour fscanf to prevent overflow
                  &voitures[i].ID,
                  voitures[i].Marque,
                  voitures[i].Model,
                  voitures[i].Carb,
                  &voitures[i].Seat,
                  voitures[i].Trans,
                  &voitures[i].Prix_Loca,
                  &voitures[i].Dispo) == 8) {
        i++;
        (*nbVoitures)++; //prevents logical errors and ensures the integrity of the data loaded from the file.
    }

    fclose(file);
    return 1;
}


