#include <stdio.h>
#define max(a,b) (a>b ? a:b)
main(){
    int n;scanf("%d",&n);
    int array[17]={};
    
    int max_height=0;
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
        max_height=max(max_height,array[i]);
    }
    
    for(int height=max_height;height>=1;height--){
        for(int index = 0;index<n;index++){
            char output= ' ';
            if(height<=array[index]){
                output = array[index] + '0';
            }
            printf("%c",output);
        }
        printf("\n");
    }
}
