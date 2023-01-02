//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            // vector<int> ans;
            // unordered_set<int> m1;
            // unordered_set<int> m2;
            // unordered_set<int> m3;
            // for(int i=0;i<n1;i++)   {m1.insert(A[i]);}
            // for(int i=0;i<n2;i++)   {m2.insert(B[i]);}
            // for(int i=0;i<n3;i++)   {m3.insert(C[i]);}
            // for(int i=0;i<n1;i++){
            //     if(m1.find(A[i])!=m1.end()&&m2.find(A[i])!=m2.end()&&m3.find(A[i])!=m3.end()){
            //         ans.push_back(A[i]);
            //         m1.erase(A[i]);
            //     }
            // }
            // return ans;
            
            // Method 2
            vector<int> ans;
            int i=0,j=0,k=0;
            while(i<n1&&j<n2&&k<n3){
                if(A[i]==B[j]&&B[j]==C[k]){
                    ans.push_back(A[i]);
                    i++;j++;k++;
                }
                else if(A[i]<B[j]){
                    i++;
                }else if(B[j]<C[k]){
                    j++;                   
                }else{
                    k++;
                }
                int a=A[i-1];
                while(a==A[i]){i++;}
                // int b=B[j-1];
                // while(b==B[j]){j++;}
                // int c=C[k-1];
                // while(c==C[i]){k++;}
            }
            if(ans.size()==0)   return {-1};
            else    return ans;
        }

};

//{ Driver Code Starts.

int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}
// } Driver Code Ends