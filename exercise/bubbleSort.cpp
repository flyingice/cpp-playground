#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;

void bubbleSort(vector<int>& v) {
    int sz = v.size();
    int flag = true;
    for(int i = 0; i < sz && flag; ++i) {
        flag = false;
        for(int j = 0; j < sz - i - 1; ++j) {
            if(v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
                flag = true;
            }
        }
    }
}

void print(const vector<int>& v) {
    ostream_iterator<int> out(cout, " ");
    copy(v.begin(), v.end(), out);
}

int main() {
    vector<int> v;

    srand(time(NULL));
    int randSize = 1 + rand() % 20;
    for(int i = 0; i < randSize; ++i)
        v.push_back(rand() % 200);

    cout << "before sort: " << endl;
    print(v);
    cout << endl;
    bubbleSort(v);
    cout << "after sort: " << endl;
    print(v);
    cout << endl;
}
