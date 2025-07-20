// Bài 5: Gộp nhiều bộ dữ liệu sinh viên và sắp xếp toàn bộ
// Có 2 danh sách struct SinhVien từ 2 lớp khác nhau.
// Gộp chúng lại bằng cách cấp phát động (malloc, realloc, calloc) một mảng mới.
// Dùng selection sort hoặc bubble sort để sắp xếp toàn bộ theo điểm trung bình giảm dần.
// Hiển thị danh sách sau sắp xếp bằng con trỏ.
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
void bubbleSortStudentsByScore(Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n1, n2;
    
    // Nhập danh sách sinh viên lớp 1
    printf("Nhập số lượng sinh viên lớp 1: ");
    scanf("%d", &n1);
    Student *students1 = (Student *)malloc(n1 * sizeof(Student));
    if (students1 == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        return 1;
    }
    for (int i = 0; i < n1; i++) {
        printf("Nhập thông tin cho sinh viên %d lớp 1:\n", i + 1);
        inputStudent(&students1[i]);
    }

    // Nhập danh sách sinh viên lớp 2
    printf("Nhập số lượng sinh viên lớp 2: ");
    scanf("%d", &n2);
    Student *students2 = (Student *)malloc(n2 * sizeof(Student));
    if (students2 == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        free(students1);
        return 1;
    }
    for (int i = 0; i < n2; i++) {
        printf("Nhập thông tin cho sinh viên %d lớp 2:\n", i + 1);
        inputStudent(&students2[i]);
    }

    // Gộp hai danh sách
    int totalStudents = n1 + n2;
    Student *allStudents = (Student *)malloc(totalStudents * sizeof(Student));
    if (allStudents == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        free(students1);
        free(students2);
        return 1;
    }
    
    memcpy(allStudents, students1, n1 * sizeof(Student));
    memcpy(allStudents + n1, students2, n2 * sizeof(Student));

    // Sắp xếp toàn bộ theo điểm giảm dần
    bubbleSortStudentsByScore(allStudents, totalStudents);

    // Hiển thị danh sách sau sắp xếp
    printf("\nDanh sách sinh viên sau khi gộp và sắp xếp theo điểm giảm dần:\n");
    for (int i = 0; i < totalStudents; i++) {
        printStudent(&allStudents[i]);
    }

    // Giải phóng bộ nhớ
    free(students1);
    free(students2);
    free(allStudents);
    return 0;
}