#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

struct Person {
    std::string firstName;
    std::string lastName;
    int age;
    int job_id;
    int position_id;
};

struct Job {
    std::string name;
    int id;
};

struct Position {
    std::string name;
    int id;
};

bool compareByName(const Person& person1, const Person& person2) {
    if (person1.lastName == person2.lastName) {
        return person1.firstName < person2.firstName;
    }
    return person1.lastName < person2.lastName;
}

bool compareByAge(const Person& person1, const Person& person2) {
    return person1.age < person2.age;
}

class PersonsList {
private:
    std::vector<Person> persons;
    std::map<int, Job> jobsMap;
    std::map<int, Position> positionsMap;

public:
    void addPerson(const Person& aPerson) {
        persons.push_back(aPerson);
    }
    void addJob(const Job& aJob) {
        jobsMap[aJob.id] = aJob;
    }
    void addPosition(const Position& aPosition) {
        positionsMap[aPosition.id] = aPosition;
    }

    void print() {
        std::cout << "Last name" << "\t" << "First name" << "\t" << "Age" << "\t" << "Job" << "\t" << "Position" << std::endl;
        for (const Person& person : persons) {
            std::cout << person.lastName << "\t" << person.firstName << "\t" << person.age << "\t" 
                << jobsMap[person.job_id].name << "\t" << positionsMap[person.position_id].name << std::endl;
        }
    }

    void sortByName() {
        std::stable_sort(persons.begin(), persons.end(), compareByName);
    }
    void sortByAge() {
        std::stable_sort(persons.begin(), persons.end(), compareByAge);
    }
    void sortByJob() {
        std::stable_sort(persons.begin(), persons.end(), [=](const Person& person1, const Person& person2) {
            if (jobsMap[person1.job_id].name == jobsMap[person2.job_id].name) {
                if (positionsMap[person1.position_id].name == positionsMap[person2.position_id].name) {
                    return compareByName(person1, person2);
                }
                return positionsMap[person1.position_id].name < positionsMap[person2.position_id].name;
            }
            return jobsMap[person1.job_id].name < jobsMap[person2.job_id].name;
            }
        );
    }
};

int main() {
    PersonsList persons;

    persons.addPosition(Position{ "auditor",1 });
    persons.addPosition(Position{ "market analyst",2 });
    persons.addPosition(Position{ "recruiter",3 });
    persons.addPosition(Position{ "training manager",4 });
    persons.addPosition(Position{ "database administrator",5 });
    persons.addPosition(Position{ "pc support specialist",6 });
    persons.addPosition(Position{ "depot manager",7 });
    persons.addPosition(Position{ "forklift driver",8 });

    persons.addJob(Job{ "Accounting",1 });
    persons.addJob(Job{ "Marketing",2 });
    persons.addJob(Job{ "Human resources",3 });
    persons.addJob(Job{ "I.T.",4 });
    persons.addJob(Job{ "Logistics",5 });

    persons.addPerson(Person{ "Kevin","Rios",33,1,1 });
    persons.addPerson(Person{ "Rebecca","Davis",28,2,2 });
    persons.addPerson(Person{ "Leroy","Carlson",36,3,3 });
    persons.addPerson(Person{ "David","Wilson",32,3,4 });
    persons.addPerson(Person{ "Clifford","Oliver",25,4,5 });
    persons.addPerson(Person{ "Erik","Harris",29,4,6 });
    persons.addPerson(Person{ "Margaret","Jones",39,5,7 });
    persons.addPerson(Person{ "Frances","Martinez",39,5,8 });
    persons.addPerson(Person{ "Alice","Moore",26,1,1 });
    persons.addPerson(Person{ "Thomas","Blake",29,4,6 });
    persons.addPerson(Person{ "Peter","Wilson",37,3,3 });
    persons.addPerson(Person{ "John","Harris",26,4,6 });

    persons.print();
    persons.sortByName();
    std::cout << "\n\n";
    persons.print();
    persons.sortByAge();
    std::cout << "\n\n";
    persons.print();
    persons.sortByJob();
    std::cout << "\n\n";
    persons.print();
}