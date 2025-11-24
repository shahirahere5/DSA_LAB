#include <iostream>
using namespace std;

int main() {
    int n;

    cout<<"Enter number of crates: ";
    cin>>n;
    
    int shipping[n];
    cout<<"Enter the shipping time: ";
    for (int i = 0; i < n; i++)
    {
        cin>>shipping[i];
    }
    
    for(int i=0; i<n-1;i++){
        int min_index=i;
        for(int j=i+1; j<n;j++){
            if(shipping[j]<shipping[min_index]){
                min_index=j;
            }
        }
        int temp=shipping[i];
        shipping[i]=shipping[min_index];
        shipping[min_index]=temp;
    }
    cout<<"Sorted shipping time: ";
    for(int i=0; i<n; i++){
        cout<<shipping[i]<<" ";
    }
    cout<<endl;
    return 0;
}