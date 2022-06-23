#include<iostream>
#include<string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	
	while(t--) {
	    string s; cin >> s;
	    int l = s.length();
	    string tmp = "";
	    int p_len = tmp.length();
	    for(char i: s) {
	        if(i == s[0] || i == s[l-1]) {
	            if(tmp.length() > p_len)
	                p_len = tmp.length();
	            tmp = "";
	        }
	        else {
	            tmp += i;
	        }
	    }
	    if(p_len) cout << p_len << endl;
	    else cout << "-1" << endl;
	}
	
	return 0;
}
