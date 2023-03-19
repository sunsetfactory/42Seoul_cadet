size_t strlcpy(char * dst, const char * src, size_t dstsize)
{
	size_t i;
    	i = 0;
   	while (i + 1 < dstsize && src[i] != '\0')
       {
       	dst[i] = src[i];
       	i++;
   	}
   	dst[i] = '\0';
   	while (str[i] != '\0')
   	    i++;
 	return (i);
}