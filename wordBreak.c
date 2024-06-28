#include <stdio.h>
#include <string.h>

char * killFirst(char ** dict, char * in, int len) {
	char * start = in;	
	char * word;
	
	for (int i = 0; i < len; i++) {
		word = strstr(in,dict[i]);
		if (word == start) {
			start = start+strlen(dict[i]);
			break;
		}
	}

	printf("Nice:%s\n",start);
	return start;

}

int main() {

	char * wordDict [] = {"apple", "pen"};	
	char * input = "applependinguspenapple";
	char * next = input;

	//do this until it stops updating
	while (1) {
		next = killFirst(wordDict, input, 2);
		if (strlen(next) == 0) {
			printf("True\n");
			break;
		}
		if (input == next) {
			printf("Failiure\n");
			break;
		}
		input = next;
	} 

	return 1;
}
