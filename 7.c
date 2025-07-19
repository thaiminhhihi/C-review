
// ## **Bài 7: Nâng cao – Gộp 2 mảng cấp phát động**

// Viết chương trình:

// - Nhập vào 2 số `n1` và `n2`, lần lượt cấp phát 2 mảng số nguyên
// - Nhập giá trị cho từng mảng
// - Dùng `realloc` hoặc `malloc` để tạo mảng thứ ba chứa tất cả phần tử từ mảng 1 và mảng 2
// - In ra mảng đã gộp
// - Giải phóng toàn bộ vùng nhớ sau khi dùng
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n1, n2;
    printf("Nhập số lượng phần tử cho mảng 1: ");
    scanf("%d", &n1);
    int *arr1 = (int *)malloc(n1 * sizeof(int));
    if (arr1 == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        return 1;
    }
    printf("Nhập %d giá trị cho mảng 1:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Nhập số lượng phần tử cho mảng 2: ");
    scanf("%d", &n2);
    int *arr2 = (int *)malloc(n2 * sizeof(int));
    if (arr2 == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        free(arr1);
        return 1;
    }
    printf("Nhập %d giá trị cho mảng 2:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int *arr3 = (int *)malloc((n1 + n2) * sizeof(int));
    if (arr3 == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        free(arr1);
        free(arr2);
        return 1;
    }
    for (int i = 0; i < n1; i++) {
        arr3[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        arr3[n1 + i] = arr2[i];
    }
    printf("Mảng sau khi gộp:\n");
    for (int i = 0; i < n1 + n2; i++) {
        printf("arr3[%d] = %d\n", i, arr3[i]);
    }
    free(arr1);
    free(arr2);
    free(arr3);
    return 0;
}
