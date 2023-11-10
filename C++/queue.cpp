#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> Q;

    cout << "Is Queue empty: " << Q.empty() << endl;

    for (int i = 0; i < 5; i++) {
        Q.push(i);
    }

    cout << "Size = " << Q.size() << endl;
    cout << "Front = " << Q.front() << endl;
    cout << "Back = " << Q.back() << endl;

    Q.pop();
    Q.pop();
    cout << "Popped 2 times\n";

    cout << "Size = " << Q.size() << endl;
    cout << "Front = " << Q.front() << endl;
    cout << "Back = " << Q.back() << endl;

    cout << "Is Queue empty: " << Q.empty() << endl;
    
    return 0;
}