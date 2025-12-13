#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> cnt ;
    cnt.reserve(participant.size() * 2) ;
    
    for (const auto& name : participant) {
        cnt[name]++ ;
    }
    
    for (const auto& name : completion) {
        cnt[name]-- ;
    }
    
    for (const auto& kv : cnt) {
        if (kv.second > 0) return kv.first ;
    }
    
    return "" ;
    
    return answer;
}