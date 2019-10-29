#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class MaxThreeProduct{
    public:

    int FindMaxProduct(vector <int> & nums) {

        // sort the array -- c++ manadates that sorting shouldnt take more than nlogn.
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Find the product of biggest 3 positie numbers
        int p1 = nums[n-1] * nums[n-2] * nums[n-3];

        // find the product of smallest 2 negative and biggest positive num
        int p2 = nums[0] * nums[1] * nums[n-1];

        return max(p1,p2);

    }
};

class MaxThreeProduct_Eff{
    public:

    int FindMaxProduct(vector <int> & nums){
        int max1, max2, max3, min1, min2;
        // Problem states that the range of input is -1000 to 1000
        max1 = max2 = max3 = -1001;
        min1 = min2 = 1001;
        int n = nums.size();
        // This solution needs that complexity is found in o(n)

        for(int i =0; i< n; i++){
            if (nums[i] >= max3){
                max1 = max2;
                max2 = max3;
                max3 = nums[i];
            }
            else if (nums[i] >= max2){
                max1 = max2;
                max2 = nums[i];
            }
            else if (nums[i] > max1){
                max1 = nums[i];
            }

            if(nums[i] < min2)
            {
                min1 = min2;
                min2 = nums[i];
            }
            else if (nums[i] < min1)
            {
                min1 = nums[i];
            }
        }

        int p1 = max3 * max2 * max1;
        int p2 = min1 * min2 * max3;

        return max(p1,p2);

    }
};

int main(){

    //MaxThreeProduct obj;
    MaxThreeProduct_Eff obj;
    vector<int> input = {-7,0,3,5,6,7,-5};
    cout << "Max product is " << obj.FindMaxProduct(input) << endl ;

    return 0;
}