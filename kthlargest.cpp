#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class kthlargest_naive
{
    public:

    int kthlargest(vector<int>& input, int k){

        // Sort in descending order and return the n-k th element

        sort(input.begin(),input.end());
        return(input[input.size() - k]);

    }

};

class kthlargest_heap{
    public:

    int kthlargest(vector<int>& input, int k){
        priority_queue<int, vector<int> , greater<int>> pq;

        for(int i=0; i< input.size() ;++i){
            if(pq.size()< k){
                pq.push(input[i]);
            }
            else{
                int min_elem = pq.top();
                if(min_elem < input[i]){
                    pq.pop();
                    pq.push(input[i]);
                }
            }
        }

        return pq.top();
    }
};

int main(){
    kthlargest_naive obj1;
    kthlargest_heap obj2;

    vector<int> input1 = {1,67,4,5,67,8,9,45,32};

    cout << obj1.kthlargest(input1, 4) << endl;
    cout << obj2.kthlargest(input1, 4) << endl;
}