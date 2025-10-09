#include <iostream>
#include <limits>

class TempConverter 
{
    public:
        double kelvinToF(double k){
            double fahrenheit = (k - 273.15) * 9.0/5.0 + 32;
            return fahrenheit;
        }
        double kelvinToC(double k){
            double celsius =  k - 273.15;
            return celsius;
        }
        double celsiusToK (double c){
            double kelvin = c + 273.15;
            return kelvin;
        }
        double celsiusToF(double c){
            double fahrenheit =(c * 1.8) + 32.0;
            return fahrenheit;
        }
        double fahrenheitToC(double f){
            double celsius = (f - 32) * (5/9.0);
            return celsius;
        }
        double fahrentheitToK(double f){
            double kelvin = fahrenheitToC(f) + 273.15;
            return kelvin;
        }
};

int main()
{
    TempConverter tempcalc = TempConverter();
    system("cls");
    bool loop = 1;

    while(loop){
        char tempUnit;
        char newUnit;
        std::string  unit = "KkCcFf";
        double currentTempValue;
        double newTempValue;

        std::cout<<"Enter a character for the temperature unit you want you convert to ['C','F','K']: ";
        std::cin >> tempUnit;
        std::cout<<std::endl;

        if(unit.find(tempUnit)== std::string::npos){
            std::cout<<"Please enter one of the 3 character to continue."<< std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            continue;
        }
    
        std::cout<<"Enter  temperature: ";

        if(!(std::cin >> currentTempValue)){
            std::cout <<"Must enter a number value"<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cout<<"Enter which unit you want to convert to ['C','F','K']: ";
        std::cin >> newUnit;
        std::cout<<std::endl;

        if (unit.find(newUnit) == std::string::npos){
            std::cout<<"Please enter one of the 3 character to continue."<< std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }else if (newUnit == tempUnit){
            std::cout<<"can't choose the same unit to convert to."<< std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        switch (tempUnit)
        {
        case 'k':
            if((newUnit == 'c') ||( newUnit =='C')){
                newTempValue = tempcalc.kelvinToC(currentTempValue);
                std::cout<<currentTempValue <<"k is: "<<newTempValue<<"c"<<std::endl;
            }else{
                newTempValue = tempcalc.kelvinToF(currentTempValue);
                std::cout<<currentTempValue <<"k is: "<<newTempValue<<"f"<<std::endl;
            }
            break;
        case 'c' :
            if((newUnit == 'k') || (newUnit == 'K')){
                newTempValue = tempcalc.celsiusToK(currentTempValue);
                std::cout<<currentTempValue <<"c is: "<<newTempValue<<"k"<<std::endl;
            }else{
                newTempValue = tempcalc.celsiusToF(currentTempValue);
                std::cout<<currentTempValue <<"c is: "<<newTempValue<<"f"<<std::endl;
            }
            break;
        case 'f':
            if((newUnit == 'k') || (newUnit == 'K')){
                newTempValue = tempcalc.fahrentheitToK(currentTempValue);
                std::cout<<currentTempValue <<"f is: "<<newTempValue<<"k"<<std::endl;
            }else{
                newTempValue = tempcalc.fahrenheitToC(currentTempValue);
                std::cout<<currentTempValue <<"f is: "<<newTempValue<<"c"<<std::endl;
            }
            break;
        default:
            break;
        }
        std::cout<<"To use again enter 1. to exit enter a 0: ";
        if(!(std::cin >> loop)){
            loop = 0;
        }
        system("cls");
    }
    
    return 0;
}