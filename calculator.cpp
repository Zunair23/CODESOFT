#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

class Calculator{
    private:
    double num1;
    double num2;
    
    public:
    Calculator(double n1, double n2){
        num1 = n1;
        num2 = n2;
    }
    void add(){
        cout<<num1<<"+"<<num2<<"="<<num1+num2<<endl;
    }
    void subtract(){
        cout<<num1<<"-"<<num2<<"="<<num1-num2<<endl;
    }
    void multiply(){
        cout<<num1<<"*"<<num2<<"="<<num1*num2<<endl;
    }
    void divide(){
        if(num2 == 0){
            cout<<"Cannot divide by zero!"<<endl;
        }
        else{
            cout<<num1<<"/"<<num2<<"="<<num1/num2<<endl;
        }
    }
    void power(){
        cout << "Result: " << pow(num1, num2) << endl;
    }
    void squareRoot(){
            if (num1 >= 0)
                cout << "Result: " << sqrt(num1) << endl;
            else
                cout << "Error: Negative input for square root!" << endl;
    }
    void factorial(){
        if (num1 < 0)
            cout << "Error: Negative input for factorial!" << endl;
        else
        {
            double fact = 1;
            for (int i = 1; i <= num1; i++)
                fact *= i;
            cout << "Result: " << fact << endl;
        }
    }
    void logarithm(){
        if (num1 <= 0)
            cout << "Error: Non-positive input for logarithm!" << endl;
        else
            cout << "Result: " << log(num1) << endl;
    }
    void sine(){
        cout << "Result: " << sin(num1 * M_PI / 180) << endl;
    }
    void cosine(){
        cout << "Result: " << cos(num1 * M_PI / 180) << endl;
    }
    void tangent(){
        cout << "Result: " << tan(num1 * M_PI / 180) << endl;
    }
};
int main(){
    int choice;
    double num1, num2;
    while(true){
         cout << "\nScientific Calculator Menu:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Power" << endl;
        cout << "6. Square Root" << endl;
        cout << "7. Factorial" << endl;
        cout << "8. Logarithm" << endl;
        cout << "9. Sine" << endl;
        cout << "10. Cosine" << endl;
        cout << "11. Tangent" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
            if (choice == 12) {
            cout << "Exiting the calculator. Goodbye!" << endl;
            break;
        }

        if (choice >= 1 && choice <= 5) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
        } else if (choice >= 6 && choice <= 11) {
            cout << "Enter a number: ";
            cin >> num1;
        } else {
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }
    Calculator c(num1,  num2);
    switch(choice){
        case 1:
            c.add();
            break;
        case 2:
            c.subtract();
            break;
        case 3:
            c.multiply();
            break;
        case 4:
            c.divide();
            break;
        case 5:
            c.power();
            break;
        case 6:
            c.squareRoot();
            break;
        case 7:
            c.factorial();
            break;
        case 8:
            c.logarithm();
            break;
        case 9:
            c.sine();
            break;
        case 10:
            c.cosine();
            break;
        case 11:
            c.tangent();
            break;
        default:
            cout<<"Invalid operation!"<<endl;
    }
    }

    return 0;
}
