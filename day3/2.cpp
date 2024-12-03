// https://adventofcode.com/2024/day/3
// solved 12/3/24
// comments: so it turns out the int j = i did come back to bite me in the ass after all.... great

#include "../headers/all.hpp"
#include <cctype>
#include <fstream>

ll solve(){
    ifstream inFile("in.txt"); 

    ll ret = 0;

    str next;
    bool on = true;
    while(getline(inFile,next)){ 
      for (int i=0; i<next.size()-4; i++){
        if (next.substr(i,4) == "do()"){
          on = true;
          continue;
        }
        if (next.substr(i,7) == "don't()"){
          on = false;
          continue;
        }
        if (next.substr(i,4) == "mul(" && on){
          int j = i+4;
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
