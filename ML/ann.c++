[Serializable]
struct PreInput
{
    public double Value;
    public double[] Weights;            
};

[Serializable]
struct Input
{
    public double InputSum;                
    public double Output;                
    public double Error;                
    public double[] Weights;        
};
            
[Serializable]        
struct Hidden        
{                
    public double InputSum;                    
    public double Output;                
    public double Error;                
    public double[] Weights;        
};
            
[Serializable]        
struct Output<T> where T : IComparable<T>         
{                
    public double InputSum;                
    public double output;                
    public double Error;                
    public double Target;     
    public T Value;   
};
private PreInput[] PreInputLayer;
private Input[] InputLayer;
private Hidden[] HiddenLayer;
private Output<string>[] OutputLayer;

void TrainNetwork(TrainingSet,MaxError)
{
     while(CurrentError>MaxError)
     {
          foreach(Pattern in TrainingSet)
          {
               ForwardPropagate(Pattern);//calculate output 
               BackPropagate()//fix errors, update weights
          }
     }
}

public bool Train()
{
    double currentError = 0;
    int currentIteration = 0;
    NeuralEventArgs Args = new NeuralEventArgs() ;

    do
    {
        currentError = 0;
        foreach (KeyValuePair<T, double[]> p in TrainingSet)
        {
            NeuralNet.ForwardPropagate(p.Value, p.Key);
            NeuralNet.BackPropagate();
            currentError += NeuralNet.GetError();
        }
                
        currentIteration++;
    
        if (IterationChanged != null && currentIteration % 5 == 0)
        {
            Args.CurrentError = currentError;
            Args.CurrentIteration = currentIteration;
            IterationChanged(this, Args);
        }

    } while (currentError > maximumError && currentIteration < 
    maximumIteration && !Args.Stop);

    if (IterationChanged != null)
    {
        Args.CurrentError = currentError;
        Args.CurrentIteration = currentIteration;
        IterationChanged(this, Args);
    }

    if (currentIteration >= maximumIteration || Args.Stop)   
        return false;//Training Not Successful
            
    return true;
}
private void ForwardPropagate(double[] pattern, T output)
{
    int i, j;
    double total;
    //Apply input to the network
    for (i = 0; i < PreInputNum; i++)
    {
        PreInputLayer[i].Value = pattern[i];
    }
    //Calculate The First(Input) Layer's Inputs and Outputs
    for (i = 0; i < InputNum; i++)
    {
        total = 0.0;
        for (j = 0; j < PreInputNum; j++)
        {
            total += PreInputLayer[j].Value * PreInputLayer[j].Weights[i];
        }
        InputLayer[i].InputSum = total;
        InputLayer[i].Output = F(total);
    }
    //Calculate The Second(Hidden) Layer's Inputs and Outputs
    for (i = 0; i < HiddenNum; i++)
    {
        total = 0.0;
        for (j = 0; j < InputNum; j++)
        {
            total += InputLayer[j].Output * InputLayer[j].Weights[i];
        }

        HiddenLayer[i].InputSum = total;
        HiddenLayer[i].Output = F(total);
    }
    //Calculate The Third(Output) Layer's Inputs, Outputs, Targets and Errors
    for (i = 0; i < OutputNum; i++)
    {
        total = 0.0;
        for (j = 0; j < HiddenNum; j++)
        {
            total += HiddenLayer[j].Output * HiddenLayer[j].Weights[i];
        }

        OutputLayer[i].InputSum = total;
        OutputLayer[i].output = F(total);
        OutputLayer[i].Target = OutputLayer[i].Value.CompareTo(output) == 0 ? 1.0 : 0.0;
        OutputLayer[i].Error = (OutputLayer[i].Target - OutputLayer[i].output) *
                                       (OutputLayer[i].output) * (1 - OutputLayer[i].output);
        }
    }        
    
private void BackPropagate()
{
    int i, j;
    double total;
    //Fix Hidden Layer's Error
    for (i = 0; i < HiddenNum; i++)
    {
        total = 0.0;
        for (j = 0; j < OutputNum; j++)
        {
            total += HiddenLayer[i].Weights[j] * OutputLayer[j].Error;
        }
        HiddenLayer[i].Error = total;
    }
    //Fix Input Layer's Error
    for (i = 0; i < InputNum; i++)
    {
        total = 0.0;
        for (j = 0; j < HiddenNum; j++)
        {
            total += InputLayer[i].Weights[j] * HiddenLayer[j].Error;
        }
        InputLayer[i].Error = total;
    }
    //Update The First Layer's Weights
    for (i = 0; i < InputNum; i++)
    {
        for(j = 0; j < PreInputNum; j++)
        {
            PreInputLayer[j].Weights[i] +=
                LearningRate * InputLayer[i].Error * PreInputLayer[j].Value;
        }
    }
    //Update The Second Layer's Weights
    for (i = 0; i < HiddenNum; i++)
    {
        for (j = 0; j < InputNum; j++)
        {
            InputLayer[j].Weights[i] +=
                LearningRate * HiddenLayer[i].Error * InputLayer[j].Output;
        }
    }
    //Update The Third Layer's Weights
    for (i = 0; i < OutputNum; i++)
    {
        for (j = 0; j < HiddenNum; j++)
        {
            HiddenLayer[j].Weights[i] +=
                LearningRate * OutputLayer[i].Error * HiddenLayer[j].Output;
        }
    }
}
