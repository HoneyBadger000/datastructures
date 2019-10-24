#include <iostream>
#include <vector>
#include <algorithm>            // For sort(), binary_search()

using namespace std;

class Student{
private:
    int id;

public:

    Student(){
        id = 0xFF;
        cout << "Student constructor " << "id is " << id << endl;
    }

    Student(int Id){
        id = Id;
        cout << "Student constructor " << "id is " << id << endl;
    }

    bool operator<(Student const &obj) {
        return ((id) < (obj.id));
    };

    int getStudentId() const{
        return this->id;
    }
};

class comparator{
public:
    bool operator()(const Student& lhs, const Student& rhs){
        return lhs.getStudentId() > rhs.getStudentId();
    }
};

int main(){
    vector<Student> v;

    Student s1;
    Student s2(10);

    v.push_back(1); // A new student object with Id 1 is created and added to the vector.
    v.push_back(4);
    v.push_back(s1); // student1 object was already created.
    v.push_back(s2);

    cout << v.size() << endl;

    //v.erase(v.end());
    cout << v.size() << endl;

    //v.erase(v.begin(),v.begin()+1); // deletes only v.begin(), the first element deletes from [inclusive , exlusive)
    cout << v.size() << endl;

    v.push_back(4);
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);

    cout << "vector size is " << v.size() << endl;
    cout << "Operator < overloaded sort:" << endl;

    sort(v.begin(), v.end());   /* Default sort algorithm sorts it in ascending order, 
                                    but here as it is a class and not basic data type, 
                                    sorting would use the oerloaded function instead and sort aaccordingly */
    for(int i=0; i<v.size(); ++i)
        cout << v[i].getStudentId() << " " << endl;

    cout << "sort by a custom comparator function :" << endl ;
    sort(v.begin(),v.end(),comparator());

    for(int i=0; i<v.size(); ++i)
        cout << v[i].getStudentId() << " " << endl;

    cout << "Sort by a Lambda function : " << endl;

    sort(v.begin(), v.end(), [](const Student & st1, const Student & st2)
        { return(st1.getStudentId() > st2.getStudentId());
        });

    for(int i=0; i<v.size(); ++i)
        cout << v[i].getStudentId() << " " << endl;

    cout << "Binary search : Search for an element " << endl;

    // Doesnt work, come back later
    //Student newStd(10);
    //cout << "Student with Id 10 is : " << binary_search(v.begin(), v.end() ,const_cast<Student&>(newStd) << endl;



    return 0;
}