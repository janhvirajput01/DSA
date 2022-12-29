#include<iostream>
using namespace std;
//Function to find the maximum occurring character in a string.
char getMaxOccuringChar(string str)
    {
        // Your code here
 
        int arr[26] ={0};
        for(int i =0;i<str.length();i++){
         char ch  = str[i];
         int number =0;
         
         number = ch-'a';
         arr[number]++;
         
        }

        int maxi = 0;
        for(int i=1;i<26;i++){
            if(arr[i]>arr[maxi]){
                  maxi = i;
                
            }
           
        }
      
        char ans = maxi+'a';
        return ans;
    }

int main(){
string s="testsample";
 
char ans = getMaxOccuringChar(s);
 cout<<"Maximum Ocuuring Character: "<<ans;  
}