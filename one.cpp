#include<iostream>
using namespace std;
int main()
 {
     int p;
     cin>>p;
     while(p)
     {
    
    string s1,s2;
    cin>>s1>>s2;
    if(s1.length()==s2.length())
    {
    s1=s1+s1;
    if(s1.find(s2)<=s1.length())
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"0"<<endl;
    }
    }
    else
    {
        cout<<"0"<<endl;
    }
    p--;
}
}
