char* reorderSpaces(char* text) {
    char s[128], *o = s, *t = text, w = 0, p = 0, j = 0, g, r, i;
    for (int i = 0, f = 0 ; text[i] ; p += text[i++] == ' ')
        text[i] != ' ' && (w += i > 0 ? text[i - 1] == ' ' : !f++);
    for (g = --w ? p / w : 0, i = 0 ; t[i] ;)
        if (t[i] == ' ') {
            for (int z = 0 ; j > 0 && z < g && p ; s[j++] = ' ', p--, z++);
            while (t[i] && t[i] == ' ' && ++i);
        } else
            s[j++] = t[i++];
    while (p-- && (s[j++] = ' '));    
    while ((*t++ = *o++));
    return text;
}