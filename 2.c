// ## **Bài 2: Tính tổng các phần tử trong mảng bằng con trỏ**

// Viết chương trình nhập vào số nguyên `n`, tạo mảng `n` phần tử kiểu `int`.
//  Nhập giá trị cho từng phần tử. Sử dụng con trỏ để tính tổng tất cả các phần tử trong mảng và in ra kết quả.
#include <stdio.h>
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum +=  (arr[i]);
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Tổng các phần tử trong mảng là: %d\n", sumArray(arr, n));
    return 0;
}
