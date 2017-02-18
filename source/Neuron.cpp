#include "stdafx.h"
#include "Neuron.h"


Neuron::Neuron(int Num_Neurons)
{
	this->NumNeurons_INPUT = Num_Neurons;
	this->Out_Function = 0.0;
	this->Weight = 0.0;
	this->Biais = 0.0;

	this->Neuron_Weights_INPUT = vector<double>();
	this->p = new vector<double>();

}


Neuron::~Neuron()
{
}

bool Neuron::Calcule_Neuron_Input_Weights()
{
	if (this->NumNeurons_INPUT <= 0)
	{
		return false;
	}
	else
	{




		for (int i = 0; i < this->NumNeurons_INPUT; ++i)
		{

			this->Weight = (this->UPPER_WEIGHT_LIMIT - this->LOWER_WEIGHT_LIMIT) * (double)(rand() % 1000) + this->LOWER_WEIGHT_LIMIT;
			this->Neuron_Weights_INPUT.push_back(this->Weight);
		}



		return true;
	}
}

void Neuron::Calcule_Neuron_Output_Function(vector<double> &NeuronData_INPUT)
{

	// ( F1 )  :  Z(2) = X*W(1)


	for (int i = 0; i < this->NumNeurons_INPUT; i++)
	{
		this->Out_Function += (this->Neuron_Weights_INPUT.at(i) * NeuronData_INPUT.at(i)) + this->Biais;
		// 
	}
	this->Out_Function /= 1000;
}


void Neuron::setWeightsInputs(vector<double>& v)
{
	// this->Neuron_Weights_INPUT.resize(v.size());
	this->Neuron_Weights_INPUT.assign(v.begin(), v.end());
	this->Neuron_Weights_INPUT = v;

}

void Neuron::Print_Neuron_Infos()
{
	cout << " Lower Weight Limit : " << this->LOWER_WEIGHT_LIMIT << endl;
	cout << " Upper Weight Limit : " << this->UPPER_WEIGHT_LIMIT << endl;
	cout << " Num Neurons INPUT  : " << this->NumNeurons_INPUT << endl;
	cout << " Biais              : " << this->Biais << endl;
	cout << " Output Function    : " << this->Out_Function << endl;
	cout << " Gradient           : " << this->Gradient << endl;

}