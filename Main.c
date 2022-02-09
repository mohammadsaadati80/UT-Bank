#include "Header.h"

int main() {
	Admin admin; /*sakhtare admin*/
	admin.adminname = "admin";
	admin.password = "123";
	admin.phonenumber = "00000000000";
	admin.next = NULL;

	Trans trans_head; /*sakhtare tarakoneshe head*/
	for (int i = 0;i < 16;i++) {
		trans_head.username[i] = '\0';
	}
	for (int i = 0;i < 30;i++) {
		trans_head.transacation_type[i] = '\0';
	}
	trans_head.transacation_amount = 0;
	trans_head.next = NULL;

	creating_user_information_linked_list(&admin);
	creating_user_transactions_linked_list(&trans_head);
	printf("\tUT Bank\n");
	check_the_order(&admin, &trans_head);

	{ /*zakhire linked list ha dar file ha*/
		FILE* user_inf;
		user_inf = fopen("user_information.txt", "w+");
		if (user_inf == NULL) {
			printf("Can not open the file 'user_information.txt' for writing the user information\n");
		}
		User* temp;
		temp = admin.next;
		while (temp != NULL) {
			fprintf(user_inf, "%s\n", temp->username);
			fprintf(user_inf, "%s\n", temp->password);
			fprintf(user_inf, "%s\n", temp->phonenumber);
			fprintf(user_inf, "%s\n", temp->unique_ID);
			fprintf(user_inf, "%f\n", temp->account_balance);
			fprintf(user_inf, "%d\n", temp->number_of_transactions);
			temp = temp->next;
		}
		fclose(user_inf);
		FILE* user_tran;
		user_tran = fopen("user_transactions.txt", "w+");
		if (user_tran == NULL) {
			printf("Can not open the file 'user_transactions.txt' for writing the user transactions\n");
		}
		Trans* temp2;
		temp2 = trans_head.next;
		while (temp2 != NULL) {
			fprintf(user_tran, "%s\n", temp2->username);
			fprintf(user_tran, "%s\n", temp2->transacation_type);
			fprintf(user_tran, "%f\n", temp2->transacation_amount);
			temp2 = temp2->next;
		}
		fclose(user_tran);
	}

	return 0;
}