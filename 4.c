// // ## **Bài 4: Tạo và in mảng động bằng calloc**

// // Viết chương trình nhập số nguyên `n`. Cấp phát bộ nhớ động cho mảng `n` số nguyên sử dụng `calloc`.
//  In toàn bộ giá trị của mảng ngay sau khi cấp phát. Sau đó cho phép người dùng nhập dữ liệu và in lại toàn bộ mảng. Giải phóng bộ nhớ cuối chương trình.
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    int *arr = (int *)calloc(n, sizeof(int));
    if (arr == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        return 1;
    }

    printf("Giá trị của mảng sau khi cấp phát:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("Nhập dữ liệu cho mảng:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Giá trị của mảng sau khi nhập dữ liệu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    return 0;
}
