#include "Header.h"

int transfer(char login_username[16], char username[16], float amount, Admin* admin, Trans* trans_head) { /*tabe tranfer az yek user be user digar*/
	User* temp;
	temp = admin->next;
	int transfer_status = 0; /*moteghayyer barresi vojoode user haye morede nazar baraye transfer  1 baraye vojood  0 baraye adame vojoode*/
	int sizeof_username = strlen(username); /*moteghayyer andaze toole username*/
	int sizeof_login_username = strlen(login_username); /*moteghayyer andaze toole login_username*/
	if (sizeof_username > 15) { /*barresi toole voroodi ha va namayeshe peyghame monaseb*/
		printf("The size of username that you entered is more than 15 character\n");
		return 0;
	}
	while (temp != NULL) {  /*halghe peyda kardane user login shode*/
		for (int i = 0;login_username[i] != '\0';i++) {
			if ((temp->username[i] == login_username[i]) && (sizeof_login_username == strlen(temp->username))) {
				transfer_status = 1;
				continue;
			}
			else {
				transfer_status = 0;
				break;
			}
		}
		if (transfer_status == 0) {
			temp = temp->next;
			continue;
		}
		if (transfer_status == 1) {
			if (temp->account_balance < amount) { /*barresi bozorgtar naboodane meghdare morede nazar baraye transfer az hesabe mabda*/
				printf("The amount you want for transfer is more than the account balance of user '%s'\n", login_username);
				break;
			}
		}
		User* temp2;
		temp2 = admin->next;
		while (temp2 != NULL) { /*halghe peyda kardane user morede nazar*/
			for (int i = 0;username[i] != '\0';i++) {
				if ((temp2->username[i] == username[i]) && (sizeof_username == strlen(temp2->username))) {
					transfer_status = 1;
					continue;
				}
				else {
					transfer_status = 0;
					break;
				}
			}
			if (transfer_status == 0) {
				temp2 = temp2->next;
				continue;
			}
			if (amount > 0) { /*barresi bozorgtar booden meghdar voroodi az 0*/
				if (transfer_status == 1) { /*ijade taghyirate morede nazar dar account user morede nazar*/
					temp2->account_balance += amount;
					temp2->number_of_transactions += 1;
					Trans* new_trans; /*ezafe kardane ettelaate tarakoneshe jadid be linked list tarakonesh ha*/
					new_trans = (Trans*)malloc(sizeof(Trans));
					for (int i = 0;i < sizeof_username;i++) {
						new_trans->username[i] = username[i];
					}
					for (int i = sizeof_username;i < 16;i++) {
						new_trans->username[i] = '\0';
					}
					char type[14] = "transfer_from_";
					for (int i = 0;i < 14;i++) {
						new_trans->transacation_type[i] = type[i];
					}
					for (int i = 14, j = 0;j < sizeof_login_username;j++, i++) {
						new_trans->transacation_type[i] = login_username[j];
					}
					for (int i = (sizeof_login_username + 14);i < 30;i++) {
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


		if ((amount > 0) && transfer_status == 1) { /*barresi bozorgtar booden meghdar voroodi az 0*/
			if (transfer_status == 1) { /*ijade taghyirate morede nazar dar account user morede nazar*/
				temp->account_balance -= amount;
				temp->number_of_transactions += 1;
				printf("The amount successfully transfer from user '%s' to user '%s'\n", login_username, username);
				Trans* new_trans1; /*ezafe kardane ettelaate tarakoneshe jadid be linked list tarakonesh ha*/
				new_trans1 = (Trans*)malloc(sizeof(Trans));
				for (int i = 0;i < sizeof_login_username;i++) {
					new_trans1->username[i] = login_username[i];
				}
				for (int i = sizeof_login_username;i < 16;i++) {
					new_trans1->username[i] = '\0';
				}
				char type1[14] = "transfer_to_";
				for (int i = 0;i < 12;i++) {
					new_trans1->transacation_type[i] = type1[i];
				}
				for (int i = 12, j = 0;j < sizeof_username;j++, i++) {
					new_trans1->transacation_type[i] = username[j];
				}
				for (int i = (sizeof_username + 12);i < 30;i++) {
					new_trans1->transacation_type[i] = '\0';
				}
				new_trans1->transacation_amount = amount;
				new_trans1->next = trans_head->next;
				trans_head->next = new_trans1;
				break;
			}
		}
		else {
			break;
		}
	}
	if (transfer_status == 0) {
		printf("We don't have any user with this username you entered for transfer\n");
	}
	return 0;
}