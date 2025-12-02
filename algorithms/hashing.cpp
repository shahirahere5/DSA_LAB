#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;

class Node
{
public:
    string key;
    string value;
    Node *next;
};
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = NULL;
        }
    }
    int hashFunction(string key)
    {
        int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            sum += key[i];
        }
        return sum % SIZE;
    }
    void insert(string key, string value)
    {
        int index = hashFunction(key);
        Node *n = new Node;
        n->key = key;
        n->value = value;
        n->next = NULL;
        if (table[index] == NULL)
        {
            table[index] = n;
        }
        else
        {
            Node *temp = table[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
        }
    }
    void display()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ": ";
            Node *temp = table[i];
            while (temp != NULL)
            {
                cout << "(" << temp->key << ", " << temp->value << ") -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
            cout << endl;
        }
    }
};
int main()
{
    HashTable myhash;

    myhash.insert("A", "aaaaa");
    myhash.insert("B", "bbbbb");
    myhash.insert("C", "ccccc");
    myhash.insert("A", "zzzzz");

    myhash.display();

    return 0;
}



//using list library
#include <iostream>
#include <list>
using namespace std;

const int SIZE=10;

class HashTable{
    private:
    list<int>* table;
    public:
    HashTable(){
    table=new list<int>[SIZE];
    }
    int hashFunction(int key){
        return key%SIZE;
    }
    void insert(int key){
        int index=hashFunction(key);
        table[index].push_back(key);
        cout<<key<<" inserted.\n";
    }
    void remove(int key){
        int index=hashFunction(key);
        bool found=false;
        for(int value:table[index]){
            if(value==key){
                found=true;
                break;
            }
        }
        if(found){
            table[index].remove(key);
            cout<<key<<" deleted\n";
        }
        else{
            cout<<key<<" not found\n";
        }
    }
    bool search(int key){
        int index=hashFunction(key);
        for(int value:table[index]){
            if(value==key){
                cout<<key<<" found\n";
                return true;
            }
        }
        cout<<key<<" not found\n";
        return false;
    }
    void display(){
        for (int i = 0; i < SIZE; i++)
        {
            cout<<"Index "<<i<<": ";
            for(int value:table[i]){
                cout<<value<<" -> ";
            }
            cout<<"NULL"<<endl;
        }
    }
    ~HashTable(){
        delete[] table;
    }
};

int main(){
    HashTable h;

    h.insert(12);
    h.insert(22);
    h.insert(13);

    h.display();

    h.search(14);
    h.remove(13);
    h.display();

    return 0;
}


//basic hash table with insert, remove, search using array
#include <iostream>
using namespace std;

const int SIZE = 10;

class HashTable
{
private:
    int table[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            table[i] = -1;
        }
    }
    int hashFunction(int key)
    {
        return key%SIZE;
    }
    void insert(int key)
    {
        int index = hashFunction(key);
        for(int i=0; i<SIZE; i++){
            int newindex=(index+i)%SIZE;
            if(table[newindex]==-1){
                table[newindex]=key;
                cout<<key<<" Inserted\n";
                return;
            }
        }
        cout<<"Hash Table is full. ReHash now!\n";
    }
    void remove(int key){
        int index=hashFunction(key);
        for(int i=0; i<SIZE; i++){
            int newindex=(index+i)%SIZE;
            if(table[newindex]==key){
                table[newindex]=-1;
                cout<<key<<" removed\n";
                return;
            }
        }
        cout<<key<<" not found\n";
    }
    bool search(int key){
        int index=hashFunction(key);
        for(int i=0; i<SIZE; i++){
            int newindex=(index+i)%SIZE;
            if(table[newindex]==key){
                cout<<key<<" found\n";
                return true;
            }
        }
        cout<<key<<" not found\n";
        return false;
    }
    void display()
    {
        cout<<"HashTable\n";
        for (int i = 0; i < SIZE; i++)
        {
            cout <<"Index "<< i << ": ";
            if(table[i]==-1){
                cout<<"EMPTY";
            }
            else{
                cout<<table[i];
            }
            cout << endl;
        }
    }
};
int main()
{
    HashTable h;

    h.insert(12);
    h.insert(22);
    h.insert(32);
    h.insert(5);

    h.display();

    h.search(22);
    h.remove(22);

    h.display();

    return 0;
}
