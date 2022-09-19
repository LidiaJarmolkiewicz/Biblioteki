
#include<iostream>
#include<tuple>
#include<vector>
std::tuple<int,std::string, int> data(int x, std::string s, int y)
{
    return std::make_tuple(x, s, y);
};
struct Patient
{
    std::string name;
    std::string surname;
    int ID;
    float height;
    int weight;

};
class MedicalRecord
{
public:
    MedicalRecord() = default;
   virtual ~MedicalRecord() = default;
   void addPatient(Patient patient)
   {
       datas.push_back(patient);
   }

    std::tuple<std::string, float, int> getPAtientData(int ID)
    {
        auto patient1 = std::find_if(datas.cbegin(), datas.cend(), [ID](auto patient) {return patient.ID = ID; });
        return make_tuple(patient1->name, patient1->height, patient1->weight);
    }
private:
    std::vector<Patient> datas;


};
int main(){
    auto dane = data(123, "yellow", 789);
    std::cout<< std::get<0>(dane) << std::get<1>(dane) << std::get<2>(dane) << std::endl;
   
    MedicalRecord nzozX;
    nzozX.addPatient(Patient{ "Jan", "Kot", 444, 1.7, 99 });
    nzozX.addPatient(Patient{ "Zuza", "Pilat", 333, 1.6, 55 });
    nzozX.addPatient(Patient{ "Kuba", "Marenda", 666, 1.8, 82 });

    auto patientData = nzozX.getPAtientData(333);

    std::cout << "imie " << std::get<0>(patientData) << " wzrost " << std::get<1>(patientData) << " waga " << std::get<2>(patientData) << std::endl;
    auto name = std::get<0>(patientData);
    auto height = std::get<1>(patientData);
    auto weight = std::get<2>(patientData);
    auto BMI = weight / (height + weight);
    std::cout << "pacjent " << name << " ma BMI w wysokosci " << BMI << std::endl;
}
