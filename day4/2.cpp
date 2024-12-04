// https://adventofcode.com/2024/day/4
// solved 12/4/24
// comments: LETS GOOOOOOOOOOOO BEST PART 2 WAS PERFECT FOR MY SOL

#include "../headers/all.hpp"
#include <cctype>
#include <fstream>
#include <string>
#include <vector>

ll solve(){
  //ifstream inFile("in.txt"); 
  ll ret = 0;
  vector<str> v;
  str next;
  while(getline(cin,next)){ 
    v.pb(next);
  }

  ll m = v.size();
  ll n = v[0].length();
  Out("Diagonal Back");
  for (ll i=0; i<m-2; i++){
    for (ll j=0; j<n-2; j++){
      if (v[i][j] == 'M' && v[i][j+2] == 'S' && v[i+1][j+1] == 'A' && v[i+2][j] == 'M' && v[i+2][j+2] == 'S'){
        ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
      if (v[i][j] == 'M' && v[i][j+2] == 'M' && v[i+1][j+1] == 'A' && v[i+2][j] == 'S' && v[i+2][j+2] == 'S'){
        ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
      if (v[i][j] == 'S' && v[i][j+2] == 'S' && v[i+1][j+1] == 'A' && v[i+2][j] == 'M' && v[i+2][j+2] == 'M'){
        ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
      if (v[i][j] == 'S' && v[i][j+2] == 'M' && v[i+1][j+1] == 'A' && v[i+2][j] == 'S' && v[i+2][j+2] == 'M'){
        ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
    }
  }
  return ret;
}

int main(){
    setupIO();
    Out("ret is:")
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
