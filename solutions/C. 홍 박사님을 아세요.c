#include <stdio.h>
//1번 풀이
main() {
  char word[102];
  scanf("%s", word);
  int cnt = 0;
  for (int i = 0; word[i]; i++) {
    if (word[i] == 'H') {
      cnt++;
    }
  }
  printf("%d", cnt);
}

//2번 풀이

main() {
  char word[102];
  scanf("%s", word);
  int cnt = 0;
  for (int i = 0; word[i]; i++) {
    cnt+=word[i]=='H';
  }
  printf("%d", cnt);
}