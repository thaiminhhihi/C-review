// ## **Bài 8: Nâng cao – Tìm số lần xuất hiện của 1 giá trị**

// Viết chương trình nhập vào `n` phần tử nguyên (mảng cấp phát động). Sau đó nhập 1 giá trị `x`. Sử dụng con trỏ để đếm và in ra số lần `x` xuất hiện trong mảng.
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, x;
    printf("Nhập số lượng phần tử: ");
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
    printf("Nhập giá trị cần tìm: ");
    scanf("%d", &x);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    printf("Giá trị %d xuất hiện %d lần trong mảng.\n", x, count);
    free(arr);
    return 0;
}
