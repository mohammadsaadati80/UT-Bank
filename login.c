#include "Header.h"

int login(char username[16], char password[16], Admin* admin, int* login_status, char login_username[16]) { /*tabe login*/
	int sizeof_username = strlen(username); /*moteghayyer andaze toole username*/
	int sizeof_password = strlen(password); /*moteghayyer andaze toole password*/
	if ((sizeof_username > 15) || (sizeof_password > 15)) { /*barresi toole voroodi ha va namayeshe peyghame monaseb*/
		if (sizeof_username > 15) {
			printf("The size of username that you entered is more than 15 character\n");
		}
		if (sizeof_password > 15) {
			printf("The size of password that you entered is more than 15 character\n");
		}
		return 0;
	}
	if ((sizeof_username == 5) && (username[0] == 'a') && (username[1] == 'd') && (username[2] == 'm') && (username[3] == 'i') && (username[4] == 'n') && (sizeof_password == 3) && (password[0] == '1') && (password[1] == '2') && (password[2] == '3')) { /*barresi logindar halate admin*/
		*login_status = 1;
		printf("You are login as '%s'\n", username);
		return 0;
	}
	User* temp;
	temp = admin->next;
	int user_login_status = 0; /*moteghayyer barresi vojoode user morede nazar baraye login  1 baraye vojood  0 baraye adame vojoode*/
	while (temp != NULL) { /*halghe peyda kardane user morede nazar*/
		for (int i = 0;username[i] != '\0';i++) {
			if ((temp->username[i] == username[i]) && (sizeof_username == strlen(temp->username))) {
				user_login_status = 1;
				continue;
			}
			else {
				user_login_status = 0;
				break;
			}
		}
		if (user_login_status == 0) {
			temp = temp->next;
			continue;
		}
		for (int i = 0;password[i] != '\0';i++) {
			if ((temp->password[i] == password[i]) && (sizeof_password == strlen(temp->password))) {
				user_login_status = 1;
				continue;
			}
			else {
				user_login_status = 0;
				break;
			}
		}
		if (user_login_status == 1) { /*taghyire vazeiiate moteghayyer login_username*/
			*login_status = 2;
			user_login_status = 1;
			for (int i = 0;i < sizeof_username;i++) { 
				login_username[i] = temp->username[i];
			}
			for (int i = sizeof_username; i < 16;i++) {
				login_username[i] = '\0';
			}
			printf("You are login as user '%s'\n", username);
			break;
		}
		else {
			user_login_status = 0;
		}
		if (user_login_status == 0) {
			temp = temp->next;
			continue;
		}
	}
	if (user_login_status == 0) {
		printf("We don't have any user with this username and password you Entered\n");
	}
	return 0;
}