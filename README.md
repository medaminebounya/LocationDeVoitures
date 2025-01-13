# Système de Gestion de Voitures (SGV)

**Système de Gestion de Voitures (SGV)** est une application simple basée sur la console écrite en C pour gérer les voitures et les utilisateurs d'un service de location de voitures. Elle inclut une authentification des utilisateurs et deux types de rôles d'utilisateur : *Propriétaire* et *Client*. Les propriétaires peuvent ajouter, modifier et lister les véhicules, tandis que les clients peuvent rechercher et afficher les voitures disponibles.

## Fonctionnalités :
- **Authentification** : Système simple de connexion utilisateur basé sur le nom d'utilisateur et le mot de passe.
- **Fonctionnalités du Propriétaire** :
  - Ajouter une nouvelle voiture.
  - Afficher toutes les voitures.
  - Rechercher une voiture spécifique.
  - Trier les voitures en fonction de certains critères.
  - Sauvegarder les données des voitures dans un fichier CSV.
  - Modifier les détails d'une voiture.
- **Fonctionnalités du Client** :
  - Afficher toutes les voitures disponibles.
  - Rechercher une voiture spécifique.
- **Stockage des données** : Les informations sur les véhicules et les utilisateurs sont stockées dans des fichiers externes (`utilisateurs.txt` pour les utilisateurs et `voitures.csv` pour les véhicules).
- **Interface en ligne de commande** : Le système est facile à utiliser via une interface terminal.

## Prérequis :
- Un compilateur C (par exemple, GCC)
- Un éditeur de texte ou un IDE pour éditer les fichiers C

## Installation :
1. Clonez ce dépôt sur votre machine locale :
   ```bash
   git clone https://github.com/votrenomutilisateur/voiture-management-system.git
