// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends

class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        string op;
       if (S.length() <=1)
       {
           return S;
       }
       
       for (int i=0;i<S.size();i++)
       {
           if (S[i] != S[i+1])
           {
               op.push_back(S[i]);
           }
       }  
     return op;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 



  // } Driver Code Ends