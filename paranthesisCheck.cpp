#include <string>
#include <algorithm>
#include <iostream>

#include <stack>

using namespace std;

class checkParanthesis{
    public:

    bool checkValidString (string& str){
        if(str.length() == 0){
            return true;
        }

        if((str.find("()")) != string::npos){
            int index = str.find("()");
            str.replace(index,2,"");
            return checkValidString(str);
        }
        else if((str.find("{}")) != string::npos){
            int index = str.find("{}");
            str.replace(index, 2, "");
            return checkValidString(str);
        }
        else if((str.find("[]")) != string::npos){
            int index = str.find("[]");
            str.replace(index, 2, "");
            return checkValidString(str);
        }
        else{
            return false;
        }

    }

};

class paranthesis_stack{
    public :

    bool checkparanthesis (string str)
    {
        stack<char> s;
        if(s.size() == 0)
            return true;

        if(s.size() == 1)
            return false;

        if

    }
};

int main()
{
    checkParanthesis obj;

    string input1 = "(){}(}(){}";
    string input2 = "(){}()(){}";
    string input3 = "(){}[](){}";

    cout << "(){}(}(){} : " <<  obj.checkValidString(input1) << endl;
    cout << "(){}()(){} : " <<  obj.checkValidString(input2) << endl;
    cout << "(){}[](){} : " <<  obj.checkValidString(input3) << endl;

}