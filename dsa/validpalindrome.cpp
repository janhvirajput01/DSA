#include<iostream>
using namespace std;
int main(){
   
 string s = "A man, a plan, a canal: Panama";
     string s1="";
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])||isdigit(s[i]))
            s1+=char(tolower(s[i]));
    }
    
    string s2=s1;
    int l=0;
    int e=s2.size()-1;
    while(l<=e){
        swap(s2[l++],s2[e--]);
    }
    cout<<(s1==s2);
    return 0;
}