// https://adventofcode.com/2024/day/8
// solved 12/u/24
// comments: happened to work well with my sol, partially attribute today's success to how easy it was to debug on a grid and cross ref with sample

#include "../headers/all.hpp"
#include <sstream>
#include <string>

ll solve() {
    str next;
    vector<str> v;    
    set<pair<char, pair<int,int>>> s;

    int n = 0;
    int m;
    while(getline(cin, next)) {
      v.pb(next);

      n++;
      m = next.size();

      for (int i=0; i<m; i++){
        if (next[i] != '.' && next[i] != '#'){
          s.insert(mp(next[i], mp(i,n)));
        }
      }
    }
    vector<str> vret = v;

    for (auto it1 = s.begin(); it1 != s.end(); ++it1) { 
      for (auto it2 = s.begin(); it2 != s.end(); ++it2) { 
        if (it1->F == it2->F && *it1 != *it2){
          int fx = it1->S.F;          
          int sx = it2->S.F;          
          int fy = it1->S.S;          
          int sy = it2->S.S;          
          pair<int,int> left = mp(fx-(sx-fx),fy-(sy-fy));
          while(left.F>=0 && left.F<m && left.S>0 && left.S<=n){
            vret[left.S-1][left.F] = '#';
            left.F = left.F-(sx-fx);
            left.S = left.S-(sy-fy);
          }
          pair<int,int> right = mp(sx+(sx-fx),sy+(sy-fy));
          while(right.F>=0 && right.F<m && right.S>0 && right.S<=n){
            vret[right.S-1][right.F] = '#';
            right.F = right.F+(sx-fx);
            right.S = right.S+(sy-fy);
          }
        }
      }
    }
    ll ret = 0;
    for (int i=0; i<v.size(); i++){
      Out(vret[i]);
      for (int j=0; j<v[0].size(); j++){
        ret += (vret[i][j] != ('.'));
      }
    }
    return ret;
}

int main() {
    setupIO();
    Out("ret is:");
    Out(solve());
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
