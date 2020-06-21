/*���ܣ�
����һ���ַ���S��һ���ַ���T������S�е�T�Ĳ�ͬ�����еĸ�����
�ַ���������������ԭ�����ַ���ɾ��һЩ�ַ���Ҳ���Բ�ɾ�����ڲ��ı����λ�õ�����µ�ʣ���ַ������磬"ACE"is a subsequence of"ABCDE"����"AEC"���ǣ�
���磺
S ="rabbbit", T ="rabbit"
����3
*/
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int numDistinct_1(string S, string T) {
        map<int,int> dp;
        for(int j=0;j<S.size();j++)
            for(int i=T.size()-1;i>=0;i--)
            if(T[i]==S[j]){
               if(i!=0) dp[i]+=dp[i-1];
               else dp[0]++;
            }
        return dp[T.size()-1];
    }
int numDistinct(string S, string T)
{
    int sl=S.size();
    int tl=T.size();
    if(sl==0||tl==0||sl<tl)
    {
        return 0;
    }
    //int *dp=new int [tl+1];
    vector<int> dp(tl+1);
    dp[0]=1;
    for(int i=1;i<sl+1;++i)
    {
        for(int j=min(i,tl);j>0;j--)
        {
            if(S[i-1]==T[j-1])
            {
                dp[j]+=dp[j-1];
            }
        }
    }
    return dp[tl];
}

int main()
{
    
    return 0;
}
