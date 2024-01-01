#include <stdio.h>

#1번 풀이
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

#2번 풀이

#include <stdio.h>
#define abs(x) (x > 0 ? x: -x)
char Decryption(char src,int key){
    char ret = src;
    //음수면 앞으로 돌고 양수면 뒤로 돌아야 된다.
    int repeat = abs(key);
    for(int i=0;i<repeat;i++){
        if(key<0)ret++;
        else ret--;
        
        if(ret>90)ret-=26;
        else if(ret<65)ret+=26;
    }
    return ret;
}
main(){
    int key;
    char word[55];
    scanf("%d",&key);//키 입력 받기
    scanf(" %[^\n]s",word);//한 줄 입력
    //키가 알파벳을 여러 번 돌게 되면 비효율적이므로 모듈러 연산으로 최적화
    for(int i=0;word[i];i++){
        if(word[i]==' '){//빈칸은 그냥 출력
            printf(" ");
            continue;
        }
        printf("%c",Decryption(word[i],key));
    }
    printf("\n");
}

