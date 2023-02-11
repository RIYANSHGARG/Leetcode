//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int Firstocc(int v[],int n ,int x){
    bool flag = 0;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == x)    flag=1;
        if (v[mid] >= x)    high=mid-1;
        else    low=mid+1;
    }
    return (flag == 1) ? low : -1;
}

int lastocc(int v[],int n ,int x){
    bool flag=0;
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == x)    flag = 1;
        if (v[mid] > x) high = mid - 1;
        else    low = mid + 1;
    }
    return (flag==1)?high:-1;
}

vector<int> find(int arr[], int n , int x )
{
    // basic approach
    // bool flag=false;
    // vector<int> ans(2,-1);
    // for(int i=0;i<n;i++){
    //     if(flag==false && arr[i]==x)    {flag=true;ans[0]=i;}
    //     if(arr[i]==x)   ans[1]=i;
    // }
    // return ans;
    
    // inbuilt function lower bound and upper bound
    
    // unsing binary approach
    
    vector<int> ans;
    ans.push_back(Firstocc(arr,n,x));
    ans.push_back(lastocc(arr,n,x));
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends