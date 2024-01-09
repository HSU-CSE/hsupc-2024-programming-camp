#include <stdio.h>
#include <string.h>

typedef struct Error {
    char time[8];
    int user;
} Error;

Error errors[10000];
int error_size = 0;
int map[1000000];
bool check[10005];

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

bool contain(char *key) {
    return map[hash(key)] != 0;
}

int find(char *key) {
    return map[hash(key)];
}

bool start(char *title, const int user) {
    int ret = find(title);
    if (ret != user) {
        return false;
    }

    return true;
}

bool end(char *title, const int user) {
    int ret = find(title);
    erase(title);
    if (ret != user) {
        return false;
    }

    return true;
}

bool make(char *title, const int user) {
    bool ret = contain(title);
    insert(title, user);
    if (ret) {
        return false;
    }

    return true;
}

void errorAdd(char *time, const int user) {
    if (check[user])return;
    check[user] = true;
    strcpy(errors[error_size].time, time);
    errors[error_size].user = user;
    error_size++;
}

int main() {
    char time[8], mode[8], title[5];
    int user, n;
    scanf("%d", &n);

    for (int repeat = 0; repeat < n; repeat++) {
        bool is_valid = true;
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
        if (!is_valid) {
            errorAdd(time, user);
        }
    }

    for (int index = 0; index < error_size; index++) {
        printf("%s %d\n", errors[index].time, errors[index].user);
    }

    return 0;
}
