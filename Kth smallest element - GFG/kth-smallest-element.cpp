//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
// arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
class Solution{
    public:
    
    int getpivotpoint(int arr[],int l,int r){
        int pivotelement=arr[r];
        int pivotpoint=l;
        
        for(int i=l;i<=r;i++){
            if(arr[i]<pivotelement){
                swap(arr[i],arr[pivotpoint]);
                pivotpoint++;
            }
        }
        swap(arr[pivotpoint],arr[r]);
        return pivotpoint;
    }
    
    
    int kthelement(int arr[],int l,int r,int k){
        int pivotpoint = getpivotpoint(arr,l,r);
        if(pivotpoint==k-1) return arr[pivotpoint];
        else if(pivotpoint<k-1)    kthelement(arr,pivotpoint+1,r,k);
        else    kthelement(arr,l,pivotpoint-1,k);
    }
    
    int kthSmallest(int arr[], int l, int r, int k) {
        
        // Method 1 : simple sorting and traversing till k
    
    //     int i=0;
    //     sort(arr,arr+r+1);
    //     while(k!=1){
    //         i++;k--;
    //     }
    //     return arr[i];
    
    // Method 2 : using heap
    // priority_queue<int> max_heap;
    // for(int i=0;i<r+1;i++){
    //     max_heap.push(arr[i]);
    //     if(max_heap.size()>k)   max_heap.pop();
    // }
    // return max_heap.top();
    
    // Method 3 : Quickselect
        return kthelement(arr,l,r,k);
    
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends