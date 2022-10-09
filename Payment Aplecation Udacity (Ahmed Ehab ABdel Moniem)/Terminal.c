/*Terminal.c*/

/***************_INCLUDES_**************/

#include "Terminal.h"
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
/***************_FUNCTIONS_**************/

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	uint8_t uint8_TransLen = 0, uint8_RetrunValue = 0;
	printf("Please Enter Transaction Date in DD/MM/YYYY Formate :  ");
	gets(termData->transactionDate);
	uint8_TransLen = strlen(termData->transactionDate);
	if ((uint8_TransLen == NULL) || (uint8_TransLen < TERM_DATE_LEN) || (uint8_TransLen > TERM_DATE_LEN) ||(termData->transactionDate[2] != '/')|| (termData->transactionDate[5] != '/'))
	{
		uint8_RetrunValue = WRONG_DATE ;
	}
	else if ((termData->transactionDate[6] == ASCII_0)&& (termData->transactionDate[7] == ASCII_0)&&(termData->transactionDate[8] == ASCII_0)&&(termData->transactionDate[9] == ASCII_0))
	{
		uint8_RetrunValue = WRONG_DATE;
	}
	else if ((termData->transactionDate[0] == ASCII_0) && (termData->transactionDate[1] > ASCII_0))
	{
		uint8_RetrunValue = WRONG_DATE;
	}
	else if ((termData->transactionDate[3] == ASCII_0) && (termData->transactionDate[4] > ASCII_0))
	{
		uint8_RetrunValue = WRONG_DATE;
	}
	else if (termData->transactionDate[0] > ASCII_3)
	{
		uint8_RetrunValue = WRONG_DATE;
	}
	else if ((termData->transactionDate[0] == ASCII_3)&& (termData->transactionDate[1] > ASCII_1))
	{
		uint8_RetrunValue = WRONG_DATE;
	}
	else if (termData->transactionDate[3] > ASCII_1)
	{
		uint8_RetrunValue = WRONG_DATE;
	}
	else if ((termData->transactionDate[3] == ASCII_1)&& (termData->transactionDate[4] > ASCII_2))
	{
		uint8_RetrunValue = WRONG_DATE;
	}
	else
	{
		uint8_RetrunValue = OK_Term;
	}
	return uint8_RetrunValue;
}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	uint8_t uint8_RetrunValue = 0 ;
	uint8_t uint8_Year_Card, uint8_Month_Card , uint8_Year_Term, uint8_Month_Term;
	uint8_Year_Card  = (cardData.cardExpirationDate[3] * 10) + cardData.cardExpirationDate[4];
	uint8_Month_Card = (cardData.cardExpirationDate[0] * 10) + cardData.cardExpirationDate[1];

	uint8_Year_Term  = (termData.transactionDate[8] * 10) + termData.transactionDate[9];
	uint8_Month_Term = (termData.transactionDate[3] * 10) + termData.transactionDate[4];
	uint8_Year_Card = (cardData.cardExpirationDate[3] * 10) + cardData.cardExpirationDate[4];
	if (uint8_Year_Term > uint8_Year_Card)
	{
		uint8_RetrunValue = EXPIRED_CARD;
	}
	else if (uint8_Month_Term > uint8_Month_Card)
	{
		uint8_RetrunValue = EXPIRED_CARD;
	}
	else
	{
		uint8_RetrunValue = OK_Term;
	}
	return uint8_RetrunValue;
}
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{

}
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	uint8_t uint8_RetrunValue = 0;
	printf("Please enter transaction amount :  ");
	fflush(stdin);
	scanf_s("%d",&termData->transAmount);
	if (termData->transAmount <= 0)
	{
		uint8_RetrunValue = INVALID_AMOUNT;
	}
	else
	{
		uint8_RetrunValue = OK_Term;

	}
	return uint8_RetrunValue;
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	uint8_t uint8_RetrunValue = 0;
	if (termData->transAmount > termData->maxTransAmount )
	{
		uint8_RetrunValue = EXCEED_MAX_AMOUNT;
	}
	else
	{
		uint8_RetrunValue = OK_Term;

	}
	return uint8_RetrunValue;
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	uint8_t uint8_RetrunValue = 0;
	printf("Please set max transaction amount :  ");
	/**fflush(stdin);
	scanf_s("%d", &termData->maxTransAmount);*/
	if (termData->maxTransAmount <= 0)
	{ 
		uint8_RetrunValue = INVALID_MAX_AMOUNT;
	}
	else
	{
		uint8_RetrunValue = OK_Term;

	}
	return uint8_RetrunValue;
}

/*End of Terminal.c*/