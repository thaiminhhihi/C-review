// Bài 2: Sắp xếp danh sách sinh viên theo điểm – dùng Insertion Sortstruct Diem gồm: diemToan, diemVan, diemTB.
// Thêm trường thông tin Diem diem vào khai báo struct SinhVien.
// Tính diemTB = (Toan + Van) / 2.
// Sắp xếp danh sách tăng dần theo diemTB bằng insertion sort.
// Thao tác hoàn toàn bằng con trỏ.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float diemToan;
    float diemVan;
    float diemTB;
} Student;
void inputStudent(Student *student) {
    printf("Nhập tên sinh viên: ");
    scanf(" %[^\n]", student->name);
    printf("Nhập tuổi sinh viên: ");
    scanf("%d", &student->age);
    printf("Nhập điểm Toán: ");
    scanf("%f", &student->diemToan);
    printf("Nhập điểm Văn: ");
    scanf("%f", &student->diemVan);
    student->diemTB = (student->diemToan + student->diemVan) / 2.0;
}
void printStudent(const Student *student) {
    printf("Tên: %s, Tuổi: %d, Điểm Toán: %.2f, Điểm Văn: %.2f, Điểm TB: %.2f\n",
           student->name, student->age, student->diemToan, student->diemVan, student->diemTB);
}
void insertionSortStudentsByAverageScore(Student *students, int n) {
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].diemTB > key.diemTB) {
            students[j + 1] = students[j];
            j--;
        }
        students[j + 1] = key;
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

    insertionSortStudentsByAverageScore(students, n);

    printf("\nDanh sách sinh viên sau khi sắp xếp theo điểm trung bình:\n");
    for (int i = 0; i < n; i++) {
        printStudent(&students[i]);
    }

    free(students);
    return 0;
}