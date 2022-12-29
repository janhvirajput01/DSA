#include<iostream>
#include<string.h>
using namespace std;
int main(){
  string str ="Welcome You all";
   for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
        
           str = str.substr(0,i)+"@40"+str.substr(i+1,str.length()-1); 
		        
        }
    }
    	cout<<str;
}