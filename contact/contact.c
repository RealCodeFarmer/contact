#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void initContact(struct Contact* c) {
	int i = 0;
	memset(c, 0, sizeof(c->peoInfos));
	c->size = 0;
}

void addContact(struct Contact* c) {
	if (MAX == c->size) {
		printf("通讯录已满");
	} else {
		printf("请输入姓名 :> ");
		scanf("%s", c->peoInfos[c->size].name);
		printf("请输入年龄 :> ");
		scanf("%d", &(c->peoInfos[c->size].age));
		printf("请输入性别 :> ");
		scanf("%s", c->peoInfos[c->size].sex);
		printf("请输入手机号 :> ");
		scanf("%s", c->peoInfos[c->size].tele);
		printf("请输入地址 :> ");
		scanf("%s", c->peoInfos[c->size].addr);

		c->size++;
	}
}

void showContact(struct Contact* c) {
	int i = 0;
	if (0 == c->size) {
		printf("通讯录为空\n");
	} else {
		printf("%-5s\t%-3s\t%-3s\t%-12s\t%-30s\n",
			"姓名", "年龄", "性别", "手机号", "地址");
		for (i = 0; i < c->size; i++) {
			printf("%-5s\t%-3d\t%-3s\t%-12s\t%-30s\n",
				c->peoInfos[i].name, c->peoInfos[i].age,
				c->peoInfos[i].sex, c->peoInfos[i].tele,
				c->peoInfos[i].addr);
		}
	}
}

int findByName(struct Contact* c, char* name) {
	//找到返回下标,找不到返回-1
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
	printf("请输入要删除的姓名 :>");
	scanf("%s", name);
	int ret = findByName(c, name);

	if (ret == -1) {
		printf("通讯录没有此人!\n");
	} else {
		//位置全部前置
		for (i = ret; i < (c->size) - 1; i++) {
			c->peoInfos[i] = c->peoInfos[i + 1];
		}

		c->size--;
	}
}

void searchContact(struct Contact* c) {
	int i = 0;
	char name[MAX_NAME];
	printf("请输入要查找的姓名 :>");
	scanf("%s", name);
	int ret = findByName(c, name);
	if (ret == -1) {
		printf("通讯录没有此人!\n");
	} else {
		printf("%-5s\t%-3s\t%-3s\t%-12s\t%-30s\n",
			"姓名", "年龄", "性别", "手机号", "地址");
		printf("%-5s\t%-3d\t%-3s\t%-12s\t%-30s\n",
			c->peoInfos[ret].name, c->peoInfos[ret].age,
			c->peoInfos[ret].sex, c->peoInfos[ret].tele,
			c->peoInfos[ret].addr);
	}
}

void modifyContact(struct Contact* c) {
	int i = 0;
	char name[MAX_NAME];
	printf("请输入要更改的姓名 :>");
	scanf("%s", name);
	int ret = findByName(c, name);
	if (ret == -1) {
		printf("通讯录没有此人!\n");
	} else {
		printf("请输入姓名 :> ");
		scanf("%s", c->peoInfos[ret].name);
		printf("请输入年龄 :> ");
		scanf("%d", &(c->peoInfos[ret].age));
		printf("请输入性别 :> ");
		scanf("%s", c->peoInfos[ret].sex);
		printf("请输入手机号 :> ");
		scanf("%s", c->peoInfos[ret].tele);
		printf("请输入地址 :> ");
		scanf("%s", c->peoInfos[ret].addr);
	}
}

void sortContact(struct Contact* c) {
	int i = 0;
	//struct PeoInfo* peos = (struct PoInfo*)malloc(c->size * sizeof(struct PeoInfo));
	struct PeoInfo* peos = (struct PoInfo*)malloc(c->size * sizeof(struct PeoInfo));
	//打印排序通讯录
	if (0 == c->size) {
		printf("通讯录为空\n");
	} else {
		peos = (struct PeoInfo*)memcpy(peos, c->peoInfos, c->size * sizeof(struct PeoInfo));
		//按照名字排序
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
			"姓名", "年龄", "性别", "手机号", "地址");
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