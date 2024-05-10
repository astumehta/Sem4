#include <stdio.h>
#define size 4
int frames[size];
int pages[14] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};

void main(){
    int pagefound,hit=0,miss=0,k=0;
    for(int i=0;i<size;i++){
        frames[i]=-1;
    }
    for(int i=0;i<14;i++){
        pagefound=0;
        for(int j=0;j<size;j++){
            if(frames[j]==pages[i]){
                hit++;
                pagefound=1;
                break;
            }
        }
        if(!pagefound){
            miss++;
            frames[k]=pages[i];
            k=(k+1)%size;
        }
        for(int z=0;z<size;z++){
            printf("%d ",frames[z]);
        }
        printf("\n");
    }
    printf("Hits:%d , Miss:%d",hit,miss);
}