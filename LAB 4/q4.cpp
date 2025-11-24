#include <iostream>
using namespace std;

int main()
{
    int arr[]={2,0,14,43,25,18,1,5,45};
    int n=sizeof(arr) / sizeof(arr[0]);
    int count=0;

    cout<<"Input List:arr[] ";
    for(int i=0; i<n; i++){
        cout <<arr[i] << " ";
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        bool swapped =false;
        count++;
        for(int j=0; j<n-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if(!swapped){
            break;
        }
    }
    cout<<"Sorted Element List...";
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    cout << "Total number of passes taken: " << count << endl;

    return 0;
}