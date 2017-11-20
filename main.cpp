#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#define NUMBERS_ANIMALS 100  //variable animals in Zoo

const int ADMIN_PASS = 1000; //variable pass admin Lvl, manager  lvl any value

using namespace std;


class Animal {
private :
   int age;         // variables age of animal;
   string kind;     // variables type animal;
   string name;     // variables name animal;
   int pawsNum;     // variables number of paws animal;
   int health;      // variables % health animal;
   bool isLeave;    // variables type of Leave (Zoo/aviary);

public:
    Animal(){
        age = 0;
        pawsNum = 0;
        isLeave = true;
        srand (time(NULL));
    }
    Animal(const int age, string kind, string name, int pawsNum, int health, bool isLeave){
        this->age = age;
        this->kind = kind;
        this->name = name;
        this->pawsNum = pawsNum;
        this->health = health;
        this->isLeave = isLeave;
    }

void setAge (int yearsAnimal) {
        age = yearsAnimal;
}
void setKind(string typeKind)
{
        kind = typeKind;
}
void setName (string nameAnimal) {
        name = nameAnimal;
}
void setpawsNum (int countNum) {
        pawsNum = countNum;
}
void setHealth (){
        health = rand() % 100;
}
void setisLeave (int isLeave){
        if (isLeave == 1){
            isLeave = true;
        } else {
            isLeave = false;
        }
}

int getAge() { return age; }
string getKind() { return kind; }
string getName() { return name; }
int getpawsNum() { return pawsNum; }
int getHealth()  { health = rand() % 100; return health; }
bool getisLeave() { return isLeave; }

void inputDataAnimals()
    {
        cout<<"...Add new animal..."<<endl;
        cout<<"Input age animal : ";
        cin>>age;
        cout<<"Input type animal : ";
        getline (cin, kind);
        getline (cin, kind);
        cout<<"Input name animal : ";
        getline (cin, name);
        cout<<"Input number of paws animal : ";
        cin>>pawsNum;
        cout<<"Input locating animal : "<<1;
        cout<<endl;
    }

void showData()
    {
        cout << "                                   Animal info: " << endl;
        cout << "=========================================================================================================" << endl;
        cout << " Age animal: " << age;
        cout << " Type animal: " << kind;
        cout << " Name animal: " << name;
        cout << " Number of paws animal: " << pawsNum;
        cout << " Health of animal: " << health;
        cout << " Locating animal: " << isLeave<<endl;
        cout << endl;
    }
};

class Zoo{
    Animal m_animals[NUMBERS_ANIMALS];
    int m_size;
public:

void showAboutInfo();
    Zoo() { m_size = 0; }
    Animal getAnimal(int index);
// adding new animal to Zoo
void addNewAnimal(Animal a){
    if (m_size >= NUMBERS_ANIMALS){
        cout << "Animal was not - No space!";
        return;
    }
    m_animals[m_size] = a;
    m_size++;
    }
// print all info about animal
void print(){
    for (int i = 0; i < m_size; i++){
        m_animals[i].showData();
    }
}
// select using animal  name in zoo
void showPopulation(string name){
    for (int i = 0; i < m_size; i++){
     //   if (m_animals[i] != nullptr){  // not worked?????
        if (m_animals[i].getName().compare(name) == 0 ){
            cout << " Age animal : "<< m_animals[i].getAge();
            cout << " Kind animal : "<< m_animals[i].getKind();
            cout << " Name animal : "<< m_animals[i].getName();
            cout << " Number of paws animal: "<< m_animals[i].getpawsNum();
            cout << " Health of animal: "<< m_animals[i].getHealth();
            cout << " Animal in zoo?: "<< m_animals[i].getisLeave()<<endl;
            cout <<endl;
     // }
        }
            else {
                cout << "Not found...\n\n";
            }
        }
}
// delete select animal from Zoo
void deleteAnimal(string name){
    for (int i = 0 ; i < m_size ; i++)
            if (m_animals[i].getName().compare(name) == 0)  {
               delete m_animals[i];
               m_animals[i] = nullptr;
                cout<<">>>>>Animal was succesfully deleted<<<<<\n\n";
            } else {
                cout << "Not found...\n\n";
            }
}
//edit select animal from Zoo
void editAnimalInfo(string name){
   int age;
   string kind;
   string animalName;
   int pawsNum;
   bool isLeave = true;
    for (int i = 0 ; i < m_size ; i++)
            if (m_animals[i].getName().compare(name) == 0)  {
                cout << "Enter new age animal: ";
                cin >> age;
                m_animals[i].setAge(age);
                cout << "Enter new kind animal: ";
                getline(cin, kind);
                getline(cin, kind);                 //bugs of C++ incorrect input
                m_animals[i].setKind(kind);
                cout << "Enter new name animal: ";
                getline(cin, animalName);
                m_animals[i].setName(animalName);
                cout << "Enter new number of paws animal: ";
                cin >> pawsNum;
                m_animals[i].setpawsNum(pawsNum);
                cout << "Enter new validation isShown (1-yes / 0-no): ";
                cin >>isLeave;
                m_animals[i].getisLeave();
            } else {
                 cout << "Not found...\n\n";
            }
}
};
// Lvl manager Zoo
class ManagerZoo{
public:
    ManagerZoo(){
    }
    Animal anim;
    Zoo z;
void userSelector(){
int userSelector;
string name;
        for(;;){
            std::cout<<"Welcome to User panel Zoo. Pls choose?"<<endl;
            std::cout<<"1 - Show about info"<<endl;
            std::cout<<"2 - Edit property animal "<<endl;
            std::cout<<"3 - Quit user panel "<<endl;
            std::cout<<"Choose select: ";
            cin>>userSelector;
            switch (userSelector){
                case 1:
                    std::cout<<"Show about info animal"<<endl;
                    anim.showData();
                    break;
                case 2:
                    std::cout<<"Edit property animal"<<endl;
                    cin>>name;
                    getline(cin, name);
                    getline(cin, name);
                    z.editAnimalInfo(name);
                    break;
                default:
                    return;
            }
        }
}
};
//Lvl admin Zoo and select option
class AdminLvl{
public:
Animal anim;
Zoo z;

void adminSelector(){
int adminSelector;
string nameAnimal;
        for(;;){
            cout <<"Welcome to Admin panel Zoo. Pls choose?"<<endl;
            cout <<"1 - Add new animal "<<endl;
            cout <<"2 - Delete animal "<<endl;
            cout <<"3 - Show population animals "<<endl;
            cout <<"4 - Edit animal "<<endl;
            cout <<"5 - Quit admin panel "<<endl;
            cout <<"Choose select: ";
            cin >>adminSelector;
            switch (adminSelector){
                case 1:
                    cout<<"Add new animal into Zoo"<<endl;
                    anim.inputDataAnimals();
                    z.addNewAnimal(anim);
                    break;
                case 2:
                    cout<<"Delete animal into Zoo"<<endl;
                    getline (cin, nameAnimal);
                    z.deleteAnimal(nameAnimal);
                    break;
                case 3:
                    cout<<"Show population animal"<<endl;
                    getline (cin, nameAnimal);
                   // getline (cin, nameAnimal);
                    z.showPopulation(nameAnimal);
                    break;
                case 4:
                    std::cout<<"Edit property animal"<<endl;
                    cin>>nameAnimal;
                    getline(cin, nameAnimal);
                    z.editAnimalInfo(nameAnimal);
                    break;
                default:
                    return;
            }
        }
}
};
// Lvl Authorization in Zoo (admin/manager)
class AuthorizationLvl{
private:
   int pass;
public:
    AuthorizationLvl(){
    }
    int setPass (int passAutentification) {
        pass = passAutentification;
    }
    int getPass (int passAutent) { return passAutent;}

void inputAutentification(){
    for(;;){
        cout<<"Please input password in Zoo : ";
        cin>>pass;
            if (pass == ADMIN_PASS) {
                AdminLvl admin;
                admin.adminSelector();
            } else {
                ManagerZoo user;
                user.userSelector();
            }
    }
}
};

int main()
{
    AuthorizationLvl zooAuthorization;
    zooAuthorization.inputAutentification();
}

