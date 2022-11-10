#include <stdio.h>
#include <string.h>

void acuse(int l, int r, int s[])
{
    s[l]++;
    if(l < r) acuse(l + 1, r, s);
}
void depoimentos(int testemunha, int suspeitos[])
{
    int l, r;
    scanf("%d%d", &l, &r);
    acuse(l, r, suspeitos);

    if(testemunha - 1)
        depoimentos(testemunha - 1, suspeitos);
}
int max(int a, int b)
{
    return a > b ? a : b;
}
int biggest_val(int a[], int size)
{
    if(size == 0) return 0;

    return max(a[size], biggest_val(a, size - 1));
}
int find_intervals(int a[], int val, int is_interval, int i, int size, int curr_seq, int max_seq, int max_index)
{
    if(a[i] == val && !is_interval)
    {
        is_interval = 1;
        printf("%d ", i);
    }
    if(a[i] != val && is_interval)
    {
        is_interval = 0;
        printf("%d\n", i - 1);
    }
    if(is_interval)
        curr_seq++;
    else
        curr_seq = 0;

    if(max_seq < curr_seq) {
        max_seq = curr_seq;
        max_index = i;
    }
    if(i == size)
    {
        if(is_interval)
            printf("%d\n", i);
        return max_index;
    }
    return find_intervals(a, val, is_interval, i + 1, size, curr_seq, max_seq, max_index);   
}
int find_max_seq(int a[], int i, int val)
{
    if(a[i] == val)
        return 1 + find_max_seq(a, i - 1, val);
    return 0;
}
void prt(int a[], int i, int size)
{
    if(i == size)
        return;
    printf("%d%s", a[i], i == size - 1 ? "" : " ");
    prt(a, i + 1, size);
}
int main()
{
    int s, t, start = 0, end = 0, max_value, max_seq;
    scanf("%d %d", &s, &t);
    int suspeitos[s];
    memset(suspeitos, 0, sizeof(suspeitos));
    depoimentos(t, suspeitos);

    prt(suspeitos, 0, s);
    printf("\n");

    max_value = biggest_val(suspeitos, s - 1);

    printf("%d\n", max_value);

    end = find_intervals(suspeitos, max_value, 0, 0, s - 1, 0, 0, 0);

    max_seq = find_max_seq(suspeitos, end, max_value);

    start = end - max_seq + 1;

    printf("maior sequencia: %d\ncomeca em: %d\ntermina em: %d\n", max_seq, start, end);
    return 0;
}