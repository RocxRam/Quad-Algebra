#include <fstream>
#include "Split_Complex.hpp"
using namespace quad;

int main(){
    const int width = 800;
    const int height = 800;
    std::ofstream image("Split_Complex_Visualizer.ppm");
    image << "P3\n";
    image << width << ' '<< height << "\n255\n";
    for(int y=0;y<height;y++){
        for(int x=0;x<width;x++){
            double px = -3.0 + 6.0*x/(width-1);
            double py = -3.0 + 6.0*y/(height-1);
            double n=norm(Split_Complex<double>(px,py));
            const double eps = 0.02;
            bool drawn = false;

            for(int k=-9; k<=9; k++){
                if(k == 0) continue;
                if(std::abs(n-k) < eps){
                    if(k > 0){
                        image << "255 255 255 "; // white
                    }
                    else{
                        image << "0 0 255 ";     // blue
                    }
                    drawn = true;
                    break;
                }
            }
            if(!drawn){
                if (std::abs(n) < eps){
                    image << "255 255 0 ";     // yellow
                }
                else{
                image << "0 0 0 ";
                }
            }
        }
        image << '\n';
    }
    return 0;
}