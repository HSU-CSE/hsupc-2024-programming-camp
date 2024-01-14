#include <stdio.h>
#include <string.h>

int map[1000001];
int hack_users[10001];

int hash(char *key) {
    int ret = 0;
    for (int index = 0; key[index]; key++) {
        ret = ret * 100 + key[index];
    }

    return ret;
}

void insert(char *key, const int value) {
    map[hash(key)] = value;
}

void erase(char *key) {
    map[hash(key)] = 0;
}

int contain(char *key) {
    return map[hash(key)] != 0;
}

int find(char *key) {
    return map[hash(key)];
}

int start(char *title, const int user) {
    int ret = find(title);
    if (ret != user) {
        return 0;
    }

    return 1;
}

int end(char *title, const int user) {
    int ret = find(title);
    erase(title);
    if (ret != user) {
        return 0;
    }

    return 1;
}

int make(char *title, const int user) {
    int ret = contain(title);
    insert(title, user);
    if (ret) {
        return 0;
    }

    return 1;
}

int main() {
    char time[8], mode[8], title[5];
    int user, n;
    scanf("%d", &n);

    for (int repeat = 0; repeat < n; repeat++) {
        int is_valid = 1;
        scanf("%s %d %s", time, &user, mode);
        if (!strcmp(mode, "make")) {
            scanf("%s", title);
            is_valid = make(title, user);
        } else if (!strcmp(mode, "into")) {
            scanf("%s", title);
        } else if (!strcmp(mode, "start")) {
            scanf("%s", title);
            is_valid = start(title, user);
        } else if (!strcmp(mode, "end")) {
            scanf("%s", title);
            is_valid = end(title, user);
        }
        if (!is_valid && !hack_users[user]) {
            hack_users[user]++;
            printf("%s %d\n", time, user);
        }
    }

    return 0;
}
