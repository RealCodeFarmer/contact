#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30

enum Option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT,
	SAVE
};

struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

struct Contact {
	struct PeoInfo peoInfos[MAX];
	int size;
};

//初始化
void initContact(struct Contact* c);
//添加
void addContact(struct Contact* c);
//展示
void showContact(struct Contact* c);
//删除
void delContact(struct Contact* c);
//搜索
void searchContact(struct Contact* c);
//更改
void modifyContact(struct Contact* c);
//排序
void sortContact(struct Contact* c);
//保存
void saveContact(struct Contact* c);