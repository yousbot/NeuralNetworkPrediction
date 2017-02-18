#pragma once
class NeuralNetwork
{
	friend class Neuron;
	int INPUT_LayerSize;
	int HIDDEN_LayerSize;
	int OUTPUT_LayerSize;


public:
	vector<vector<Neuron>> Network;

	NeuralNetwork(int, int, int);
	NeuralNetwork(){}
	~NeuralNetwork();

	void AddNeuron(int, int);
	void CreateNetwork();
	void Print_Network_Infos();
};

