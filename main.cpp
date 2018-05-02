#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();

        int possible[n];
        vector<string>::iterator it;

        for(int i=0;i<n;i++){
            possible[i]=false;
            it=find(wordDict.begin(),wordDict.end(),s.substr(0,i+1));
            if(it!=wordDict.end()){
                possible[i]=true;
            }
            else{
                for(int j=0;j<i;j++){
                   // cout<<i<<"--"<<j<<endl;
                    if(!possible[j])
                        continue;

                   //cout<<i<<":"<<j<<endl;
                   it=find(wordDict.begin(),wordDict.end(),s.substr(j+1,i-j));
                   if(it!=wordDict.end()){
                            possible[i]=true;
                            break;
                    }

                }
            }

        }

       // for(int i=0;i<n;i++)
       //         cout<<"n:"<<possible[i]<<endl;

        return possible[n-1];
    }
};

int main(){
        vector<string> D;
        string s;
        s="applepenapple";

        D.push_back("apple");
        D.push_back("pen");

        vector<string>::iterator it;
        it=find(D.begin(),D.end(),s.substr(8,12));
        if(it!=D.end())
                cout<<"cunzai"<<endl;



        Solution thes;
        if(thes.wordBreak(s,D))
                cout<<1<<endl;
        else
                cout<<0<<endl;

        return 0;
}
