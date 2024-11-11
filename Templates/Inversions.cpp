i64 inversions(vector<i64>& a) {
    if (a.size() <= 1) return 0;
    
    i64 h = a.size() / 2;
    
    vector<i64> l(a.begin(), a.begin() + h);
    vector<i64> r(a.begin() + h, a.end());
    
    i64 z = 0;
    z += inversions(l);
    z += inversions(r);
    
    // merge
    auto il = l.begin();
    auto ir = r.begin();
    auto ia = a.begin();
    
    while (il != l.end() || ir != r.end()) {
        bool f = ir == r.end() || (il != l.end() && ir != r.end() && *il <= *ir);
        
        if (!f) z += l.end() - il;
        *ia++ = f ? *il++ : *ir++;
    }
    
    return z;
}
 
i64 count_inversions(vector<i64> a) {
    return (inversions(a));
}