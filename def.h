#include <stdlib.h>
#include <iostream>
#include <stdexcept>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "mysql_connection.h" // or #include "path/mysql_connection.h"

#define EXAMPLE_HOST "localhost"
#define EXAMPLE_USER "root"
#define EXAMPLE_PASS "root"
#define EXAMPLE_DB "fin"
using namespace std;

void fileWrite(const string fileName, const vector<string> &data);
    int sendViaSocket(const vector<string> &data);

class UserInfo{
private:
    string FirstName;
    string LastName;
    string sex;
    int age;
public:
    void setAllData();
    void showAllData();
    void sqlRowWrite();

    vector<string> writeAllDataToFile(const string filename);
    void setFirstName(const string value);
    void setLastName(const string value);
    void setSex(const string value);
    void setAge(const int value);
    string getFirstName();
    string getLastName();
    string getSex();
    int getAge();
};
