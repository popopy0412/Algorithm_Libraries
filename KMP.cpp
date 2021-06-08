void getPI(){
    int n = P.length();
    int begin = 1, match = 0;
    while(begin + match < n){
        if(P[match] == P[begin + match]){
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
}
void KMP(){
    int n = T.length(), m = P.length();
    int begin = 0, match = 0;
    while(begin + match < n){
        if(match < m && T[begin+match] == P[match]){
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
}
