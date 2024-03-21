#include <iostream>
#include <iomanip> //per i manipolatori dell'output (tipo fixed)
#include <cmath>
#include <fstream>
#include <sstream>


int main()
{
    std::string namefile="data.csv";
    std::fstream fstr(namefile);
    if(fstr.fail()){
        std::cerr << "file not found" << std::endl;
        return 1;
    }
    std::string outputFileName="result.csv";
    std::ofstream ofs(outputFileName);
    double val;
    double sum=0;
    int N=0;
    ofs << "# N Mean" << std::endl;
    while(fstr >> val){
        double x = 0.75 * val -1.75;
        sum += x;
        N++;
        ofs << N << " " << std::scientific << std::setprecision(16) << sum/N << std::endl;
    }

    fstr.close();
    return 0;
}
