int ft_isdigit (int n){
    if (n >= '1' && n <= '9')
        return (1);
    else
        return (0);
}

int ft_isalpha (int n){
    if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
        return (1);
    else
        return (0);
}

int ft_isalnum (int n){
    if(ft_isalpha(n) || ft_isdigit(n))
        return (1);
    else
        return (0);
}