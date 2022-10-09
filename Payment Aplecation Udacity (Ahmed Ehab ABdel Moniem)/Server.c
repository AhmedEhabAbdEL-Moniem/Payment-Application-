/*server.c*/

/***************_INCLUDES_**************/

#include "Server.h"
#include <stdio.h>
/***************_GLOBAL_VAR_**************/

ST_accountsDB_t struct_accountes[ACC_SIZE] = { {100,"123456"} , {500,"234567"} , {10000,"345678"} };
ST_transaction_t struct_transdata[ACC_SIZE] = { NULL };

/***************_FUNCTIONS_**************/

EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	uint8_t uint8_RetrunValue = 0, card_term_valid[VALID_SIZE] = {NULL};

	/*trasaction validation */
	card_term_valid[3] = getTransactionDate(transData->terminalData.transactionDate);

	ST_cardData_t  struct_card;
	ST_terminalData_t  struct_term;
	uint8_t card_len, term_len;
	card_len = strlen(transData->cardHolderData.cardExpirationDate);
	term_len = strlen(transData->terminalData.transactionDate);
	for (int i = 0; i < card_len; i++)
	{
		struct_card.cardExpirationDate[i] = transData->cardHolderData.cardExpirationDate[i];
	}
	for (int i = 0; i < term_len; i++)
	{
		struct_term.transactionDate[i] = transData->terminalData.transactionDate[i];
	}
	card_term_valid[4] = isCardExpired(struct_card, struct_term);
	card_term_valid[5] = getTransactionAmount(transData->terminalData.transAmount);
	card_term_valid[6] = setMaxAmount(transData->terminalData.maxTransAmount);
	card_term_valid[7] = isBelowMaxAmount(transData->terminalData.transAmount);
	//if ()
	for (int i = 0; i < 8; i++)
	{
		if (card_term_valid[i] != OK_CARD)
		{
			uint8_RetrunValue = INVALID_CARD ;
			break;
		}
		else
		{
			uint8_RetrunValue = OK_CARD;
		}
	}
	return uint8_RetrunValue;
}
EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{
	uint8_t uint8_RetrunValue = 0, card_term_valid[VALID_SIZE] = { NULL };
	uint8_t str_len = 0;
	/*card validation */
	card_term_valid[0] = getCardHolderName(cardData->cardHolderName);
	card_term_valid[1] = getCardExpiryDate(cardData->cardExpirationDate);
	card_term_valid[2] = getCardPAN(cardData->primaryAccountNumber);
	str_len = strlen(cardData->primaryAccountNumber);
	if (card_term_valid[0] == WRONG_NAME)
	{
		uint8_RetrunValue = WRONG_NAME;
		//printf("name");
	}
	else if (card_term_valid[1] == WRONG_EXP_DATE)
	{
		uint8_RetrunValue = WRONG_EXP_DATE;
		//printf("date");
	}
	else if (card_term_valid[2] == WRONG_PAN)
	{
		uint8_RetrunValue = WRONG_PAN;
		//printf("pan");
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 13,x=0; x < str_len; j++,x++)
			{
				if (cardData->primaryAccountNumber[j] == struct_accountes[0].primaryAccountNumber[x])
				{
					uint8_RetrunValue = OK_CARD;
					
				}
				else
				{
					uint8_RetrunValue = 4;
				}
			}
		}
	}

	return uint8_RetrunValue;
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{
	uint8_t uint8_RetrunValue = 0, card_term_valid[VALID_SIZE] = { NULL };
	card_term_valid[0] = getTransactionDate(termData->transactionDate);
	card_term_valid[1] = getTransactionAmount(termData->transAmount);
	card_term_valid[2] = setMaxAmount(termData->maxTransAmount);
	if (card_term_valid[0] == WRONG_DATE)
	{
		uint8_RetrunValue = WRONG_DATE;
	}
	else if (card_term_valid[1] == INVALID_AMOUNT)
	{
		uint8_RetrunValue = INVALID_AMOUNT;
	}
	else if (card_term_valid[2] == INVALID_MAX_AMOUNT)
	{
		uint8_RetrunValue = INVALID_MAX_AMOUNT;
	}
	else if (termData->transAmount < struct_accountes[0].balance)
	{
		uint8_RetrunValue = LOW_BALANCE;
	}
	else
	{
		uint8_RetrunValue = OK_SERVER;
	}

	return uint8_RetrunValue;
}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{

}
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{

}

/*End of Server.c*/