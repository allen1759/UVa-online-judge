#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class CPoint
{
public:
    double x_, y_;
};
class CEdge
{
public:
    int point[2];
    double length;
    bool operator < (const CEdge& rhs) const
    {
        return length<rhs.length;
    }
};
int findHead(vector<int>& arr, int n)
{
    int ptr = n;
    while(arr[ptr]!=ptr){
        ptr = arr[ptr];
    }
    return ptr;
}
int main()
{
    int testCase;
    cin >> testCase;
    for(int test=0; test<testCase; test++){
        int n;
        cin >> n;
        vector<CPoint> points(n);
        vector<CEdge> edges;
        for(int i=0; i<n; i++){
            cin >> points[i].x_ >> points[i].y_;
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                CEdge newEdge;
                newEdge.point[0] = i;
                newEdge.point[1] = j;
                newEdge.length = sqrt( pow(points[i].x_-points[j].x_, 2) + pow(points[i].y_-points[j].y_, 2));
                edges.push_back(newEdge);
            }
        }
        sort(edges.begin(), edges.end());
        vector<int> arr(n);
        for(int i=0; i<n; i++) arr[i] = i;
        int setNum = n;
        double lengthSum = 0;
        for(int i=0; i<edges.size(); i++){
            arr[ edges[i].point[0] ] = findHead(arr, edges[i].point[0]);
            arr[ edges[i].point[1] ] = findHead(arr, edges[i].point[1]);
            if(arr[ edges[i].point[0] ] != arr[ edges[i].point[1] ]){
                arr[ arr[edges[i].point[1]] ] = arr[ edges[i].point[0] ];
                lengthSum += edges[i].length;
                setNum--;

            }
            if(setNum == 1) break;
        }
        printf("%.2f\n", lengthSum);
        if(test != testCase-1) cout << endl;
    }

    return 0;
}
