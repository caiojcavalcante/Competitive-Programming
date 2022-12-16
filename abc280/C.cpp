#include <stdio.h>
// int main()
// {
//     char ans = '\0', buffer;

//     while(cin >> buffer)
//         ans ^= buffer;

//     cout << ans << endl;
//     return 0;
// }

int main()
{
    char ans = '\0', buffer;

    while(scanf(" %c", &buffer) != EOF)
        ans ^= buffer;

    printf("%c\n", ans);
    return 0;
}