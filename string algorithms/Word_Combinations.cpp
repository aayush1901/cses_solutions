#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007


// int solverec(string s, vector<string>&v,string last,int index){
//     //base case
//     if(index ==0){
//         if(binary_search(v.begin(),v.end(),last)){
//             return 1;
//         }else{
//             return 0;
//         }
//     }
//     // recursive case
//     int ans = 0;
//     if(binary_search(v.begin(),v.end(),last)){
        
//         string temp = ""; temp.append(1,s[index-1]);
//         ans = ans + solverec(s,v,temp,index-1);
//     }
//     last = s[index-1]+last;
//     ans += solverec(s,v,last,index-1);

//     return ans; 
// }

// int solveMem(string s,unordered_set<string>&v,string last,int index,map<pair<int,string>,int>&dp,int maxLength){

//      if(index ==0){
//         if(v.find(last) != v.end()){
//             return 1;
//         }else{
//             return 0;
//         }
//     }
//     if(last.size()>maxLength)return 0;
//     pair<int,string>p = make_pair(index,last);
//     if(dp.find(p) != dp.end())return dp[p];
//     // recursive case
//     int ans = 0;
//     if(v.find(last) != v.end()){
        
//         string temp = ""; temp.append(1,s[index-1]);
//         ans = (ans + solveMem(s,v,temp,index-1,dp,maxLength))%mod;
//     }
    
//     last = s[index-1]+last;
//     ans =( ans+ solveMem(s,v,last,index-1,dp,maxLength))%mod;

//      dp[p]=ans%mod; 
//      return dp[p];

// }


// int main(){
//     string s;
//     cin>>s;
//     int k;
//     cin>>k;
//     vector<string>v(k);
//     unordered_set<string>u;
//     int maxlenght= 0;
//     for(int  i = 0; i<k;i++){
//         cin>>v[i];
//         u.insert(v[i]);
//         if(v[i].size()>maxlenght)maxlenght = v[i].size();
//     }
//     sort(v.begin(),v.end());

//     string last ="";last.append(1,s[s.size()-1]);
//     map<pair<int,string>,int>dp;
//     int m = solveMem(s,u,last,s.size()-1,dp,maxlenght);
//     cout<<m<<endl;

// }

//in all the above problem we didnt get pass through time limit so we are going to use data structure known as tri;

class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i = 0; i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root,string word){
            if(word.length()==0){
                root->isTerminal=true;
                return;
            }

            int index = word[0]-'a';
            TrieNode* child;

            if(root->children[index] != NULL){
            child = root->children[index];
            }else{
                child = new TrieNode(word[0]);
                root->children[index]=child;
            }
            insertUtil(child,word.substr(1));
        }

        void insertWord(string word){
            insertUtil(root,word);
        }

        bool searchUtil(TrieNode* root,string word){
            //base case
            if(word.length()==0){
                return root->isTerminal;
            }
            int index = word[0]-'a';
            TrieNode *child;

            //present
            if(root->children[index] != NULL){
                child = root->children[index];
            }else{
                return false;
            }
            return searchUtil(child,word.substr(1));
        }

        bool searchWord(string word){
            return searchUtil(root,word);
        }

        int waysUtil(string s, TrieNode* root){
            vector<int>dp(s.size()+1,0);
        
        dp[s.size()]=1;

        for(int i = s.size()-1;i>=0;i--){
            TrieNode* child = root;
            for(int j = i;j<s.size();j++){
                int index = s[j]-'a';                
                if(child->children[index] != NULL){
                    if(child->children[index]->isTerminal){
                        dp[i]= (dp[i]+dp[j+1])%mod;
                    }

                    child = child->children[index];

                }else{
                    break;
                }
            }
        }
        return dp[0];

        }

        int waystoconstruct(string s){
            return waysUtil(s,root);
        }

    };

    int solveRec(Trie* t,string s,int n,string temp){
        //base case
            if(n==0){
                if(t->searchWord(temp))return 1;
                else return 0;

            }
        //recursive case
        int ans = 0;

        if(t->searchWord(temp)){
            string tempo = "";tempo.append(1,s[n-1]);
            ans = (ans + solveRec(t,s,n-1,tempo))%mod;

        }
        temp = s[n-1]+temp;
        ans = (ans + solveRec(t,s,n-1,temp))%mod;

        return (ans)%mod;

    }

unordered_map<string, int> dp;

int solveMem(Trie* t, string s, int n, string temp, unordered_map<string, int>& dp) {
    if (n == 0) {
        if (t->searchWord(temp)) return 1;
        return 0;
    }

    string key = to_string(n) + "|" + temp;
    if (dp.count(key)) return dp[key];

    int ans = 0;

    if (t->searchWord(temp)) {
        string tempo = "";
        tempo.append(1, s[n - 1]);
        ans = (ans + solveMem(t, s, n - 1, tempo, dp)) % mod;
    }

    temp = s[n - 1] + temp;
    ans = (ans + solveMem(t, s, n - 1, temp, dp)) % mod;

    dp[key] = ans;
    return ans;
}

int solveTab(Trie*t, string s,int maxLength){
    vector<int>dp(s.size()+1,0);dp[0]=1;

    for(int i = 1; i<=s.size();i++){
        for(int len = 1;len <= maxLength && i - len>=0;len++){
            string sub = s.substr(i-len,len);
            if(t->searchWord(sub)){
                dp[i]= (dp[i-len]+dp[i])%mod;
            }
        }
    }
    return dp[s.size()];
}




    signed main(){
        string s;
        cin>>s;
        int n;
        cin>>n;
        Trie* t = new Trie();

        int maxwordLen=0;

        for(int i = 0; i<n;i++){
            string jethalal;
            cin>>jethalal;
            if(jethalal.length()>maxwordLen)maxwordLen= jethalal.length();
            t->insertWord(jethalal);
        }
        string temp= "";temp.append(1,s[s.size()-1]);

        // int m = solveRec(t,s,s.size()-1,temp);---recursive exponential time
        // cout<<m<<endl;
        
        //int m = solveMem(t,s,s.size()-1,temp,dp);--memoization but will not work due to memory stack 
        // int m = solveTab(t,s,maxwordLen);
        // cout<<m<<endl;
        //what i learnt after so many incorrect attemps is that rechecking the tri everytime will cause error as it is also o(lengthofword to be searched)
        //so now i introduced a funciton withing trie to solve this.

        int m= t->waystoconstruct(s);
        cout<<m<<endl;

    }
//yeh question hee trie ka tha ... due to misjudgement of the question that it might be a dp question it took me around 6-7 hours :( but got a solid learning that how can we decrease time by defining a function within the trie class itself.
//none of the approaches previously used were wrong but had time complesity of O(n*k*k) -- and worst case k was around 10^6 so that was not possible at all...
