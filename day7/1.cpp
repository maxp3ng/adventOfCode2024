// https://adventofcode.com/2024/day/7
// 
// comments: 

#include "../headers/all.hpp"
#include <sstream>
#include <string>

bool recurse(unsigned long long n, vector<ll> v, bool divide, str trace){
  if (v.size() <= 0){
    if (divide==n){
      Out(trace + " " + to_string(n) + " " + "true");
      return true;
    }
    //Out(trace + " " +to_string(n) + " " + "false");
    return false;
  } 

  ll last = v[v.size()-1]; 
  v.erase(v.begin()+v.size()-1);
 
  if (n%last == 0){
   return recurse(n/last, v, true, trace + to_string(n) + " " + to_string(last) + " " + "divide clean ")||recurse(n-last, v, false, trace + " " + to_string(n) + " " + to_string(last) + " " + "subtract ");
  } else {
   return recurse(n-last, v, false, trace + " " + to_string(n) + " " + to_string(last) + " " + "subtract ");
  }
}

unsigned long long solve() {
    unsigned long long ret = 0;
    str next;
    
    while(getline(cin, next)) {
      stringstream ss(next);
      unsigned long long n;
      str eat;
      ss >> n >> eat;
      vector<ll> v;

      ll next;
      while(ss >> next){
        v.pb(next);
      }
      ret += recurse(n,v,true,"") * n;
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
