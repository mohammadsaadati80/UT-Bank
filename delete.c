#include "Header.h"

int delete(char username[16], Admin* admin, Trans* trans_head) { /*tabe delete user*/
	int delete_status = 0; /*moteghayyer barresi vojoode user morede nazar baraye hazf  1 baraye vojood  0 baraye adame vojoode*/
	int sizeof_username = strlen(username); /*moteghayyer andaze toole username*/
	if (sizeof_username > 15) { /*barresi toole voroodi ha va namayeshe peyghame monaseb*/
		printf("The size of username that you entered is more than 15 character\n");
		return 0;
	}
	User* temp; /*node dar hale barresi*/
	temp = admin->next; 
	User* prev; /*node ghable node temp*/
	prev = admin->next;
	int count = 0; /*moteghayyer fahmidane chandomin node boodane node temp dar linked list user information*/
	while (temp != NULL) { /*halghe peyda kardane user morede nazar*/
		count++;
		for (int i = 0;username[i] != '\0';i++) {
			if ((temp->username[i] == username[i]) && (sizeof_username == strlen(temp->username))) {
				delete_status = 1;
				continue;
			}
			else {
				delete_status = 0;
				break;
			}
		}
		if (delete_status == 1) {
			break;
		}
		if (count == 1) {
			temp = temp->next;
		}
		else {
			temp = temp->next;
			prev = prev->next;
		}
	}
	if (delete_status == 0) {
		printf("We don't have any user with this username you entered for delete\n");
	}
	if (delete_status == 1) {
		if (count == 1) {
			admin->next = temp->next;
			free(temp); /*paak kardane ettelaate user az hafeze*/
			printf("The account of user '%s' successfully delete\n", username);
		}
		if (count > 1) {
			prev->next = temp->next;
			free(temp); /*paak kardane ettelaate user az hafeze*/
			printf("The account of user '%s' successfully delete\n", username);
		}
	}
	Trans* temp2; /*node dar hale barresi*/
	temp2 = trans_head->next;
	Trans* prev2; /*node ghable node temp2*/
	prev2 = trans_head;
	while (temp2 != NULL) { /*halghe peyda kardane tarakonesh haye user morede nazar*/
		for (int i = 0;username[i] != '\0';i++) {
			if ((temp2->username[i] == username[i]) && (sizeof_username == strlen(temp2->username))) {
				delete_status = 1;
				continue;
			}
			else {
				delete_status = 0;
				break;
			}
		}
		if (delete_status == 0) {
			temp2 = temp2->next;
			prev2 = prev2->next;
			continue;
		}
		if (delete_status == 1) {
			prev2->next = temp2->next;
			free(temp2); /*paak kardane ettelaate user az hafeze*/
			temp2 = trans_head->next;
			prev2 = trans_head;
		}
	}
	return 0;
}