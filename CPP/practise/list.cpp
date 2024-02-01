# include <iostream>
# include <list>
# include <string>
using namespace std;

 int main() 
 {
    list<string> s;
    s.push_back("hello");
    s.push_back("world");
    s.push_front("tide");
    s.push_front("crimson");
    s.push_front("alabama");
    list<string>::iterator p;
    // vector 可以使用 < 判断，list 只能使用 !=
    for (p = s.begin(); p != s.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    return 0;
 }