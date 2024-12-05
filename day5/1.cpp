// https://adventofcode.com/2024/day/5
// solved 12/5/24 
// comments: oh my god this was terrible just horrendous. partially not knowing std enough to do simple stuff like splice and search (need to make inlines) but also just general bad practices

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
    
    Out("we made it!");
    
    // Read the comma-separated lists
    while(getline(cin, next)) {
        if(next.empty()) continue;
        
        vector<int> v;
        size_t pos = 0;
        str token;
        
        // Split by commas
        while((pos = next.find(',')) != string::npos) {
            token = next.substr(0, pos);
            v.pb(stoi(token));
            next.erase(0, pos + 1);
        }
        // Don't forget the last number
        if(!next.empty()) {
            v.pb(stoi(next));
        }
        
        bool clear = true;
        for(int i = 0; i < v.size(); i++) {
            for(int j = 0; j < vrules.size(); j++) {
                if(vrules[j].F == v[i]) {
                    bool found = false;
                    auto it = std::find(v.begin(), v.end(), vrules[j].S);
                    if (it == v.end()) {
                      Out("does not exist in line");
                      found = true;
                      continue;
                    }
                    for(int k = i+1; k < v.size(); k++) {
                        Out("rule is " + to_string(vrules[j].F)  + " " + to_string(vrules[j].S));
                        Out("testing " + to_string(v[i]) + " " + to_string(v[k]));
                        if(v[k] == vrules[j].S) {
                            Out("found");
                            found = true;
                            break;
                        }
                    }
                    if(found == false) {
                        Out(v[i]);
                        clear = false;
                        break;
                    }
                }
            }
        }
        if(clear) {
          Out("row cleared");
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
