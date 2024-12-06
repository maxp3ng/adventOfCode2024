// https://adventofcode.com/2024/day/6
// solved 12/6/24
// comments: terrible i couldn't get cli to work for an hour

#include "../headers/all.hpp"

ll solve() {
    ll ret = 1;
    str next;
    
    vector<string> v;
    int x = 0;
    int y = 0;
    int n = 0;
    while(getline(cin, next)) {
      for (int j=0; j<next.size(); j++){
        cout << "Got line: " << next << endl;
        if (next[j] == '^') {
          x = j;
          y = n;
        }
      }
 
      n++;
      v.pb(next);
    }
    int m = v[0].size();
    int dir = 1; //1234 up right down left
    n = 10;
    while (x > 0 && x < m-1 && y > 0 && y < n-1){
        cout << "At (" << x << "," << y << ") dir=" << dir << " char=" << v[y][x] << endl;
        cout.flush();
      v[y][x] = 'X';
            switch(dir) {
            case 1: // up
                if(y > 0 && v[y-1][x] != '#') y--;
                else { dir = 2; x++; }
                break;
            case 2: // right
                if(x < m-1 && v[y][x+1] != '#') x++;
                else { dir = 3; y++; }
                break;
            case 3: // down
                if(y < n-1 && v[y+1][x] != '#') y++;
                else { dir = 4; x--; }
                break;
            case 4: // left
                if(x > 0 && v[y][x-1] != '#') x--;
                else { dir = 1; y--; }
                break;
        }
    }
    for (int i=0; i<n; i++){
        cout << v[i] << endl;
    }

    for (int i=0; i<n; i++){
      for (int j=0; j<m; j++){
        if (v[i][j] == 'X') ret++;
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
