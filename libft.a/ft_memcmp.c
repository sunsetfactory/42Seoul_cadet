int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const char *tmp_s1;
    const char *tmp_s2;

    tmp_s1 = (const char *)s1;
    tmp_s2 = (const char *)s2;
    i = 0;
    while (i < n)
    {
        if(tmp_s1[i] != tmp_s2[i])
            return (tmp_s1[i] - tmp_s2[i]);
        i++;
    }
    return(tmp_s1[i] - tmp_s2[i]);
}