#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

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
	SORT
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

//≥ı ºªØ
void initContact(struct Contact* c);
void addContact(struct Contact* c);
void showContact(struct Contact* c);
void delContact(struct Contact* c);
void searchContact(struct Contact* c);
void modifyContact(struct Contact* c);