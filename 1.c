// Bài 1: Quản lý sinh viên – Sắp xếp theo tên
// Khai báo struct SinhVien gồm: ten, tuoi, diem.
// Nhập danh sách n sinh viên.
// Dùng con trỏ để:
// Nhập danh sách.
// Sắp xếp danh sách tăng dần theo tên (dùng strcmp()).
// In danh sách sau sắp xếp.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float score;
} Student;
void inputStudent(Student *student) {
    printf("Nhập tên sinh viên: ");
    scanf(" %[^\n]", student->name);
    printf("Nhập tuổi sinh viên: ");
    scanf("%d", &student->age);
    printf("Nhập điểm sinh viên: ");
    scanf("%f", &student->score);
}
void printStudent(const Student *student) {
    printf("Tên: %s, Tuổi: %d, Điểm: %.2f\n", student->name, student->age, student->score);
}
void sortStudentsByName(Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
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

    sortStudentsByName(students, n);

    printf("\nDanh sách sinh viên sau khi sắp xếp theo tên:\n");
    for (int i = 0; i < n; i++) {
        printStudent(&students[i]);
    }

    free(students);
    return 0;
}