#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(int &a, int &b, int &c) {
    if ((a < b) && (b < c)) return true;
    if ((b < c) && (c < a)) {
        swap(a, b);
        swap(c, b);
        return true;
    }
    if ((c < a) && (a < b)) {
        swap(a, c);
        swap(c, b);
        return true;
    }
    return false;
}
string larrysArray(vector<int> A) {
    int len = A.size();
    bool flag = true;
    for (int i = 0; i < len - 1; i++) {
        int index = 0;
        while (index < len - 2){
            flag = check(A[index], A[index + 1], A[index + 2]);
            index++;
            if (!flag) break;
        }
    } 
    if (flag) return "YES";
    else return "NO";
}
int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        v.push_back(x);
    }
    cout << larrysArray(v);
}