#include "Header.h"

int deposit(char username[16], float amount, Admin* admin, Trans* trans_head) { /*tabe variz be hesab*/
	User* temp;
	temp = admin->next;
	int deposit_status = 0; /*moteghayyer barresi vojoode user morede nazar baraye variz  1 baraye vojood  0 baraye adame vojoode*/
	int sizeof_username = strlen(username); /*moteghayyer andaze toole username*/
	if (sizeof_username > 15) { /*barresi toole voroodi ha va namayeshe peyghame monaseb*/
		printf("The size of username that you entered is more than 15 character\n");
		return 0;
	}
	while (temp != NULL) { /*halghe peyda kardane user morede nazar*/
		for (int i = 0;username[i] != '\0';i++) {
			if ((temp->username[i] == username[i]) && (sizeof_username == strlen(temp->username))) {
				deposit_status = 1;
				continue;
			}
			else {
				deposit_status = 0;
				break;
			}
		}
		if (deposit_status == 0) {
			temp = temp->next;
			continue;
		}
		if (amount > 0) { /*barresi bozorgtar booden meghdar voroodi az 0*/
			if (deposit_status == 1) { /*ijade taghyirate morede nazar dar account user morede nazar*/
				temp->account_balance += amount;
				temp->number_of_transactions += 1;
				printf("The amount successfully added to account balance of user '%s'\n", username);
				Trans* new_trans; /*ezafe kardane ettelaate tarakoneshe jadid be linked list tarakonesh ha*/
				new_trans = (Trans*)malloc(sizeof(Trans));
				for (int i = 0;i < sizeof_username;i++) {
					new_trans->username[i] = username[i];
				}
				for (int i = sizeof_username;i < 16;i++) {
					new_trans->username[i] = '\0';
				}
				char type[7] = "deposit";
				for (int i = 0;i < 7;i++) {
					new_trans->transacation_type[i] = type[i];
				}
				for (int i = 7;i < 30;i++) {
					new_trans->transacation_type[i] = '\0';
				}
				new_trans->transacation_amount = amount;
				new_trans->next = trans_head->next;
				trans_head->next = new_trans;
				break;
			}
		}
		else {
			printf("The amount you want for deposit isn't more than 0\n");
			break;
		}
	}
	if (deposit_status == 0) {
		printf("We don't have any user with this username you entered for deposit\n");
	}
	return 0;
}