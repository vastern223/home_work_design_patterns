#include<iostream>
#include <string>

using namespace std;



class Car
{
public:

	string Body;
	string Engine;
	string Wheels;
	string  paint;
	string Salon;

	void Show() const
	{
		cout << "Body: " << Body << endl;
		cout << "Engine: " << Engine << endl;
		cout << "Wheels: " << Wheels << endl;
		cout << "Paint: " << paint << endl;
		cout << "Salon: " << Salon << endl;
	}

};

class AutoTechnology
{
protected:

    Car* car;

public:
    void CreateNewcar()
    {
        car = new Car();
    }
   
    Car* GetMycar() const
    {
        return car;
    }
   
    virtual void BuildBody() = 0;
    virtual void InstallEngine() = 0;
    virtual void InstallWheels() = 0;
    virtual void Paint() = 0;
    virtual void PrepareSalon() = 0;
};


class SportCarTechnology : public  AutoTechnology
{
    void BuildBody()
    {
        car->Body = "SportCarBody";
    }
    void InstallEngine()
    {
        car->Engine = "SportCarEngine";
    }
    void InstallWheels()
    {
        car->Wheels = "SportCarWheels";
    }
    void Paint()
    {
        car->paint = "SportCarPaint";

    }
    void PrepareSalon()
    {
        car->Salon = "SportCarSalon";
    }
};



class MiniAutoTechnology : public  AutoTechnology
{
    void BuildBody()
    {
        car->Body = "MiniCarBody";
    }
    void InstallEngine()
    {
        car->Engine = "MiniCarEngine";
    }
    void InstallWheels()
    {
        car->Wheels = "MiniCarWheels";
    }
    void Paint()
    {
        car->paint = "MiniCarPaint";

    }
    void PrepareSalon()
    {
        car->Salon = "MiniCarSalon";
    }
};


class SUVAutoTechnology : public  AutoTechnology
{

    void BuildBody()
    {
        car->Body = "SUVCarBody";
    }
    void InstallEngine()
    {
        car->Engine = "SUVCarEngine";
    }
    void InstallWheels()
    {
        car->Wheels = "SUVCarWheels";
    }
    void Paint()
    {
        car->paint = "SUVCarPaint";

    }
    void PrepareSalon()
    {
        car->Salon = "SUVCarSalon";
    }
};

class Conveyor
{
private:

    AutoTechnology* ModelTehnology;

public:
    void SetTehnology(AutoTechnology* builder)
    {
        this->ModelTehnology = builder;
    }
    Car* Getcar() const
    {
        return ModelTehnology->GetMycar();
    }
    void Configurate()
    {
      
        ModelTehnology->CreateNewcar();
        ModelTehnology->BuildBody();
        ModelTehnology->InstallEngine();
        ModelTehnology->InstallWheels();
        ModelTehnology->Paint();
        ModelTehnology->PrepareSalon();
    }
};


int main()
{

     Conveyor dir;
     dir.SetTehnology(new  SUVAutoTechnology());
     dir.Configurate();

     Car* car = dir.Getcar();

     car->Show();
     
}
    
