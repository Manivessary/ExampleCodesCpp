#include <iostream>
//#include "soci\soci.h"
//#include "soci\sqlite3\soci-sqlite3.h"
#include "sqlite3.h"


using String = std::string;
using std::cout;

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main() {
	cout << "selam\n";

	sqlite3* db;
	char* zErrMsg;
	int rc;

	rc = sqlite3_open("test.db", &db);
	if(rc)
		std::cout << "Errorcode: " << rc << std::endl;	
	
	/*
	{
		const char* query = "CREATE TABLE Persons (PersonID int,LastName varchar(255),FirstName varchar(255),Address varchar(255),City varchar(255)); ";
		int result = sqlite3_exec(db, query, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			std::cout << "SQL error:: " << zErrMsg << std::endl;
			sqlite3_free(zErrMsg);
		}
	}
	*/

	{
		// (PersonID, LastName, FirstName, Address, City)
		// const char* query = "INSERT INTO Persons VALUES(123, 'GEBEÞS', 'SAMÝ', 'USKUDAR', 'ANTALYA');";
		int result = sqlite3_exec(db, "INSERT INTO Persons VALUES(12123, 'GEBES', 'SAM', 'USKUDAR', 'ANTALYA');", callback, 0, &zErrMsg);

		if (rc != SQLITE_OK) {
			std::cout << "SQL error:: " << zErrMsg << std::endl;
			sqlite3_free(zErrMsg);
		}
	}

	std::cin.get();
}