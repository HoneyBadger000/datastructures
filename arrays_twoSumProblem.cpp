#include <array>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution1{
public:
    vector<int> twoSum(vector<int>& numset, int target){
        
        int n = numset.size();
        vector<int> retvalue = {0,0};

        for(int i =0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    if(numset[i]+numset[j] == target){
                        retvalue[0] = i;
                        retvalue[1] = j;
                        return retvalue;
                    }
                }
            }
        }
    }
};

int main()
{
    Solution1 sol;
    vector<int> input = {1,6,7,11,67,54,6,3};

    auto found = sol.twoSum(input, 71);
    cout << "found at : " << found.front() << "," << found.back() << endl;

    found = sol.twoSum(input, 57);
    cout << "found at : " << found.front() << "," << found.back() << endl;

    found = sol.twoSum(input, 73);
    cout << "found at : " << found.front() << "," << found.back() << endl;

    return 0;
}