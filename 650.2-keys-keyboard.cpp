//Problem path : https://leetcode.com/problems/2-keys-keyboard/
class Solution {
public:
    int minSteps(int n) {
        
        bool prime[n+1]; 
        memset(prime, true, sizeof(prime)); 

        for (int p=2; p*p<=n; p++) 
        { 
            if (prime[p] == true) 
            { 
                for (int i=p*p; i<=n; i += p) 
                    prime[i] = false; 
            } 
        }
        if(n == 1)
            return 0;
        if(prime[n] == true)
            return n;
        
        vector<int> primes(n+1,0);
        primes[0] = 0;
        primes[1] = 0;
        for(int i=2; i<=n; i++){
            if(prime[i] == true){
                primes[i]=i;
            }
            else {
             for(int j=2; j<i; j++){
                if(prime[j]==true && i%j==0){
                    primes[i] = primes[i/j] + j;
                }   
             }   
            }
        }
        return primes[n];
    }

};
