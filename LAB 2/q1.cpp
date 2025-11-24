#include <iostream>
#include <string>
using namespace std;

class StudentFeeManager{
    int* fees;
    int students;

    public:
    StudentFeeManager(int s,int initialFee){
        students = s;
        fees = new int[students];
        for(int i=0;i<students;i++){
            fees[i] = initialFee;
        }
    }

    StudentFeeManager(const StudentFeeManager& other){
        students = other.students;
        fees = new int[students];
        for(int i=0;i<students;i++){
            fees[i] = other.fees[i];
        }
    }

    StudentFeeManager& operator=(const StudentFeeManager& other){
        if(this == &other){
            return *this;
        }
        students = other.students;
        fees = new int[students];
        for(int i=0;i<students;i++){
            fees[i] = other.fees[i];
        }
        return *this;
    }

    ~StudentFeeManager(){
        delete[] fees;
    }

    void setFee(int std,int amount){
        if(std>=0 && std< students){
            fees[std] = amount;
        }else{
            cout << "invalid student number" << endl;
        }
    }

    int getFee(int std){
        if(std>=0 && std< students){
           return fees[std];
        }else{
            cout << "invalid student number" << endl;
            return -1;
        }
    }

    void display(){
        for(int i=0;i<students;i++){
            cout << fees[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    StudentFeeManager s1(3,500);
    s1.display();
    cout << endl;
    StudentFeeManager s2 = s1;
    s2.display();
    cout << endl;
    s2.setFee(1,1000);
    cout << endl;
    s1.display();
    cout << endl;
    s2.display();
    return 0;
}