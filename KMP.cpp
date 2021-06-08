vector<int> getPI(const string& N){
    int n = N.length();
    vector<int> pi(n, 0);
    int begin = 1, match = 0;
    while(begin + match < n){
        if(N[match] == N[begin + match]){
            match++;
            pi[begin+match-1] = match;
        }
        else{
            if(!match) begin++;
            else{
                begin += match - pi[match-1];
                match = pi[match-1];
            }
        }
    }
    return pi;
}

vector<int> KMP(const string& H, const string& N){
    int n = H.length(), m = N.length();
    vector<int> v;
    int begin = 0, match = 0;
    while(begin + match < n){
        if(match < m && H[begin+match] == N[match]){
            match++;
            if(match == m) v.push_back(begin+1);
        }
        else{
            if(!match) begin++;
            else{
                begin += match - pi[match-1];
                match = pi[match-1];
            }
        }
    }
    return v;
}

vector<int> KMP2(const string& H, const string& N){
    int n = H.length(), m = N.length();
    vector<int> v;
    int begin = 0, match = 0;
    for(int i=0;i<n;i++){
        while(match > 0 && H[i] != N[match]) match = pi[match-1];
        if(H[i] == N[match]){
            match++;
            if(match == m){
                v.push_back(i-m+1);
                match = pi[match-1];
            }
        }
    }
    return v;
}
