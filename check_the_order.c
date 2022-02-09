#include "Header.h"

void check_the_order(Admin* admin, Trans* trans_head) { /*tabe barresi dastoor voroodi*/
	int login_status = 0; /*moteghayyer vazeiiate login  1 login admin  2 login user  0 bedoone login*/
	char order[9]; /*moteghayyer daryafte dastoor*/
	char login_username[16]; /*moteghayyer name user login*/
	while (1) { /*halghe barresi dastoor ha*/
		printf("\nPlease Enter your order\n");
		scanf("%s", order);
		if ((strlen(order) == 8) && (order[0] == 'a') && (order[1] == 'd') && (order[2] == 'd') && (order[3] == '_') && (order[4] == 'u') && (order[5] == 's') && (order[6] == 'e') && (order[7] == 'r')) { /*barresi halate add user*/
			if (login_status != 1) {
				printf("You aren't login as admin for this order\n");
			}
			else {
				char username[16];
				char password[16];
				char phonenumber[12];
				scanf(" %s", username);
				scanf(" %s", password);
				scanf(" %s", phonenumber);
				add_user(username, password, phonenumber, admin);
			}
		}
		else if ((strlen(order) == 5) && (order[0] == 'l') && (order[1] == 'o') && (order[2] == 'g') && (order[3] == 'i') && (order[4] == 'n')) { /*barresi halate login*/
			if (login_status != 0) {
				printf("You are login\nFor login with another user please logout\n");
			}
			else {
				char username[16];
				char password[16];
				scanf(" %s", username);
				scanf(" %s", password);
				login(username, password, admin, &login_status, login_username);
			}
		}
		else if ((strlen(order) == 6) && (order[0] == 'l') && (order[1] == 'o') && (order[2] == 'g') && (order[3] == 'o') && (order[4] == 'u') && (order[5] == 't')) { /*barresi halate logout*/
			if (login_status == 0) {
				printf("You aren't login as admin or any user for this order\n");
			}
			else {
				if (login_status == 1) {
					login_status = 0;
					printf("User 'admin' logout successfully \n");
				}
				if (login_status == 2) {
					login_status = 0;
					printf("User '%s' logout successfully \n", login_username);
				}
			}
		}
		else if ((strlen(order) == 7) && (order[0] == 'd') && (order[1] == 'e') && (order[2] == 'p') && (order[3] == 'o') && (order[4] == 's') && (order[5] == 'i') && (order[6] == 't')) { /*barresi halate deposit*/
			if (login_status != 1) { 
				printf("You aren't login as admin for this order\n");
			}
			else {
				char username[16];
				float amount;
				scanf(" %s", username);
				scanf(" %f", &amount);
				deposit(username, amount, admin, trans_head);
			}
		}
		else if ((strlen(order) == 4) && (order[0] == 'v') && (order[1] == 'i') && (order[2] == 'e') && (order[3] == 'w')) { /*barresi halate view*/
			if (login_status == 1) {
				char username[16];
				scanf(" %s", username);
				view(username, admin, trans_head);
			}
			else if (login_status == 2) {
				view(login_username, admin, trans_head);
			}
			else if (login_status == 0) {
				printf("You aren't login as admin or any user for this order\n");
			}
		}
		else if ((strlen(order) == 8) && (order[0] == 'w') && (order[1] == 'i') && (order[2] == 't') && (order[3] == 'h') && (order[4] == 'd') && (order[5] == 'r') && (order[6] == 'a') && (order[7] == 'w')) { /*barresi halate withdraw*/
			if (login_status != 1) {
				printf("You aren't login as admin for this order\n");
			}
			else {
				char username[16];
				float amount;
				scanf(" %s", username);
				scanf(" %f", &amount);
				withdraw(username, amount, admin, trans_head);
			}
		}
		else if ((strlen(order) == 8) && (order[0] == 't') && (order[1] == 'r') && (order[2] == 'a') && (order[3] == 'n') && (order[4] == 's') && (order[5] == 'f') && (order[6] == 'e') && (order[7] == 'r')) { /*barresi halate transfer*/
			if (login_status != 2) {
				printf("You aren't login as any user for this order\n");
			}
			else {
				char username[16];
				float amount;
				scanf(" %s", username);
				scanf(" %f", &amount);
				transfer(login_username, username, amount, admin, trans_head);
			}
		}
		else if ((strlen(order) == 6) && (order[0] == 'd') && (order[1] == 'e') && (order[2] == 'l') && (order[3] == 'e') && (order[4] == 't') && (order[5] == 'e')) { /*barresi halate delete*/
			if (login_status != 1) {
				printf("You aren't login as admin for this order\n");
			}
			else {
				char username[16];
				scanf(" %s", username);
				delete(username, admin, trans_head);
			}
		}
		else if ((strlen(order) == 4) && (order[0] == 'e') && (order[1] == 'x') && (order[2] == 'i') && (order[3] == 't')) { /*barresi halate exit*/
			break;
		}
		else {
			printf("Invalid order\n"); /*namayeshe peghame monaseb darsoorate ghabool naboodan dastoore voroodi */
		}
	}
}