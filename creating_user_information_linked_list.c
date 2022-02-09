#include "Header.h"

void creating_user_information_linked_list(Admin* admin) { /*tabe khandan ettelaat user ha az file va zakhire dar linked list*/
	FILE* user_info;
	user_info = fopen("user_information.txt", "r");
	if (user_info == NULL) {
		printf("Can not open the file 'user_information.txt' for reading user information\n");
		return;
	}
	int fscanf_return = 1;
	User* temp;
	temp = (User*)malloc(sizeof(User));
	int count = 0;
	while (fscanf_return != -1) { /*halghe khandan az file va ijade node haye linked list*/
		char username[16];
		fscanf_return = fscanf(user_info, "%s", username);
		if (fscanf_return == 1) {
			count++;
		}
		if ((count == 1) && (fscanf_return == 1)) {
			User* user;
			user = (User*)malloc(sizeof(User));

			for (int i = 0;i < 16; i++) {
				user->username[i] = username[i];
			}

			char password[16];
			fscanf(user_info, "%s", password);
			for (int i = 0;i < 16; i++) {
				user->password[i] = password[i];
			}

			char phonenumber[12];
			fscanf(user_info, "%s", phonenumber);
			for (int i = 0;i < 12; i++) {
				user->phonenumber[i] = phonenumber[i];
			}

			char unique_ID[27];
			fscanf(user_info, "%s", unique_ID);
			for (int i = 0;i < 27; i++) {
				user->unique_ID[i] = unique_ID[i];
			}

			float account_balance;
			fscanf(user_info, "%f", &account_balance);
			user->account_balance = account_balance;

			int number_of_transactions;
			fscanf(user_info, "%d", &number_of_transactions);
			user->number_of_transactions = number_of_transactions;

			user->next = NULL;
			temp = user;
			admin->next = temp;
		}

		if ((count > 1) && (fscanf_return == 1)) {
			while (temp->next != NULL) {
				temp = temp->next;
			}
			User* user2;
			user2 = (User*)malloc(sizeof(User));

			for (int i = 0;i < 16; i++) {
				user2->username[i] = username[i];
			}

			char password[16];
			fscanf(user_info, "%s", password);
			for (int i = 0;i < 16; i++) {
				user2->password[i] = password[i];
			}

			char phonenumber[12];
			fscanf(user_info, "%s", phonenumber);
			for (int i = 0;i < 12; i++) {
				user2->phonenumber[i] = phonenumber[i];
			}

			char unique_ID[27];
			fscanf(user_info, "%s", unique_ID);
			for (int i = 0;i < 27; i++) {
				user2->unique_ID[i] = unique_ID[i];
			}

			float account_balance;
			fscanf(user_info, "%f", &account_balance);
			user2->account_balance = account_balance;

			int number_of_transactions;
			fscanf(user_info, "%d", &number_of_transactions);
			user2->number_of_transactions = number_of_transactions;
			user2->next = NULL;
			temp->next = user2;
		}
		
	}
	fclose(user_info);
}