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

    bool checkValidString (string str)
    {
        if(str.size() == 0)
            return true;

        if(str.size() == 1)
            return false;

        int n = str.size();
        stack<char> st;
        // if first element in str is ) || } || ] return flase

        if(str[0] ==')' || str[0] == ']' || str[0]  == '}'){
            return false;
        }
        else{
            st.push(str[0]);
        }

        for(int i=1 ; i<n ; i++){
            if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
                if(st.empty()){
                    return false;
                }
                else{
                    if((st.top()== '{' && str[i]== '}') || (st.top() == '(' && str[i] == ')') || (st.top()== '{' && str[i] == '}')){
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    
                }
            }
            else{
                st.push(str[i]);
            }
        }

        if(st.empty()) return true;
        else return false;


    }
};

int main()
{
    //checkParanthesis obj;
    paranthesis_stack obj;

    string input1 = "(){}(}(){}";
    string input2 = "(){}()(){}";
    string input3 = "(){}{}";

    cout << "(){}(}(){} : " <<  obj.checkValidString(input1) << endl;
    cout << "(){}()(){} : " <<  obj.checkValidString(input2) << endl;
    cout << "(){}{} : " <<  obj.checkValidString(input3) << endl;

}