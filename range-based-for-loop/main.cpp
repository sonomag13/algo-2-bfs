#include <iostream>
#include <vector>
using namespace std;

// ref.: https://www.youtube.com/watch?v=8qrZYjL2jBg

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6};
    vector<int> vec = {1, 2, 3, 4, 5, 6};

    for(int i : arr) {
        cout << "i = " << i << endl;
    }

    for(auto itr : vec) {
        cout << "itr = " << itr << endl;
    }

    return 0;
}
