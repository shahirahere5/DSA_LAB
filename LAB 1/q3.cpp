#include <iostream>
#include <string>
using namespace std;

class Box{
    private:
    int* number;

    public:
    Box(int n=0){
        number = new int(n);
    }

    Box(const Box& other){
        number = new int(*other.number);
    }

    Box& operator=(const Box& other){
        if(this == &other){
            return *this;
        }

        number = new int(*other.number);
        return *this;
    }

    void setNum(int num){
        *number = num;
    }

    int getNum(){
        return *number;
    }

    ~Box(){
        delete number;
    }
};

int main(){
    cout << "shallow copy" << endl;
    Box b1(10);
    Box b2 = b1;
    b2.setNum(20);

    cout << b1.getNum() << endl;
    cout << b2.getNum() << endl;

    cout << "deep copy" << endl;
    Box b3(30);
    Box b4;
    b4 = b3;
    b4.setNum(40);

    cout << b3.getNum() << endl;
    cout << b4.getNum() << endl;
    return 0;
}