#include <string>
#include <vector>

using namespace std;
bool isZere(long long x){
    while(x > 0) {
        if(x%5 == 2){
            return true;
        }
        x/=5;
    }
    return false;
}
int solution(int n, long long l, long long r) {
    int answer = 0;
    for(long long i = l; i <= r; i++){
        long long x = i - 1;
        
        if(!isZere(x)) {
            answer++;
        }
    }
    return answer;
}