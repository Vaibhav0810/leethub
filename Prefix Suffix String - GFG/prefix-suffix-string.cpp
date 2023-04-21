//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        
        unordered_set<string> st1,st2;
        
        for(int i=0;i<s1.size();i++){
            int n=s1[i].size();
            string a="";
            for(int j=0;j<n;j++){
                a.push_back(s1[i][j]);
                st1.insert(a);
            }
        }
        
        for(int i=0;i<s1.size();i++){
            int n=s1[i].size();
            string a="";
            for(int j=n-1;j>=0;j--){
                a.push_back(s1[i][j]);
                string y=a;
                reverse(y.begin(),y.end());
                st2.insert(y);
            }
        }
        int c=0;
        for(int i=0;i<s2.size();i++){
            string x=s2[i];
            if(st1.find(x)!=st1.end() || st2.find(x)!=st2.end()){
                c++;
            }
        }
        return c;
    
        
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends