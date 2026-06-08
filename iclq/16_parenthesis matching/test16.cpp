#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_LEN = 100010;

vector<long long> L(MAX_LEN, 0);
vector<long long> R(MAX_LEN, 0);
long long sum = 0;

bool match(char c1, char c2) {
    return (c1 == '(' && c2 == ')');
}

void simplify(const string& s) {
    vector<char> stack;

    for (char c : s) {
        if (!stack.empty() && match(stack.back(), c)) {
            stack.pop_back();
        }
        else {
            stack.push_back(c);
        }
    }

    if (stack.empty()) {
        sum++;
        return;
    }

    // 检查栈中是否所有字符都相同
    char first_char = stack[0];
    for (char c : stack) {
        if (c != first_char) {
            return; // 栈中有不同字符，无法匹配
        }
    }

    int count = stack.size();
    if (first_char == '(') {
        L[count]++;
    }
    else {
        R[count]++;
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        simplify(str);
    }

    long long record = sum / 2; // 完全匹配的字符串可以两两配对

    // 匹配左括号和右括号数量相同的字符串
    for (int i = 0; i < MAX_LEN; i++) {
        record += min(L[i], R[i]);
    }

    cout << record << endl;

    return 0;
}