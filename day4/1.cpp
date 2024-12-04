// https://adventofcode.com/2024/day/4
// solved 12/4/24 
// comments: bwahaha brute force and vim ftw! forgot edge case so a bit of burnt time there... always spend a bit more time reading problem statement 

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
  Out("horizontal");
  for (ll i=0; i<m; i++){
    for (ll j=0; j<n-3; j++){
      if (v[i].substr(j,4) == "XMAS" || v[i].substr(j,4) == "SAMX") {
        ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
    }
  }
  Out("vertical");
  for (ll i=0; i<m-3; i++){
    for (ll j=0; j<n; j++){
      if (v[i][j] == 'X' && v[i+1][j] == 'M' && v[i+2][j] == 'A' && v[i+3][j] == 'S'){
          ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
      if (v[i][j] == 'S' && v[i+1][j] == 'A' && v[i+2][j] == 'M' && v[i+3][j] == 'X') {
         ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
    }
  }
  Out("Diagonal");
  for (ll i=0; i<m-3; i++){
    for (ll j=0; j<n-3; j++){
      if (v[i][j] == 'X' && v[i+1][j+1] == 'M' && v[i+2][j+2] == 'A' && v[i+3][j+3] == 'S'){ 
        ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
      if (v[i][j] == 'S' && v[i+1][j+1] == 'A' && v[i+2][j+2] == 'M' && v[i+3][j+3] == 'X'){ 
        ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
   }
  }
  Out("Diagonal Back");
  for (ll i=0; i<m-3; i++){
    for (ll j=0; j<n-3; j++){
      if (v[i][j+3] == 'X' && v[i+1][j+2] == 'M' && v[i+2][j+1] == 'A' && v[i+3][j] == 'S'){ 
        ret++; 
        Out("loc" + to_string(i) + " " + to_string(j));
      }
      if (v[i][j+3] == 'S' && v[i+1][j+2] == 'A' && v[i+2][j+1] == 'M' && v[i+3][j] == 'X'){ 
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
