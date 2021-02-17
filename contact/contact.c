#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void initContact(struct Contact* c) {
	int i = 0;
	memset(c, 0, sizeof(c->peoInfos));
	c->size = 0;
}

void addContact(struct Contact* c) {
	if (MAX == c->size) {
		printf("ͨѶ¼����");
	} else {
		printf("���������� :> ");
		scanf("%s", c->peoInfos[c->size].name);
		printf("���������� :> ");
		scanf("%d", &(c->peoInfos[c->size].age));
		printf("�������Ա� :> ");
		scanf("%s", c->peoInfos[c->size].sex);
		printf("�������ֻ��� :> ");
		scanf("%s", c->peoInfos[c->size].tele);
		printf("�������ַ :> ");
		scanf("%s", c->peoInfos[c->size].addr);

		c->size++;
	}
}

void showContact(struct Contact* c) {
	int i = 0;
	if (0 == c->size) {
		printf("ͨѶ¼Ϊ��\n");
	} else {
		printf("%-5s\t%-3s\t%-3s\t%-12s\t%-30s\n",
			"����", "����", "�Ա�", "�ֻ���", "��ַ");
		for (i = 0; i < c->size; i++) {
			printf("%-5s\t%-3d\t%-3s\t%-12s\t%-30s\n",
				c->peoInfos[i].name, c->peoInfos[i].age,
				c->peoInfos[i].sex, c->peoInfos[i].tele,
				c->peoInfos[i].addr);
		}
	}
}

int findByName(struct Contact* c, char* name) {
	//�ҵ������±�,�Ҳ�������-1
	int i = 0;
	for (i = 0; i < c->size; i++) {
		if (!strcmp(c->peoInfos[i].name, name)) {
			return i;
		}
	}
	return -1;
}

void delContact(struct Contact* c) {
	int i = 0;
	char name[MAX_NAME];
	printf("������Ҫɾ�������� :>");
	scanf("%s", name);
	int ret = findByName(c, name);

	if (ret == -1) {
		printf("ͨѶ¼û�д���!\n");
	} else {
		//λ��ȫ��ǰ��
		for (i = ret; i < (c->size) - 1; i++) {
			c->peoInfos[i] = c->peoInfos[i + 1];
		}

		c->size--;
	}
}

void searchContact(struct Contact* c) {
	int i = 0;
	char name[MAX_NAME];
	printf("������Ҫ���ҵ����� :>");
	scanf("%s", name);
	int ret = findByName(c, name);
	if (ret == -1) {
		printf("ͨѶ¼û�д���!\n");
	} else {
		printf("%-5s\t%-3s\t%-3s\t%-12s\t%-30s\n",
			"����", "����", "�Ա�", "�ֻ���", "��ַ");
		printf("%-5s\t%-3d\t%-3s\t%-12s\t%-30s\n",
			c->peoInfos[ret].name, c->peoInfos[ret].age,
			c->peoInfos[ret].sex, c->peoInfos[ret].tele,
			c->peoInfos[ret].addr);
	}
}

void modifyContact(struct Contact* c) {
	int i = 0;
	char name[MAX_NAME];
	printf("������Ҫ���ĵ����� :>");
	scanf("%s", name);
	int ret = findByName(c, name);
	if (ret == -1) {
		printf("ͨѶ¼û�д���!\n");
	} else {
		printf("���������� :> ");
		scanf("%s", c->peoInfos[ret].name);
		printf("���������� :> ");
		scanf("%d", &(c->peoInfos[ret].age));
		printf("�������Ա� :> ");
		scanf("%s", c->peoInfos[ret].sex);
		printf("�������ֻ��� :> ");
		scanf("%s", c->peoInfos[ret].tele);
		printf("�������ַ :> ");
		scanf("%s", c->peoInfos[ret].addr);
	}
}

void sortContact(struct Contact* c) {
	int i = 0;
	//struct PeoInfo* peos = (struct PoInfo*)malloc(c->size * sizeof(struct PeoInfo));
	struct PeoInfo* peos = (struct PoInfo*)malloc(c->size * sizeof(struct PeoInfo));
	//��ӡ����ͨѶ¼
	if (0 == c->size) {
		printf("ͨѶ¼Ϊ��\n");
	} else {
		peos = (struct PeoInfo*)memcpy(peos, c->peoInfos, c->size * sizeof(struct PeoInfo));
		//������������
		for (i = 0; i < c->size - 1; i++) {
			int j = 0;
			for (j = 0; j < c->size - 1 - i; j++) {
				if (strcmp(peos[j].name, peos[j + 1].name) > 0) {
					struct PeoInfo tmp = peos[j + 1];
					peos[j + 1] = peos[j];
					peos[j] = tmp;
				}
			}
		}
		printf("%-5s\t%-3s\t%-3s\t%-12s\t%-30s\n",
			"����", "����", "�Ա�", "�ֻ���", "��ַ");
		for (i = 0; i < c->size; i++) {
			printf("%-5s\t%-3d\t%-3s\t%-12s\t%-30s\n",
				peos[i].name, peos[i].age,
				peos[i].sex, peos[i].tele,
				peos[i].addr);
		}
	}
	free(peos);
	peos = NULL;
}