#include <iostream>
#include <map>
#include <set>

using namespace std;

map<string, int> rooms;
set<int> hack_users;

bool make(int user_id, const string &room_name) {
    if (rooms.find(room_name) != rooms.end()) {
        rooms[room_name] = user_id;
        return false;
    }
    rooms[room_name] = user_id;
    return true;
}

bool start(int user_id, string room_name) {
    if (rooms[room_name] != user_id) {
        return false;
    }
    return true;
}

bool end(int user_id, string room_name) {
    if (rooms[room_name] != user_id) {
        rooms.erase(room_name);
        return false;
    }
    rooms.erase(room_name);
    return true;
}

void solve() {
    bool is_valid = true;
    int user_id;
    string time, mode, room_name;
    cin >> time >> user_id >> mode;
    if (mode != "login" && mode != "gaming") {
        cin >> room_name;
    }

    if (mode == "make") {
        is_valid = make(user_id, room_name);
    } else if (mode == "start") {
        is_valid = start(user_id, room_name);
    } else if (mode == "end") {
        is_valid = end(user_id, room_name);
    }

    if (!is_valid && hack_users.find(user_id) == hack_users.end()) {
        hack_users.insert(user_id);
        cout << time << ' ' << user_id << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int N;
    cin >> N;
    for (int repeat = 0; repeat < N; ++repeat) {
        solve();
    }
    return 0;
}
