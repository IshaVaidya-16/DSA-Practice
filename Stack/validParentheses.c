#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s)
{
    int len = strlen(s);
    int stack[len];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[')
        {
            top++;
            stack[top] = c;
        }
        else
        {
            if (top == -1)
            {
                return false;
            }
            if (s[i] == ')' && stack[top] == '(' ||
                s[i] == ']' && stack[top] == '[' ||
                s[i] == '}' && stack[top] == '{')
            {
                top--;
            }
            else
            {
                return false;
            }
        }
    }
    return top == -1;
}

int main()
{
    char s[100];
    printf("Enter string:");
    scanf("%s", s);
    if (isValid(s))
    {
        printf("Valid parentheses");
    }
    else
    {
        printf("Invalid parentheses");
    }
    return 0;
}