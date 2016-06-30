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
