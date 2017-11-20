//fifo http://meansofmine.blogspot.ca/2011/04/c-program-to-implement-fifo-page.html
#include <stdio.h>
int main()
{
    int i, j, numPages, refNums[50], frame[10], numFrames, k, avail, count = 0;
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    //scanf("%d", &n);
    numPages = 20;
    printf("\n ENTER THE PAGE NUMBER :\n");
    //for (i = 1; i <= numPages; i++)
    //    scanf("%d", &a[i]);
    refNums[0] = 7;
    refNums[1] = 0;
    refNums[2] = 1;
    refNums[3] = 2;
    refNums[4] = 0;
    refNums[5] = 3;
    refNums[6] = 0;
    refNums[7] = 4;
    refNums[8] = 2;
    refNums[9] = 3;
    refNums[10] = 0;
    refNums[11] = 3;
    refNums[12] = 2;
    refNums[13] = 1;
    refNums[14] = 2;
    refNums[15] = 0;
    refNums[16] = 1;
    refNums[17] = 7;
    refNums[18] = 0;
    refNums[19] = 1;
    printf("\n ENTER THE NUMBER OF FRAMES :");
    //scanf("%d", &no);
    numFrames = 3;
    for (i = 0; i < numFrames; i++)
        frame[i] = -1;
    j = 0;
    printf("\tref string\t page frames\n");
    for (i = 1; i <= numPages; i++)
    {
        printf("%d\t\t", refNums[i]);
        avail = 0;
        for (k = 0; k < numFrames; k++)
            if (frame[k] == refNums[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = refNums[i];
            j = (j + 1) % numFrames;
            count++;
            for (k = 0; k < numFrames; k++)
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }
    printf("Page Fault Is %d", count);
    return 0;
}