#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu() {
	printf("*****************************************************\n");
	printf("*****1. add                       2. del      *******\n");
	printf("*****3. search                    4. modify   *******\n");
	printf("*****5. show                      6. sort     *******\n");
	printf("*****7.save                       0. exit     *******\n");
	printf("*****************************************************\n");
}

int main(void) {
	int input = 0;
	//可以写成动态内存版本
	struct Contact c;
	//初始化
	initContact(&c);
	do {
		menu();
		printf("请选择 :> ");
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
				sortContact(&c);
				break;
			case SAVE:
				saveContact(&c);
				break;
			case EXIT:
				//退出的时候也保存一下
				saveContact(&c);
				printf("退出通讯录!\n");
				break;
			default:
				printf("选择错误,请重新输入!\n");
				break;
		}
	} while (input);
	return 0;
}