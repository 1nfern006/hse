
template<typename InIter, typename OutIter, typename Predicate, typename Action>

OutIter TransformIf(InIter first, InIter last, OutIter out, Predicate condition, Action f) {
    
    for (InIter i = first; i != last; ++i) {
        if (condition(*i)) {
            *out = f(*i);
            ++out;
        }
    }
    return out;
}