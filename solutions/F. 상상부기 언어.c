#include <stdio.h>
main(){
    char a[55];
    scanf("%[^\n]s",a);//한 줄 입력받기 테크닉
    for(int i=0;a[i];i++){
        if(a[i]<=63)a[i]-=32;
        int value=a[i]-196;
        while(value<0)value+=127;
        printf("%c",value);
    }
}