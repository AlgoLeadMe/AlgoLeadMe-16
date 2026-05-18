class Solution {
    fun solution(numer1: Int, denom1: Int, numer2: Int, denom2: Int): IntArray {
        var numer = numer1 * denom2 + numer2 * denom1
        var denom = denom1 * denom2
        
        var gcdValue = gcd(numer, denom)
        
        return intArrayOf(numer / gcdValue, denom / gcdValue)
    }

    private tailrec fun gcd(a: Int, b: Int): Int = if (b == 0) a else gcd(b, a % b)
}