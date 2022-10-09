/*Card.h*/
#ifndef CARD_H
#define CARD_H
/***************_INCLUDES_**************/

#include "StdTypes.h"
/***************_MACROS_**************/
#define NAME_SIZE   25
#define PAN_SIZE    20
#define CED_SIZE    6

#define MAX_NAME_LEN        24
#define MIN_NAME_LEN		20

#define CARD_DATE_LEN        5


#define MAX_PAN_LEN        6
#define MIN_PAN_LEN		   2
/***************_TYPEDEFS_**************/

typedef struct ST_cardData_t
{
	uint8_t cardHolderName[NAME_SIZE];
	uint8_t primaryAccountNumber[PAN_SIZE];
	uint8_t cardExpirationDate[CED_SIZE];
}ST_cardData_t;

typedef enum EN_cardError_t
{
	OK_CARD, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN
}EN_cardError_t;

/***************_PROTOTYPES_**************/

EN_cardError_t getCardHolderName(ST_cardData_t* cardData);
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData);
EN_cardError_t getCardPAN(ST_cardData_t* cardData);

#endif /*End of Card.h*/

