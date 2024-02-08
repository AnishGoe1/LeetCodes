#include<stdarg.h>
static
void str_cat(char** str, int* len, int* cap, const char format[], ...) {
	char buf[100];
	va_list args;
	va_start(args, format);
	int sz = vsprintf(buf, format, args);
	va_end(args);
	if (*len + sz + 1 >= *cap) {
		do {
			*cap = (*cap) ? *cap * 2 : 32;
		} while (*len + sz + 1 >= *cap);
		*str = realloc(*str, *cap);
	}
	memcpy(*str + *len, buf, sz + 1);
	*len += sz;
}
static
void tree_2_str_helper(struct TreeNode* root, char** str, int* len, int* cap) {
	str_cat(str, len, cap, "%d", root->val);
	if (root->right || root->left) {
		str_cat(str, len, cap, "(", root->val);
		if (root->left) {
			tree_2_str_helper(root->left, str, len, cap);
		}
		if (root->right) {
			str_cat(str, len, cap, ")(", root->val);
			tree_2_str_helper(root->right, str, len, cap);
		}
		str_cat(str, len, cap, ")");
	}
}
char * tree2str(struct TreeNode* root){
	char* ret = NULL;
	int len = 0;
	int cap = 0;
	tree_2_str_helper(root, &ret, &len, &cap);
	return ret;
}
