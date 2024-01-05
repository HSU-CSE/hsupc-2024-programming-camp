#include <stdio.h>
#include <stdlib.h>
int cats[1002],students[100002];
int compare(void* a,void *b){
    int* A=(int*)a;
    int* B=(int*)b;
    return *A > *B;
}

int upperBound(int target,int size, int array[]){
    int left=0,right=size-1;
    while(left<=right){
        int mid =(left+right)/2;
        if(array[mid]>target){
            right=mid-1;
        }else{
            left= mid+1;
        }
    }
    return left;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    // 고양이 몸무게 입력받기
    for(int i=0;i<n;i++)
        scanf("%d",&cats[i]);
    // 학생 키 입력받기
    for(int i=0;i<m;i++)
        scanf("%d",&students[i]);

    // 정렬
    qsort(students,m,sizeof(int),compare);

    // 모든 고양이들에 대해서 '착한인간구별공식' 적용
    for(int i=0;i<n;i++){
        int target = cats[i];
        int cnt = upperBound(target,m,students);
        printf("%d ",cnt);
    }
    printf("\n");
    return 0;
}
