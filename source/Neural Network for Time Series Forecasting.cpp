// Neural Network Time Series Forcasting.cpp : Defines the entry point for the console application.
//

/*
*
*	Created on : 18 / 02 / 2017
*	Author : Youssef Sbai Idrissi. 
*
*/

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{




	vector<double> Data{ 10.5, 11.00, 14.5, 12.0 };

	Network_Configuration NetConf;
	NetConf.setInputData(Data);
	NetConf.RUN();

	for (auto it : Data)
	{
		cout << " >    " << it << endl;
	}

	cout << endl << " Predicted Result : " << NetConf.getPredictedAnswer().at(0) << endl << endl;


	system("pause");
}

