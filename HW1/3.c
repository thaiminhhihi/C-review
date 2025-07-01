// 🔸 Bài 3: Tính trung bình cộng 3 số
// Nhập vào 3 số thực a, b, c và tính trung bình cộng.

#include <stdio.h>
int main(int argc, char const *argv[])
{
    float a,b,c;
    scanf("%f %f %f", &a, &b, &c);
    printf("trung binh cong la = %.2f", (a+b+c)/3);
    return 0;
}
