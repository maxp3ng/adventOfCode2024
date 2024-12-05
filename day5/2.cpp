// https://adventofcode.com/2024/day/5
// solved 12/5/24 
// comments: honestly i tuned out halfway through but got it with relatively low difficulty just took forever. same comments as for part 1. not proud of today

#include "../headers/all.hpp"
#include <cctype>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#include "../headers/all.hpp"
#include <cctype>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

ll solve() {
    ll ret = 0;
    vector<pair<int, int>> vrules;
    str next;
    
    // Read the rules (XX|YY format)
    while(getline(cin, next)) {
        if(next.empty() || next.size() != 5) break;
        vrules.pb(mp(stoi(next.substr(0,2)), stoi(next.substr(3,2))));
    }
    
    sort(vrules.begin(), vrules.end());
    
    // Read the comma-separated lists
    while(getline(cin, next)) {
        if(next.empty()) continue;
        
        vector<int> v;
        size_t pos = 0;
        str token;
        
        while((pos = next.find(',')) != string::npos) {
            token = next.substr(0, pos);
            v.pb(stoi(token));
            next.erase(0, pos + 1);
        }
        if(!next.empty()) {
            v.pb(stoi(next));
        }
       
        set<int> incorrect; 
        bool clear = true;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < vrules.size(); j++) {
                if(vrules[j].F == v[i]) {
                    bool found = false;
                    auto it = std::find(v.begin(), v.end(), vrules[j].S);
                    if (it == v.end()) {
                      //Out("does not exist in line");
                      found = true;
                      continue;
                    }
                    for(int k = i+1; k < v.size(); k++) {
                        //Out("rule is " + to_string(vrules[j].F)  + " " + to_string(vrules[j].S));
                        //Out("testing " + to_string(v[i]) + " " + to_string(v[k]));
                        if(v[k] == vrules[j].S) {
                            //Out("found");
                            found = true;
                            break;
                        }
                    }
                    if(found == false) {
                        //Out(v[i]);
                        incorrect.insert(v[i]);
                        clear = false;
                    }
                }
            }
        }
        if(!clear) {
          Out("incorrect seq");
          Out(incorrect.size());
          for (int i=0; i<vrules.size(); i++){
            int first = vrules[i].F;
            int second = vrules[i].S;
            if (!(count(v.begin(), v.end(), first) > 0 && count(v.begin(), v.end(), second) > 0)) continue;
            for (int j=v.size()-1; j>=0; j--){
              if (v[j] == first){
                swap(v[j], v[j-1]);
                Out("" + to_string(first) + " " + to_string(second));
                vOut(v);
              }
              if (v[j] == second){
                break;
              }
            }
          }
          vOut(v);
          ret += v[v.size()/2];
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
