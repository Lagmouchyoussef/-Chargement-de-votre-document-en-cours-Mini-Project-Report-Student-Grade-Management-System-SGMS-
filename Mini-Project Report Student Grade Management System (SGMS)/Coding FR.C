#include <stdio.h>
#include <stdlib.h>
const int MAX_MATIERES = 100;
const int MAX_NOTES = 100;
const int MAX_STUDIANTS = 100;

void saisirEtudiants(char nomEtudiant[][100], char prenomEtudiant[][100], int *nbEtudiants);
void saisirMatieres(char nomMatieres[][100], int *nbMatieres);
void saisirNotes(float notes[][MAX_NOTES], int nbMatieres, int nbEtudiants, char nomMatieres[][100], char nomEtudiant[][100], char prenomEtudiant[][100]);
float calculerMoyenne(float notes[], int nbNotes);
float trouverNoteMin(float notes[], int nbNotes);
float trouverNoteMax(float notes[], int nbNotes);
void trierNotes(float notes[], int nbNotes);

int main() {
    char nomEtudiant[MAX_STUDIANTS][100], prenomEtudiant[MAX_STUDIANTS][100], nomMatieres[MAX_MATIERES][100];
    int nbEtudiants, nbMatieres;

    saisirEtudiants(nomEtudiant, prenomEtudiant, &nbEtudiants);
    saisirMatieres(nomMatieres, &nbMatieres);

    float notes[MAX_MATIERES][MAX_NOTES];
    saisirNotes(notes, nbMatieres, nbEtudiants, nomMatieres, nomEtudiant, prenomEtudiant);

    printf("\n");
    for (int i = 0; i < nbEtudiants; i++) {
        printf("\nNom de l'etudiant %i : %s %s\n", i + 1, prenomEtudiant[i], nomEtudiant[i]);
        for (int j = 0; j < nbMatieres; j++) {
            printf("\nMatiere : %s\n", nomMatieres[j]);
            printf("Moyenne : %.2f\n", calculerMoyenne(notes[j], nbEtudiants));
            printf("Note minimale : %.2f\n", trouverNoteMin(notes[j], nbEtudiants));
            printf("Note maximale : %.2f\n", trouverNoteMax(notes[j], nbEtudiants));

            trierNotes(notes[j], nbEtudiants);
            printf("Notes triees : ");
            for (int k = 0; k < nbEtudiants; k++) {
                printf("%.2f ", notes[j][k]);
            }
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}

void saisirEtudiants(char nomEtudiant[][100], char prenomEtudiant[][100], int *nbEtudiants) {
    do {
        printf("Entrez le nombre d'etudiants : ");
        scanf("%d", nbEtudiants);
        if (*nbEtudiants <= 0 || *nbEtudiants > MAX_STUDIANTS) {
            printf("Nombre d'etudiants invalide. Veuillez reessayer.\n");
        }
    } while (*nbEtudiants <= 0 || *nbEtudiants > MAX_STUDIANTS);

    for (int i = 0; i < *nbEtudiants; i++) {
        printf("Entrez le nom de famille de l'etudiant %d : ", i + 1);
        scanf("%s", nomEtudiant[i]);
        printf("Entrez le prenom de l'etudiant %d : ", i + 1);
        scanf("%s", prenomEtudiant[i]);
    }
}

void saisirMatieres(char nomMatieres[][100], int *nbMatieres) {
    printf("Entrez le nombre de matieres : ");
    scanf("%d", nbMatieres);
    for (int i = 0; i < *nbMatieres; i++) {
        printf("Entrez le nom de la matiere %d : ", i + 1);
        scanf("%s", nomMatieres[i]);
    }
}

void saisirNotes(float notes[][MAX_NOTES], int nbMatieres, int nbEtudiants, char nomMatieres[][100], char nomEtudiant[][100], char prenomEtudiant[][100]) {
    for (int i = 0; i < nbMatieres; i++) {
        printf("\nMatiere : %s\n", nomMatieres[i]);
        for (int j = 0; j < nbEtudiants; j++) {
            printf("Note pour l'etudiant %s %s : ", prenomEtudiant[j], nomEtudiant[j]);
            scanf("%f", &notes[i][j]);
        }
    }
}

float calculerMoyenne(float notes[], int nbNotes) {
    float somme = 0.0;
    for (int i = 0; i < nbNotes; i++) {
        somme += notes[i];
    }
    return somme / nbNotes;
}

float trouverNoteMin(float notes[], int nbNotes) {
    float min = notes[0];
    for (int i = 1; i < nbNotes; i++) {
        if (notes[i] < min) {
            min = notes[i];
        }
    }
    return min;
}

float trouverNoteMax(float notes[], int nbNotes) {
    float max = notes[0];
    for (int i = 1; i < nbNotes; i++) {
        if (notes[i] > max) {
            max = notes[i];
        }
    }
    return max;
}

void trierNotes(float notes[], int nbNotes) {
    for (int i = 0; i < nbNotes - 1; i++) {
        for (int j = 0; j < nbNotes - i - 1; j++) {
            if (notes[j] > notes[j + 1]) {
                float temp = notes[j];
                notes[j] = notes[j + 1];
                notes[j + 1] = temp;
            }
        }
    }
}