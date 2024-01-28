// Mehtod 1 : making all subarrays
// int ans=0;
// for(int i=0;i<nums.size();i++){
//     int sum=0;
//     for(int j=i;j<nums.size();j++){
//         sum+=nums[j];
//         if(sum==k)  ans++;
//     }
// }
// return ans;
// method 2 : using sorting
sort(nums.begin(),nums.end());
int i=0,j=0,ans=0,sum=0;
while(j<nums.size()){
sum+=nums[j];
if(sum==k){
ans++;
sum-=nums[i];
i++;
}
else if(sum<k)   j++;
else{
sum-=nums[i];
i++;
}
}