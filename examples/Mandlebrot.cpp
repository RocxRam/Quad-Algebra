#include <fstream>
#include "Complex.hpp"
using namespace quad;

int main(){
    const int width = 800;
    const int height = 800;
    std::ofstream image("mandelbrot.ppm");
    image << "P3\n";
    image << width << ' '<< height << "\n255\n";
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            double re =-2.0 + 3.0*x/(width-1);
            double im =-1.5 + 3.0*y/(height-1);
            Complex<double> c(re,im);
            Complex<double> z(0,0);
            int iter=0;
            const int maxIter=500;
            while(iter<maxIter && modulo(z)<2.0){               
                z=z*z+c;
                iter++;
            }
            int redness = (iter*9)%256;
            int greenness = (iter*7)%256;
            int blueness = (iter*3)%256;
            image<< redness << ' '<< greenness << ' '<< blueness << ' ';
        }
        image << '\n';
    }
}