// Bài 3: 

// Sắp xếp sinh viên theo tuổi giảm dần (Selection Sort)
// Sử dụng selection sort để sắp xếp danh sách sinh viên theo tuổi giảm dần.
// Tất cả thao tác sắp xếp và hiển thị sử dụng con trỏ (không dùng ds[i]).
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
void selectionSortStudentsByAge(Student *students, int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (students[j].age > students[maxIndex].age) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Student temp = students[i];
            students[i] = students[maxIndex];
            students[maxIndex] = temp;
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

    selectionSortStudentsByAge(students, n);

    printf("\nDanh sách sinh viên sau khi sắp xếp theo tuổi giảm dần:\n");
    for (int i = 0; i < n; i++) {
        printStudent(&students[i]);
    }

    free(students);
    return 0;
}