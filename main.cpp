#include "def.h"

int main(int argc,const char *argv[]){
    UserInfo person1;
    person1.setAllData();
    person1.showAllData();
    person1.sqlRowWrite();
    vector<string> buf = person1.writeAllDataToFile("out.txt");
    sendViaSocket(buf);
    return 0;
}
