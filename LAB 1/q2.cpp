#include <iostream>
#include <string>
using namespace std;

class Exam{
    private:
    string* studentName;
    string* examDate;
    int score;

    public:
    Exam(){
        studentName = nullptr;
        examDate = nullptr;
        score = 0;
    }

    void setDetails(string name,string date,int score){
        studentName = new string(name);
        examDate = new string(date);
        this->score = score;
    }

    void displayDetails(){
        cout << "student name: " << *studentName << endl;
        cout << "exam date: " << *examDate << endl;
        cout << "score: " << score << endl;
    }

    ~Exam(){
        delete studentName;
        delete examDate;
    }
};

int main(){
    Exam ex1;
    ex1.setDetails("shahira","26-aug",50);
    ex1.displayDetails();

    Exam ex2 = ex1;
    ex2.displayDetails();
    return 0;
}