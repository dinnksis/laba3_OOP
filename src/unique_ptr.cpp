#include <iostream>
#include <vector>
#include <memory>


void dyn_array_fill(int size,std::vector<int>& ar){
    std::cout<<"enter "<<size<<" cif: ";
    for (int i=0;i<size;i++){
        auto cif= std::make_unique<int>(); //умный указатель на исключительное владение этой памятью
        std::cin>> *cif;
        ar[i] = *cif;
        
    }
    std::cout<<"your arr: ";
    for (int i=0;i<size;i++){
        std::cout<<ar[i]<<" ";
    }

}

std::unique_ptr<int []> auto_dyn_array_fill(int size){
    auto auto_cif_arr= std::make_unique<int[]>(size);
    for (int i=0;i<size;i++){
        auto_cif_arr[i] = i+1;
    }

    return auto_cif_arr;
}

int main(){
    int size=0;
    std::cout<<"enter size: ";
    std::cin>>size;
    std::cout<<"auto_cif_array: ";
    auto arr = auto_dyn_array_fill(size);
    for (int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    } 
    std::cout<<std::endl;
    
    std::vector <int> ar(size);
    dyn_array_fill(size,ar);
    return 0;
}