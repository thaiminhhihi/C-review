

// // ## **Bài 9: Nâng cao – Quản lý danh sách động**

// // Viết chương trình nhập `n` sinh viên (gồm tên, điểm), dùng cấp phát động. In ra danh sách sinh viên, 
// điểm trung bình toàn lớp và tên sinh viên có điểm cao nhất. Cho phép nhập thêm sinh viên sau khi đã nhập danh sách ban đầu (sử dụng `realloc`).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
typedef struct {
    char name[MAX_NAME_LENGTH];
    float score;
} Student;
void inputStudent(Student *student) {
    printf("Nhập tên sinh viên: ");
    scanf(" %[^\n]", student->name);
    printf("Nhập điểm sinh viên: ");
    scanf("%f", &student->score);
}
void printStudent(const Student *student) {
    printf("Tên: %s, Điểm: %.2f\n", student->name, student->score);
}
float calculateAverageScore(const Student *students, int n) {
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        total += students[i].score;
    }
    return total / n;
}
void findTopStudent(const Student *students, int n) {
    if (n == 0) return;
    Student topStudent = students[0];
    for (int i = 1; i < n; i++) {
        if (students[i].score > topStudent.score) {
            topStudent = students[i];
        }
    }
    printf("Sinh viên có điểm cao nhất: %s với điểm %.2f\n", topStudent.name, topStudent.score);
}
int main() {
    int n;
    printf("Nhập số lượng sinh viên: ");
    scanf("%d", &n);
    
    Student *students = (Student *)malloc(n * sizeof(Student));
    if (students == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhập thông tin cho sinh viên %d:\n", i + 1);
        inputStudent(&students[i]);
    }

    printf("\nDanh sách sinh viên:\n");
    for (int i = 0; i < n; i++) {
        printStudent(&students[i]);
    }

    float averageScore = calculateAverageScore(students, n);
    printf("Điểm trung bình toàn lớp: %.2f\n", averageScore);

    findTopStudent(students, n);

    char choice;
    printf("Bạn có muốn thêm sinh viên mới? (y/n): ");
    scanf(" %c", &choice);
    
    while (choice == 'y' || choice == 'Y') {
        n++;
        students = (Student *)realloc(students, n * sizeof(Student));
        if (students == NULL) {
            printf("Cấp phát bộ nhớ thất bại khi mở rộng!\n");
            return 1;
        }
        printf("Nhập thông tin cho sinh viên %d:\n", n);
        inputStudent(&students[n - 1]);

        printf("\nDanh sách sinh viên sau khi thêm:\n");
        for (int i = 0; i < n; i++) {
            printStudent(&students[i]);
        }

        averageScore = calculateAverageScore(students, n);
        printf("Điểm trung bình toàn lớp: %.2f\n", averageScore);
        
        findTopStudent(students, n);

        printf("Bạn có muốn thêm sinh viên mới? (y/n): ");
        scanf(" %c", &choice);
    }

    free(students);
    return 0;
}