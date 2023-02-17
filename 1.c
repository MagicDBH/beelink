// 出现次数最多的数
#include <stdio.h>
int main()
{
    int c, b, n;
    scanf("%d", &n);
    int a[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n - j - 1; i++)
            if (a[i] >= a[i + 1])
            {
                c = a[i];
                a[i] = a[i + 1];
                a[i + 1] = c;
            }
    int d[100] = {0}, e[100];
    int k = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == a[i + 1])
            d[k]++;
        if (a[i] != a[i + 1])
        {
            e[k] = a[i];
            k++;
        }
    }
    for (int i = 0; i < k; i++)
    {
        int in;
        for (int j = 0; j < k - 1 - i; j++)
            if (d[i] >= a[i + 1])
            {
                in = d[k];
                d[k] = d[k + 1];
                d[k + 1] = in;
            }
    }
    int al;
    for (int i = k; i > 0; i--)
    {
        if (d[i] > d[i - 1])
            printf("%d", e[i]);
        if (d[i] == d[i - 1])
        {
            if (e[i] > e[i - 1])
                continue;
            if (e[i] < e[i - 1])
            {
                al = e[i];
                e[i] = e[i - 1];
                e[i - 1] = al;
            }
        }
    }
}