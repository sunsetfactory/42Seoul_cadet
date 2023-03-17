int ft_isprint (int n){
    if (32 <= n && n <= 126)
        return (1);
    else
        return (0);
}