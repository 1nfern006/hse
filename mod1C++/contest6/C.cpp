
template<typename Iter>

Iter Unique(Iter first, Iter last) {
    
    Iter former = first;
    if (first == last) {
        return last;
    }
    for (Iter i = first; i != last; ++i) {  
        if (*i != *former) {
            ++former;
            *former = *i;
        }
    }
    return ++former;
}