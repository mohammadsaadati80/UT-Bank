#include "Header.h"

int view(char username[16], Admin* admin, Trans* trans_head) { /* tabe namayeshe attelaat user*/
	User* temp;
	temp = admin->next;
	int view_status = 0; /*moteghayyer barresi vojoode user morede nazar baraye view  1 baraye vojood  0 baraye adame vojoode*/
	int sizeof_username = strlen(username); /*moteghayyer andaze toole username*/
	if (sizeof_username > 15) { /*barresi toole voroodi ha va namayeshe peyghame monaseb*/
		printf("The size of username that you entered is more than 15 character\n");
		return 0;
	}
	while (temp != NULL) { /*halghe peyda kardane user morede nazar*/
		for (int i = 0;username[i] != '\0';i++) {
			if ((temp->username[i] == username[i]) && (sizeof_username == strlen(temp->username))) {
				view_status = 1;
				continue;
			}
			else {
				view_status = 0;
				break;
			}
		}
		if (view_status == 0) {
			temp = temp->next;
			continue;
		}
		if (view_status == 1) { /*namayeshe ettelaate account user morede nazar*/
			printf("\nThe unique_ID of user '%s' is: %s\n", username, temp->unique_ID);
			printf("The username of user '%s' is: %s\n", username, temp->username);
			printf("The phonenumber of user '%s' is: %s\n", username, temp->phonenumber);
			printf("The account balance of user '%s' is: %f\n", username, temp->account_balance);
			printf("The number of transactions of user '%s' is: %d\n", username, temp->number_of_transactions);
			Trans* temp2;
			temp2 = trans_head;
			while (temp2 != NULL) { /*halghe peyda kardane ettelaate tarakonesh haye user morede nazar*/
				int view_trens = 0;
				for (int i = 0;username[i] != '\0';i++) {
					if ((temp2->username[i] == username[i]) && (sizeof_username == strlen(temp2->username))) {
						view_trens = 1;
						continue;
					}
					else {
						view_trens = 0;
						break;
					}
				}
				if (view_trens == 1) { /*namayeshe ettelaate tarakonesh haye user morede nazar*/
					printf("The transacation type is: %s", temp2->transacation_type);
					printf(" & the transacation amount is: %f\n", temp2->transacation_amount);
				}
				temp2 = temp2->next;
			}
			break;
		}
	}
	if (view_status == 0) {
		printf("We don't have any user with this username you entered for showing the details of it's account\n");
	}
	return 0;
}