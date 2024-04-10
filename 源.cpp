#include <stdio.h>
#include <stdlib.h>
int main()
{
    int* arr;
    int N = 0, input = 0, i = 0;
    int sum = 0, max = 0;
    scanf_s("%d", &N);
    arr = (int*)malloc(sizeof(int) * N);
    int minus = 0;
    //对数组进行赋初值，并且记录负数个数
    for (i = 0; i < N; i++)
    {
        scanf_s("%d", &input);
        arr[i] = input;
        if (input < 0)
        {
            minus++;
        }
    }
    //如果全为负数，直接输出0，并结束程序
    if (minus == N)
    {
        printf("0");
        return 0;
    }
    //对最大子数组进行求解
    max = arr[1];
    for (i = 0; i < N; i++)
    {
        sum = sum + arr[i];
        if (sum > max)
        {
            max = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    printf("%d", max);
    return 0;
}
