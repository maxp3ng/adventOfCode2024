// https://adventofcode.com/2024/day/2
// solved 12/2/24
// comments: I CHOKEDDDDDD OMG should have just gone for the on^2 solve from the start

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
   
    ll n = 0;
    string next;
    while(getline(cin,next)){ 
 	stringstream ss(next);
 	ll nextToken;
    	vll v; 

 	while (ss >> nextToken) {
	     v.push_back(nextToken);
 	}

	if (v[0] == 0) {
		cout << n;
		return;
	}
	// done reading input
	bool ascending = (v[1] - v[0] >=0);
    	bool safe = true;
	    for (int i=1; i<v.size(); i++){
		if (ascending && v[i] - v[i-1] < 1 || v[i] - v[i-1] > 3 ){
			safe = false;
			break;
		}
		if (!ascending && v[i-1] - v[i] < 1 || v[i-1] - v[i] > 3 ){
			safe = false;
			break;
		}
	    }
	    if (!safe){
		for (int i=0; i<v.size(); i++){
			vll vc(v);
			vc.erase(vc.begin() + i);
			vOut(vc);
			ascending = (vc[1] - vc[0] >=0);
			safe = true;
			    for (int i=1; i<vc.size(); i++){
				if (ascending && vc[i] - vc[i-1] < 1 || vc[i] - vc[i-1] > 3 ){
					safe = false;
					break;
				}
				if (!ascending && vc[i-1] - vc[i] < 1 || vc[i-1] - vc[i] > 3 ){
					safe = false;
					break;
				}
			    }
			 if (safe == true) break;
		}
	    }
	    cout << safe << endl;
	    n += (int)safe;
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
