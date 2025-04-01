#include <iostream>
#include <memory>
#include <vector>

class archive {
    public:
        archive(int people_id):people_id(people_id) {
            std::cout<<"created"<<std::endl;
        }
        ~archive() {
            std::cout<<"deleted"<<std::endl;
        }
        void set_data(const std::vector<int>& vec){
            data=vec;
        }
        const std::vector<int>& get_data() const{
            return data;
        }
        
    private: 
        int people_id;
        std::vector<int> data;
};


int main(){
    auto archive1=std::make_shared<archive>(100); //создание указателя на архив
    std::vector<int> vec={1,2,3,4,6,7};
    archive1->set_data(vec);
    std::cout<<archive1.use_count()<<std::endl;
    {
        std::cout<<"in block: ";
        auto archive2=archive1;
        std::cout<<archive1.use_count()<<" ";
        auto archive3=archive1;
        std::cout<<archive1.use_count()<<std::endl;
    }
    std::cout<<"not in block: "<<archive1.use_count()<<std::endl;
    
    return 0;
}