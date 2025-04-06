#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const int N = 1e5 + 5;
vector<int> a;
int sz = 0;
int stk[N];
int ans = 0;

void push(int x) { stk[++sz] = x; }
int pop() { return stk[sz--]; }

vector<int> readline() {
    string line;
    getline(cin, line); // 读入整行

    vector<int> nums;
    stringstream ss(line);
    string token;

    while (getline(ss, token, ',')) {
        nums.push_back(stoi(token));
    }

    return nums;
}

int main() {
    a = readline();

    for (int i = 0; i < a.size(); i++) {
        while (sz && a[stk[sz]] < a[i]) {
            int t = pop();
            if (!sz)
                break;
            int w = i - stk[sz] - 1;
            int h = min(a[i], a[stk[sz]]) - a[t];
            ans += w * h;
        }
        push(i);
    }
    cout << ans;

    return 0;
}
