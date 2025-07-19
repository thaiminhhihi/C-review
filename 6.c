// ## **Bài 6: Nâng cao – Đảo ngược mảng bằng con trỏ**

// Viết chương trình nhập vào `n` số nguyên và lưu trong mảng cấp phát động. Dùng con trỏ để đảo ngược mảng đó mà không dùng mảng phụ. In mảng sau khi đảo ngược.
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int n;
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
    // Đảo ngược mảng bằng con trỏ
    int *ptr1 = arr;
    int *ptr2 = arr + n - 1;
    while (ptr1 < ptr2) {
        int temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        ptr1++;
        ptr2--;
    }
    printf("Mảng sau khi đảo ngược:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    free(arr);
    return 0;
}
