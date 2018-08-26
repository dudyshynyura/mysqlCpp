#include "def.h"

void UserInfo::setAllData(){
    cout << "Enter first name(Example: John): ";
    cin >> FirstName;
    cout << "Enter last name(Example: Doe): ";
    cin >> LastName;
    cout << "Enter sex(Example: m): ";
    cin >> sex;
    cout << "Enter age(Example: 25): ";
    cin >> age;
}
void UserInfo::showAllData(){
    cout << "\nFirst name: " << FirstName << endl;
    cout << "Last name: " << LastName << endl;
    cout << "Age: " << age << endl;
    cout << "Sex: " << sex << endl;
}

void UserInfo::sqlRowWrite(){
  string url(EXAMPLE_HOST);
  const string user(EXAMPLE_USER);
  const string password(EXAMPLE_PASS);
  const string database(EXAMPLE_DB);

  try{
    sql::Driver* driver = get_driver_instance();
    std::auto_ptr<sql::Connection> con(driver->connect(url, user, password));
    con->setSchema(database);
    sql::PreparedStatement *prep ;
    prep = con->prepareStatement("INSERT INTO client(Name, SecondName, age, sex) VALUES(?, ?, ?, ?)");
    prep->setString(1, FirstName);
    prep->setString(2, LastName);
    prep->setInt(3, age);
    prep->setString(4, sex);
    prep->execute();
  } catch(sql::SQLException &e) {
    cout << "ERROR: SQLException in" << __FILE__ << endl;
    cout << "ERROR: " << e.what() << endl;
  }
}

vector<string> UserInfo::writeAllDataToFile(const string filename){
    vector<string> data;
    string buf;
    buf = "First name: ";
    buf.append(FirstName);
    data.push_back(buf);
    buf = "Last name: ";
    buf.append(LastName);
    data.push_back(buf);
    ostringstream ss;
    ss << age;
    buf = "Age: ";
    buf.append(ss.str());
    data.push_back(buf);
    buf = "Sex: ";
    buf.append(sex);
    data.push_back(buf);
    fileWrite(filename, data);
    return data;
}

void UserInfo::setFirstName(const string value){
    this->FirstName = value;
}
void UserInfo::setLastName(const string value){
    this->LastName = value;
}
void UserInfo::setSex(const string value){
    this->sex = value; // m or f
}
void UserInfo::setAge(const int value){
    this->age = value;
}

string UserInfo::getFirstName(){
    return FirstName;
}
string UserInfo::getLastName(){
    return LastName;
}
string UserInfo::getSex(){
    return sex;
}
int UserInfo::getAge(){
    return age;
}

void fileWrite(const string fileName, const vector<string> &data){
  ofstream out(fileName.c_str(), ofstream::out);
  if(!out.is_open()) cout << "Error opening output file\n";
  for(int i = 0; i < data.size(); i++){
    out << data[i] << endl;
  };
}
