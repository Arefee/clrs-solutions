namespace clrs
{
    template <typename InputIterator, typename T>
    InputIterator linear_search(InputIterator first,
                                InputIterator last,
                                const T& value)
    {
        for (auto i = first; i != last; ++i)
        {
            if (*i == value)
            {
                return i;
            }
        }

        return last;
    }
}
