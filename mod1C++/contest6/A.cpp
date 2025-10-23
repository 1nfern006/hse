
template<typename It, typename Pred>

bool AnyOf(It first, It last, Pred f) {
    for (It i = first; i != last; ++i) {
        if (f(i)) {
            return true;
        }
    }
    return false;
}