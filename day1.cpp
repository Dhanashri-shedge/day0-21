#include <iostream>
using namespace std;

class Largest
{
public:
    int a[5];

    void large()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Enter Element " << i + 1 << ": ";
            cin >> a[i];
        }
    }
    void display()
    {
        cout << "The entered elements are: ";
        for (int i = 0; i < 5; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void findKthLargest(int k)
    {
        if (k < 1 || k > 5)
        {
            cout << "Invalid input. k should be between 1 and 5." << endl;
            return;
        }

        // Bubble sort to sort the array in descending order
        for (int i = 0; i < 5 - 1; i++)  // n-1 times
        {
            for (int j = 0; j < 5 - i - 1; j++) 
            {
                if (a[j] < a[j + 1])  
                {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        cout << "The " << k << "-th largest element is: " << a[k - 1] << endl;
    }
};

int main()
{
    Largest l;
    l.large();  
    l.display(); 

    int k;
    cout << "Enter the value of k (1 to 5): ";
    cin >> k;

    l.findKthLargest(k); 
    return 0;
}
