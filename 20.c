bool isValid(char* s) {
    int l;
    char *stack, c;
    int sp = 0;

    // Check if the input string is empty or null, indicating a valid expression.
    if (!s || !*s) return true;

    // Calculate the length of the input string.
    l = strlen(s);

    // Allocate memory for the stack based on the length of the string.
    stack = malloc(l * sizeof(char));

    // Iterate through each character in the string.
    while (c = *s++) {
        switch (c) {
            // If an opening parenthesis is encountered, push it onto the stack.
            case '(':
            case '{':
            case '[':
                stack[sp++] = c;
                break;
            // If a closing parenthesis is encountered, check the corresponding opening parenthesis on the stack.
            case ')':
                if (sp == 0 || stack[--sp] != '(') { free(stack); return false; }
                break;
            case '}':
                if (sp == 0 || stack[--sp] != '{') { free(stack); return false; }
                break;
            case ']':
                if (sp == 0 || stack[--sp] != '[') { free(stack); return false; }
                break;
            default:
                break;
        }
    }

    // Free the memory allocated for the stack.
    free(stack);

    // If the stack is empty, the expression is valid; otherwise, it is not.
    return sp == 0 ? true : false;
}
