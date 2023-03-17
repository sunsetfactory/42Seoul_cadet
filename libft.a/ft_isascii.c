int ft_isascii (int n){
    if (0 <= n && n <= 127)
        return (1);
    else
        return (0);
}