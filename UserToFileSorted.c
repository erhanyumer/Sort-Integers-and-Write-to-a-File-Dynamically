#include <stdio.h>
#include <stdlib.h>

void bubbles(int[], int);

int main()
{
    FILE *fp = fopen("elements.txt", "w");
    int i = 0;    //array index counter
    int temp;     //temp value
    int *arrptr;  //dynamic array pointer
    int size = 0; //dynamic array size
    arrptr = (int *)malloc(size * sizeof(int));
    printf("Enter numbers (if you want sort; press *):");
    do //getting inputs until *
    {
        scanf("%d", &temp);
        arrptr[i] = temp;
        size++;
        i++;
        arrptr = realloc(arrptr, (size + 1) * sizeof(int));
    } while (getchar() != '*');

    bubbles(arrptr, i);            //sorts the inputs
    for (int i = 0; i < size; i++) //writes to file
    {
        fprintf(fp, "%d ", arrptr[i]);
    }
    fclose(fp);
    free(arrptr);

    return 0;
}

void bubbles(int array1[], int size)
{
    int a, b, c;
    for (a = 0; a < (size - 1); a++)
    {
        for (b = 0; b < size - a - 1; b++)
        {
            if (array1[b] > array1[b + 1])
            {
                c = array1[b];
                array1[b] = array1[b + 1];
                array1[b + 1] = c;
            }
        }
    }
}