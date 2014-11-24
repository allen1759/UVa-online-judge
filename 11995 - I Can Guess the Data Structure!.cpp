//#define CODE1
//#define CODE2
#define CODE3

#ifdef CODE1
#include <stdio.h>

bool st(int [][1000], int);
bool qu(int [][1000], int);
bool pq(int [][1000], int);

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        int cnt=0;
        bool bst=false;
        bool bqu=false;
        bool bpq=false;
        int arr[100];
        int a[2][1000];
        for(int i=0; i<n; i++)
        {
            scanf("%d%d", &a[0][i], &a[1][i]);
        }
        if(st(a, n))
        {
            bst=true;
            cnt++;
        }
        if(qu(a, n))
        {
            bqu=true;
            cnt++;
        }
        if(pq(a, n))
        {
            bpq=true;
            cnt++;
        }
        if(cnt==0)
            printf("impossible\n");
        else if(cnt==1)
        {
            if(bst)
                printf("stack\n");
            else if(bqu)
                printf("queue\n");
            else if(bpq)
                printf("priority queue\n");
        }
        else if(cnt>1)
            printf("not sure\n");
    }
    return 0;
}

bool st(int a[][1000], int n)
{
    int arr[100];
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(a[0][i]==1 && cnt<100)
        {
            arr[cnt]=a[1][i];
            cnt++;
        }
        else if(a[0][i]==1)
        {
            return false;
        }
        else if(a[0][i]==2 && cnt>0 && a[1][i]==arr[cnt-1])
        {
            cnt--;
        }
        else if(a[0][i]==2)
        {
            return false;
        }
    }
    return true;
}

bool qu(int a[][1000], int n)
{
    int arr[100];
    int sta=0;
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        if(a[0][i]==1 && cnt<100)
        {
            arr[sta+cnt]=a[1][i];
            cnt++;
        }
        else if(a[0][i]==1)
        {
            return false;
        }
        else if(a[0][i]==2 && a[1][i]==arr[sta] && cnt>0)
        {
            sta++;
            cnt--;
        }
        else if(a[0][i]==2)
        {
            return false;
        }
    }
    return true;
}

bool pq(int a[][1000], int n)
{
    int arr[100];
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        int maxi=0;
        for(int j=0; j<cnt; j++)
        {
            if(arr[maxi]<arr[j])
            {
                maxi=j;
            }
        }
        if(a[0][i]==1 && cnt<100)
        {
            arr[cnt]=a[1][i];
            cnt++;
        }
        else if(a[0][i]==1)
        {
            return false;
        }
        else if(a[0][i]==2 && cnt>0 && a[1][i]==arr[maxi])
        {
            for(int j=maxi; j+1<cnt; j++)
            {
                arr[j]=arr[j+1];
            }
            cnt--;
        }
        else if(a[0][i]==2)
        {
            return false;
        }
    }
    return true;
}

#endif // CODE1


//  this code was accepted on 2014/09/23
#ifdef CODE2

#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{

    int n;
    while(cin >> n){
        int q=1, s=1, p=1, op, ele;
        stack<int> sta;
        queue<int> que;
        vector<int> arr;
        for(int i=0; i<n; i++){
            cin >> op >> ele;
            if(op==1){
                sta.push(ele);
                que.push(ele);
                arr.push_back(ele);
            }
            else if(op==2){
                if(sta.empty()) s=0;
                if(que.empty()) q=0;
                if(arr.empty()) p=0;
                if(!sta.empty()){
                    if(sta.top()!=ele) s=0;
                    sta.pop();
                }
                if(!que.empty()){
                    if(que.front()!=ele) q=0;
                    que.pop();
                }
                sort(arr.begin(), arr.end());
                if(!arr.empty()){
                    if(arr[arr.size()-1]!=ele) p=0;
                    arr.pop_back();
                }
            }
        }
        if(s+q+p > 1) cout << "not sure" << endl;
        else if(s+q+p == 0) cout << "impossible" << endl;
        else if(s) cout << "stack" << endl;
        else if(q) cout << "queue" << endl;
        else if(p) cout << "priority queue" << endl;
    }

    return 0;
}

#endif // CODE 2


#ifdef CODE3

#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
using namespace std;

int main()
{

    int n;
    while(cin >> n){
        int q=1, s=1, p=1, op, ele;
        stack<int> sta;
        queue<int> que;
        priority_queue<int> prq;
        for(int i=0; i<n; i++){
            cin >> op >> ele;
            if(op==1){
                sta.push(ele);
                que.push(ele);
                prq.push(ele);
            }
            else if(op==2){
                if(sta.empty() || sta.top()!=ele) s=0;
                else sta.pop();
                if(que.empty() || que.front()!=ele) q=0;
                else que.pop();
                if(prq.empty() || prq.top()!=ele) p=0;
                else prq.pop();
            }
        }
        if(s+q+p > 1) cout << "not sure" << endl;
        else if(s+q+p == 0) cout << "impossible" << endl;
        else if(s) cout << "stack" << endl;
        else if(q) cout << "queue" << endl;
        else if(p) cout << "priority queue" << endl;
    }

    return 0;
}


#endif // CODE3
