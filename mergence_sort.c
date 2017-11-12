
#include "stdio.h"
#include "string.h"
#include "sys/timeb.h"

void sort(int *pArray, int p, int r, int q)
{
    int i;

    int Array0Length = r - p + 1, Array1Length = q - r;

    int Array0[Array0Length];
    int Array1[Array1Length];

    memcpy(Array0, pArray + p, Array0Length * sizeof(int));
    memcpy(Array1, pArray + r + 1, Array1Length * sizeof(int)); 

    int *pArray0 = Array0, *pArray1 = Array1;
    pArray = pArray + p;

    for (i = 0; i < q - p; i++)
    {
        if (*pArray0 > *pArray1)
        {
            *pArray++ = *pArray1++;
            Array1Length--;

            if (Array1Length == 0)
            {
                memcpy(pArray, pArray0, Array0Length * sizeof(int));
                break;
            }
        }
        else
        {
            *pArray++ = *pArray0++;
            Array0Length--;

            if (Array0Length == 0)
            {
                memcpy(pArray, pArray1, Array1Length * sizeof(int));
                break;
            }
        }
    }
}

void mergence_sort(int *pArray, int p, int q)
{
    if (p < q)
    {
        int r = (p + q) / 2;

        mergence_sort(pArray, p, r), mergence_sort(pArray, r + 1, q);
        sort(pArray, p, r, q);
    }
}

int main(int argc, char *argv[])
{
    int i;

    struct timeb StartTime, EndTime;

    int Array[] = {2017, -2015, -8, -1, -1985, -12, -10, 6, 24, 1988};
    
    printf("before sorting, Array = \r\n");
    for (i = 0; i < sizeof(Array) / sizeof(int); i++)
    {
        printf("%d, ", Array[i]);
    }
    printf("\r\n");

    ftime(&StartTime);
    i = 10000000;
    while (i--)
        mergence_sort(Array, 0, sizeof(Array) / sizeof(int) - 1);
    ftime(&EndTime);

    printf("time using on sort is %ld ms...\r\n", (EndTime.time - StartTime.time)* 1000 + (EndTime.millitm - StartTime.millitm));

    printf("after sorting, Array = \r\n");
    for (i = 0; i < sizeof(Array) / sizeof(int); i++)
    {
        printf("%d, ", Array[i]);
    }
    printf("\r\n");

    return 0;
}
