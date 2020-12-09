#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include <stdbool.h>
#include <stdio.h>
#include "ContactQueue.h"
#include "Contact.h"

void printCommands() {
	printf("Commands:\n");
	printf("\t0 - Exit from program\n");
	printf("\t1 - Print contacts in queue\n");
	printf("\t2 - Add contact to queue\n");
	printf("\t3 - Get contact from queue\n");
}

void startMenu() {
	bool flag = true;
	int n = 0;

	FILE* exFile;
	exFile = fopen("storage.txt", "r+");
	if (exFile == NULL) {
		exFile = fopen("storage.txt", "w+");
	}
	else {
		fscanf(exFile, "%d", &n);
	}
	
	struct Contact* rawContacts = (struct Contact*)malloc(n * sizeof(struct Contact));
	struct ContactQueue list = queueConstructor();

	int newContactsCount = 0;
	int newContactsSize = 5;
	struct Contact* newContacts = (struct Contact*)malloc(newContactsSize * sizeof(struct Contact));

	char tempName[30];
	char tempPhone[30];

	struct Contact* tempContact;

	for (int i = 0; i < n; i++) {
		
		fscanf(exFile, "%s", &tempName);
		fscanf(exFile, "\t%s", &tempPhone);
		rawContacts[i] = contactConstructor(tempName, tempPhone);
		enqueue(&list, (rawContacts + i));
	}
	while (flag) {
		printCommands();
		int command;
		scanf("%d", &command);
		switch (command) {
		case 0:
			flag = false;
			printf("goodbye");
			fclose(exFile);
			exFile = fopen("storage.txt", "w");
			fprintf(exFile, "%d\n", list.count);

			if (list.count > 0) {
				int curCount = list.count;
				for (int i = 0; i < curCount; i++) {
					tempContact = dequeue(&list);
					fprintf(exFile, "%s\n", tempContact->name);
					fprintf(exFile, "\t%s\n", tempContact->phone);
				}
			}
			fclose(exFile);
			break;

		case 1:
			print(&list);
			break;

		case 2:
			printf("Enter name: \n");
			scanf("%s", &tempName);
			printf("\n");
			printf("Enter phone: ");
			scanf("%s", &tempPhone);
			printf("\n");
			if (newContactsCount >= newContactsSize) {
				newContactsSize += 5;
				newContacts = (struct Contact*)realloc(newContactsSize * sizeof(struct Contact));
			}

			newContactsCount++;
			newContacts[newContactsCount - 1] = contactConstructor(tempName, tempPhone);
			enqueue(&list, (newContacts + newContactsCount - 1));
			break;

		case 3:
			tempContact = dequeue(&list);
			printf("\tyour contact: \n\t\t%s - %s\n", tempContact->name, tempContact->phone);
			break;

		default:
			printf("incorrect command\n\ttry again\n");
			break;
		}
	}
}