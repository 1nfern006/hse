
template<typename InIter, typename OutIter, typename Predicate>

OutIter RemoveCopyIf(InIter first, InIter last, OutIter out, Predicate f) {
    
    for (InIter i = first; i != last; ++i) {
        if (!f(*i)) {
            *out = *i;
            ++out;
        }
    }
    return out;
}