#include <iostream>
#include "Vector.h"

int main()
{
    using std::cout;
    using std::endl;

    try
    {
        Vector<int> v(7);

        for(int i = 0; i < 9; i++)
        {
            v.push_back(i);
        }

        cout << "Vector: "   << v << endl;
        cout << "Capacity: " << v.capacity() << endl;
        cout << "Length : "  << v.length()   << endl << endl;

        cout << "Insert some values..." << endl << endl;

        v.insert(7, 10);
        v.insert(2, 20);
        v.insert(4, 15);

        cout << "Vector: "   << v            << endl;
        cout << "Capacity: " << v.capacity() << endl;
        cout << "Length : "  << v.length()   << endl << endl;
        
        Vector<int> v2(Vector<int>(5));
        cout << "Vector created by move-constructor" << endl;
        for(std::size_t i = 0; i < v2.length(); i++)
        {
            cout << v2[i] << " ";
        }
        cout << endl << endl;
    }
    catch(const char *msg)
    {
        cout << msg << endl;
    }
    
    return 0;
}
