/*Card.c*/

/***************_INCLUDES_**************/

#include "Card.h"
#include <stdio.h>
/***************_FUNCTIONS_**************/

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t uint8_NameLen = 0, uint8_RetrunValue = 0;
	printf("Please Enter Card Name :  ");
	gets(cardData->cardHolderName);
	uint8_NameLen = strlen(cardData->cardHolderName) ;
	if ((uint8_NameLen == NULL) || (uint8_NameLen < MIN_NAME_LEN) || (uint8_NameLen > MAX_NAME_LEN))
	{
		uint8_RetrunValue = WRONG_NAME;
	}
	else
	{
		uint8_RetrunValue = OK_CARD;
	}
	 return uint8_RetrunValue ;
}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	uint8_t uint8_DateLen = 0, uint8_RetrunValue = 0;
	printf("Please Enter Expire Date in MM/YY Format :  ");
	gets(cardData->cardExpirationDate);
	uint8_DateLen = strlen(cardData->cardExpirationDate);
	if ((uint8_DateLen == NULL) || (uint8_DateLen < CARD_DATE_LEN) || (uint8_DateLen > CARD_DATE_LEN)||(cardData->cardExpirationDate[2] != '/'))
	{
		uint8_RetrunValue = WRONG_EXP_DATE;
	}
	else if ((cardData->cardExpirationDate[0] == ASCII_0) && (cardData->cardExpirationDate[1] == ASCII_0))
	{
		uint8_RetrunValue = WRONG_EXP_DATE;
	}
	else if ((cardData->cardExpirationDate[3] == ASCII_0) && (cardData->cardExpirationDate[4] == ASCII_0))
	{
		uint8_RetrunValue = WRONG_EXP_DATE;
	}
	else if (cardData->cardExpirationDate[0] > ASCII_1)
	{
		uint8_RetrunValue = WRONG_EXP_DATE;
	}
	else if ((cardData->cardExpirationDate[0] == ASCII_1) )
	{
		if (cardData->cardExpirationDate[1] > ASCII_2)
		{
			uint8_RetrunValue = WRONG_EXP_DATE;
		}
		else
		{}
	}
	else if ((cardData->cardExpirationDate[3] > ASCII_9)|| (cardData->cardExpirationDate[4] > ASCII_9))
	{
		uint8_RetrunValue = WRONG_EXP_DATE;
	}
	else
	{
		uint8_RetrunValue = OK_CARD;
	}
	return uint8_RetrunValue;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t uint8_PanLen = 0, uint8_RetrunValue = 0, uint8_Iteration;
	printf("Please Enter Card PAN :  ");
	gets(cardData->primaryAccountNumber);
	uint8_PanLen = strlen(cardData->primaryAccountNumber);
	for (uint8_Iteration = 0; uint8_Iteration < uint8_PanLen; uint8_Iteration++)
	{
		if ((cardData->primaryAccountNumber[uint8_Iteration] < ASCII_0) || (cardData->primaryAccountNumber[uint8_Iteration] > ASCII_9) && (cardData->primaryAccountNumber[uint8_Iteration] != 0))
		{
			uint8_RetrunValue = WRONG_PAN;
			break;
		}
		if ((uint8_PanLen == NULL) || (uint8_PanLen < MIN_PAN_LEN) || (uint8_PanLen > MAX_PAN_LEN))
		{
			uint8_RetrunValue = WRONG_PAN;
			break;
		}
		else
		{
			uint8_RetrunValue = OK_CARD;
			
		}

	}

	return uint8_RetrunValue;
}

/*End of Card.c*/