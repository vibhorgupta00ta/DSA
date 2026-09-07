class Solution {
public:
    bool isValid(string s){
        if(s.size()==0 || s.size()>3) return false;
        if(s.size()>1 && s[0]=='0') return false;
        if(stoll(s)>255) return false;
        return true; 
    }
    vector<string>ans;
    void solve(string curr,int part,string remain){
        if(part==4){
            if(isValid(remain)){
                ans.push_back(curr+remain);
            }
            return;
        }
        string s;
        for(int i=0;i<remain.size();i++){
            s+=remain[i];
            if(isValid(s)){
                solve(curr+s+'.',part+1,remain.substr(i+1));
            }
            else break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        solve("",1,s);
        return ans;
    }
};