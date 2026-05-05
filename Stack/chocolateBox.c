#include <stdio.h>
#define max 50
int main()
{
    int choc[] = {1, 2, 0, 3, 0, 0};
    int n=6;
    int top = -1;
    int stack[max];
    for (int i = 0; i <n; i++)
    {
        if (choc[i] > 0)
        {
            top++;
            stack[top] = choc[i];
        }
        else if (choc[i] == 0)
        {
            if(top!=-1)
            {
                printf("%d ",stack[top]);
                top--;
            }
        }
    }
    return 0;
}