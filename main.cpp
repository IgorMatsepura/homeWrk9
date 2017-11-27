#include <cstdlib>
#include <iostream>
#include <time.h>
#define NUMBERS_ANIMALS 100  //variable animals in Zoo
#define SELECTONE 1
#define SELECTTWO 2
#define SELECTTHRE 3
#define SELECTFOUR 4


const int ADMIN_PASS = 1000; //variable pass admin Lvl, manager  lvl any value

using namespace std;

class Animal {
private :
   int age;         // variables age of animal;
   char* kind;     // variables type animal;
   char* name;     // variables name animal;
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
    Animal(const int age, char* kind, char* name, int pawsNum, int health, bool isLeave){
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
void setKind(char* typeKind)
{
        kind = typeKind;
}
void setName (char* nameAnimal) {
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

void inputDataAnimals() {
        cout<<"...Add new animal..."<<endl;
        cout<<"Input age animal : ";
        cin>>age;
        cout<<"Input type animal : ";
        gets (kind);
        gets (kind);
        cout<<"Input name animal : ";
        gets (name);
        cout<<"Input number of paws animal : ";
        cin>>pawsNum;
        cout<<"Input locating animal : "<<1;
        cout<<endl;
}

void showData() {
	int age;
	char* kind;
	char* name;
	int pawsNum;
	int health;
   	bool isLeave = true;
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
    Animal animals[NUMBERS_ANIMALS];
    int size;
public:
void showAboutInfo();
    Zoo() { size = 0; }
    Animal getAnimal(int index);

// adding new animal to Zoo
void addNewAnimal(Animal a){
    if (size >= NUMBERS_ANIMALS){
        cout << "Animal was not - No space!";
        return;
    }
    animals[size] = a;
    size++;
    }
// print all info about animal
void print(){
    for (int i = 0; i < size; i++){
        animals[i].showData();
    }
}
// select using animal  name in zoo
void showPopulation(char* name){
    for (int i = 0; i < size; i++){
     //   if (m_animals[i] != nullptr){  // not worked?????
        if (animals[i].getName().compare(name) == 0 ){
            cout << " Age animal : "<< animals[i].getAge();
            cout << " Kind animal : "<< animals[i].getKind();
            cout << " Name animal : "<< animals[i].getName();
            cout << " Number of paws animal: "<< animals[i].getpawsNum();
            cout << " Health of animal: "<< animals[i].getHealth();
            cout << " Animal in zoo?: "<< animals[i].getisLeave()<<endl;
            cout <<endl;
     // }
        }
            else {
                cout << "Not found...\n\n";
            }
        }
}
// delete select animal from Zoo
void deleteAnimal(char* name){
    for (int i = 0 ; i < size ; i++)
            if (animals[i].getName().compare(name) == 0)  {
				delete animals[i];
           		animals[i] = nullptr;
                cout<<">>>>>Animal was succesfully deleted<<<<<\n\n";
            } else {
                cout << "Not found...\n\n";
            }
}
//edit select animal from Zoo
void editAnimalInfo(char* name){
   int age;
   char* kind;
   char* animalName;
   int pawsNum;
   bool isLeave = true;
    for (int i = 0 ; i < size ; i++)
            if (animals[i].getName().compare(name) == 0)  {
                cout << "Enter new age animal: ";
                cin >> age;
                animals[i].setAge(age);
                cout << "Enter new kind animal: ";
                gets(kind);
                animals[i].setKind(kind);
                cout << "Enter new name animal: ";
                gets(animalName);
                animals[i].setName(animalName);
                cout << "Enter new number of paws animal: ";
                cin >> pawsNum;
                animals[i].setpawsNum(pawsNum);
                cout << "Enter new validation isShown (1-yes / 0-no): ";
                cin >>isLeave;
                animals[i].getisLeave();
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
char* name;
        for(;;){
            std::cout<<"Welcome to User panel Zoo. Pls choose?"<<endl;
            std::cout<<"1 - Show about info"<<endl;
            std::cout<<"2 - Edit property animal "<<endl;
            std::cout<<"3 - Quit user panel "<<endl;
            std::cout<<"Choose select: ";
            cin>>userSelector;
            switch (userSelector){
                case SELECTONE:
                    std::cout<<"Show about info animal"<<endl;
                    anim.showData();
                    break;
                case SELECTTWO:
                    std::cout<<"Edit property animal"<<endl;
                    cin>>name;
                    gets(name);
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
char* nameAnimal;
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
                case SELECTONE:
                    cout<<"Add new animal into Zoo"<<endl;
                    anim.inputDataAnimals();
                    z.addNewAnimal(anim);
                    break;
                case SELECTTWO:
                    cout<<"Delete animal into Zoo"<<endl;
                    gets (nameAnimal);
                    z.deleteAnimal(nameAnimal);
                    break;
                case SELECTTHRE:
                    cout<<"Show population animal"<<endl;
                    gets (nameAnimal);
                    z.showPopulation(nameAnimal);
                    break;
                case SELECTFOUR:
                    std::cout<<"Edit property animal"<<endl;
                    cin>>nameAnimal;
                    gets(nameAnimal);
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

