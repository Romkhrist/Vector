#include <iostream>
#include <vector>
#include "Vector.h"

int main()
{
    using namespace std;

    Vector<int> v(7);

    for(int i = 0; i < 9; i++)
    {
        v.push_back(i);
    }

    cout << "Vector: " << v << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Length : " << v.length() << endl << endl;

    cout << "Insert some values..." << endl << endl;

    v.insert(7, 10);
    v.insert(2, 20);
    v.insert(4, 15);

    cout << "Vector: " << v << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Length : " << v.length() << endl;

    return 0;
}
