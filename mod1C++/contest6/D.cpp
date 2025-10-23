
template<typename InIter, typename OutIter>

OutIter ReverseCopy(InIter first, InIter last, OutIter out) {

    InIter i = last;

    while (i != first) {
        --i;
        *out = *i;
        ++out;
    }
    return out;
}