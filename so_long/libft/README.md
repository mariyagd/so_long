# libft

##`ft_atoi()`

skips non-printable caracters like:
- `\t`	9  TAB			(horizontal tab)
- '\n'	10  NL  		(new line)
- '\v	11  VT  		(vertical tab)
- '\f'	12  FF ou NP	(new page from feed or new page)
- '\r'	13  CR  		(carriage return)  
- ' '	32  SP			(space)

Accept only one sign '-' or '+'.

## ```size_t ft_strcspn(const char *s, const char *reject)```

If a caracter from `s' can be found in `set`, returns the size of the longest sub-string of `s` that does not conain any caracter from `set`.

## ```char	*ft_strpbrk(const char *s1, const char *s2)```

Locates in the null-terminated string s the first occurrence of any character in the string charset and returns a pointer to this character. 
If no characters from charset occur anywhere in s strpbrk() returns NULL.

