#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class baseball{
    public:

    int calPoints(vector<string>& operations){
        int n= operations.size();

        if(n==0) return 0;

        vector<bool> cancel(n,false);

        for(int i=0; i<n;i++){
            if(operations[i] == "C"){
                // go back and cancel the last valid operation
                int j = i-1;

                while(j>=0){

                    if(!cancel[j]){
                        cancel[j] = true;
                        break;
                    }                    
                    --j;
                }
                cancel[i] = true;
            }
            else if (operations[i] == "D"){
                int j=i-1;

                while(j>=0){
                    if(!cancel[j]){
                        // stoi string => int
                        // to_String int => string
                        operations[i] = to_string(2*stoi(operations[j]));
                        break;
                    }
                    --j;
                }
            }
            else if(operations[i] == "+")
            {
                // find 2 elements not cancelled and add them together
                int j = i-1;
                int count =0;
                int sum =0;

                while(j>0){
                    if(count == 2) break;
                    if(!cancel[j]){
                        sum = sum + stoi(operations[j]);
                        ++ count;
                    }
                    --j;

                    operations[i] = to_string(sum);
                }
            } else{
                // number, so do nothing
        }

        }

        int sum=0;

        for(int i=0 ; i<n; i++){
            if(!cancel[i]){
                sum+= stoi(operations[i]);
            }
        }

        return sum;

    }
};

class baseball_stack{
    public:

    int calPoints(vector<string>& operations){
        int n= operations.size();
        if(n==0) return 0;

        stack<int> st;

        for(int i =0; i<n; i++)
        {
            if(operations[i] == "C"){
                if(!(st.empty())){
                    st.pop();
                }
            }
            else if(operations[i] == "D"){
                if(!(st.empty())){
                    st.push(2*(st.top()));
                }
            }else if (operations[i] == "+"){
                if(!(st.empty())){
                    int v1 = st.top();
                    st.pop();

                    if(!(st.empty())){                        
                        int v2 = st.top();
                        st.push(v1);
                        st.push(v1+v2);
                    }else{
                        st.push(v1);
                        st.push(v1);
                    }
                }

            }else{
                st.push(stoi(operations[i]));
            }
        }

        int sum=0;

        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};


int main(){
    baseball obj;
    baseball_stack obj1;

    vector<string> input1 = {"5","+","C","D","3","5","6","C"};
    vector<string> input2 = {"8","C","5","7","3","5","6","C","D","7","+"};

    cout << "Score is " << obj.calPoints(input1) << endl;
    cout << "Score is " << obj1.calPoints(input1) << endl;

    cout << "Score is " << obj.calPoints(input2) << endl;
    cout << "Score is " << obj1.calPoints(input2) << endl;
    return 0;
}