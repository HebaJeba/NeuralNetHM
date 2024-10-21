#include <vector>
using namespace std; 
#include <iostream> 

class Neuron{};
   typedef vector<Neuron> Layer; 



struct Connection{
	double weight;
	double deltaWeight; 
};

// ********************** class Neuron ***************

class Neuron{
	public:
		Neuron(unsigned numOutputs);
	private:
		double m_outputVal; 
		vector<Connection> m_outputWeights; 


};

Neuron::Neuron(unsigned numOutputs){
	for (unsigned c = 0; c < numOutputs; ++c){
		m_outputWeights.push_back(Connection());
		
	}
}

//****************** class Net ********************* */
class Net{
	public:
		Net(const vector<unsigned> &topology);
		void feedForward(const vector<double> &inputVals){};
		void backProp(const vector<double> &targetVals){};
		void getResults(vector <double> &resultVals) const{}; 
	private:
		vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
		// can access the layer and then from 
		// the layer access a specific neuron

};

Net::Net(const vector<unsigned> &topology){
	unsigned numLayers = topology.size(); // num of elements (num of layers)
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum){
		// each iteration we create a new layer and add to m_layers
		m_layers.push_back(Layer()); //layer object added to vector
		unsigned numOutputs;
		if (layerNum == topology.size()-1){
			numOutputs = 1;
		} 
		else{
			numOutputs = topology.at(layerNum + 1);
		}
		//after creating new layer we next add ith neurons
		// add bias neuron to the layer
		for (unsigned neuronNum = 0; neuronNum <= topology.at(layerNum); ++neuronNum){
			m_layers.back().push_back(Neuron(numOutputs));
			cout << "Made a Neuron" << endl; 
		}
	}

}
/*
constructor needs to make neurons
 2d arrangment by layers
 can have 2d array
 going forward neuron needs to access info from
 layer to the right 
 layer should be a datatype 
 all of the neurons arranged in layers
 net can have array of layers
 

 connection weights


*/
int main(){
	// { if send {3,2,1}  want 3 layers in the net
	// first layer is the input layer with 3 neurons
	// 1 hidden layer of 2 neurons
	// second layer is result layer with one neuron
	vector<unsigned> topology; 
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	vector<double> inputVals; 
	myNet.feedForward(inputVals); 

	vector<double> targetVals; 
	myNet.backProp(targetVals);  // tell output what it will be 
	
	vector<double> resultVals; 
	myNet.getResults(resultVals);

}



/*

{
public:
	Net(const vector<unsigned> &topology); // topology of the neural network is the layer structure, input values, and target output values.
	void feedForward(const vector<double> &inputVals); //Passes input values through each layer to produce outputs.
	void backProp(const vector<double> &targetVals); //
	void getResults(vector<double> &resultVals) const;
	double getRecentAverageError(void) const { return m_recentAverageError; }

private:
	vector<Layer> m_layers; //m_layers[layerNum][neuronNum]
	double m_error;
	double m_recentAverageError;
	static double m_recentAverageSmoothingFactor;
};

main(){
    Net myNet (topology);
    myNet.feedForward(inputVals);
    myNet.backProp(targetVals);
    myNet.getResults(resultVals);
}

// class Neuron
//calculating gradients
//input and output weights 
*/