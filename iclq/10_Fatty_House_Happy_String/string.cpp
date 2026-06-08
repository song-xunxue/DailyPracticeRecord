#include <iostream>
#include <string>
#include <vector>
using namespace std;

const string target = "fattyhappy";

int main() {
    int T;
    cin >> T;
    while (T--) 
    {
        string s;
        cin >> s;
        int n = s.size();
        if (n < 10) 
        {
            cout << -1 << endl;
            continue;
        }
        size_t found = s.find(target);
        if (found != string::npos) 
        {
            //有符合的子串
            cout << found + 3 << " " << found + 4 << endl;
            continue;
        }
        //模拟哈希 存储每一个字符的下标
        vector<int> pos[26];
        for (int i = 0; i < n; i++) 
        {
            int index = s[i] - 'a';
            if (index >= 0 && index < 26) 
            {
                pos[index].push_back(i);
            }
        }

        bool solved = false;
        for (int i = 0; i <= n - 10; i++) 
        {
            vector<int> diff;
            for (int j = 0; j < 10; j++) 
            {
                if (s[i + j] != target[j]) 
                {
                    diff.push_back(j);
                }
            }
            if (diff.size() > 2) 
            {
                continue;
            }

            if (diff.size() == 2) 
            {
                int j1 = diff[0];
                int j2 = diff[1];
                if (s[i + j1] == target[j2] && s[i + j2] == target[j1]) 
                {
                    cout << i + j1 + 1 << " " << i + j2 + 1 << endl;
                    solved = true;
                    break;
                }
            }
            else if (diff.size() == 1) 
            {
                int j = diff[0];
                char need_char = target[j];
                int char_index = need_char - 'a';
                //符合条件
                //if (char_index < 0 || char_index >= 26) 
                //{
                //    continue;
                //}
                for (int p : pos[char_index]) 
                {
                    if (p < i || p >= i + 10) 
                    {
                        cout << i + j + 1 << " " << p + 1 << endl;
                        solved = true;
                        break;
                    }
                }
                if (solved) 
                {
                    break;
                }
            }
        }
        if (!solved) 
        {
            cout << -1 << endl;
        }
    }
    return 0;
}