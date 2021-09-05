#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
clock_t T;
#define ctime cerr <<endl<< "Time : " << double(clock() - T) / CLOCKS_PER_SEC << endl
#define debug(x) cout << (#x) << " " << (x) <<" "<< endl
#define debug2(x, y) cerr << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< endl
#define debug3(x, y, z) cout << (#x) << " " << (x) <<" "<< (#y) << " " << (y) <<" "<< (#z) << " " << (z) << endl
#define marwan ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);ios_base::sync_with_stdio(0);
#define read freopen("input.txt", "r", stdin);
#define write  freopen("output.txt", "w", stdout);
#define f(a, b, c) for(ll a = b; a < c; a++)
#define fr(a, b, c) for(int a = b; a >= c; a--)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define cinvec(v, n) f(i, 0, n){ll a;cin>>a;v.pb(a);};
#define printvec(v, n) for (auto e: v) cout << e << " "; cout << endl;
#define pb push_back
#define pf push_front
#define RESET(a, b) memset(a, b, sizeof(a))
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double pi = acos(-1);
int dirx[8] = {-1, 0, 0, 1, -1, -1, 1, 1};
int diry[8] = {0, 1, -1, 0, -1, 1, -1, 1};
using namespace std;

pair<int, int> start, dest;
string startDirection;
vector<string> directions = {"N", "E", "S", "W"};

void shiftDirection(vector<string> &v, string curDirection,
                    string destDirection){
    int destIdx = -1, curIdx = -1;
    if (curDirection == "N") curIdx = 0; if (curDirection == "E") curIdx = 1;
    if (curDirection == "S") curIdx = 2; if (curDirection == "W") curIdx = 3;

    if (destDirection == "N") destIdx = 0; if (destDirection == "E") destIdx = 1;
    if (destDirection == "S") destIdx = 2; if (destDirection == "W") destIdx = 3;

    while (curIdx != destIdx){
        v.push_back("D");
        curIdx++;
        curIdx %= 4;
    }
}

vector<string> solve(string initDirection, string path){
    vector<string> v;
    pair<int, int> mystart = start;
    pair<int, int> mydest = dest;

    //need to shift from my direction to direction i should take
    shiftDirection(v, startDirection, initDirection);

    if (path == "X"){
        if (initDirection == "W"){
            //need to move west
            int ctr = 0;
            ctr = abs(mystart.first - mydest.first);
            mystart.first = mydest.first;
//            while (mystart.first > mydest.first)
//                ctr++, mystart.first--;
            if (ctr)

                v.push_back("A " + to_string(ctr));
        }else{
            //need to move right
            int ctr = 0;
            ctr = abs(mystart.first - mydest.first);
            mystart.first = mydest.first;
//            while (mystart.first < mydest.first)
//                ctr++, mystart.first++;
            if (ctr)

                v.push_back("A " + to_string(ctr));
        }
        if (mystart.second != mydest.second){
            //now need to move north or south
            string nextDirection = "";
            if (mystart.second <= mydest.second){
                nextDirection = "N";
            }else{
                nextDirection = "S";
            }
            shiftDirection(v, initDirection, nextDirection);
            if (nextDirection == "N"){
                int ctr = 0 ;
                ctr = abs(mystart.second - mydest.second);
                mystart.second = mydest.second;
//                while (mystart.second < mydest.second)
//                    ctr++, mystart.second++;
                if (ctr)

                    v.push_back("A " + to_string(ctr));
            }else{
                int ctr = 0 ;
                ctr = abs(mystart.second - mydest.second);
                mystart.second = mydest.second;
//                while (mystart.second > mydest.second)
//                    ctr++, mystart.second--;
                if (ctr)

                    v.push_back("A " + to_string(ctr));
            }
        }

    }else{
        if (initDirection == "N"){
            int ctr = 0 ;
            ctr = abs(mystart.second - mydest.second);
            mystart.second = mydest.second;
//            while (mystart.second < mydest.second)
//                ctr++, mystart.second++;
            if (ctr)

                v.push_back("A " + to_string(ctr));
        }else{
            int ctr = 0 ;
            ctr = abs(mystart.second - mydest.second);
            mystart.second = mydest.second;
//            while (mystart.second > mydest.second)
//                ctr++, mystart.second--;'
            if (ctr)

                v.push_back("A " + to_string(ctr));
        }
        if (mystart.first != mydest.first){
            //now need to move west or east
            string nextDirection = "";
            if (mystart.first <= mydest.first){
                nextDirection = "E";
            }else{
                nextDirection = "W";
            }
            shiftDirection(v, initDirection, nextDirection);
            if (nextDirection == "W"){
                //need to move west
                int ctr = 0;
                ctr = abs(mystart.first - mydest.first);
                mystart.first = mydest.first;
//                while (mystart.first > mydest.first)
//                    ctr++, mystart.first--;
                if (ctr)
                    v.push_back("A " + to_string(ctr));
            }else{
                //need to move right
                int ctr = 0;
                ctr = abs(mystart.first - mydest.first);
                mystart.first = mydest.first;
//                while (mystart.first < mydest.first)
//                    ctr++, mystart.first++;
                if (ctr)
                    v.push_back("A " + to_string(ctr));
            }
        }

    }

    return v;
}


int main() {

#ifdef offline_debug
    read
#endif

    marwan
    cin >> start.first >> start.second;
    cin >> startDirection;
    cin >> dest.first >> dest.second;
    if (startDirection == "O")
        startDirection = "W";
    string moveOnX, moveOnY;
    if (start.first <= dest.first)
        moveOnX = "E";
    else
        moveOnX = "W";
    if (start.second <= dest.second)
        moveOnY = "N";
    else
        moveOnY = "S";

    vector<string> sol2 = solve(moveOnY, "Y");

    vector<string> sol1 = solve(moveOnX, "X");
    while (sol2.size() && (sol2.back() == "A 0" || sol2.back() == "D"))
        sol2.pop_back();

    while (sol1.size() && (sol1.back() == "A 0" || sol1.back() == "D"))
        sol1.pop_back();
    //printvec(sol1, sol1.size());
    //printvec(sol2, sol2.size());
    if (sol1.size() <= sol2.size()){
        cout << sol1.size() << endl;
            for (auto e: sol1)
                cout << e << endl;
    }else{
        cout << sol2.size() << endl;
            for (auto e: sol2)
                cout << e << endl;
    }
}