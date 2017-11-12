
#include "stdio.h"

// 原理：
// 类似摸牌，从桌子上抓牌放到左手上的最右边，且在此之前左手上的牌从左到右按从小到大的顺序已排序好；
// 然后拿最右边牌跟它左边的牌进行比较，如果最右边的牌面大，则保持当前位置不变，如果小，两者相互调换位置；
// 依次进行下去，直到从桌面拿起的牌大于它左边的牌为止；
// 循环之前的动作，直到桌面的牌全部拿完为止；
// 算法复杂度：被排序数组的元素个数为n, 复杂度为n * (n-1) / 2

/**
  * SrcArrayLength: 被排序数组元素的个数
  * pSrcArray:      指向被排序的数组
  */
void insertion_sort(int SrcArrayLength, int *pSrcArray)
{
    int i, j;

    for (i = 1; i < SrcArrayLength; i++)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (*(pSrcArray + j + 1) < *(pSrcArray + j))
            {
                int temp = *(pSrcArray + j);
                *(pSrcArray + j) = *(pSrcArray + j + 1);
                *(pSrcArray + j + 1) = temp;
            }
            else
            {
                break;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i;
    int SrcArray[] = {0, 1985, 10, 10, 1988, 6, 24, 0, -1985, -10, -10, -1988, -6, -24, 0, 2015, 1, 8, -2015, -1, -8};
   
    printf("before sorting, SrcArray = \r\n");
    for (i = 0; i < sizeof(SrcArray) / sizeof(int); i++)
    {
        printf("%d, ", SrcArray[i]);
    }
    printf("\r\n");

    insertion_sort(sizeof(SrcArray) / sizeof(int), SrcArray);

    printf("after sorting, SrcArray = \r\n");
    for (i = 0; i < sizeof(SrcArray) / sizeof(int); i++)
    {
        printf("%d, ", SrcArray[i]);
    }
    printf("\r\n");
    
    return 0;
}
