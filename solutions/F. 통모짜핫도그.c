#include <stdio.h>
#define max(a,b) (a>b ? a : b)
int main() {
	int n; scanf("%d", &n);
	int s, d; scanf("%d %d", &s, &d);
	printf("YES\n");
	int endPoint = s + d;
	for (int i = 0; i < n-1; i++) {
		scanf("%d %d", &s, &d);
		if (s >= endPoint)printf("YES\n");
		else printf("No\n");
		endPoint = max(endPoint,s+d);
	}
	return 0;
}