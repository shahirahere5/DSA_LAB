#include <iostream>
#include <string>
using namespace std;

class bookManagement{
    public:
    string name;
    int id;
    int experience;

    bookManagement(){}

    void setDetails(){
        cout << "enter details: " << endl;
        cout << "enter name: " ;
        cin >> name;
        cout << "enter id: ";
        cin >> id;
        cout << "enter years of experience: ";
        cin >> experience;
    }

    void showDetails(){
        cout << "details: " << endl;
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
        cout << "years of experience: " << experience << endl;
    }

};

class Library{
    private:
    static const int existingBookCount = 3;
    int existingBookId[existingBookCount] = {1,2,3};
    int* newBookId;
    int newBookCount;

    public:
    Library():newBookId(nullptr),newBookCount(0){}

    ~Library(){
        delete[] newBookId;
    }

    void showExistingBooks(){
        cout << "printing existing book IDs: " << endl;
        for(int i=0;i<existingBookCount;i++){
            cout << existingBookId[i] << endl;
        }
    }

    void addBook(){
        cout << "enter the num of books you want to add: ";
        cin >> newBookCount;

        newBookId = new int[newBookCount];

        cout << "enter the IDs of new books: " << endl;
        for(int i=0;i<newBookCount;i++){
            cin >> newBookId[i];
        }
    }

    void showNewBook(){
        for(int i=0;i<newBookCount;i++){
            cout << newBookId[i] << endl;
        }
    }
};

int main(){
    Library l1;
    l1.showExistingBooks();
    l1.addBook();
    l1.showNewBook();

    bookManagement b1;
    b1.setDetails();
    b1.showDetails();

    return 0;
}
