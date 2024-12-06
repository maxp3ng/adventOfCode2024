// https://adventofcode.com/2024/day/6
// solved 12/6/24 
// comments: 

#include "../headers/all.hpp"
#include <vector>

bool loopsforever(vector<string> v, int x, int y, int n, int m) {
  set<pair<pair<int,int>, int>> history; 
  int dir = 1; //1234 up right down left
  while (x > 0 && x < m-1 && y > 0 && y < n-1){
      auto state = mp(mp(x,y),dir);
      if (history.count(state) > 0) return true;
      history.insert(state);
      cout << "At (" << x << "," << y << ") dir=" << dir << " char=" << v[y][x] << endl;
      cout.flush();
      v[y][x] = 'X';
      switch(dir) {
        case 1: // up
            if(y > 0 && v[y-1][x] != '#') y--;
            else { dir = 2;}
            break;
        case 2: // right
            if(x < m-1 && v[y][x+1] != '#') x++;
            else { dir = 3; }
            break;
        case 3: // down
            if(y < n-1 && v[y+1][x] != '#') y++;
            else { dir = 4; }
            break;
        case 4: // left
            if(x > 0 && v[y][x-1] != '#') x--;
            else { dir = 1; }
            break;
      }
  }
 return false;
}


ll solve(){
    ll ret = 0;
    str next;
    
    vector<string> v;
    int x = 0;
    int y = 0;
    int n = 0;
    while(getline(cin, next)) {
      for (int j=0; j<next.size(); j++){
        if (next[j] == '^') {
          x = j;
          y = n;
        }
      }
 
      n++;
      v.pb(next);
    }
    n = v.size();
    int m = v[0].size();

    auto vprint = v;
    for (int i=0; i<m; i++){
      for (int j=0; j<n; j++){
        if (i == x && y == j) continue;
        vector<string> vpass = v;
        vpass[j][i] = '#';
        Out("new loop");
        if (loopsforever(vpass,x,y,n,m)){
          for (int k=0; k<n; k++){
            Out(vpass[k]);
          }
          vprint[j][i] = 'O';
          ret++;
        }
      }
    }
    for (int i=0; i<v.size(); i++){
      Out(vprint[i]);
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
