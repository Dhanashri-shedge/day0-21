#include <iostream>
using namespace std;

class recursion {
public:
    int fact(int num) {
        if (num == 0 || num == 1) {
            return 1;
        }
        return num * fact(num - 1);
    }
};

int main() {
    recursion r;
    int n;
    cout << "Enter the number: ";
    cin >> n;  
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        cout << "The factorial is: " << r.fact(n) << endl;
    }
    
    return 0;
}
