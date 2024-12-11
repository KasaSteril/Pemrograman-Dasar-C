#include <stdio.h>
#include <string.h>

#define MAX_COURSES 10
#define MAX_STUDENTS 50
#define MAX_NAME_LEN 50

int main() {
    int numCourses;
    int numStudents[MAX_COURSES];
    char courseNames[MAX_COURSES][MAX_NAME_LEN];
    char studentNames[MAX_COURSES][MAX_STUDENTS][MAX_NAME_LEN];
    float grades[MAX_COURSES][MAX_STUDENTS];
    float averages[MAX_COURSES] = {0};

    // Input number of courses
    printf("Enter the number of courses (max %d): ", MAX_COURSES);
    scanf("%d", &numCourses);
    getchar(); // Clear newline character from buffer

    // Validate number of courses
    if (numCourses <= 0 || numCourses > MAX_COURSES) {
        printf("Invalid number of courses. Exiting...\n");
        return 1;
    }

    // Input course names and number of students for each course
    for (int i = 0; i < numCourses; i++) {
        printf("Enter the name of course %d: ", i + 1);
        fgets(courseNames[i], MAX_NAME_LEN, stdin);
        courseNames[i][strcspn(courseNames[i], "\n")] = '\0'; // Remove newline character

        printf("Enter the number of students in %s (max %d): ", courseNames[i], MAX_STUDENTS);
        scanf("%d", &numStudents[i]);
        getchar(); // Clear newline character from buffer

        // Validate number of students
        if (numStudents[i] <= 0 || numStudents[i] > MAX_STUDENTS) {
            printf("Invalid number of students for course %s. Exiting...\n", courseNames[i]);
            return 1;
        }
    }

    // Input student names and their grades for each course
    for (int i = 0; i < numCourses; i++) {
        printf("\nEntering grades for %s:\n", courseNames[i]);
        for (int j = 0; j < numStudents[i]; j++) {
            printf("Enter the name of student %d: ", j + 1);
            fgets(studentNames[i][j], MAX_NAME_LEN, stdin);
            studentNames[i][j][strcspn(studentNames[i][j], "\n")] = '\0'; // Remove newline character

            printf("Enter the grade for %s: ", studentNames[i][j]);
            scanf("%f", &grades[i][j]);
            getchar(); // Clear newline character from buffer

            // Validate grade
            if (grades[i][j] < 0.0 || grades[i][j] > 100.0) {
                printf("Invalid grade for %s. Please enter a grade between 0 and 100.\n", studentNames[i][j]);
                j--; // Retry for the same student
            }
        }
    }

    // Calculate averages for each course
    for (int i = 0; i < numCourses; i++) {
        float sum = 0;
        for (int j = 0; j < numStudents[i]; j++) {
            sum += grades[i][j];
        }
        averages[i] = sum / numStudents[i];
    }

    // Display each course as a separate table
    printf("\nResults:\n");
    for (int i = 0; i < numCourses; i++) {
        printf("\nCourse: %s\n", courseNames[i]);
        printf("%-20s%-10s\n", "Student Name", "Grade");

        for (int j = 0; j < numStudents[i]; j++) {
            printf("%-20s%-10.2f\n", studentNames[i][j], grades[i][j]);
        }

        printf("Average Grade for %s: %.2f\n", courseNames[i], averages[i]);
    }

    return 0;
}
