#include <stdio.h>
main(){
    int key;
    char word[55];
    scanf("%d",&key);//키 입력 받기
    scanf(" %[^\n]s",word);//한 줄 입력
    //키가 알파벳을 여러 번 돌게 되면 비효율적이므로 모듈러 연산으로 최적화
    if(key>=0)key%=26;
    else key = -((-key)%26);
    for(int i=0;word[i];i++){
        if(word[i]==' '){//빈칸은 그냥 출력
            printf(" ");
            continue;
        }
        int output = word[i]-key; //복호화
        //벗어났을 때 처리
        if(output<65)output+=26;
        else if(output>90)output-=26;
        printf("%c",output);
    }
}