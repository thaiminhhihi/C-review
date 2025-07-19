// ## **Bài 5: Mở rộng mảng bằng realloc**

// Viết chương trình:

// - Nhập số lượng phần tử `n` và cấp phát động mảng bằng `malloc`
// - Nhập `n` giá trị và in ra
// - Sau đó yêu cầu người dùng nhập thêm `m` phần tử mới
// - Dùng `realloc` để mở rộng vùng nhớ chứa mảng, nhập thêm dữ liệu và in ra toàn bộ mảng mới
// - Giải phóng bộ nhớ sau khi sử dụng
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n;
    printf("Nhập số lượng phần tử ban đầu: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        return 1;
    }
    printf("Nhập %d giá trị cho mảng:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Giá trị của mảng ban đầu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    int m;
    printf("Nhập số lượng phần tử mới cần thêm: ");
    scanf("%d", &m);
    arr = (int *)realloc(arr, (n + m) * sizeof(int));
    if (arr == NULL) {
        printf("Cấp phát bộ nhớ thất bại khi mở rộng!\n");
        return 1;
    }
    printf("Nhập %d giá trị mới cho mảng:\n", m);
    for (int i = n; i < n + m; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Giá trị của mảng sau khi mở rộng:\n");
    for (int i = 0; i < n + m; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}
