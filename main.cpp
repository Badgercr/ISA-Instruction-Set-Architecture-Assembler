#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

using namespace std;
string dec_to_binary(int dec);
string reg_to_bin(string reg);
string to_string(int Number);

int main()
{
    string file;
    cin >> file;
    ifstream fin(file);
    ofstream out("program.o");


    if(fin.fail())
    {
        cout << "File not open: ";
        EXIT_SUCCESS;
    }

    string op, registers,cond;
    int num;

    while(!fin.eof())
    {
      fin >> op;

      if(op=="move")
      {
        out << "0000";
        fin >> num;
        out << dec_to_binary(num);
        fin >> registers;
        out << reg_to_bin(registers);
        out << endl;
      }
      else if(op=="add")
      {
        out << "0001";
        fin >> registers;
        out << reg_to_bin(registers);
        fin >> registers;
        out << reg_to_bin(registers);
        fin >> registers;
        out << reg_to_bin(registers);
        out << "00";
        out << endl;
      }
      else if(op=="subtract")
      {
        out << "0010";
        fin >> registers;
        out << reg_to_bin(registers);
        fin >> registers;
        out << reg_to_bin(registers);
        fin >> registers;
        out << reg_to_bin(registers);
        out << "00";
        out << endl;
      }
      else if(op=="multiply")
      {
        out << "0100";
        fin >> registers;
        out << reg_to_bin(registers);
        fin >> registers;
        out << reg_to_bin(registers);
        fin >> registers;
        out << reg_to_bin(registers);
        out << "00";
        out << endl;
      }
      else if(op=="divide")
      {
        out << "1000";
        fin >> registers;
        out << reg_to_bin(registers);
        fin >> registers;
        out << reg_to_bin(registers);
        fin >> registers;
        out << reg_to_bin(registers);
        out << "00";
        out << endl;
      }
      else if(op=="stop")
      {
          out << "0011";
          out << "00000000";
          out << endl;
      }
      else if(op=="makeArr")
      {
          out << "0111";
          fin >> num;
          out << dec_to_binary(num);
          fin >> registers;
          out << reg_to_bin(registers);
          out << endl;
      }
      else if(op=="screen")
      {
          out << "1100";
          fin >> registers;
          out << reg_to_bin(registers);
          out << "000000";
          out << endl;
      }
       else if(op=="increment")
      {
          out << "1110";
          fin >> registers;
          out << reg_to_bin(registers);
          out << "000000";
          out << endl;
      }
      else if(op=="decrement")
      {
          out << "1011";
          fin >> registers;
          out << reg_to_bin(registers);
          out << "000000";
          out << endl;
      }
      else if(op=="erase")
      {
          out << "1001";
          out << "00000000";
          out << endl;
      }
      else if(op=="goto")
      {
        out << "0110";
        fin >> num;
        out << dec_to_binary(num);
        out << "00";
        out << endl;
      }
      else if(op=="find")
      {
          out << "1010";
          fin >> num;
          out << dec_to_binary(num);
          fin >> registers;
          out << reg_to_bin(registers);
          out << endl;
      }
      else if(op=="in")
      {
          out << "1111";
          fin >> registers;
          out << reg_to_bin(registers);
          out << "000000";
          out << endl;
      }
      else if(op=="skipif")
      {
          out << "0101";
          fin >> registers;
          out << reg_to_bin(registers);
          fin >> cond;
          if(cond=="greater")
          {
              out << "1111";
          }
          else if(cond=="less")
          {
              out << "0000";
          }
          else if(cond=="equal")
          {
              out << "1010";
          }
          fin >> registers;
          out << reg_to_bin(registers);
          out << endl;

      }

    }
    return 0;
}
string to_string(int Number)
{
     stringstream ss;
     ss << Number;
     return ss.str();
}
string dec_to_binary(int dec)
{
    string bin = "";

    if(dec == 0)
        return "000000";

    while(dec / 2 != 0)
    {
        bin = to_string(dec % 2) + bin;
        dec /= 2;
    }

    bin = "1" + bin;

    while(bin.size() < 6)   // have to make sure that
        bin = "0" + bin;    // each number uses 6 bits

    return bin;
}
string reg_to_bin(string reg)
{
    if(reg == "donnie")         // basically a simple if.. else
        return "00";       // that will read in a register and
    else if(reg == "mikey")    // return the appropriate address.
        return "01";
    else if(reg == "ralphie")
        return "10";
    else if(reg == "leo")
        return "11";

    else
    {
        cout << "Error\n";
        exit(2);           // kill the program if invalid register
    }                      // is addressed.
}
