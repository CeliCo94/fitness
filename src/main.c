#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct User {
    char name[50];
    int age;
    char gender[10];
    float weight;
    float height;
    float waist_hip_ratio;
    char exercise_purpose[50];
    int exercise_days_per_week;
    char location[50];
    char exercise_preferences[50];
    char fitness_assessment[100];
};

void addUser(struct User *users, int *count, const char *name, int age, const char *gender, float weight, float height, float waist_hip_ratio, const char *exercise_purpose, int exercise_days_per_week, const char *location, const char *exercise_preferences, const char *fitness_assessment) {
    strcpy(users[*count].name, name);
    users[*count].age = age;
    strcpy(users[*count].gender, gender);
    users[*count].weight = weight;
    users[*count].height = height;
    users[*count].waist_hip_ratio = waist_hip_ratio;
    strcpy(users[*count].exercise_purpose, exercise_purpose);
    users[*count].exercise_days_per_week = exercise_days_per_week;
    strcpy(users[*count].location, location);
    strcpy(users[*count].exercise_preferences, exercise_preferences);
    strcpy(users[*count].fitness_assessment, fitness_assessment);
    (*count)++;
}

void saveToTextFile(struct User *users, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "Name: %s\n", users[i].name);
        fprintf(file, "Age: %d\n", users[i].age);
        fprintf(file, "Gender: %s\n", users[i].gender);
        fprintf(file, "Weight: %.2f\n", users[i].weight);
        fprintf(file, "Height: %.2f\n", users[i].height);
        fprintf(file, "Waist-Hip Ratio: %.2f\n", users[i].waist_hip_ratio);
        fprintf(file, "Exercise Purpose: %s\n", users[i].exercise_purpose);
        fprintf(file, "Exercise Days/Week: %d\n", users[i].exercise_days_per_week);
        fprintf(file, "Location: %s\n", users[i].location);
        fprintf(file, "Exercise Preferences: %s\n", users[i].exercise_preferences);
        fprintf(file, "Fitness Assessment: %s\n", users[i].fitness_assessment);
        fprintf(file, "\n");
    }
    fclose(file);
}

void loadFromTextFile(struct User *users, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    *count = 0;
    while (fscanf(file, "Name: %s\n", users[*count].name) != EOF) {
        fscanf(file, "Age: %d\n", &users[*count].age);
        fscanf(file, "Gender: %s\n", users[*count].gender);
        fscanf(file, "Weight: %f\n", &users[*count].weight);
        fscanf(file, "Height: %f\n", &users[*count].height);
        fscanf(file, "Waist-Hip Ratio: %f\n", &users[*count].waist_hip_ratio);
        fscanf(file, "Exercise Purpose: %s\n", users[*count].exercise_purpose);
        fscanf(file, "Exercise Days/Week: %d\n", &users[*count].exercise_days_per_week);
        fscanf(file, "Location: %s\n", users[*count].location);
        fscanf(file, "Exercise Preferences: %s\n", users[*count].exercise_preferences);
        fscanf(file, "Fitness Assessment: %s\n", users[*count].fitness_assessment);
        fscanf(file, "\n");
        (*count)++;
    }
    fclose(file);
}

void findUserByName(struct User *users, int count, const char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(users[i].name, name) == 0) {
            printf("Name: %s\n", users[i].name);
            printf("Age: %d\n", users[i].age);
            printf("Gender: %s\n", users[i].gender);
            printf("Weight in Kg.: %.2f\n", users[i].weight);
            printf("Height in cm: %.2f\n", users[i].height);
            printf("Waist-Hip Ratio: %.2f\n", users[i].waist_hip_ratio);
            printf("Exercise Purpose: %s\n", users[i].exercise_purpose);
            printf("Exercise Days/Week: %d\n", users[i].exercise_days_per_week);
            printf("Location: %s\n", users[i].location);
            printf("Exercise Preferences: %s\n", users[i].exercise_preferences);
            printf("Fitness Assessment: %s\n", users[i].fitness_assessment);
            return;
        }
    }
    printf("User not found!\n");
}

int main() {
    struct User users [100];
    int count = 0;
    int choice;
    char name [50];

    while (1) {
        printf("1. Add User\n");
        printf("2. Save Users to Text File\n");
        printf("3. Load Users from Text File\n");
        printf("4. Find User by Name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                int age;
                printf("Enter age: ");
                scanf("%d", &age);
                char gender[10];
                printf("Enter gender: ");
                scanf("%s", gender);
                float weight, height, waist_hip_ratio;
                printf("Enter weight: ");
                scanf("%f", &weight);
                printf("Enter height: ");
                scanf("%f", &height);
                printf("Enter waist-hip ratio: ");
                scanf("%f", &waist_hip_ratio);
                char exercise_purpose[50], location[50], exercise_preferences[50], fitness_assessment[100];
                printf("Enter exercise purpose: ");
                scanf("%s", exercise_purpose);
                int exercise_days_per_week;
                printf("Enter exercise days per week: ");
                scanf("%d", &exercise_days_per_week);
                printf("Enter location: ");
                scanf("%s", location);
                printf("Enter exercise preferences: ");
                scanf("%s", exercise_preferences);
                printf("Enter fitness assessment: ");
                scanf("%s", fitness_assessment);

                addUser(users, &count, name, age, gender, weight, height, waist_hip_ratio, exercise_purpose, exercise_days_per_week, location, exercise_preferences, fitness_assessment);
                break;
            case 2:
                saveToTextFile(users, count, "users.txt");
                break;
            case 3:
                loadFromTextFile(users, &count, "users.txt");
                break;
            case 4:
                printf("Enter name to find: ");
                scanf("%s", name);
                findUserByName(users, count, name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
