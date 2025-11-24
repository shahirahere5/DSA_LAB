#include <iostream>
#include <string>
using namespace std;

class Shop{
    private:
    string productName;
    int* quantities;
    int numBranches;

    public:
    Shop(string name,int branches){
        productName = name;
        numBranches = branches;
        quantities = new int[numBranches];
        for(int i=0 ; i<numBranches;i++){
            quantities[i] = 0;
        }
    }

    Shop(const Shop& other){
        productName = other.productName;
        numBranches = other.numBranches;
        quantities = new int[numBranches];
        for(int i=0;i<numBranches;i++){
            quantities[i] = other.quantities[i];
        }
    }

    Shop& operator=(const Shop& other){
        if(this == &other){
            return *this;
        }
        productName = other.productName;
        numBranches = other.numBranches;
        quantities = new int[other.numBranches];
        for(int i=0;i<numBranches;i++){
            quantities[i] = other.quantities[i];
        }
        return *this;
    }

    ~Shop(){
        delete[] quantities;
    }

    void setQuantity(int branchNum,int quantity){
        if(branchNum>=0 && branchNum < numBranches){
            quantities[branchNum] = quantity;
        }else{
            cout << "invalid branch number" << endl;
        }
    }

    void display(){
        cout << "product name: " << productName << endl;
        cout << "quantities in branches: " << endl;
        for(int i=0;i<numBranches;i++){
            cout << quantities[i] << " ";
        }
        cout << endl;
    }
};  

int main(){
    Shop s1("books",2);
    s1.setQuantity(0,5);
    s1.setQuantity(1,10);

    cout << "shop 1 details: " << endl;
    s1.display();

    Shop s2 = s1;
    cout << "shop 2 details: " << endl;
    s2.display();

    s2.setQuantity(1,30);
    cout << "updated shop details: " << endl;
    s1.display();
    s2.display();

    Shop s3("pens",2);
    s3.setQuantity(0,2);
    s3.setQuantity(1,3);
    s3.display();

    s3 = s1;
    s3.display();
    return 0;
}