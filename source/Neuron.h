#pragma once
#include <vector>
using namespace std;
class Neuron
{

private:

	double LOWER_WEIGHT_LIMIT = -0.3;
	double UPPER_WEIGHT_LIMIT = 0.7;
	int NumNeurons_INPUT;
	double Gradient;
	double Weight;
public:

	vector<double> Neuron_Weights_INPUT;
	vector<double> *p;
	double Out_Function;
	double Biais;

	Neuron(int);
	Neuron(){}
	~Neuron();
	bool Calcule_Neuron_Input_Weights();
	void Calcule_Neuron_Output_Function(std::vector<double>&);

	void Print_Neuron_Infos();


	void setGradient(double g)
	{
		this->Gradient = g;
	}

	double GetGradient()
	{
		return Gradient;
	}

	void setWeightsInputs(vector<double> &v);

	void operator=(vector<double>& v)
	{
		int i = 0;
		for (vector<double>::iterator it = v.begin(); it != v.end(); ++it)
		{
			this->Neuron_Weights_INPUT.at(i) = *it;
			i++;
		}
	}
};

