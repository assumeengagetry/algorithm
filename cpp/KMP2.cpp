#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> nextbuild(const string &pattern)
{

    // ABCABCABCD

    int m = pattern.size();
    int j = 0;
    vector<int> next(m, 0);
    for(int i = 1 ; i< m ; i++){
        while(j > 0 && pattern[i] != pattern[j]){
            j = next[j - 1];
        }
        if(pattern[i] == pattern[j]){
            j++;
        }
        next[i] = j;
    }
    return next;
}


int KMP(const string &pattern, const string &text){
    int n = text.size(), m = pattern.size();
    vector<int> next = nextbuild(pattern);
    int j = 0;
    for(int i = 0; i < n ; i++){
        while(j > 0 && text[i] != pattern[j]){
            j = next[j -1];
        }
        if(text[i] == pattern[j]){
            j++;
        }
        if (j == m){
            return i - m + 2;
        }
        
    }
    return -1;
}

int main(){
    string text = "ABCDABCDABDE";
    string pattern = "ABCDABD";
    int pos = KMP(pattern, text);
    if(pos != -1){
        cout<<pos<<endl;
    }
    else{
        cout<<"未找到"<<endl;
    }
    return 0;

}