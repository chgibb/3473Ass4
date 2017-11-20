//lru https://www.thecrazyprogrammer.com/2016/11/lru-page-replacement-algorithm-c.html

#include <stdio.h>
 
int findLRU(int time[], int n){
    int i, minimum = time[0], pos = 0;
 
    for(i = 1; i < n; ++i){
        if(time[i] < minimum){
            minimum = time[i];
            pos = i;
        }
    }
    
    return pos;
}
 
int main()
{
    int no_of_frames, no_of_pages, frames[10], pages[30], counter = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
    printf("Enter number of frames: ");
    //scanf("%d", &no_of_frames);
    no_of_frames = 3;
    printf("Enter number of pages: ");
    //scanf("%d", &no_of_pages);
    no_of_pages = 6;
    printf("Enter reference string: ");
    
   /* for(i = 0; i < no_of_pages; ++i){
        scanf("%d", &pages[i]);
    }*/
    pages[0] = 5;
    pages[1] = 7;
    pages[2] = 5;
    pages[3] = 6;
    pages[4] = 7;
    pages[5] = 3;
    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                counter++;
                time[j] = counter;
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
            pos = findLRU(time, no_of_frames);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        
        printf("\n");
        
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    
    return 0;
}