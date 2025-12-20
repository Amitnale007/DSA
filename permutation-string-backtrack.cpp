// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


void permute(string &str,int index)
{
    if(index==str.length())
    {
        cout<<str<<endl;
        return;
    }
    
    for(int i=index;i<str.length();i++)
    {
        swap(str[index],str[i]);
        permute(str,index+1);
        swap(str[index],str[i]);
    }
}
int main() {
    // Write C++ code here
    string str="ABC";
    permute(str,0);

    return 0;
}
