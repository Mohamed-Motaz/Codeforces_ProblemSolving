#include <iostream>
#include <stdio.h>
#include <functional>
#include <string>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <iomanip>
#include <complex>
#include <unordered_set>
#include <assert.h>
#include <sstream>


#define ll long long
#define ld long double

#define debug1(x) cout << (#x) << " " << (x) <<" "<< endl
#define debug2(x,y) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl
#define debug3(x,y,z) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << endl
#define debug4(x,y,z, a) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << " "<< (#a) << " " << (a) << endl

#define trace1(x) cerr<<#x<<": "<<x<<" "<<endl
#define trace2(x, y) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z) cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

#define ull unsigned long long
#define endl "\n"
#define MohamedMotaz ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define readwrite freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define read freopen("input.txt", "r", stdin);
#define write freopen("output.txt", "w", stdout);
#define clr(x, y) memset(x, y, sizeof(x));
#define f(a, b, c) for(ll a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define vll vector<ll>
#define vld vector<ld>
#define vii vector<int>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<ll,ll>
#define pld pair<ld, ld>
#define vpii vector<pii>
#define vpll vector<pll>
#define vpld vector<pld>
#define vc vector<char>
#define vs vector<string>
#define vp vector<point>
#define vb vector<bool>
#define mll map<ll,ll>
#define mii map<int, int>
#define mllv map<ll, vll>
#define mcll map<char, ll>
#define mcii map<char, int>
#define msll map<string, ll>
#define mss map<string, string>
#define mcs map<char, string>
#define sll set<ll>
#define sz(x) (ll)x.size()
#define cinvec(v) f(i, 0, v.size()) cin >> v[i]
#define coutvec(v) for (auto e: v) cout << e << " "; cout << endl;
#define printvec(v) for (auto e: v) cout << e << " "; cout << endl;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pi acos(-1)
#define point complex<ld>

using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 7;
int n, p;
class Node{
public:
    int value;
    Node *next, *previous;
};
class LinkedList{
public:
    Node* head;
    Node* tail;
};
Node* root = new Node();
Node* tail = new Node();
Node* cur = new Node();

void insertBefore(Node* cur, Node* toAdd){
    Node *before = cur->previous;
    if (before != 0)
        before->next = toAdd;
    toAdd->next = cur;
    toAdd->previous = before;
    cur->previous = toAdd;
}
void insertAfter(Node* cur, Node* toAdd){
    Node* next = cur->next;
    if (next != 0)
        next->previous = toAdd;
    cur->next = toAdd;
    toAdd->previous = cur;
    toAdd->next = next;
    if (toAdd->next == 0)
        tail = toAdd;
}

int main(){
    MohamedMotaz;
    cin >> n >> p;

    root = tail;
    tail = root;
    int val; cin >> val;
    root->value = val;
    cur = root;
    for (int i = 0; i < n - 1; i++){
        int val;cin >> val;
        Node *nn = new Node();
        nn->value = val;
        insertAfter(tail, nn);
    }
//    for (int i = 0; i < n; i++){
//        cout << root->value << " ";
//        root = root->next;
//    }
    cur = root;
    for (int i = 0; i < p - 1; i++)
        cur = cur->next;
//    cout << endl;
//    cout << "THIS is the current: " << cur->value << " tail: " << tail->value << endl;
    int q;
    cin >> q;
    while (q--){
        string s;
        cin >> s;
        if (s == "moveLeft"){
            if (cur->previous)
                cur = cur->previous;
        }else if (s == "moveRight"){
            if (cur->next)
                cur = cur->next;
        }else if (s == "print")
            cout << cur->value << endl;
        else if (s == "insertLeft"){
            int x; cin >> x;
            Node *nn = new Node();
            nn->value = x;
            insertBefore(cur, nn);
        }else if (s == "insertRight"){
            int x; cin >> x;
            Node *nn = new Node();
            nn->value = x;
            insertAfter(cur, nn);
        }
    }

}