// https://adventofcode.com/2024/day/7
// solved 12/7/24
// comments: need to figure out what was going on with ull

#include "../headers/all.hpp"
#include <sstream>
#include <string>

bool endsWithNumber(unsigned long long n, unsigned long long last) {
    // Get number of digits in last
    unsigned long long temp = last;
    unsigned long long divisor = 1;
    while (temp > 0) {
        temp /= 10;
        divisor *= 10;
    }
    
    // Check if n ends with last
    return (n % divisor) == last;
}

unsigned long long removeEnd(unsigned long long n, unsigned long long last) {
    unsigned long long temp = last;
    unsigned long long divisor = 1;
    while (temp > 0) {
        temp /= 10;
        divisor *= 10;
    }
    return n / divisor;
}

bool recurse(unsigned long long n, vector<ll> v, str op, str trace){
  if (v.size() <= 0){
    if ((op == "divide" && n==1) || (op == "subtract" && n==0)){
      Out(trace + " " + to_string(n) + " " + "true");
      return true;
    }
    //Out(trace + " " +to_string(n) + " " + "false");
    return false;
  } 

  ll last = v[v.size()-1]; 
  v.erase(v.begin()+v.size()-1);
 
  bool subtract = recurse(n-last, v, "subtract", trace + " " + to_string(n) + " " + to_string(last) + " " + "subtract ");
  bool pipe = false;
  bool divide = false;
  if (n%last == 0){
    divide = recurse(n/last, v, "divide", trace + to_string(n) + " " + to_string(last) + " " + "divide clean ");
  }
  str strn = to_string(n);
  str strlast = to_string(last);
  if (endsWithNumber(n, last)) {
    if (n == last && v.size() == 0) return true;
    unsigned long long newn = removeEnd(n, last);
    pipe = recurse(newn, v, "pipe", trace + " " + to_string(n) + " " + to_string(last) + " " + "pipe");
}
 return divide || subtract || pipe;
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
      ret += recurse(n,v,"subtract","") * n;
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
