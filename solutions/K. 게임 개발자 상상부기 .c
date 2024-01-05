#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Error {
    char time[8];
    int id;
} Error;
typedef struct Room {
    int adminId;
    int lastidx;
    int users[10005];
    char title[3];
} Room;
typedef struct Manage {
    Room data[10005]; // 10000개
    int lastidx;
} Manage;
void RoomInit(Room *it) {
    it->adminId = -1;
    it->lastidx = 0;
    memset(it->users, 0, sizeof(int) * 10005);
    strcpy(it->title, "0:00");
}
void ManageInit(Manage *it) {
    it->lastidx = 0;
    for (int i = 0; i < 10002; i++) {
        RoomInit(&it->data[i]);
    }
}
void ErrorInit(Error *it) {
    for (int i = 0; i < 10002; i++) {
        it[i].id = -1;
        strcpy(it[i].time, "0:00");
    }
}
int AlreadyMake(Manage *it, char title[]) {
    int size = it->lastidx;
    for (int i = 0; i < size; i++) {
        int compare = strcmp(it->data[i].title, title);
        if (!compare) { //둘이 같을 때
            return i;
        }
    }
    return -1;
}
void newRoom(Room *it, char title[], int id) {
    it->adminId = id;
    strcpy(it->title, title);
}
void setAdminId(Room *it, int id) { it->adminId = id; }
void enterRoom(Manage *it, int idx, int id) {
    int *lastidx = &it->data[idx].lastidx;
    it->data[idx].users[(*lastidx)++] = id;
}
bool makeRoom(Manage *it, char title[], int id) {
    int already = AlreadyMake(it, title);
    if (already != -1) {                  //이미 만들어졌기에
        setAdminId(&it->data[already], id); //방장 아이디 바꾸기
        enterRoom(it, already, id);         //그 방에 내가 들어가기
        return false;                       //못 만들었고 에러 추가
    }
    int idx = it->lastidx; //현재 인덱스에 title과 id 추가
    newRoom(&it->data[idx], title, id);
    enterRoom(it, it->lastidx++, id);
    return true;
}

int erroridx = 0;
void AddError(Error *it, char time[], int id, bool Already[]) {
    if (Already[id])
        return;
    Already[id] = true;
    it[erroridx].id = id;
    strcpy(it[erroridx++].time, time);
}
bool GameStart(Manage *it, char title[], int id) {
    int idx = AlreadyMake(it, title);
    if (it->data[idx].adminId == id)
        return true;
    return false;
}
void removeValue(Manage *its, int idx) {
    // idx에 있는 값을 없앨 거기에
    // idx에 idx+1값을 넣는 행위를 반복하면 된다.
    Room *it = its->data;
    for (int i = idx; i < its->lastidx; i++) {
        it[i].adminId = it[i + 1].adminId;
        it[i].lastidx = it[i + 1].lastidx;
        strcpy(it[i].title, it[i + 1].title);
        memcpy(it[i].users, it[i + 1].users, sizeof(int) * 10005);
    }
    RoomInit(&its->data[--its->lastidx]);
}
bool GameEnd(Manage *it, char title[], int id) {
    bool ret = false;
    int idx = AlreadyMake(it, title);
    if (it->data[idx].adminId == id)
        ret = true;
    removeValue(it, idx); //해당하는 곳에 값은 없애야됨.
    return ret;
}
Error errors[10002];
bool Numbering[10002];
Manage manage;
int main() {
    int n;
    scanf("%d", &n);
    ManageInit(&manage);
    ErrorInit(errors);
    char title[5];
    for (int i = 0; i < n; i++) {
        char time[8], mode[7];
        int id;
        scanf("%s %d %s", time, &id, mode);
        if (mode[0] == 'm') { //방 만들기
            scanf("%s", title);
            bool flag = makeRoom(&manage, title, id);
            if (!flag) {
                AddError(errors, time, id, Numbering);
            }
        } else if (mode[0] == 'i') {
            scanf("%s", title);
            int idx = AlreadyMake(&manage, title);
            enterRoom(&manage, idx, id);
        } else if (mode[0] == 's') {
            scanf("%s", title);
            bool flag = GameStart(&manage, title, id);
            if (!flag) {
                AddError(errors, time, id, Numbering);
            }
        } else if (mode[0] == 'e') { //게임 끝
            scanf("%s", title);
            bool flag = GameEnd(&manage, title, id);
            if (!flag) {
                AddError(errors, time, id, Numbering);
            }
        }
    }
    for (int i = 0; i < erroridx; i++) {
        printf("%s %d\n", errors[i].time, errors[i].id);
    }
    return 0;
}
