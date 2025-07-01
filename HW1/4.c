// 🔸 Bài 4: Chuyển đổi độ C sang độ F
// Viết chương trình nhập vào nhiệt độ Celsius, chuyển sang độ Fahrenheit theo công thức:
// F = C * 9 / 5 + 32


#include <stdio.h>
int main(int argc, char const *argv[])
{
    float C;
    scanf("%f", &C);
    printf("Do F la = %.2f", C * 9 / 5 + 32);
    /* code */
    return 0;
}
