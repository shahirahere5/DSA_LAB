#include <iostream>
#include <string>
using namespace std;

class FruitShopInventory{
    private:
    int** inventory;
    int fruits;
    int attributes;

    public:
    FruitShopInventory(int fruits,int initialQuantity,int initialPrice){
        this->fruits = fruits;
        attributes = 2;
        inventory = new int*[fruits];
        for(int i=0;i<fruits;i++){
            inventory[i]= new int[attributes];
            inventory[i][0] = initialQuantity;
            inventory[i][1] = initialPrice;
        }
    }

    FruitShopInventory(const FruitShopInventory& other){
        fruits = other.fruits;
        attributes = other.attributes;
        inventory = new int*[fruits];
        for(int i=0 ; i<fruits; i++){
            inventory[i] = new int[attributes];
            for(int j=0; j<attributes;j++){
                inventory[i][j] = other.inventory[i][j];
            }
        }
    }

    FruitShopInventory& operator=(const FruitShopInventory& other) {
        if (this == &other){
            return *this; 
        } 

        fruits = other.fruits;
        attributes = other.attributes;

        inventory = new int*[fruits];
        for (int i = 0; i < fruits; i++) {
            inventory[i] = new int[attributes];
            for (int j = 0; j < attributes; j++) {
                inventory[i][j] = other.inventory[i][j];
            }
        }
        return *this;
    }

    ~FruitShopInventory() {
        for (int i = 0; i < fruits; i++) {
            delete[] inventory[i];
        }
        delete[] inventory;
    }

    void setFruitDetails(int fruitIndex, int quantity, int price) {
        if (fruitIndex >= 0 && fruitIndex < fruits) {
            inventory[fruitIndex][0] = quantity;
            inventory[fruitIndex][1] = price;
        } else {
            cout << "Invalid fruit index!" << endl;
        }
    }

    void displayInventory() const {
        cout << "Fruit Inventory (Quantity | Price):\n";
        for (int i = 0; i < fruits; i++) {
            cout << "Fruit " << i << ": "
                 << inventory[i][0] << " | " << inventory[i][1] << endl;
        }
        cout << endl;
    }
};

int main(){
    FruitShopInventory shop1(3, 10, 50);

    cout << "shop1:\n";
    shop1.displayInventory();

    FruitShopInventory shop2 = shop1;

    shop1.setFruitDetails(1, 20, 70);

    cout << "Updated shop1:\n";
    shop1.displayInventory();

    cout << "shop2:\n";
    shop2.displayInventory();
    return 0;
}