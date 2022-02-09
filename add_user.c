#include "Header.h"

int add_user(char username[16], char password[16], char phonenumber[12], Admin* admin) { /*tabe ijad user jadid*/
	int duplicate_user = 0; /*moteghayyer peyda kardan user tekrari  1 baraye tekrari boodan  0 baraye tekrari nabodan*/
	int sizeof_username = strlen(username); /*moteghayyer andaze toole username*/
	int sizeof_password = strlen(password); /*moteghayyer andaze toole password*/
	int sizeof_phonenumber = strlen(phonenumber); /*moteghayyer andaze toole phonenumber*/
	if ((sizeof_username > 15) || (sizeof_password > 15) || (sizeof_phonenumber > 11)) { /*barresi toole voroodi ha va namayeshe peyghame monaseb*/
		if (sizeof_username > 15) {
			printf("The size of username that you entered is more than 15 character\n");
		}
		if (sizeof_password > 15) {
			printf("The size of password that you entered is more than 15 character\n");
		}
		if (sizeof_phonenumber > 11) {
			printf("The size of phonenumber that you entered is more than 11 character\n");
		}
		return 0;
	}
	User* temp;
	temp = admin->next;
	while (temp != NULL) { /*barresi tekrari naboodan username va phonenumber voroodi*/
		for (int i = 0;i < 16;i++) {
			if (temp->username[i] == username[i]) {
				duplicate_user = 1;
				continue;
			}
			else {
				duplicate_user = 0;
				break;
			}
		}
		if (duplicate_user == 1) {
			break;
		}
		for (int i = 0;i < 12; i++) {
			if (temp->phonenumber[i] == phonenumber[i]) {
				duplicate_user = 1;
				continue;
			}
			else {
				duplicate_user = 0;
				break;
			}
		}
		if (duplicate_user == 1) {
			break;
		}
		temp = temp->next;
	}
	if (duplicate_user == 0) { /*ijade user jadid*/
		User* new_user;
		new_user = (User*)malloc(sizeof(User));

		for (int i = 0;i < sizeof_username; i++) {
			new_user->username[i] = username[i];
		}
		for (int i = sizeof_username;i < 16; i++) {
			new_user->username[i] = '\0';
		}
		for (int i = 0; i < sizeof_phonenumber; i++) {
			new_user->phonenumber[i] = phonenumber[i];
		}
		for (int i = sizeof_phonenumber; i < 12; i++) {
			new_user->phonenumber[i] = '\0';
		}
		for (int i = 0;i < sizeof_username;i++) {
			new_user->unique_ID[i] = username[i];
		}
		for (int i = sizeof_username, j = 0; i < (sizeof_username + 12);i++, j++) {
			new_user->unique_ID[i] = phonenumber[j];
		}
		for (int i = (sizeof_username + 12), j = 0; i < 27;i++, j++) {
			new_user->unique_ID[i] = '\0';
		}
		for (int i = 0;i < sizeof_password; i++) {
			new_user->password[i] = password[i];
		}
		for (int i = sizeof_password;i < 16; i++) {
			new_user->password[i] = '\0';
		}
		new_user->account_balance = 0;
		new_user->number_of_transactions = 0;
		new_user->next = admin->next; /*ezafe kardane user jadid be linked list*/
		admin->next = new_user;
		printf("The user '%s' successfully added\n", username);
	}
	if (duplicate_user == 1) { /*namayeshe peghame monaseb dar soorate tekrari boodan mavarede voroodi*/
		printf("The user already exists\n");
	}
	return 0;
}