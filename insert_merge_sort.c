
#include "stdio.h"

void insert(int *pArray, int i)
{
    for ( ; i > 0; i--)
    {
        if (*(pArray + i) < *(pArray + i - 1))
        {
            int tmp = *(pArray + i - 1);
            *(pArray + i - 1) = *(pArray + i);
            *(pArray + i) = tmp;
        }
        else
        {
            break;
        }
    }
}

void merge(int *pArray, int i)
{
    if (i > 0)
    {
        i--;

        merge(pArray, i);
        insert(pArray, i);
    }
}

int main(int argc, char *argv[])
{
    int Array[] = {-2015, 1010, -1988, 8, 1, 24, 6, -1985, 1010};

    printf("before sort, Array = \r\n");
    for (int i = 0; i < sizeof(Array) / sizeof(int); i++)
    {
        printf("%d, ", Array[i]);
    }
    printf("\r\n");

    merge(Array, sizeof(Array) / sizeof(int));

    printf("after sort, Array = \r\n");
    for (int i = 0; i < sizeof(Array) / sizeof(int); i++)
    {
        printf("%d, ", Array[i]);
    }
    printf("\r\n");

    return 0;
}

