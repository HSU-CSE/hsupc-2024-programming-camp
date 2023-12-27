#include <stdbool.h>
#include <stdio.h>
bool compare(int idx, char word[]) {
  char words[] = "Hong";
  int i = idx;
  for (; word[i] && words[i - idx]; i++) {
    if (word[i] != words[i - idx])
      return 0;
  }
  if (i != idx + 4)
    return 0;
  return 1;
}
main() {
  char word[102];
  scanf("%s", word);
  int cnt = 0;
  for (int i = 0; word[i]; i++) {
    if (word[i] == 'H') {
      bool ret = compare(i, word);
      if (ret) {
        cnt++;
        i += 3;
      }
    }
  }
  printf("%d", cnt);
}