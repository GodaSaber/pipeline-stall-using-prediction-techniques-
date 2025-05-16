#include <stdio.h>

// Function to analyze a single grade
void analyzeGrade(int grade) {
    printf("Analyzing grade: %d\n", grade);

    if (grade >= 50) {
        printf("Passed this subject\n");
    } else {
        printf("Failed this subject\n");
    }

    if (grade % 2 == 0) {
        printf("The grade is even\n");
    } else {
        printf("The grade is odd\n");
    }

    if (grade % 10 == 0) {
        printf("The grade is a multiple of 10\n");
    }

    if (grade > 90) {
        printf("Excellent!\n");
    } else if (grade >= 75) {
        printf("Very Good\n");
    } else if (grade >= 60) {
        printf("Good\n");
    } else if (grade >= 50) {
        printf("Acceptable\n");
    } else {
        printf("Weak\n");
    }

    printf("--------------\n");
}

// Function to evaluate a student: sum, average, and performance
void evaluateStudent(int grades[], int size, int studentNumber) {
    int sum = 0;
    int i = 0;

    printf("\nReport for Student #%d:\n", studentNumber + 1);

    while (i < size) {
        printf("Subject %d: %d marks\n", i + 1, grades[i]);
        analyzeGrade(grades[i]);  // Call analysis function
        sum += grades[i];
        i++;
    }

    float avg = (float)sum / size;

    printf("Total: %d\n", sum);
    printf("Average: %.2f\n", avg);

    // Overall grade level using switch
    char gradeLevel;
    if (avg >= 90) gradeLevel = 'A';
    else if (avg >= 75) gradeLevel = 'B';
    else if (avg >= 60) gradeLevel = 'C';
    else if (avg >= 50) gradeLevel = 'D';
    else gradeLevel = 'F';

    switch (gradeLevel) {
        case 'A':
            printf("Overall Grade: Excellent (A)\n");
            break;
        case 'B':
            printf("Overall Grade: Very Good (B)\n");
            break;
        case 'C':
            printf("Overall Grade: Good (C)\n");
            break;
        case 'D':
            printf("Overall Grade: Acceptable (D)\n");
            break;
        case 'F':
            printf("Overall Grade: Fail (F)\n");
            break;
    }

    printf("==================================\n");
}

int main() {
    // 3 students, each has 4 subject grades
    int students[3][4] = {
        {85, 90, 78, 92},
        {45, 60, 55, 40},
        {100, 88, 75, 95}
    };

    int studentIndex = 0;

    // Loop through each student
    while (studentIndex < 3) {
        evaluateStudent(students[studentIndex], 4, studentIndex);
        studentIndex++;
    }

    return 0;
}
