#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class duplicates{
    public :

    bool containsNearByDuplicates(vector<int>& nums , int distance){
        int n = nums.size();

        for(int i = 0; i<= n-1 ; ++i)
        {
            int j = i+1;
            while(j<=n){
                if(abs(j-i) > distance)break;
                if(nums[i]==nums[j]){
                    return true;
                }
                ++j;
            }
        }

        return false;

    }
};

class duplicates_efficient{
    public:

    bool containsNearByDuplicates(vector<int>& nums, int distance){
        unordered_map<int, int> hash_map;

        for(int i =0 ; i< nums.size(); ++i){
            if(hash_map.find(nums[i]) != hash_map.end()){
                // Number already found
                if(abs(hash_map[nums[i]] - i) <= distance) {
                    return true;
                }
                else{
                    hash_map[nums[i]] = i;
                }
            }
            else{
                // Number isnt already there, add it now
                hash_map[nums[i]] = i;
            }
            
        }
    }
};

int main(){

    duplicates obj1;
    duplicates_efficient obj2;

    vector<int> input = {1,2,3,4,5,9,1,2,2,3,6,7,1,1};

    cout << obj2.containsNearByDuplicates(input,6) << endl;

    return 0;
}