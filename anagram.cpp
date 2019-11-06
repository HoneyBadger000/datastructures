#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

class anagram{
    public:

    bool isanagram(string& actual , string& angrm){

        if(actual.size() != angrm.size())return false;
        if(actual == "" && angrm == "") return true;

        vector<bool> matched(angrm.size(), false);

        for(int i =0; i<actual.size() ; ++i){
            for(int j=0; j<angrm.size();++j){
                if(angrm[j] == actual[i] && !matched[j]){
                    matched[j] = true;
                    break;
                }
            }
        }

        //check if matched[] has all trues in it
        for(int i=0; i<matched.size();++i){
            if(!matched[i]) return false;
        }

        return true;
    }
};

class anagram_efficient{
    public:

    bool isanagram(string& actual , string& anagrm){
        // Sort both the strings and if they are same, its an anagram!

        if(actual.length() != anagrm.length()) return false;
        sort(actual.begin(), actual.end());
        sort(anagrm.begin(),anagrm.end());

        return actual==anagrm;

    }
};

class anagram_hash{
    public :

    bool isanagram(string& actual, string& anagrm){

        unordered_map<char, int> actual_map;

        for(int i=0; i<actual.size();i++){
            ++actual_map[actual[i]];
        }

        for(int i =0; i<anagrm.size();i++)
        {
            --actual_map[actual[i]];
        }

        for(auto it : actual_map){
            if(it.second != 0) return false;
        }

        return true;

    }
};

class anagram_ascii{
    public :

    bool isanagram(string s, string t){
        vector<int> H(128,0);

        for(int i=0; i<s.size();++i){
            H[s[i]]++;
        }

        for(int i=0; i<t.size();++i){
            H[t[i]]--;
        }

        for(int i=0; i<128;++i){
            if(H[i]!=0) return false;
        }

        return true;
    }
};

int main(){
    anagram obj1;
    anagram_efficient obj2;
    anagram_hash obj3;
    anagram_ascii obj4;

    string input = "asdfghjkl";
    string anagram = "lkjhgfdsa";

    cout << obj1.isanagram(input,anagram) << endl;
    cout << obj2.isanagram(input,anagram) << endl;
    cout << obj3.isanagram(input,anagram) << endl;
    cout << obj4.isanagram(input,anagram) << endl;

    input = "asdfghjkl";
    anagram = "lkjhgfsa";

    cout << obj1.isanagram(input,anagram) << endl;
    cout << obj2.isanagram(input,anagram) << endl;
    cout << obj3.isanagram(input,anagram) << endl;
    cout << obj4.isanagram(input,anagram) << endl;

    return 0;
}