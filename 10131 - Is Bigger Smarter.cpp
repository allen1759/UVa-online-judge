#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Cele
{
public:
    int weight, iq, num;
    bool operator < (const Cele &rhs)const
    {
        //return weight<rhs.weight && iq>rhs.iq;
        return iq > rhs.iq;
    }
};
bool cmp(const Cele &lhs, const Cele &rhs)
{
    return lhs.weight < rhs.weight;
}

int LIS(vector<Cele> &s, vector<int> &pos)
{
    if(s.size() == 0) return 0;
    vector<Cele> v;
    v.push_back(s[0]);
    pos.push_back(0);
    int ptr = 0;
    for(int i=1; i<s.size(); i++){
        if(v.back().iq > s[i].iq && v.back().weight < s[i].weight) {
            v.push_back(s[i]);
            pos.push_back(++ptr);
        }
        else {
            vector<Cele>::iterator it = lower_bound(v.begin(), v.end(), s[i]);
            *it = s[i];
            pos.push_back(it - v.begin());
        }
    }
    return v.size();
}
int main()
{
    vector<Cele> sequence;
    vector<int> position;
    int w, iq, lisLen, ptr = 0;
    while(cin >> w >> iq) {
        sequence.push_back((Cele){w, iq, ++ptr});
    }
    sort(sequence.begin(), sequence.end(), cmp);

    lisLen = LIS(sequence, position);
    vector<int> lis;
    ptr = position.size()-1;
    for(int i = lisLen-1; i>=0; i--){
        while(ptr >=0 && i != position[ptr]) ptr--;
        lis.push_back(sequence[ptr].num);
    }
    cout << lisLen << endl;
    for(vector<int>::reverse_iterator it = lis.rbegin(); it!=lis.rend(); it++)
        cout << *it << endl;

    return 0;
}
