#include <iostream>
#include <string>
using namespace std;
#include "C.h";

int keys[]={3,1,4,0,2};

int main(){

cout<<"Please enter message\r\n>";
string mess=GetStr();
int len = GetLen(mess);
if(len%2!=0){
    mess+='a';
    len++;
}
string p2;
string p1;
for(int i  = 0;i<len;i++){
    if(i+1<=len/2){
        p2+=mess[i];
    }else{p1+=mess[i];}
}
string encr;
for(int i = 0;i<5;i++){
    int ind = keys[i];
    encr+=p1[ind];
    encr+=p2[ind];
}
cout<<"\r\nYour encrypted message is :\r\n";
cout<<encr<<endl;
len = GetLen(encr);
char ch[len/2][2]={0};
int ind = 0;
for(int i = 0;i<len;i+=2){
    ch[ind][0]=encr[i];
    ch[ind][1]=encr[i+1];
    ind++;
}
string decr;
char ch1[len/2][2]={0};
for(int i = 0;i<5;i++){
    int ind = keys[i];
    ch1[i][0]=ch[ind][0];
    ch1[i][1]=ch[ind][1];
}
string s1;
string s2;
for(int i  = 0;i<len;i++){
    if(i+1<=len/2){
        s2+=mess[i];
    }else{s1+=mess[i];}
}
cout<<"Your decrypted message is: \r\n";
cout<<s2;
cout<<s1;
return 0;
}
