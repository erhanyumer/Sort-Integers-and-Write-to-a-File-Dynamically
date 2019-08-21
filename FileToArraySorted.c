#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *fp;
    fp = fopen("elements.txt", "r");
    if (fp == NULL)
    {
        printf("Error Reading File\n");
        exit(0);
    }
    int *ptr, n = 11;
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using malloc.\n");
        for (int i = 0; i < n; i++) //get the elements of array
        {
            fscanf(fp, "%d", &ptr[i]);
        }
        printf("The elements of the array are: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d\n\n", ptr[i]);
        }
        fclose(fp);
        return 0;
    }
}