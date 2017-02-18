#include "stdafx.h"
#include "BackPropagation.h"


BackPropagation::BackPropagation(int INPUT_L, int HIDDEN_L, int OUTPUT_L)
{
	Network_Learning_Factor = 0.3;
	this->INPUT_LayerSize = INPUT_L;
	this->HIDDEN_LayerSize = HIDDEN_L;
	this->OUTPUT_LayerSize = OUTPUT_L;
}


BackPropagation::~BackPropagation()
{
}

void BackPropagation::ComputeGradien_OUTPUT_layer(NeuralNetwork N, double DestVal)
{
	vector<Neuron> OUTPUT_layer = N.Network.back();
	double NetAnswer;
	double Derivative;

	for (int i = 0; i < this->OUTPUT_LayerSize; ++i)
	{
		NetAnswer = OUTPUT_layer.at(i).Out_Function;
		Derivative = (1 - NetAnswer) * NetAnswer;
		OUTPUT_layer.at(i).setGradient(Derivative * (DestVal - NetAnswer));
	}
}

void BackPropagation::ComputeGradien_HIDDEN_layer(NeuralNetwork N)
{
	double sum = 0.0;
	double HidAnswer;
	double Derivative = 0.0;
	vector<double> NumInputs;
	for (int i = 0; i < this->HIDDEN_LayerSize; ++i)
	{
		HidAnswer = N.Network.at(1).at(i).Out_Function;
		NumInputs = N.Network.back().at(0).Neuron_Weights_INPUT;
		Derivative = (1 - HidAnswer) * HidAnswer;

		for (int j = 0; j < NumInputs.size(); ++j)
		{
			sum += N.Network.back().at(0).GetGradient() * NumInputs.at(j);
		}

		N.Network.at(1).at(i).setGradient(Derivative * sum);

	}
}


void BackPropagation::UpdateWeights_HIDDEN_Layer(NeuralNetwork N)
{

	double Delta;
	for (int i = 0; i < this->INPUT_LayerSize; i++)
	{
		for (int j = 0; j < this->HIDDEN_LayerSize; j++)
		{
			Delta = Network_Learning_Factor * N.Network.at(1).at(j).GetGradient() * N.Network.front().at(i).Out_Function;
			Delta += N.Network.at(1).at(j).Neuron_Weights_INPUT.at(i);
			N.Network.at(1).at(j).Neuron_Weights_INPUT.at(i) = Delta;

		}
	}
}



void BackPropagation::UpdateBiais_HIDDEN_Layer(NeuralNetwork N)
{
	double Delta;
	for (int i = 0; i < this->HIDDEN_LayerSize; ++i)
	{
		Delta = Network_Learning_Factor * N.Network.at(1).at(i).GetGradient();
		Delta -= N.Network.at(1).at(i).Biais;
		N.Network.at(1).at(i).Biais = Delta;
	}
}




void BackPropagation::UpdateWeights_OUTPUT_Layer(NeuralNetwork N)
{
	double Delta;
	for (int i = 0; i < this->HIDDEN_LayerSize; ++i)
	{
		for (int j = 0; j < this->OUTPUT_LayerSize; ++j)
		{
			Delta = Network_Learning_Factor * N.Network.back().at(j).GetGradient() * N.Network.at(1).at(i).Out_Function;
			Delta += N.Network.back().at(j).Neuron_Weights_INPUT.at(i);
			N.Network.back().at(j).Neuron_Weights_INPUT.at(i) = Delta;
		}
	}
}


void BackPropagation::UpdateBiais_OUTPUT_Layer(NeuralNetwork N)
{
	double Delta;
	for (int i = 0; i < this->OUTPUT_LayerSize; ++i)
	{
		Delta = Network_Learning_Factor * N.Network.back().at(i).GetGradient();
		Delta += N.Network.back().at(i).Biais;
		N.Network.back().at(i).Biais = Delta;
	}
}




void BackPropagation::BackPropagation_M(double V1, double V2, double V3, NeuralNetwork N)
{
	double Dest = V3 / 1000;
	double Post_Conv = 0;

	RAW_Weights = vector<double>();

	for (int i = 0; i < this->INPUT_LayerSize; ++i)
	{
		if (i == 0)
		{
			this->Params.push_back(V1);

		}
		else if (i == 1)
		{

			Params.clear();
			Params.push_back(V2);
		}
		else {

			Params.clear();
			Params.at(0) = 0.0;

		}



		RAW_Weights.push_back(1.0);
		N.Network.front().at(i).Neuron_Weights_INPUT = RAW_Weights;

		N.Network.front().at(i).Calcule_Neuron_Output_Function(Params);
		Post_Conv = N.Network.front().at(i).Out_Function;
		NeuronsResults.push_back(Post_Conv);

	}


	for (int i = 0; i < this->HIDDEN_LayerSize; ++i)
	{
		Params.clear();
		Params.push_back(NeuronsResults.at(0));
		Params.push_back(NeuronsResults.at(1));

		N.Network.at(1).at(i).Calcule_Neuron_Input_Weights();
		N.Network.at(1).at(i).Calcule_Neuron_Output_Function(Params);

		Post_Conv = N.Network.at(1).at(i).Out_Function;
		NeuronsResults.push_back(Post_Conv);
	}

	for (int i = 0; i < this->OUTPUT_LayerSize; ++i)
	{
		Params.clear();

		Params = NeuronsResults;

		N.Network.back().at(i).Calcule_Neuron_Input_Weights();
		N.Network.back().at(i).Calcule_Neuron_Output_Function(Params);

		Post_Conv = N.Network.back().at(i).Out_Function;
		NeuronsResults.push_back(Post_Conv);
	}

	if (V3 != 0)
	{
		this->ComputeGradien_OUTPUT_layer(N, Dest);
		this->ComputeGradien_HIDDEN_layer(N);

		this->UpdateWeights_HIDDEN_Layer(N);
		this->UpdateBiais_HIDDEN_Layer(N);

		this->UpdateWeights_OUTPUT_Layer(N);
		this->UpdateBiais_OUTPUT_Layer(N);
	}

	this->Result_BP = N.Network.back().at(0).Out_Function;

}



























