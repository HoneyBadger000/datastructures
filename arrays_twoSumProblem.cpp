
#include <algorithm>
#include <vector>
#include <iostream>
#include <array>

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


class Solution_eff{
    public:
    vector<int> twoSum(vector<int>& numset, int target){
        vector< pair<int, int>> nums2;
        vector<int> retval = {0,0};

        for(int i=0; i<numset.size(); i++)
        {
            pair<int,int> temp(numset[i],i);
            nums2.push_back(temp);
        }

        // sorting a vector of pairs, sorts it by the first element
        sort(nums2.begin(),nums2.end());

        int i= 0;
        int j= (nums2.size()-1);

        while(i<j){
            if(nums2[i].first + nums2[j].first == target){

                cout << "Found match" << endl;

                retval[0] = nums2[i].second;
                retval[1] = nums2[j].second;

                //vector<int> t{nums2[i].second, nums2[j].second};
                return retval;
            }
            else if(nums2[i].first+nums2[j].first > target){
                --j;
            }
            else
            {
                ++i;
            }                            
        }
    }
};

int main()
{
    //Solution1 sol;
    Solution_eff sol;
    vector<int> input = {1,6,7,11,67,54,6,8,0,3};

    auto found = sol.twoSum(input, 71);
    cout << "found at : " << found.front() << "," << found.back() << endl;

    found = sol.twoSum(input, 18);
    cout << "found at : " << found.front() << "," << found.back() << endl;

    found = sol.twoSum(input, 73);
    cout << "found at : " << found.front() << "," << found.back() << endl;

    return 0;
}