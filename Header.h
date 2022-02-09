#pragma once
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct user_information User; /*ijade taype jadid user*/
typedef struct user_transactions Trans; /* ijade taype jadid tarakoneshha*/
typedef struct admin Admin; /*ijade taype jadid admin*/

int delete(char username[16], Admin* admin, Trans* trans_head); /*tabe delete user*/
int transfer(char login_username[16], char username[16], float amount, Admin* admin, Trans* trans_head); /*tabe tranfer az yek user be user digar*/
int withdraw(char username[16], float amount, Admin* admin, Trans* trans_head); /*tabe bardasht az hesab*/
int view(char username[16], Admin* admin, Trans* trans_head); /* tabe namayeshe attelaat user*/
int deposit(char username[16], float amount, Admin* admin, Trans* trans_head); /*tabe variz be hesab*/
int login(char username[16], char password[16], Admin* admin, int* login_status, char login_username[16]); /*tabe login*/
int add_user(char username[16], char password[16], char phonenumber[12], Admin* admin); /*tabe ijad user jadid*/
void check_the_order(Admin* admin, Trans* trans_head); /*tabe barresi dastoor voroodi*/
void creating_user_information_linked_list(Admin* admin); /*tabe khandan ettelaat user ha az file va zakhire dar linked list*/
void creating_user_transactions_linked_list(Trans* trans_head); /*tabe khandan ettelaat tarakonesh ha az file va zakhire dar linked list*/

struct user_information { /*sakhtare ettelaat user ha*/
	char username[16];
	char password[16];
	char phonenumber[12];
	char unique_ID[27];
	float account_balance;
	int number_of_transactions;
	User* next;
};

struct user_transactions { /*sakhtare ettelaat tarakonesh ha*/
	char username[16];
	char transacation_type[30];
	float transacation_amount;
	Trans* next;
};

struct admin { /*sakhtare admin*/
	char* adminname;
	char* password;
	char* phonenumber;
	User* next;
};
