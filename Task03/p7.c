#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    char s1[MAX], s2[MAX], i;
    printf("Enter string one: ");
    fgets(s1, sizeof(s1), stdin);

    for (i = 0; s1[i] != '\0'; ++i) {
        s2[i] = s1[i];
    }

    s2[i] = '\0';
    printf("Copied string: %s", s2);
    return 0;
}