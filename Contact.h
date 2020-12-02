#ifndef PERSON
#define PERSON

struct Contact{
	char name[30];
	char phone[30];
};

struct Contact contactConstructor(char name[30], char phone[30]);
#endif