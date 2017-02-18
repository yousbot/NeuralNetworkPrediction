#pragma once
class Network_Configuration
{

	int INPUT_LAYER_NUM = 2;
	int HIDDEN_LAYER_NUM = 5;
	int OUTPUT_LAYER_NUM = 1;

	vector<double> INPUT_Data;
	vector<double> PredictedAnswer;
	NeuralNetwork NETWORK;
	BackPropagation Propagation;
	double TMP1, TMP2, TMP3;
	double Test, P;
public:
	Network_Configuration();
	~Network_Configuration();

	void Preparation();
	void teaching();
	double Predict_Answer();
	void setInputData(vector<double>&);
	void RUN();

	vector<double>& getPredictedAnswer()
	{
		return PredictedAnswer;
	}

};

