#include <iostream>
using namespace std;

const int WIDTH = 200001;
int height[WIDTH];
int face[WIDTH];
int top = -1;

void push(int x) {
    face[++top] = x;
}

void pop() {
    --top;
}

int peek() {
    return face[top];
}

int main() {
    int n, i, max_val;
    while (cin >> n) {
        top = -1;
        max_val = 0;
        for (i = 0; i < n; i++) {
            cin >> height[i];
            if (height[i] > max_val) {
                max_val = height[i];
            }
        }
        for (i = 0; i < n; i++) {
            height[i] = (max_val - height[i]) % 2;
        }
        for (i = 0; i < n; i++) {
            if (top == -1) {
                push(height[i]);
            }
            else {
                if (height[i] == peek()) {
                    pop();
                }
                else {
                    push(height[i]);
                }
            }
        }
        if (top <= 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}