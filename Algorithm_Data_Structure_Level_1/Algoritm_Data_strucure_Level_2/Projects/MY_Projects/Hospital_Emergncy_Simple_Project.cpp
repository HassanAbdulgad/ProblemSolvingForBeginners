#include <iostream>
#include <string>
#include <list>
#include <stdexcept>

using namespace std;


class Patient {
public:
    string name;        
    int age;            
    string condition;  
    int priority;       

   
    Patient(string n, int a, string c) {
        name = n;
        age = a;
        condition = c;

       
        if (condition == "critical")
            priority = 1; 
        else if (condition == "urgent")
            priority = 2; 
        else
            priority = 3; 
    }
};


class PriorityQueue {
private:
    list<Patient> queue; 
public:
   
    void add_patient(string name, int age, string condition) {
        Patient newPatient(name, age, condition); 
        auto it = queue.begin();

        
        while (it != queue.end() && it->priority <= newPatient.priority) {
            ++it;
        }
        queue.insert(it, newPatient); 
        cout << "Added Patient: " << name << endl;
    }

   
    void process_patient() {
        if (queue.empty()) {
            cout << "No patients to process." << endl;
            return;
        }

       
        Patient highestPriorityPatient = queue.front();
        queue.pop_front(); 
        cout << "Processing Patient: " << highestPriorityPatient.name
             << ", Age: " << highestPriorityPatient.age
             << ", Condition: " << highestPriorityPatient.condition
             << ", Priority: " << highestPriorityPatient.priority << endl;
    }

   
    void display_queue() const {
        if (queue.empty()) {
            cout << "The queue is empty." << endl;
            return;
        }
        cout << "Current Patients in Queue:" << endl;
        for (const auto& patient : queue) {
            cout << "Name: " << patient.name
                 << ", Age: " << patient.age
                 << ", Condition: " << patient.condition
                 << ", Priority: " << patient.priority << endl;
        }
    }

    
    int queue_size() const {
        return queue.size();
    }

    
    string front_name() const {
        if (queue.empty()) {
            throw string("The queue is empty. No front patient.");
        }
        return queue.front().name;
    }
};


int main() {
    PriorityQueue pq; 
    int choice;

    do {
        
        cout << "\n------ Emergency Room System ------\n";
        cout << "1) Add Patient\n";
        cout << "2) Process Patient\n";
        cout << "3) Display Queue\n";
        cout << "4) Queue Size\n";
        cout << "5) Front Patient Name";
        cout << endl;
        cout << "6) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, condition;
                int age;

                
                cout << "Please Enter Patient Name: ";
                cin >> name;
                cout << "Please Enter Patient Age: ";
                cin >> age;
                cout << "Please Enter Patient Condition (critical, urgent, normal): ";
                cin >> condition;

                
                pq.add_patient(name, age, condition);
                break;
            }
            case 2:
                
                pq.process_patient();
                break;
            case 3:
                
                pq.display_queue();
                break;
            case 4:
                
                cout << "Number of Patients in Queue: " << pq.queue_size() << endl;
                break;
            case 5:
                try {
                   
                    cout << "Front Patient Name: " << pq.front_name() << endl;
                } catch (string& e) {
                    cout << e << endl;
                }
                break;
            case 6:
                
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
