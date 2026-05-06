#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long answer = num;
    for(int i = 0; i < 500; i++)
    {
        if(answer == 1)
        {
            return i;
        }
        answer = answer&1 ? answer * 3 + 1 : answer >> 1;
    }
    return -1;
}