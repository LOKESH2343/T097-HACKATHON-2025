#include <stdio.h>
#include <string.h>
#include <ctype.h>
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
void suggestCareer(const char interest[]) {
    if (strcmp(interest, "science") == 0) {
        printf("\nCareer Options in Science:\n");
        printf("1. Doctor - Diagnose and treat illnesses to improve patients' health.\n");
        printf("2. Engineer - Design, develop, and maintain technologies and structures.\n");
        printf("3. Research Scientist - Conduct experiments to advance scientific knowledge.\n");
        printf("4. Data Analyst - Analyze data to help organizations make informed decisions.\n");
    } 
    else if (strcmp(interest, "arts") == 0) {
        printf("\nCareer Options in Arts:\n");
        printf("1. Artist - Create visual art like paintings, sculptures, and digital media.\n");
        printf("2. Writer - Craft stories, articles, or books to entertain or inform.\n");
        printf("3. Psychologist - Study human behavior and mental health.\n");
        printf("4. Journalist - Report news, conduct interviews, and write articles.\n");
    } 
    else if (strcmp(interest, "commerce") == 0) {
        printf("\nCareer Options in Commerce:\n");
        printf("1. Chartered Accountant - Manage financial records, audits, and taxes.\n");
        printf("2. Business Analyst - Analyze data to help businesses improve operations.\n");
        printf("3. Financial Advisor - Provide investment and financial planning advice.\n");
        printf("4. Marketing Manager - Develop strategies to promote products and services.\n");
    } 
    else {
        printf("\nSorry, we don't have career options for that interest yet.\n");
    }
}
int getValidRating(const char *careerName) {
    int rating;
    do {
        printf("%s (1 to 5): ", careerName);
        scanf("%d", &rating);
        getchar(); 
        if (rating < 1 || rating > 5) {
            printf("Invalid rating. Please enter a number between 1 and 5.\n");
        }
    } while (rating < 1 || rating > 5);
    return rating;
}
void rateCareers(const char interest[]) {
    int rating;
    char choice;
    printf("\nWould you like to rate the careers you just explored? (Y/N): ");
    scanf(" %c", &choice);
    getchar(); 
    if (choice == 'Y' || choice == 'y') {
        printf("\nRate each career on a scale of 1 to 5 (1 = Not Interested, 5 = Highly Interested):\n");
        if (strcmp(interest, "science") == 0) {
            getValidRating("1. Doctor");
            getValidRating("2. Engineer");
            getValidRating("3. Research Scientist");
            getValidRating("4. Data Analyst");
        } else if (strcmp(interest, "arts") == 0) {
            getValidRating("1. Artist");
            getValidRating("2. Writer");
            getValidRating("3. Psychologist");
            getValidRating("4. Journalist");
        } else if (strcmp(interest, "commerce") == 0) {
            getValidRating("1. Chartered Accountant");
            getValidRating("2. Business Analyst");
            getValidRating("3. Financial Advisor");
            getValidRating("4. Marketing Manager");
        }
    }
}
int main() {
    char interest[50];
    char continueChoice;
    printf("Welcome to the Advanced Career Guidance Tool!\n");
    do {
        printf("\nEnter your area of interest (Science, Arts, Commerce): ");
        fgets(interest, sizeof(interest), stdin);
        interest[strcspn(interest, "\n")] = 0; 
        toLowerCase(interest);
        suggestCareer(interest);
        rateCareers(interest);
        printf("\nWould you like to explore another interest? (Y/N): ");
        scanf(" %c", &continueChoice);
        getchar(); 
    } while (continueChoice == 'Y' || continueChoice == 'y');
    printf("\nThank you for using the Career Guidance Tool. Goodbye!\n");
    return 0;
}