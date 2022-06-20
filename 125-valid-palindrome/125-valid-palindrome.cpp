class Solution {
public:
    string singleWord(string str){
        string _str;
        for(int i=0;i<str.length();i++){
            if(str[i]>='a' && str[i]<='z' || str[i]>='A' && str[i]<='Z' || str[i]>='0' &&str[i]<='9'){
                _str+=str[i];
            }
        }
        transform(_str.begin(), _str.end(), _str.begin(), ::tolower);
        cout<<_str<<endl;
        return _str;
    }
    bool isPalindrome(string str){
        string _str = singleWord(str);
        if(str.length()==0 || str.length()==1)
            return true;
        
        int i=0, j=_str.length()-1;

        while(i<=j){
            if(_str[i]!=_str[j]) return false;

            i++; j--;
        }
        return true;
    }
};