#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>


namespace ariel{
    class NumberWithUnits{
        double number;
        std::string units;
        public:
        static std::map<std::string,NumberWithUnits> conv;
        NumberWithUnits(double number , std::string units);
        double get_number()const {
            return this->number;
        }
        std::string get_units() const {
            return this-> units;
        }
        void set_number(double number){
            this->number = number;
        }
        void set_units(std::string units){
            this->units = units;
        }

        NumberWithUnits& operator++(); // pre-increment  done.
        NumberWithUnits& operator--(); // pre-decrement   done.
        NumberWithUnits operator++(int); // post-increment  done. 
        NumberWithUnits operator--(int); // post-decrement   done.
        NumberWithUnits operator+();
        NumberWithUnits operator-();
        NumberWithUnits operator+(const NumberWithUnits &num1);
        NumberWithUnits operator-(const NumberWithUnits &num1);
        NumberWithUnits& operator +=(const NumberWithUnits& b);
        NumberWithUnits& operator -=(const NumberWithUnits& b);
        NumberWithUnits& operator =(const NumberWithUnits& b);
        bool operator == ( const NumberWithUnits &num2)const; // equal operator
        bool operator != ( const NumberWithUnits &num2)const; // not equal operator
        bool operator < ( const NumberWithUnits &num2)const; // less than operator
        bool operator > ( const NumberWithUnits &num2)const; // greater than operator
        bool operator <=( const NumberWithUnits &num2)const; //less or equal than operator
        bool operator >=( const NumberWithUnits &num2)const; // greater or equal than operator        
        
        static void read_units(std::ifstream& units_file){  // a function that reads the units file into a vector of strings
        std::string str;
            while (std::getline(units_file, str))
            {
                char equal;
                double num1,num2;
                std::string unit1,unit2;
                std::istringstream iss{str};
                iss >> num1>> unit1>> equal >> num2>> unit2;
                NumberWithUnits temp1 {num1,unit1};
                NumberWithUnits temp2{num2,unit2};
                conv.insert(std::pair<std::string,NumberWithUnits>(unit1,temp2));
                // int i=0;
                // str.at(i) != "=";
                // while (!isalpha( str.at(i)))
                // {
                //     i++;
                // } 
                // std::string unit = 
            }

        }
        static void print_conv(){
            for(std::map<std::string,NumberWithUnits>::const_iterator it = conv.begin();
                it != conv.end(); ++it)
                {
                  std::cout << it->first<<" "<< it->second.get_number() << " " << it->second.get_units() << "\n"; 
                }
         }
    };
    
    NumberWithUnits operator*( double b ,NumberWithUnits num) ; // multiply number with units with double.
    NumberWithUnits operator*(  NumberWithUnits num,double b) ; // multiply number with units with double.
    NumberWithUnits operator*( NumberWithUnits num ,int b) ; // multiply number with units with double.
    NumberWithUnits operator*( int b ,NumberWithUnits num) ; // multiply number with units with double.
    std::ostream& operator<<(std::ostream& os, const NumberWithUnits& num); // ostream operator
    std::istream& operator>>(std::istream& is, NumberWithUnits& num); //istream operator

 
};