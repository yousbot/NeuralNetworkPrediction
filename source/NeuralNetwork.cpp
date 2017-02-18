#include "stdafx.h"
#include "NeuralNetwork.h"


NeuralNetwork::NeuralNetwork(int INPUT_L, int HIDDEN_L, int OUTPUT_L)
{
	this->INPUT_LayerSize = INPUT_L;
	this->HIDDEN_LayerSize = HIDDEN_L;
	this->OUTPUT_LayerSize = OUTPUT_L;

}


NeuralNetwork::~NeuralNetwork()
{
}


void NeuralNetwork::AddNeuron(int LayerSize, int NumNeuron_INPUT)
{
	vector<Neuron> tmp;
	for (int i = 0; i < LayerSize; ++i)
	{
		Neuron tmpN(NumNeuron_INPUT);
		tmp.push_back(tmpN);
	}
	this->Network.push_back(tmp);
}

void NeuralNetwork::CreateNetwork()
{
	this->AddNeuron(this->INPUT_LayerSize, 1);
	this->AddNeuron(this->HIDDEN_LayerSize, 2);
	this->AddNeuron(this->OUTPUT_LayerSize, 5);

}


void NeuralNetwork::Print_Network_Infos()
{
	cout << " Input Layer Size  : " << this->INPUT_LayerSize << endl;
	cout << " Hidden Layer Size : " << this->HIDDEN_LayerSize << endl;
	cout << " Output Layer Size : " << this->OUTPUT_LayerSize << endl;
	cout << " Network           : " << endl;
	for (int i = 0; i < this->Network.size(); ++i)
	{
		for (auto it : this->Network.at(i))
		{
			cout << " Neuron : " << endl;
			it.Print_Neuron_Infos();
		}
		cout << endl;
	}

}