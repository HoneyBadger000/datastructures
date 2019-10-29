#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    stack<int> s;

    s.push(5);
    s.push(10);
    s.push(15);

    cout << "s.size() " << s.size() << endl;
    cout << "s.empty() " << s.empty() << endl;
    cout << "s.top() " << s.top() << endl;

    s.pop();
    cout << "s.top() " << s.top() << endl;

    s.pop();
    cout << "s.top() " << s.top() << endl;

    s.pop();
    cout << "s.empty() " << s.empty() << endl;

    return 0;
}