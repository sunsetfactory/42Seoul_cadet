int ft_isalpha (int n){
    if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
        return (1);
    else
        return (0);
}