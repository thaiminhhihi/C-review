// 🔸 vBài 2: Tính chu vi và diện tích hình chữ nhật
// Viết chương trình:
// Nhập chiều dài và chiều rộng


// Tính chu vi và diện tích theo công thức:


// Chu vi = 2 * (dài + rộng)
// Diện tích = dài * rộng
#include <stdio.h>
int main(int argc, char const *argv[])
{
    printf(" Nhap chieu dai va chieu rong: ");
    float dai, rong;
    scanf(" %f %f", &dai, &rong);
    printf("chu vi = %.2f\n", 2 * (dai + rong));
    printf("dien tich = %.2f", dai *rong);
    return 0;
}
