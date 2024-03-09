char** split(const char* s, char delim, int* returnSize) {
	*returnSize = 0;
	const char* p = s;
	int startIndex = 0, endIndex = 0;
	char** res = (char**)malloc(sizeof(char*) * strlen(s));
	while (*p)
	{
		if (*p == delim)
		{
			if (endIndex - startIndex == 0)
			{
			}
			else
			{
				int len = endIndex - startIndex;
				res[*returnSize] = (char*)malloc(len+1);
		//char *strncpy(char *dest, const char *src, size_t n)
				strncpy(res[*returnSize],s+startIndex,len);
				res[*returnSize][len] = '\0';
				(*returnSize)++;
			}

			startIndex = endIndex+1;
		}
		endIndex++;
		p++;
	}

	if (endIndex - startIndex == 0)
	{
	}
	else
	{
		int len = endIndex - startIndex;
		res[*returnSize] = (char*)malloc(len + 1);
		//char *strncpy(char *dest, const char *src, size_t n)
		strncpy(res[*returnSize], s + startIndex, len);
		res[*returnSize][len] = '\0';
		(*returnSize)++;
	}

	return res;
}
//Input: path = "/../"
//Output : "/"
//Input: path = "/home//foo/"
//Output : "/home/foo"

//?
//   /a/../../b/../c//.//
char* simplifyPath(char* path) {
	int size = 0;
	char** names = split(path,'/',&size);
	char** stack = (char**)malloc(size*sizeof(char*));
	char* res = (char*)calloc(strlen(path)+1,sizeof(char));
	int stackIndex = 0;

	for (int i = 0; i < size; i++)
	{
		if (strcmp(names[i], ".") == 0 || strcmp(names[i], "") == 0)
			continue;
		if (strcmp(names[i], "..") == 0)
		{
			stackIndex--;
			if (stackIndex < 0)
				stackIndex = 0;
		}
		else
		{
			stack[stackIndex] = names[i];
			stackIndex++;
		}
	}

	int resIndex = 0;

	for (int i = 0; i < stackIndex; i++)
	{
		sprintf(res + resIndex, "/");
		resIndex++;
		sprintf(res + resIndex, stack[i]);
		resIndex += strlen(stack[i]);
	}

	free(names);
	free(stack);

	if (strcmp(res, "") == 0)
		res = "/";
	return res;
}
