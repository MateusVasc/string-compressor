#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* compress_string(char* word)
{
	int word_size = strlen(word);
	char* compressed = (char*)(malloc(2 * word_size));
	int compressed_i = 0;

	for(int i = 0; i < word_size;)
	{
		char curr = word[i];
		int count = 1;

		while(i + 1 < word_size && word[i] == word[i + 1])
		{
			count++;
			i++;
		}

		compressed[compressed_i++] = curr;
		compressed[compressed_i++] = count + '0'; // converte para char
		
		i++;
	}

	compressed[compressed_i] = '\0';
	return compressed;
}

void get_user_input()
{
	char word[256];
	printf("Input a string to be compressed: ");
	fgets(word, 256, stdin);

	word[strcspn(word, "\n")] = '\0';

	char* compressed_word = compress_string(word);
	printf("Compressed string: %s\n", compressed_word);

	free(compressed_word);
}

int main()
{
	get_user_input();
	return 0;
}
