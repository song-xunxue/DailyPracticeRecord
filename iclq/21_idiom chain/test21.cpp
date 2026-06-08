#include <bits/stdc++.h> 

using namespace std;

struct BiaoJi
{
    long ChengYu;
    bool visit;

    BiaoJi(long ChengYu_, bool visit_)
    {
        ChengYu = ChengYu_;
        visit = visit_;
    }
};

vector<BiaoJi> g[300000 + 10];

struct Pos
{
public:
    long id;
    long step;

    Pos(long id_, long step_) : id(id_), step(step_)
    {}
};

struct ChengYu
{
public:
    long ChengYuA;
    long ChengYuB;
    long ChengYuC;
    long ChengYuD;
};

queue<Pos> q;

int main()
{
    //freopen("E://test.txt", "r", stdin); 
    long m;
    cin >> m;
    for (long i = 0; i < m; i++)
    {
        ChengYu tmp;
        cin >> tmp.ChengYuA >> tmp.ChengYuB >> tmp.ChengYuC >> tmp.ChengYuD;
        g[tmp.ChengYuA].push_back(BiaoJi(tmp.ChengYuD, 0));//以成语第一个字作为横坐标来存储成语，记录着每一个开头的成语都能走到哪里去 
    }

    ChengYu ChengYustart, ChengYuend;
    cin >> ChengYustart.ChengYuA >> ChengYustart.ChengYuB >> ChengYustart.ChengYuC >> ChengYustart.ChengYuD
        >> ChengYuend.ChengYuA >> ChengYuend.ChengYuB >> ChengYuend.ChengYuC >> ChengYuend.ChengYuD;
    if (ChengYustart.ChengYuA == ChengYuend.ChengYuA && ChengYustart.ChengYuB == ChengYuend.ChengYuB &&
        ChengYustart.ChengYuC == ChengYuend.ChengYuC && ChengYustart.ChengYuD == ChengYuend.ChengYuD)
    {//相等的情况 
        cout << 1 << endl;
        return 0;
    }
    if (ChengYustart.ChengYuD == ChengYuend.ChengYuA)
    {//开头成语和结尾成语恰好能连上 
        cout << 2 << endl;
        return 0;
    }
    Pos PosStart(ChengYustart.ChengYuD, 0);
    q.push(PosStart);
    long MIN = 300000 + 10;
    while (!q.empty())
    {
        Pos tmp = q.front();
        for (long i = 0; i < g[tmp.id].size(); i++)
        {//遍历这一行vector 
            if (g[tmp.id][i].visit == 0)
            {//没有访问过 
                if (g[tmp.id][i].ChengYu == ChengYuend.ChengYuA)
                {
                    if (tmp.step + 3 <= MIN)
                    {
                        MIN = tmp.step + 3;
                    }
                }
                g[tmp.id][i].visit = 1;
                Pos ReturnPos(g[tmp.id][i].ChengYu, tmp.step + 1);
                q.push(ReturnPos);
            }
        }
        q.pop();
    }
    if (MIN != 300000 + 10)
    {
        cout << MIN << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}