class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        // if(k==1)    return max(arr[0],arr[1]);
        // map<int,long long> m;
        // for(int i=0;i<arr.size();i++)   m[arr[i]]=0;
        // while(true){
        //     vector<int>::iterator it;
        //     if( (arr[0]==*max_element(arr.begin(),arr.end())) || (arr[1]==*max_element(arr.begin(),arr.end())))  return *max_element(arr.begin(),arr.end());
        //     if(arr[0]>arr[1]){
        //         m[arr[0]]++;
        //         arr.push_back(arr[1]);
        //         it=arr.begin()+1;
        //         arr.erase(it);
        //         if(m[arr[0]] == k)  return arr[0];
        //     }else{
        //         m[arr[1]]++;
        //         arr.push_back(arr[0]);
        //         arr.erase(arr.begin());
        //         if(m[arr[1]] == k)  return arr[1];
        //     }
        // }
        // return 0;
        
        
        int win=0,winner=arr[0];
        for(int i=1;i<arr.size();i++){
            if(winner > arr[i]){
                win++;
            }else{
                win=1;
                winner=arr[i];
            }
            cout<<winner<<" ";
            if(win == k)    break;
        }
        return winner;
    }
};