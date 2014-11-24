#define CODE2
#ifdef CODE1

#include <stdio.h>

int checkA(int [], int, int);
int main()
{
    int N=1, n=1;
    int stk[1000]= {0};
    int sc=0;
    int A[1000]= {0};
    int Ac=0;
    int B[1000]= {0};

    while(1)
    {
        n=N;
        scanf("%d", &N);
        if(N==0 && n==0)
            break;
        bool out=false;
        while(N!=0)
        {
            bool flag=true;
            out=false;
            sc=0;
            Ac=N;
            for(int i=0; i<N; i++)
            {
                A[i]=N-i;
            }
            for(int i=0; i<N; i++)
            {
                scanf("%d", &B[i]);
                if(B[0]==0)
                {
                    out=true;
                    break;
                }
            }
            if(out)
            {
                n=N;
                N=0;
                printf("\n");
                break;
            }
            for(int i=0; i<N; i++)
            {
                if(B[i]==stk[sc-1])
                {
                    sc--;
                    continue;
                }
                else if(B[i]==A[Ac-1])
                {
                    Ac--;
                    continue;
                }
                else if(checkA(A, B[i], Ac)!=-1)
                {
                    int p=checkA(A, B[i], Ac);
                    for(int j=Ac-1; j>p; j--)
                    {
                        stk[sc]=A[j];
                        sc++;
                    }
                    Ac=p;
                    continue;
                }
                else
                {
                    flag=false;
                    break;
                }
            }
            flag? printf("Yes\n") :printf("No\n");
        }
    }
    return 0;
}

int checkA(int A[], int cur, int x)
{
    for(int i=0; i<x; i++)
    {
        if(cur==A[i])
            return i;
    }
    return -1;
}

#endif // CODE1

#ifdef CODE2
//----------this code 2 ACed on 20140929------------
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    int n;
    while(cin >> n && n!=0){
        getchar();
        queue<int> init, qu;
        stack<int> st;
        for(int i=0; i<n; i++) init.push(i+1);
        string str;
        while(getline(cin, str) && str!="0"){
            stringstream ss;
            qu = init;
            while(!st.empty()) st.pop();
            int current;
            bool fail=false;
            ss << str;
            for(int i=0; i<n; i++){
                ss >> current;
                if(!st.empty() && st.top()==current){
                    st.pop();
                    continue;
                }
                bool check = false;
                while(!qu.empty() && qu.front()!=current){
                    st.push(qu.front());
                    qu.pop();
                }
                if(qu.empty()){
                    fail = true;
                    break;
                }
                else{
                    qu.pop();
                }
            }
            if(fail) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
        cout << endl;
    }
    return 0;
}

#endif // CODE2
