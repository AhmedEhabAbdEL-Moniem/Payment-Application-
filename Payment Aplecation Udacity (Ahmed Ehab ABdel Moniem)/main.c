#include <stdio.h>
#include <stdlib.h>
#include "App.h"
extern struct_accountes[ACC_SIZE];
extern struct_transdata[ACC_SIZE];
int main ()
{
	ST_cardData_t* ptr_card = (ST_cardData_t*)malloc(sizeof(ST_cardData_t));
	ST_terminalData_t* ptr_term = (ST_terminalData_t*)malloc(sizeof(ST_terminalData_t));

	if (isAmountAvailable(ptr_term) == OK_CARD)
	{
		printf("OK, transaction is done");
	}
	else 
	{
		printf("LOW BALANCE");
	}
	return 0;
}





















	/*
	if (getTransactionAmount(ptr_term) == INVALID_AMOUNT)
	{
		printf("INVALID_AMOUNT\n");
	}
	else
	{
		printf("ok\n");
	}
	if (setMaxAmount(ptr_term) == INVALID_MAX_AMOUNT)
	{
		printf("INVALID_MAX_AMOUNT\n");
	}
	else
	{
		printf("ok\n");
	}
	if (isBelowMaxAmount(ptr_term) == EXCEED_MAX_AMOUNT)
	{
		printf("EXCEED_MAX_AMOUNT\n");
	}
	else
	{
		printf("transaction amount is below max amount, ok\n");
	}*/




	/*if (getCardExpiryDate(ptr_card) == WRONG_EXP_DATE)
	{
		printf("worng card date\n");
	}
	else
	{
		printf("ok_card\n");
	}

	if (getTransactionDate(ptr_term) == WRONG_DATE)
	{
		printf("worng term date\n");
	}
	else
	{
		printf("ok_terminal\n");
	}
	
	ST_cardData_t  struct_card;
	ST_terminalData_t  struct_term;
	uint8_t card_len, term_len;
	card_len = strlen(ptr_card->cardExpirationDate);
	term_len = strlen(ptr_term->transactionDate);
	for (int i = 0; i < card_len; i++)
	{
		struct_card.cardExpirationDate[i] = ptr_card->cardExpirationDate[i];
	}
	for (int i = 0; i < term_len; i++)
	{
		struct_term.transactionDate[i] = ptr_term->transactionDate[i];
	}

	if (isCardExpired(struct_card,struct_term) == EXPIRED_CARD)
	{
		printf("card date expired\n");
	}
	else
	{
		printf("card ok \n");
	}*/
