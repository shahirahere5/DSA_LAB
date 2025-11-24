#include <iostream>
#include <string>
using namespace std;

int main(){
    int students = 5;
    int *numOfCourses = new int[students];
    int **marks = new int*[students];
    int *studentIDs = new int[students];

    for(int i=0;i<students;i++){
        cout << "enter student " << i+1 << "ID: ";
        cin >> studentIDs[i];

        cout << "enter number of courses for student " << studentIDs[i] << ":";
        cin >> numOfCourses[i];

        marks[i] = new int[numOfCourses[i]];

        cout << "enter marks for " << numOfCourses[i] << " courses: ";
        for(int j=0;j<numOfCourses[i];j++){
            cin >> marks[i][j];
        }
    }

    cout << "student data: " << endl;
    for(int i=0;i<students;i++){
        cout << "student ID: " << studentIDs[i] << endl;
        cout << "courses: " << numOfCourses[i] << endl;
        cout << "marks: ";
        for(int j=0;j<numOfCourses[i];j++){
            cout << marks[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0;i<students;i++){
        delete[] marks[i];
    }
    delete[] marks;
    delete[] numOfCourses;
    delete[] studentIDs;

    return 0;
}