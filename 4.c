
// Bài 4: Dùng Bubble Sort sắp xếp danh sách sinh viên theo tên
// Viết hàm void bubbleSortSV(struct SinhVien *ds, int n) để:
// Sắp xếp theo tên bằng strcmp().
// Đếm số lần hoán đổi xảy ra.
// Xuất kết quả sau sắp xếp.
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
void bubbleSortStudentsByName(Student *students, int n, int *swapCount) {
    *swapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                (*swapCount)++;
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

    int swapCount = 0;
    bubbleSortStudentsByName(students, n, &swapCount);

    printf("\nDanh sách sinh viên sau khi sắp xếp theo tên:\n");
    for (int i = 0; i < n; i++) {
        printStudent(&students[i]);
    }

    printf("Số lần hoán đổi xảy ra: %d\n", swapCount);

    free(students);
    return 0;
}
    
    
   