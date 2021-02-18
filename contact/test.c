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
	//����д�ɶ�̬�ڴ�汾
	struct Contact c;
	//��ʼ��
	initContact(&c);
	do {
		menu();
		printf("��ѡ�� :> ");
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
				//�˳���ʱ��Ҳ����һ��
				saveContact(&c);
				printf("�˳�ͨѶ¼!\n");
				break;
			default:
				printf("ѡ�����,����������!\n");
				break;
		}
	} while (input);
	return 0;
}