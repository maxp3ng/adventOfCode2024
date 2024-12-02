// https://adventofcode.com/2024/day/1
// solved 12/1/24
// comments: took some time to get used to cpp again and learn a few things, but going well so far

#include <bits/stdc++.h>
#include "../headers/quicksort.h"

using namespace std;
using ll = long long;
const ll MXN = 2e5 + 10;
using str = string;
using db = long double;
using vll = vector<ll>;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define endl "\n";
#define F first
#define S second
#define pb push_back
#define mp make_pair

#define Rep(i, x, y)   for (__typeof(x) i=x; i < y; i++)
#define Repi(i, x, y)  for (__typeof(x) i=x; i > y; i--)
#define vOut(v) Rep(i,0,v.size()){cout << v[i] << " ";} cout << endl;
#define Out(s)  cout << s << '\n';

void solve(){
    vll v1;
    vll v2;
   
    ll next1;
    ll next2;
    while(cin >> next1){ 
	    if (next1 == 0) {break;}
	    v1.pb(next1);
	    cin >> next2;
	    v2.pb(next2);
    }
    quicksort(v1);
    quicksort(v2);

    ll i;
    ll n = 0;
    Rep(i, 0, v1.size()){
	n += abs(v1[i] - v2[i]);
    }
    cout << n;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    solve();
    return 0;
}



/*
 * tomorrow and
 *              tomorrow and
 *                            tomorrow
 *
 * creeps in this petty pace from day to day
 *      to the last syllable of recorded time
 *          and all our yesterdays have lighted fools the way to dusty death
 *
 *          out, out, brief candle!
 */
