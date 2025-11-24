#include <iostream>
using namespace std;

int main() {
    int n;

    cout<<"Enter number of bottles: ";
    cin>>n;
    
    int arr[n];
    cout<<"Enter the fill levels: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for(int gap=n/2; gap>0; gap/=2){
        for(int j=gap; j<n; j++){
            int temp=arr[j];
            int res=j;
            while(res>=gap&& arr[res-gap]>temp){
                arr[res]=arr[res-gap];
                res-=gap;
            }
            arr[res]=temp;
        }
    }
    cout << "Sorted shipping time: ";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}