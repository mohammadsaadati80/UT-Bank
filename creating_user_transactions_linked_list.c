#include "Header.h"

void creating_user_transactions_linked_list(Trans* trans_head) { /*tabe khandan ettelaat tarakonesh ha az file va zakhire dar linked list*/
	FILE* user_trans;
	user_trans = fopen("user_transactions.txt", "r");
	if (user_trans == NULL) {
		printf("Can not open the file 'user_transactions.txt' for reading the user transactions\n");
		return;
	}
	int fscanf_return = 1;
	Trans* temp;
	temp = (Trans*)malloc(sizeof(Trans));
	temp = trans_head;
	int count = 0;
	while (fscanf_return != -1) { /*halghe khandan az file va ijade node haye linked list*/
		char username[16];
		fscanf_return = fscanf(user_trans, "%s", username);
		if (fscanf_return == 1) {
			count++;
		}
		if ((count == 1) && (fscanf_return == 1)) {
			Trans* temp1;
			temp1 = (Trans*)malloc(sizeof(Trans));

			for (int i = 0;i < 16; i++) {
				temp1->username[i] = username[i];
			}

			char transacation_type[30];
			fscanf_return = fscanf(user_trans, "%s", transacation_type);
			for (int i = 0;i < 30; i++) {
				temp1->transacation_type[i] = transacation_type[i];
			}

			float transacation_amount;
			fscanf(user_trans, "%f", &transacation_amount);
			temp1->transacation_amount = transacation_amount;

			temp1->next = NULL;
			temp = temp1;
			trans_head->next = temp;
		}

		if ((count > 1) && (fscanf_return == 1)) {
			while (temp->next != NULL) {
				temp = temp->next;
			}
			Trans* temp2;
			temp2 = (Trans*)malloc(sizeof(Trans));

			for (int i = 0;i < 16; i++) {
				temp2->username[i] = username[i];
			}

			char transacation_type[30];
			fscanf_return = fscanf(user_trans, "%s", transacation_type);
			for (int i = 0;i < 30; i++) {
				temp2->transacation_type[i] = transacation_type[i];
			}

			float transacation_amount;
			fscanf(user_trans, "%f", &transacation_amount);
			temp2->transacation_amount = transacation_amount;

			temp2->next = NULL;
			temp->next = temp2;
		}
	}
	fclose(user_trans);
}