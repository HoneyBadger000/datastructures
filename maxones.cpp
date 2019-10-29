#include <vector>
#include <iostream>

using namespace std;

class maxones {
    public:
    int findMaxConsecutiveOnes (vector <int>& nums) {
        int max_l = 0;
        int n = nums.size();

        for(int i=0; i< n; ++i)
        {
            if(nums[i] == 1)
            {
                int current_l = 1;
                int r = i+1;

                while(nums[r] == 1)
                {
                    ++current_l;
                    ++r;
                }

                max_l = max(max_l,current_l);
            }
        }
        return max_l;

    }
};

class maxones_efficient{
    public:

    int findMaxConsecutiveOnes(vector <int> & nums) {
            int max_l = 0;
            int n = nums.size();

            int i=0;

            while (i <= n)
            {
                if(nums[i] == 1)
                {
                    int current_l = 1;
                    int r = i+1;

                    while(nums[r] == 1)
                    {
                        ++current_l;
                        ++r;
                    }
                    i = r;
                    max_l = max(max_l,current_l);
                }
                else
                {
                    ++i;
                }                
            }
            
        return max_l;
    }

};

int main()
{
    //maxones obj;

    maxones_efficient obj;
    vector <int> input = {1,0,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0};
    cout << "Max num of ones is : " << obj.findMaxConsecutiveOnes(input) << endl;

}