#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string A, B, C;
        cin >> A >> B;
        int a = A.size();
        int b = B.size();
        int carry = 0;

        while (a > 0 || b > 0 || carry > 0)
        {
            int sum = carry;
            if (a > 0) sum += A[--a] - '0';
            if (b > 0) sum += B[--b] - '0';

            C += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(C.begin(), C.end());

        int m = C.size() + 2;
        int m1 = m - A.size();
        int m2 = m - B.size() - 1;

        while (m1--) cout << " ";
        cout << A << endl;
        cout << "+";
        while (m2--) cout << " ";
        cout << B << endl;

        for (int i = 0; i < m; i++) cout << "-";
        cout << endl << "  " << C << endl;
    }
    return 0;
}
