#include <fisher_yates.h>

void fisher_yates_shuffle(void *array, size_t size, size_t nmemb) {
	// https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
	for(uint32_t i = nmemb - 1; i > 0; --i) {
		const uint32_t j = rand() % (i + 1);
		// swap list[i], list[j]
		void *temp = malloc(size);
		if(temp == NULL) {
			perror("Fatal error");
			return;
		}
		memcpy(temp, array + i * size, size); 				// temp = a[i]
		memcpy(array + i * size, array + j * size, size);	// a[i] = a[j]
		memcpy(array + j * size, temp, size);				// a[j] = temp
		free(temp);
	}
}