#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void generateSubsets(int start,int Num,int* arr,vector<int>& vect)
{
    int sum;
    for(int mask=0;mask<(1<<Num);mask++)
    {
        sum=0;
        for(int item=0;item<Num;item++)
            if(mask & (1<<item))
                sum+=arr[item+start];
        vect.push_back(sum);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int N,A,B,K;
    unsigned long long ans=0;
    vector<int> left,right;
    vector<int>::iterator low,high;
    int arr[50];
 
    cin>>N>>A>>B;
    for(int i=0;i<N;i++)
        cin>>arr[i];
     
    generateSubsets(0,N/2,arr,left);
    generateSubsets(N/2,N&1?N/2+1:N/2,arr,right);
    sort(right.begin(),right.end());
 
    for(int i=0;i<left.size();i++)
    {
        low=lower_bound(right.begin(),right.end(),A-left[i]);
        high=upper_bound(right.begin(),right.end(),B-left[i]);
        ans+=(high-right.begin())-(low-right.begin());
    }
    cout<<ans<<endl;
     
    return 0;
}