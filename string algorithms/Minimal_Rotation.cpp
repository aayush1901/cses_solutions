#include <bits/stdc++.h>
using namespace std;

// Duval's Lyndon Factorization
vector<pair<int,string>> duval(const string &s) {
    int n = s.size();

    vector<pair<int,string>> starts; // start index of each factor

    int i = 0;
    while (i < n) {
        int j = i + 1;
        int k = i;

        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j]) 
                k = i;
            else 
                k++;
            j++;
        }

        int length = j - k;

        while (i <= k) {
            starts.push_back({i,s.substr(i,length)});
            i += length;
        }
    }
    return starts;
}

// Smallest rotation
pair<int,string> smallest_rotation(string s) {
    string t = s + s;
    int n = s.size();

    // Get Lyndon factors START indices
    vector<pair<int,string>> fac_starts = duval(t);

    // Find smallest starting prefix
    pair<int,string> best = fac_starts[0];
    for (auto st : fac_starts  ) {
        if(st.first >= n){
            break;
        }
        if (st.second < best.second) {
            best = st;
        }
    }

    // Return actual rotation of original length
    return best;
}
int main() {
    string s ;
    cin>>s;
    string t = s+s;
    pair<int,string>p = smallest_rotation(s);
    for(int i = p.first ; i<p.first+s.size();i++){
        cout<<t[i];
    }cout<<endl;

}

// if you want to study the lyndon factors and duval algorithm study it on cp-algorithm website.
