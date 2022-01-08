#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <numeric>

//**namespace(DO NOT USE in Developping)******************
//********************************************************
using namespace std;
using ll = long long;
using vecll = vector<ll>;
using vecin = vector<int>;
//********************************************************

//*class and struct**********_****************************
//**                       /.^.\
//********************    / | | \
//**                     /  | |  \
//**rule and caution**  /    V    \
//**                    \    O    /
//********************   ‾‾‾‾‾‾‾‾‾
//**
//***- 大文字のスネークケースで名前を記述すること.
//***- メンバ変数、メンバ関数、オペレータについて目的を明記
//*** すること.
//********************************************************
struct FRACTION
{
    // 分数を扱うためのクラス（構造体）
    // <numeric>ライブラリーに依存する
    // ue:分子
    // sita:分母
    // yakubun関数:約分して正負などを統一する
    // operator<:分数のsetを扱えるようにするために導入している
    // 正負の無限大を区別する　∞：1/0 -∞：-1/0
    // 0は 0/1 と表す
    // c++17以上のみに対応
    long long ue = 0;
    long long sita = 0;
    void yakubun()
    {
        long long kouyaku = gcd(ue, sita);
        ue = ue / kouyaku;
        sita = sita / kouyaku;
        if (sita == 0)
            ue /= abs(ue);
        else if (ue == 0)
            sita = 1;
        else if (sita < 0)
        {
            ue = (-1) * ue;
            sita = (-1) * sita;
        }
    };
    bool operator<(const FRACTION &r) const
    {
        return (ue * r.sita) < (r.ue * sita);
    };
};

class UNION_FIND_TREE
{
public:
    // parent:各ノードの親の番号を格納する.
    //
    // 各ノードはそれぞれが根であるとして初期化
    std::vector<int> parent;

    //それぞれを根として初期化(size1の木の集まり)
    UNION_FIND_TREE(int n)
    {
        parent = std::vector<int>(n, -1);
    }

    //根まで辿って根の番号を返す=根の番号をグループ番号とする
    int root(int node_number)
    {
        if (parent[node_number] < 0)
            return node_number;
        return parent[node_number] = root(parent[node_number]);
    }

    //木の結合 additionの根の親としてoriginの根を設定する
    void unite(int origin, int addition)
    {
        int ro = root(origin);
        int ra = root(addition);
        // 元々同じ木に居たら何もしない
        if (ro == ra)
            return;
        // 木の大きさを更新するために加算してから結合
        parent[ro] += parent[ra];
        // 必ず大きいほうを根として小さいほうをくっつける(計算量のために平衡木に近付ける)
        // 大小が逆だったらswapする
        if (size(ro) < size(ra))
            std::swap(ro, ra);
        parent[ra] = ro;
        return;
    }

    //根まで辿って引数のノードと同じ木に含まれるノードの個数を返す
    int size(int node_number)
    {
        return (-1) * parent[root(node_number)];
    }

    // 2つのノードが同じ根に繋がっているか返す
    bool is_similar(int node_a, int node_b)
    {
        return root(node_a) == root(node_b);
    }
};

class ADJENCY_LIST
{
    // 隣接リストを表す
    // 指定数の空のベクトルを以て初期化する
    std::vector<std::vector<int>> list;
    ADJENCY_LIST(int n)
    {
        list = std::vector<std::vector<int>>(n);
    }

    // 有向辺を設定する
    void direct(int from, int to)
    {
        list[from].push_back(to);
    }

    // 無向辺を設定する
    void nodirect(int a, int b)
    {
        list[a].push_back(b);
        list[b].push_back(a);
    }
};

//********************************************************

//**function*****************_****************************
//**                       /.^.\
//********************    / | | \
//**                     /  | |  \
//**rule and caution**  /    V    \
//**                     \    O    /
//********************   ‾‾‾‾‾‾‾‾‾
//**
//***- 小文字のスネークケースで名前を記述すること.
//***- 関数自体、引数、返値について目的を明記
//*** すること.
//********************************************************
void say_yes_or_no(int torf)
{
    // yesかnoを標準出力する関数
    // torf>0でYes
    if (torf > 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return;
}
//********************************************************

int main(void)
{
    // ここに処理を書く
    return 0;
}