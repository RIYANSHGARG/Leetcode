class ATM {
public:
    vector<long long int> notes={20,50,100,200,500};
    vector<long long int> cash;
    long long int total_cash;
    ATM() {
        cash.resize(5);
        fill(cash.begin(),cash.end(),0);
        total_cash=0;
    }
    
    void deposit(vector<int> banknotesCount) {
        for(long long int i=0;i<5;i++){
            cash[i]+=banknotesCount[i];
            total_cash+=banknotesCount[i]*notes[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        if(amount > total_cash) return {-1};
        vector<int> ans(5,0);
        long long int remainingAmount = amount;
        for (long long int i = cash.size() - 1; i >= 0; i--) {
            long long int numberOfNotes = remainingAmount / notes[i];
            if (cash[i] < numberOfNotes) {
                numberOfNotes = cash[i];
            }
            ans[i] = (int)numberOfNotes;
            cash[i]-=numberOfNotes;
            remainingAmount -= numberOfNotes * notes[i];

            if (remainingAmount == 0)
                return ans;
        }
        if(remainingAmount!=0){
            for(long long int i=0;i<5;i++){cash[i]+=ans[i];}
            return {-1};
        }
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */