#include <string>

using namespace std;

int solution(string t, string p) {
    int p_len = p.length();
    int result = 0;

    for(int i = 0; i <= t.length() - p_len; i++){
        string sub = t.substr(i, p_len);

        if(sub<= p){
            result++;
        }
    }
    return result;
}