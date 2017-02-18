#pragma once
class BackPropagation
{
private:

	friend class Neuron;
	int INPUT_LayerSize;
	int HIDDEN_LayerSize;
	int OUTPUT_LayerSize;
	double Network_Learning_Factor;
	double Result_BP;

public:
	BackPropagation(int, int, int);
	BackPropagation(){}
	~BackPropagation();

	vector<double> NeuronsResults;
	vector<double> RAW_Weights;
	vector<double> Params;


	void ComputeGradien_OUTPUT_layer(NeuralNetwork, double);
	void UpdateWeights_OUTPUT_Layer(NeuralNetwork);
	void UpdateBiais_OUTPUT_Layer(NeuralNetwork);

	void ComputeGradien_HIDDEN_layer(NeuralNetwork);
	void UpdateWeights_HIDDEN_Layer(NeuralNetwork);
	void UpdateBiais_HIDDEN_Layer(NeuralNetwork);


	void BackPropagation_M(double, double, double, NeuralNetwork);


	double GetResult(){
		return Result_BP;
	}


};

