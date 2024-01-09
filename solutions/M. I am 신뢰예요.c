#include <stdio.h>
#include <stdlib.h>

int cats[1002];
int students[100002];

int compare(void *a, void *b) {
    int *A = (int *) a;
    int *B = (int *) b;
    return *A > *B;
}

int upperBound(int target, int size, const int array[]) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 고양이 몸무게 입력받기
    for (int index = 0; index < n; index++) {
        scanf("%d", &cats[index]);
    }

    // 학생 키 입력받기
    for (int index = 0; index < m; index++) {
        scanf("%d", &students[index]);
    }

    // 정렬
    qsort(students, m, sizeof(int), compare);

    // 모든 고양이들의 키에 대해서 '착한인간구별공식' 을 만족하는 학생의 마지막 인덱스 파악
    for (int index = 0; index < n; index++) {
        int target = cats[index];
        int count = upperBound(target, m, students);
        printf("%d ", count);
    }

    printf("\n");
    return 0;
}
