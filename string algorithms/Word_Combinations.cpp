#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

#define int long long


class TrieNode{
    public:
        char ch;
        TrieNode* children[26];
        bool isTerminal ;

        TrieNode(char data){
        ch = data;
        for(int i = 0; i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
        TrieNode* root;
    
        Trie(){
            root = new TrieNode('\0');
        }

        void insert(string s,TrieNode *root){
            TrieNode* temp = root;
            int idx;
            for(int i =0; i<s.size();i++){
                 idx = s[i]-'a';
                if(temp->children[idx] == NULL){
                    TrieNode* child = new TrieNode(s[i]);
                    temp->children[idx]=child;
                   
                }
                 temp = temp->children[idx];
                if(i==s.size()-1){
                    temp->isTerminal=true;
                }
            }
        }
        void build(string s){
            insert(s,this->root);
        }

        int search(string p, int starting_index,vector<int>&dp) {
        if (starting_index == p.size())  // ✅ base case
            return 1;
        if(dp[starting_index] != -1)return dp[starting_index];

        int sol = 0;
        TrieNode* temp = root;

        for (int i = starting_index; i < p.size(); i++) {
            int idx = p[i] - 'a';
            if (temp->children[idx] == NULL) break; // ✅ no further path
            temp = temp->children[idx];

            // ✅ when a valid word ends, recursively continue
            if (temp->isTerminal) {
                sol =( sol+ search(p, i + 1,dp))%mod;
            }
        }
        return dp[starting_index]=(sol%mod);
    }

};

signed main(){
    string major;
    cin>>major;
    int n;
    cin>>n;
    Trie* t = new Trie();

    for(int i = 0; i<n;i++){
        string minor;
        cin>>minor;
        t->build(minor);
    }
    vector<int>dp(major.size()+1,-1);
    
    cout<<t->search(major,0,dp)<<endl;
}