#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

vector<map<int, int>> b;
vector<int> mb;
vector<vector<int>> r;
int n, m, a, tmp;
char in;
int user, item, value;

int main()
{
    cin >> n >> m >> a;
    b.resize(n);
    r.resize(m);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        mb.push_back(tmp);
    }

    while (a > 0)
    {
        a--;
        cin >> in;
        if (in == 'B')
        {
            cin >> user >> item >> value;
            b[--item][--user] = value;
        }
        else if (in == 'W')
        {
            cin >> user >> item;
            b[--item].erase(--user);
        }
    }

    for (int i = 0; i < n; i++)
    {
        priority_queue<pair<int, int>> q;
        for (auto j = b[i].begin(); j != b[i].end(); j++)
        {
            q.push(make_pair(j->second, j->first));
        }
        while (mb[i] > 0 && !q.empty())
        {
            r[q.top().second].push_back(i);
            q.pop();
            mb[i]--;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (r[i].empty())
            cout << "NONE" << endl;
        else
        {
            for (int j = 0; j < r[i].size(); j++)
            {
                cout << r[i][j] + 1 << " ";
            }
            cout << endl;
        }
    }
}
