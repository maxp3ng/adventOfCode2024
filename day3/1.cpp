// https://adventofcode.com/2024/day/3
// solved 12/3/24 
// comments: hit a BIG bump with changing to file input that ended up not even being the problem haha... should spend more time with cpp

#include "../headers/all.hpp"
#include <cctype>
#include <fstream>

ll solve(){
    ifstream inFile("in.txt"); 
    ll ret = 0;

    str next;
    while(getline(inFile,next)){ 
      for (int i=4; i<next.size(); i++){
        if (next.substr(i-4,4) == "mul("){
          int j = i;
          str firstNum = "";
          while(isdigit(next[j])){
            firstNum += next[j];
            j++;
          }
          if (next[j] != ',') continue;
          j++;
          str secondNum = "";
          while(isdigit(next[j])){
            secondNum += next[j];
            j++;
          }
          if (next[j] != ')') continue;
          int mul = stoi(firstNum)*stoi(secondNum);
          ret += mul;
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
