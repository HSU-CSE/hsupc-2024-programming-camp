#include <stdio.h>
int main() {
	int n; scanf("%d", &n);
	printf("YES\n");
	int s, d; scanf("%d %d", &s, &d);
	int endPoint = s + d;
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &s, &d);
		if (s >= endPoint)printf("YES\n");
		else printf("No\n");
		endPoint = (endPoint > s + d ? endPoint : s + d);
	}
	return 0;
}