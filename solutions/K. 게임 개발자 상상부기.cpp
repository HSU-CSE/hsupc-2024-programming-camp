#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

class Room {
private:
    string title;
    vector<int> users;
    int adminId;
    
public:
    Room(string &title, int &id) {
        this->title = title;
        this->adminId = id;
    }

    int getAdminId() { return adminId; }

    void setAdminId(int &adminId) { this->adminId = adminId; }

    string getTitle() { return title; }

    vector<int> &getUsers() { return users; }

    void setTitle(string &title) { this->title = title; }

    void setUsers(vector<int> &users) { this->users = users; }
};

class Manage {
public:
    vector<Room> data;

    Manage() { data.clear(); }

    bool enterRoom(string &title, int &id) {
        //어느 유저가 어느 방으로 들어가는지
        bool ret = false;
        for (Room &r: data) {
            if (r.getTitle() == title) {
                r.getUsers().push_back(id);
                ret = true;
                break;
            }
        }
        return ret;
    }

    int isAlreadyMake(string &title) { //이미 만들어진 적이 있는지 적발
        int index = -1;
        for (int i = 0; i < data.size(); i++) {
            if (data[i].getTitle() == title) {
                index = i;
                break;
            }
        }
        return index;
    }

    bool gameStart(string &title,
                   int &id) { //어떤 아이가 게임을 시작했는지 중요함
        bool ret = false;
        for (Room r: data) {
            if (r.getTitle() == title) {
                if (r.getAdminId() == id) {
                    ret = true;
                    break;
                }
            }
        }
        return ret;
    }

    bool makeRoom(string &title, int &id) {
        int index = isAlreadyMake(title); //이미 만들어진 적이 있는지 확인
        if (index != -1) { //이미 만들어진 적이 있으면 방장만 바꾸자.
            this->data[index].setAdminId(id);
            this->data[index].getUsers().push_back(id);
            return false;
        }
        Room newRoom(title, id);
        newRoom.getUsers().push_back(id);
        data.push_back(newRoom);
        return true;
    }

    bool gameEnd(string &title, int &id) {
        bool ret = false;
        vector<Room>::iterator it = data.begin();
        while (it != data.end()) {
            if ((*it).getTitle() == title) {
                if ((*it).getAdminId() == id) {
                    ret = true;
                }
                data.erase(it);
                break;
            }
            it++;
        }
        return ret;
    }
};

class Error {
private:
    string time;
    int id;

public:
    Error(string &time, int &id) {
        this->time = time;
        this->id = id;
    }

    int getId() { return id; }

    string getTime() { return time; }

    void setId(int &id) { this->id = id; }

    void setTime(string &time) { this->time = time; }
};

void errorAdd(vector<Error> &errors, Error newError, bool Already[]) {
    int id = newError.getId();
    if (Already[id])
        return;
    errors.push_back(newError);
    Already[id] = true;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    vector<Error> errors;
    bool Numbering[10002]{}; //숫자 이미 출력했는지 중복체크
    Manage manage;
    int n;
    cin >> n;
    string title = "";
    for (int i = 0; i < n; i++) {
        string time, mode;
        int id;
        cin >> time >> id >> mode;
        if (mode[0] == 'm') {
            cin >> title;
            bool flag = manage.makeRoom(title, id);
            if (!flag)
                errorAdd(errors, Error(time, id), Numbering);
        } else if (mode[0] == 'i') {
            cin >> title;
            manage.enterRoom(title, id);
        } else if (mode[0] == 's') {
            cin >> title;
            bool flag = manage.gameStart(title, id);
            if (flag == 0) { // id 안 맞는 아이가 시작함.
                errorAdd(errors, Error(time, id), Numbering);
            }
        } else if (mode[0] == 'e') {
            cin >> title;
            bool flag = manage.gameEnd(title, id);
            if (!flag)
                errorAdd(errors, Error(time, id), Numbering);
        }
    }
    for (Error &output: errors) {
        cout << output.getTime() << " " << output.getId() << endl;
    }
    return 0;
}
