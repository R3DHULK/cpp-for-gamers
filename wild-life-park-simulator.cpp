#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Animal class
class Animal
{
public:
    Animal(string name, string species, int age, bool isMale)
    {
        this->name = name;
        this->species = species;
        this->age = age;
        this->isMale = isMale;
    }

    string getName()
    {
        return name;
    }

    string getSpecies()
    {
        return species;
    }

    int getAge()
    {
        return age;
    }

    bool getIsMale()
    {
        return isMale;
    }

private:
    string name;
    string species;
    int age;
    bool isMale;
};

// Park class
class Park
{
public:
    Park()
    {
        // Initialize the list of animals
        animals.push_back(Animal("Simba", "Lion", 5, true));
        animals.push_back(Animal("Nala", "Lion", 4, false));
        animals.push_back(Animal("Mufasa", "Lion", 12, true));
        animals.push_back(Animal("Timon", "Meerkat", 2, true));
        animals.push_back(Animal("Pumbaa", "Warthog", 6, false));
    }

    void listAnimals()
    {
        // Display the list of animals in the park
        cout << "List of animals:" << endl;
        for (int i = 0; i < animals.size(); i++)
        {
            cout << i + 1 << ". " << animals[i].getName() << " - " << animals[i].getSpecies() << " (" << animals[i].getAge() << " years old, " << (animals[i].getIsMale() ? "male" : "female") << ")" << endl;
        }
        cout << endl;
    }

    void addAnimal(string name, string species, int age, bool isMale)
    {
        // Add a new animal to the park
        animals.push_back(Animal(name, species, age, isMale));
        cout << "New animal added!" << endl;
        listAnimals();
    }

private:
    vector<Animal> animals;
};

int main()
{
    // Create a new park
    Park park;

    // Main game loop
    while (true)
    {
        // Display options and prompt for choice
        cout << "Choose an option:" << endl;
        cout << "1. List animals" << endl;
        cout << "2. Add animal" << endl;
        cout << "3. Exit" << endl;
        int choice;
        cin >> choice;

        // Handle choice
        if (choice == 1)
        {
            park.listAnimals();
        }
        else if (choice == 2)
        {
            // Prompt for animal details
            string name, species;
            int age;
            bool isMale;
            cout << "Enter the name of the animal: ";
            cin >> name;
            cout << "Enter the species of the animal: ";
            cin >> species;
            cout << "Enter the age of the animal: ";
            cin >> age;
            cout << "Is the animal male? (y/n): ";
            char maleChoice;
            cin >> maleChoice;
            isMale = (maleChoice == 'y' || maleChoice == 'Y');
            park.addAnimal(name, species, age, isMale);
        }
        else if (choice == 3)
        {
            break;
        }
    }

    return 0;
}
