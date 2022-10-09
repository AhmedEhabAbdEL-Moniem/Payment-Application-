/*Termianl.h*/
#ifndef TERMINAL_H
#define TERMINAL_H

/***************_INCLUDES_**************/

#include "StdTypes.h"
#include "Card.h"

/***************_MACROS_**************/

#define TERM_DATE_LEN    10
#define DATE_SIZE        11
/***************_TYPEDEFS_**************/


typedef struct ST_terminalData_t
{
	uint32_t transAmount;
	uint32_t maxTransAmount;
	uint8_t transactionDate[DATE_SIZE];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
	OK_Term, WRONG_DATE, EXPIRED_CARD, INVALID_CARD, INVALID_AMOUNT, EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;

/***************_PROTOTYPES_**************/

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData);
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData);
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData);
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData);
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData);
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData);

#endif /*End of Terminal.h*/