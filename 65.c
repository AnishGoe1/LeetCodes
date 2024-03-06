bool isNumber(char *s) {
    bool num = false, exp = false, sign = false, dec = false;

    for (int i = 0; i < strlen(s); i++) {
        char c = s[i];

        /* is digit? */
        if (c >= '0' && c <= '9') {
            num = true;
        /* check for e */
        } else if (c == 'e' || c == 'E') {
            if (exp || !num) {
                return false;
            } else {
                /* we're parsing a new integer expression */
                exp = true, sign = false, num = false, dec = false;
            }
        /* check for sign */    
        } else if (c == '+' || c == '-') {
            /* we already parsed signed, or some number */
            if (sign || num || dec) {
                return false;
            } else {
                sign = true;
            }
        }
        /* check for decimal */
        else if (c == '.') {
            if (dec || exp) {
                return false;
            } else {
                dec = true;
            }
        /* something else */ 
        } else {
            return false;
        }
    }

    return num;    
}
