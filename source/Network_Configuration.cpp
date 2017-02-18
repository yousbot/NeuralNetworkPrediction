#include "stdafx.h"
#include "Network_Configuration.h"


Network_Configuration::Network_Configuration()
{

	NETWORK = NeuralNetwork(INPUT_LAYER_NUM, HIDDEN_LAYER_NUM, OUTPUT_LAYER_NUM);
	Propagation = BackPropagation(INPUT_LAYER_NUM, HIDDEN_LAYER_NUM, OUTPUT_LAYER_NUM);

	this->INPUT_LAYER_NUM = 1;
	this->HIDDEN_LAYER_NUM = 5;
	this->OUTPUT_LAYER_NUM = 2;
}


Network_Configuration::~Network_Configuration()
{
}

void Network_Configuration::Preparation()
{
	this->NETWORK.CreateNetwork();
}


void Network_Configuration::teaching()
{
	int i = 0;
	while ((i + 2) < this->INPUT_Data.size())
	{
		TMP1 = INPUT_Data.at(i);
		TMP2 = INPUT_Data.at(i + 1);
		TMP3 = INPUT_Data.at(i + 2);
		P = TMP3;

		Propagation.BackPropagation_M(TMP1, TMP2, TMP3, NETWORK);
		i++;
		Test = Propagation.GetResult();
	}


	TMP1 = INPUT_Data.at(i);
	TMP2 = INPUT_Data.at(i + 1);

}

double Network_Configuration::Predict_Answer()
{
	Propagation.BackPropagation_M(TMP1, TMP2, 0, NETWORK);
	return Propagation.GetResult();
}



void Network_Configuration::setInputData(vector<double>& v)
{
	int i = 0;

	INPUT_Data = v;

}


void Network_Configuration::RUN()
{
	this->Preparation();
	this->teaching();
	double FinalResult = this->Predict_Answer();
	FinalResult = (P * FinalResult) / Test;
	this->PredictedAnswer.push_back(FinalResult);


}