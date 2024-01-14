#include <stdio.h>

int main() {
    int n, s, d;
    scanf("%d", &n);
    int answer = 0;
    int end_point = -1;
    for (int index = 0; index < n; index++) {
        scanf("%d %d", &s, &d);
	if (index == 0){
	    end_point = s + d;
	    answer ++;
	}
        else if (s >= end_point) {
            answer ++;
	    end_point = s + d;
        }
    }
    printf("%d", answer);
    return 0;
}
