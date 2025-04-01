#include <iostream>
#include <vector>


void dyn_array_fill(int size,std::vector<int>& ar){
    std::cout<<"enter "<<size<<" cif: ";
    for (int i=0;i<size;i++){
        int *cif= new int(i);
        std::cin>> *cif;
        ar[i] = *cif;
        //delete cif; утечка
    }
    std::cout<<"your arr: ";
    for (int i=0;i<size;i++){
        std::cout<<ar[i]<<" ";
    }

}

int* auto_dyn_array_fill(int size){
    int *auto_cif_arr= new int[size];
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
    int *arr = auto_dyn_array_fill(size);
    for (int i=0;i<size;i++){
        std::cout<<arr[i]<<" ";
    } 
    std::cout<<std::endl;
    delete [] arr;//утечки нет
    std::vector <int> ar(size);
    dyn_array_fill(size,ar);
    return 0;
}