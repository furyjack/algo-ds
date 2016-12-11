#include <iostream>
#include <string>
using namespace std;

void process(bool ** arr,string&s1,string&s2,string&s3,int len1,int len2)
{

    arr[0][0]=1;
   for(int i=1;i<len2;i++)
   {
     if(s3[i-1]==s1[i-1] && arr[0][i-1])
     arr[0][i]=1;
     else
     arr[0][i]=0;


   }

    for(int i=1;i<len1;i++)
   {
     if(s1[i-1]==s2[i-1] && arr[i-1][0])
     arr[i][0]=1;
     else
     arr[i][0]=0;


   }

   for(int i=1;i<len1;i++)
   {
      for(int j=1;j<len2;j++)
      {

        if((s1[i+j-1]==s2[i-1]&&arr[i-1][j]) || (s1[i+j-1]==s3[j-1]&&arr[i][j-1]))
        arr[i][j]=1;
        else
        arr[i][j]=0;

      }
   }


}

int main()
{

    string s1="aaxabz",s2="aab",s3="axy";
    

    if(s1.size()!=s2.size()+s3.size())
    {
    cout<<"no";
    return 0;
    }
    int l1,l2,l3;
    l1=s1.size();
    l2=s2.size();
    l3=s3.size();

    bool **arr=new bool*[l2+1];
    for(int i=0;i<l2+1;i++)
    arr[i]=new bool[l3+1];

    process(arr,s1,s2,s3,l2+1,l3+1);

    cout<<arr[l2][l3];

	cin.get();

    return 0;
}

