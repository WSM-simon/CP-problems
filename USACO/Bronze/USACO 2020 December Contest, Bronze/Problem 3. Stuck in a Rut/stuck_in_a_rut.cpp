#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <tuple>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("C:\\Users\\Simian\\OneDrive\\CCC_senior_2021_2\\test\\test.in", "r", stdin);

    int N, x, y, dx, dy, t, pos;
    char dir;
    vector<pair<int, int>> nor, est;
    pair<int, int> tem_n, tem_e, temP1, temP2;
    map<int, vector<tuple<int, int, int, int, int>>> colls; //{key1_int:[(x1, y1, x2, y2)]}
    map<pair<int, int>, int> order, stop; 

    cin >> N;
    int result[N]={0};

    for (int i=0; i<N; i++)
    {
        cin >> dir >> x >> y;
        order[pair<int, int>(x, y)] = i; // 每只牛的输入输出顺序
        if (dir == 'N') nor.push_back(pair<int, int>(x, y));
        else est.push_back(pair<int, int>(x, y));
    }

    for (int ni=0;  ni<nor.size(); ni++)
    {
        tem_n = nor[ni];
        for (int ei=0; ei<est.size(); ei++)
        {
            tem_e = est[ei];
            dx = tem_n.first - tem_e.first;
            dy = tem_e.second - tem_n.second;

            if (dx < 0 || dy < 0)
                continue;

            else if (dx > dy)   // east cow 撞 north cow
            {   
                colls[dx].push_back(make_tuple(tem_e.first, tem_e.second, tem_n.first, tem_n.second, 1));
            }
            else if (dx < dy)   // north cow 撞 east cow
            {
                colls[dy].push_back(make_tuple(tem_n.first, tem_n.second, tem_e.first, tem_e.second, 0));
            }
        }  
    }

    for (auto it:colls)
    {   
        t=it.first;
        for (auto tup:it.second)
        {   
            pos = get<4>(tup);
            temP1 = make_pair(get<0>(tup), get<1>(tup));
            temP2 = make_pair(get<2>(tup), get<3>(tup));
            if (stop.find(temP1) == stop.end())
            {      
                if (stop.find(temP2) != stop.end())
                {
                    if (pos)
                    {
                        if (temP2.second + stop[temP2] < temP1.second) 
                            continue;       
                    }
                    else
                    {
                        if (temP2.first + stop[temP2] < temP1.first)
                            continue;
                    }
                }
                
                stop.insert(make_pair(temP1, t));
                result[order[temP1]] = t;
            }
        }
    }

    for (int i:result)
    {
        if (i) cout << i << "\n";
        else cout << "Infinity" << "\n";
    }
}