#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu() {
	printf("*****************************************************\n");
	printf("*****1. add                       2. del      *******\n");
	printf("*****3. search                    4. modify   *******\n");
	printf("*****5. show                      6. sort     *******\n");
	printf("*****0. exit                                  *******\n");
	printf("*****************************************************\n");
}

int main(void) {
	int input = 0;
	struct Contact c;
	//³õÊ¼»¯
	initContact(&c);
	do {
		menu();
		printf("ÇëÑ¡Ôñ :> ");
		scanf("%d", &input);
		switch (input) {
			case ADD:
				addContact(&c);
				break;
			case DEL:
				delContact(&c);
				break;
			case SEARCH:
				searchContact(&c);
				break;
			case MODIFY:
				modifyContact(&c);
				break;
			case SHOW:
				showContact(&c);
				break;
			case SORT:
				break;
			case EXIT:
				break;
			default:
				break;
		}
	} while (input);
	return 0;
}