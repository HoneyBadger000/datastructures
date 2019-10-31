#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int main(){

    unordered_map<string, int> hash_map;
    vector<string> names;

    names.push_back("Jaimie");
    names.push_back("Cersei");
    names.push_back("Arya");
    names.push_back("Ned");
    names.push_back("Catelyn");
    names.push_back("Arya");

    for(int i=0; i<names.size(); i++){
        if(hash_map.find(names[i]) == hash_map.end()){
            //We are at the end of the hash map but didnt find the name

            hash_map.insert(make_pair(names[i],1));
        }
        else{
            hash_map[names[i]] = hash_map[names[i]] +1;
        }
        
    }

    for(auto it = hash_map.begin(); it!=hash_map.end();++it){
        cout << it->first << " " << it->second << endl;
    }

return 0;
}