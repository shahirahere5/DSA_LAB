#include <iostream>
#include <string>
using namespace std;

class bankAccount{
    private:
    double balance;

    public:
    bankAccount():balance(0.0){}

    bankAccount(double balance):balance(balance){}

    bankAccount(const bankAccount& other){
        balance = other.balance;
    }

    void deposit(double amount){
        balance += amount;
    }

    void withdraw(double amount){
        if(amount <= balance){
            balance -= amount;
        }else{
            cout << "insufficient balance" << endl;
        }
    }

    double getBalance(){
        return balance;
    }
};

int main(){
    bankAccount b1;
    cout << b1.getBalance() << endl;

    bankAccount b2(1000.0);
    cout << b2.getBalance() << endl;

    bankAccount b3(b2);
    b3.withdraw(200.0);
    cout << b3.getBalance() << endl;
    cout << b2.getBalance() << endl;

    return 0;
}