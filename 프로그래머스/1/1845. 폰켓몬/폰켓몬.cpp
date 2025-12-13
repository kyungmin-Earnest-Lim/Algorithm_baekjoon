#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> cnt ;
    
    for (const auto& poke : nums) {
        cnt[poke]++ ;
    }
    
    int max_type = cnt.size() ;
    int max_pick = nums.size() / 2 ;
    
    return min(max_type, max_pick) ;
    
}