#include <stdio.h>
#include <string.h>

typedef struct {
	char bookId[7];
	char authorName[30];
	char bookTitle[50];
	char publisher[30];
	char yearOfPublication[5];
	int quantityInStock;
} BookInventory;

struct Transactions {
	char transactionCode;
	int quantity;
};

int main() {
	BookInventory book = {
		"BK-2044",
		"JK Rowling",
		"Harry Potter and the Prisoner of Azkaban",
		"Bloomsbury",
		"1999",
		25
	};
	struct Transactions txn;

	printf(
		"Book Details:\n"
		"============\n"
		"Book ID             : %s\n"
		"Author Name         : %s\n"
		"Book Title          : %s\n"
		"Publisher           : %s\n"
		"Year of Publication : %s\n"
		"Quantity in Stock   : %d\n",
		book.bookId,
		book.authorName,
		book.bookTitle,
		book.publisher,
		book.yearOfPublication,
		book.quantityInStock
	);

	while (1) {
		printf("\n\nTransaction Code (S=sold, P=purchased, X=exit)  : ");
		scanf(" %c", &txn.transactionCode);

		// exit or invalid code
		if (txn.transactionCode == 'X') {
			printf("Exited - End of Transactions.\n");
			break;
		}
		if (txn.transactionCode != 'S' && txn.transactionCode != 'P') {
			printf("Invalid transaction code!\n");
			continue;
		}

		printf("Transaction Quantity                            : ");
		scanf(" %d", &txn.quantity);
	
		if (txn.transactionCode == 'S') {
			book.quantityInStock -= txn.quantity;
		}
		else { 
			// transactionCode == 'P'
			book.quantityInStock += txn.quantity;
		} 


		printf("Sold:  %d copies of \"%s\" by %s.\nThere are now %d copies in stock.\n",
			txn.quantity,
			book.bookTitle,
			book.authorName,
			book.quantityInStock
		);
	}
}