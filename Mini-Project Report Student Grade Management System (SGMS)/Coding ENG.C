#include <stdio.h>
#include <stdlib.h>
const int MAX_SUBJECTS = 100;
const int MAX_GRADES = 100;
const int MAX_STUDENTS = 100;

void enterStudents(char lastName[][100], char firstName[][100], int *studentCount);
void enterSubjects(char subjectNames[][100], int *subjectCount);
void enterGrades(float grades[][MAX_GRADES], int subjectCount, int studentCount, char subjectNames[][100], char lastName[][100], char firstName[][100]);
float calculateAverage(float grades[], int gradeCount);
float findMinGrade(float grades[], int gradeCount);
float findMaxGrade(float grades[], int gradeCount);
void sortGrades(float grades[], int gradeCount);

int main() {
    char lastName[MAX_STUDENTS][100], firstName[MAX_STUDENTS][100], subjectNames[MAX_SUBJECTS][100];
    int studentCount, subjectCount;

    enterStudents(lastName, firstName, &studentCount);
    enterSubjects(subjectNames, &subjectCount);

    float grades[MAX_SUBJECTS][MAX_GRADES];
    enterGrades(grades, subjectCount, studentCount, subjectNames, lastName, firstName);

    printf("\n");
    for (int i = 0; i < studentCount; i++) {
        printf("\nStudent %i : %s %s\n", i + 1, firstName[i], lastName[i]);
        for (int j = 0; j < subjectCount; j++) {
            printf("\nSubject : %s\n", subjectNames[j]);
            printf("Average : %.2f\n", calculateAverage(grades[j], studentCount));
            printf("Minimum grade : %.2f\n", findMinGrade(grades[j], studentCount));
            printf("Maximum grade : %.2f\n", findMaxGrade(grades[j], studentCount));

            sortGrades(grades[j], studentCount);
            printf("Sorted grades : ");
            for (int k = 0; k < studentCount; k++) {
                printf("%.2f ", grades[j][k]);
            }
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}

void enterStudents(char lastName[][100], char firstName[][100], int *studentCount) {
    do {
        printf("Enter number of students : ");
        scanf("%d", studentCount);
        if (*studentCount <= 0 || *studentCount > MAX_STUDENTS) {
            printf("Invalid number of students. Please try again.\n");
        }
    } while (*studentCount <= 0 || *studentCount > MAX_STUDENTS);

    for (int i = 0; i < *studentCount; i++) {
        printf("Enter last name of student %d : ", i + 1);
        scanf("%s", lastName[i]);
        printf("Enter first name of student %d : ", i + 1);
        scanf("%s", firstName[i]);
    }
}

void enterSubjects(char subjectNames[][100], int *subjectCount) {
    printf("Enter number of subjects : ");
    scanf("%d", subjectCount);
    for (int i = 0; i < *subjectCount; i++) {
        printf("Enter name of subject %d : ", i + 1);
        scanf("%s", subjectNames[i]);
    }
}

void enterGrades(float grades[][MAX_GRADES], int subjectCount, int studentCount, char subjectNames[][100], char lastName[][100], char firstName[][100]) {
    for (int i = 0; i < subjectCount; i++) {
        printf("\nSubject : %s\n", subjectNames[i]);
        for (int j = 0; j < studentCount; j++) {
            printf("Grade for student %s %s : ", firstName[j], lastName[j]);
            scanf("%f", &grades[i][j]);
        }
    }
}

float calculateAverage(float grades[], int gradeCount) {
    float sum = 0.0;
    for (int i = 0; i < gradeCount; i++) {
        sum += grades[i];
    }
    return sum / gradeCount;
}

float findMinGrade(float grades[], int gradeCount) {
    float min = grades[0];
    for (int i = 1; i < gradeCount; i++) {
        if (grades[i] < min) {
            min = grades[i];
        }
    }
    return min;
}

float findMaxGrade(float grades[], int gradeCount) {
    float max = grades[0];
    for (int i = 1; i < gradeCount; i++) {
        if (grades[i] > max) {
            max = grades[i];
        }
    }
    return max;
}

void sortGrades(float grades[], int gradeCount) {
    for (int i = 0; i < gradeCount - 1; i++) {
        for (int j = 0; j < gradeCount - i - 1; j++) {
            if (grades[j] > grades[j + 1]) {
                float temp = grades[j];
                grades[j] = grades[j + 1];
                grades[j + 1] = temp;
            }
        }
    }
}