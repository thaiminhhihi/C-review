// ## **Bài 3: Cấp phát mảng động bằng malloc**

// Viết chương trình nhập vào số lượng phần tử `n`. Sử dụng `malloc` để cấp phát vùng nhớ động cho một mảng số nguyên `n` phần tử
// . Nhập giá trị, tính tổng, trung bình cộng và tìm phần tử lớn nhất trong mảng. Giải phóng bộ nhớ sau khi hoàn thành.
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    if (n == NULL) {
        printf("Cấp phát bộ nhớ thất bại!\n");
        return 1;
    }
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int sum = 0;
    float average;
    int max = arr[0];
    for (size_t i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    average = (float)sum / n;
    printf("Tổng: %d\n", sum);
    printf("Trung bình cộng: %.2f\n", average);
    printf("Phần tử lớn nhất: %d\n", max);
    free(n);
    return 0;
}
