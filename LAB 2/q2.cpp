#include <iostream>
#include <string>
using namespace std;

class ProductStockManager{
    int* stock;
    int products;

    public:
    ProductStockManager(int n,int initialStock){
        products = n;
        stock = new int[products];
        for(int i=0;i<products;i++){
            stock[i] = initialStock;
        }
    }

    ProductStockManager(const ProductStockManager& other){
        products = other.products;
        stock = new int[products];
        for(int i=0;i<products;i++){
            stock[i] = other.stock[i];
        }
    }

    ProductStockManager& operator=(const ProductStockManager& other){
        if(this == &other){
            return *this;
        }
        products = other.products;
        stock = new int[products];
        for(int i=0;i<products;i++){
            stock[i] = other.stock[i];
        }
        return *this;
    }

    ProductStockManager(){
        delete[] stock;
    }

    void setStock(int index,int stk){
        if(index>=0 && index< products){
            stock[index] = stk;
        }else{
            cout << "invalid stock address" << endl;
        }
    }

    int getStock(int index){
        if(index>=0 && index< products){
           return stock[index];
        }else{
            cout << "invalid stock address" << endl;
            return -1;
        }
    }

    void display(){
        for(int i=0;i<products;i++){
            cout << stock[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    ProductStockManager p1(3,100);
    p1.display();
    cout << endl;
    ProductStockManager p2 = p1;
    p2.display();
    cout << endl;
    p2.setStock(1,150);
    cout << endl;
    p1.display();
    cout << endl;
    p2.display();
    return 0;
}