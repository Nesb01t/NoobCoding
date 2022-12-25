#include<iostream>
#include<string>
using namespace std;

int getCount(char s[]){
    int n = 0;
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z') n++;
    return n;
}
int getCount(string &s){
    int n=0;
    for(int i=0;s[i]!='\0';i++)
        if(s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z') n++;
    return n;
}
int getCount(char s[],char c){
    int n=0;
    for(int i=0;s[i]!='\0';i++)
        if(s[i]==c)  n++;
    return n;
}
int getCount(string &s,char c){
    int n=0;
    for(int i=0;s[i]!='\0';i++)
        if(s[i]==c)  n++;
    return n;
}
void getCount(char s[],int c[]){
    int p;
    for(int i=0;i<26;i++)   c[i]=0;
    for(int i=0;s[i]!='\0';i++)
        if(s[i]>='a'&&s[i]<='z'){
            p=s[i]-'a';
            c[p]++;
        }
        else if(s[i]>='A'&&s[i]<='Z'){
            p=s[i]-'A';
            c[p]++;
        }
}
int main(){
    const int N=100;
    char s[N];
    string t;
    int c[26]={0};
    cin>>s;
    cout<<getCount(s)<<endl;
    cout<<getCount(s,'A')<<endl;
    cin>>t;
    cout<<getCount(t)<<endl;
    cout<<getCount(t,'A')<<endl;
    getCount(s,c);
    for(int i=0;i<26;i++)
        cout<<char('A'+i)<<":"<<c[i]<<endl;
    return 0;
}